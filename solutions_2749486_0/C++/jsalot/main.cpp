//
//  main.cpp
//  CodeJam
//
//  Created by Sercan Tutar on 4/13/13.
//  Copyright (c) 2013 Sercan Tutar. All rights reserved.
//

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <sstream>

#include <assert.h>
#include <math.h>

#define LOG_ERROR cout << "ERROR IN LINE: " << __LINE__ << endl
//#define NO_PROFILING

using namespace std;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#include <time.h>
#include <windows.h>
#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
inline int gettimeofday(struct timeval *tv, void *tz) {
	FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag;
	if (NULL != tv) {
		GetSystemTimeAsFileTime(&ft);
		tmpres |= ft.dwHighDateTime;
		tmpres <<= 32;
		tmpres |= ft.dwLowDateTime;
		tmpres /= 10;
		tmpres -= DELTA_EPOCH_IN_MICROSECS;
		tv->tv_sec = (long)(tmpres / 1000000UL);
		tv->tv_usec = (long)(tmpres % 1000000UL); }
	return 0; }
#else
#include <sys/time.h>
#endif

inline double get_time() {
	static struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1000000.0; }

static double time_started = get_time();
static double total_time = 0.0;
static long timer_counter = 0;

inline void start_time() {
	time_started = get_time(); }
inline void end_time() {
	total_time += get_time() - time_started;
	timer_counter++; }
inline void print_time() {
	if (timer_counter)
		cerr << "Count: " << timer_counter << " Total: " << total_time << " Avg: " << total_time / timer_counter << endl;
	else
		cerr << "Nothing recorded!" << endl; }
inline void reset_time() {
	total_time = 0.0;
	timer_counter = 0; }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifndef NO_PROFILING
#define PROFILED_SCOPE \
std::ostringstream _oss; \
_oss << __FUNCTION__ << ":" << __LINE__; \
ScopedProfile _sco_pro(_oss.str());

#define PROFILED_SCOPE_WITH_ID(ID) \
std::ostringstream _oss; \
_oss << __FUNCTION__ << ":" << __LINE__ << ":" << (ID); \
ScopedProfile _sco_pro(_oss.str());

#define PROFILED_NAMED_SCOPE(NAME) \
std::ostringstream _oss; \
_oss << (NAME); \
ScopedProfile _sco_pro(_oss.str());

#define PROFILED_NAMED_SCOPE_WITH_ID(NAME, ID) \
std::ostringstream _oss; \
_oss << (NAME) << ":" << (ID); \
ScopedProfile _sco_pro(_oss.str());
#else
#define PROFILED_SCOPE
#define PROFILED_SCOPE_WITH_ID(ID)
#define PROFILED_NAMED_SCOPE(NAME)
#define PROFILED_NAMED_SCOPE_WITH_ID(NAME, ID)
#endif

/**********************************************************************/

class Profile {
    friend class ScopedProfile;
    friend class Profiler;
private:
    Profile(const string& name);
    ~Profile();
    bool start();
    bool stop();
    unsigned int getCallCount() const;
    string getName() const;
    double getTime() const;
    map<string, Profile* >& getSubProfiles();
    map<string, Profile*> m_subProfiles;
    string m_name;
    unsigned int m_callCount;
    double m_time;
    double m_startTime;
};

/**********************************************************************/

class ScopedProfile {
public:
    ScopedProfile(const string& name);
    ~ScopedProfile();
private:
    Profile *m_profile;
};

/**********************************************************************/

class Profiler {
    friend class Profile;
    friend class ScopedProfile;
public:
    static void printStats(const string& filename);
    static void setOmitRecursiveCalls(bool omit);
    static bool getOmitRecursiveCalls();
private:
    Profiler();
    ~Profiler();
    static Profiler* getInstance();
    Profile* getProfile(const string& name);
    static void printStats();
    static void printStats(ofstream& fs, map<string, Profile*>* p, int depth);
    map<string, Profile*>& getCurrentProfilesRoot();
    void pushProfile(Profile *p);
    void popProfile();
    bool isInStack(const string& name);
    map<string, Profile*> m_profiles;
    static Profiler* m_instance;
    vector<Profile*> m_profileStack;
    bool m_omitRecursiveCalls;
};

/**********************************************************************/

inline Profile::Profile(const string& name) :
m_name(name), m_callCount(0), m_time(0.0) { }
inline Profile::~Profile() { }
inline bool Profile::start() {
    Profiler::getInstance()->pushProfile(this);
    m_startTime = get_time();
    return true; }
inline bool Profile::stop() {
    Profiler::getInstance()->popProfile();
    m_time += get_time() - m_startTime;
    ++m_callCount;
    return true; }
inline unsigned int Profile::getCallCount() const { return m_callCount; }
inline string Profile::getName() const { return m_name; }
inline double Profile::getTime() const { return m_time; }
inline map<string, Profile* >& Profile::getSubProfiles() { return m_subProfiles; }

/**********************************************************************/

inline ScopedProfile::ScopedProfile(const string& name) {
    string n(name);
    if (Profiler::getInstance()->isInStack(n)) { // profile is already in stack (probably a recursive call)
        if (Profiler::getInstance()->getOmitRecursiveCalls()) {
            m_profile = NULL;
            return; }
        else {
            n = "RECURSIVE@" + n; } }
    m_profile = Profiler::getInstance()->getProfile(n);
    if (m_profile != NULL) {
        if (!m_profile->start()) { // cannot start profiler (probably a recursive call for flat profiler)
            m_profile = NULL; } }
    else {
        cerr << "Cannot start scoped profiler: " << n << endl; } }
inline ScopedProfile::~ScopedProfile() {
    if (m_profile != NULL) {
        m_profile->stop(); } }

/**********************************************************************/

Profiler* Profiler::m_instance = NULL;
inline Profiler::Profiler() : m_omitRecursiveCalls(true) { }
inline Profiler::~Profiler() { }
inline Profiler* Profiler::getInstance() {
    if (m_instance == NULL) {
        m_instance = new Profiler;
        atexit(printStats); }
    return m_instance; }
inline Profile* Profiler::getProfile(const string& name) {
    map<string, Profile* >& profiles = getCurrentProfilesRoot();
    map<string, Profile* >::iterator it = profiles.find(name);
    if (it != profiles.end()) {
        return it->second; }
    else {
        Profile* result = new Profile(name);
        profiles[name] = result;
        return result; } }
inline map<string, Profile* >& Profiler::getCurrentProfilesRoot() {
    return m_profileStack.empty() ? m_profiles : m_profileStack.back()->getSubProfiles(); }
inline void Profiler::pushProfile(Profile* p) {
    m_profileStack.push_back(p); }
inline void Profiler::popProfile() {
    if (!m_profileStack.empty()) {
        m_profileStack.pop_back(); } }
inline bool Profiler::isInStack(const string& name) {
    for (unsigned int i=0; i<m_profileStack.size(); i++) {
        if (m_profileStack[i]->getName() == name) {
            return true; } }
    return false; }
inline void Profiler::printStats(ofstream& fs, map<string, Profile* >* p, int depth) {
    ostringstream oss;
    for (int i=0; i<depth; i++) {
        oss << "\t"; }
    map<string, Profile* >::iterator it = p->begin();
    for (; it != p->end(); it++) {
        unsigned int cc = it->second->getCallCount();
        double wall = it->second->getTime();
        fs << oss.str() << it->second->getName() << "  T:" << wall << "  #:" << cc << "  A:" << wall / cc << endl;
        printStats(fs, &(it->second->getSubProfiles()), depth+1); } }
inline void Profiler::printStats() {
    printStats("profiny.out"); }
inline void Profiler::printStats(const string& filename) {
    ofstream fs;
    fs.open(filename.c_str());
    if (!fs.is_open()) {
        cerr << "Cannot open profiler output file: " << filename << std::endl;
        return; }
    Profiler::printStats(fs, &(getInstance()->m_profiles), 0);
    fs.close(); }
inline void Profiler::setOmitRecursiveCalls(bool omit) {
    getInstance()->m_omitRecursiveCalls = omit; }
inline bool Profiler::getOmitRecursiveCalls() {
    return getInstance()->m_omitRecursiveCalls; }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<typename T>
ostream& operator<<(ostream &s, const vector<T> &c) {
	for(typename vector<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }
template<typename T>
ostream& operator<<(ostream &s, const list<T> &c) {
	for(typename list<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }
template<typename T>
ostream& operator<<(ostream &s, const deque<T> &c) {
	for(typename deque<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }
template<typename T>
ostream& operator<<(ostream &s, const stack<T> &c) {
	for(typename stack<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }
template<typename K, typename T>
ostream& operator<<(ostream &s, const map<K,T> &c) {
	for (typename map<K,T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << "(" << i->first << " -> " << i->second << ") ";
	return s; }
template<typename K, typename T>
ostream& operator<<(ostream &s, const unordered_map<K,T> &c) {
	for (typename unordered_map<K,T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << "(" << i->first << " -> " << i->second << ") ";
	return s; }
template<typename T>
ostream& operator<<(ostream &s, const set<T> &c) {
	for(typename set<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }
template<typename T>
ostream& operator<<(ostream &s, const unordered_set<T> &c) {
	for(typename unordered_set<T>::const_iterator i = c.begin(); i != c.end(); ++i)
		s << *i << " ";
	return s; }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<typename T>
class Heap
{
	template<typename TT>
	friend ostream& operator<<(ostream &s, const Heap<TT> &c);
public:
	inline Heap(bool isReverse=false) : isReverse(isReverse) { }
	inline Heap(const vector<T>& v, bool isReverse=false) : heap(v), isReverse(isReverse) {
		if (isReverse) make_heap(heap.begin(), heap.end(), greater<T>());
		else make_heap(heap.begin(), heap.end(), less<T>()); }
	inline void push(const T& e) {
		heap.push_back(e);
		if (isReverse) push_heap(heap.begin(), heap.end(), greater<T>());
		else push_heap(heap.begin(), heap.end(), less<T>()); }
	inline void pop() {
		if (isReverse) pop_heap(heap.begin(), heap.end(), greater<T>());
		else pop_heap(heap.begin(), heap.end(), less<T>());
		heap.pop_back(); }
	inline T top() const { return heap.front(); }
private:
	vector<T> heap;
	bool isReverse;
};

template<typename T>
ostream& operator<<(ostream &s, const Heap<T> &c) {
	return s << c.heap; }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline bool check_pos(int n) { return n >= 0; }
inline bool check_neg(int n) { return n <= 0; }

class BigInteger
{
	friend ostream& operator<<(ostream &s, const BigInteger &n);
    friend istream& operator>>(istream &s, BigInteger &val);
    
public:
	/* some constants */
	static BigInteger zero;
	static BigInteger one;
	static BigInteger two;
    
	/* constructors */
	inline BigInteger() : pos(true) { val.push_back(0); }
	inline BigInteger(const char* c) { string s = c; fromString(s); }
	inline BigInteger(const string& s) { fromString(s); }
	inline BigInteger(int l) : pos(l >= 0) {
		if (!pos) l = -l;
		div_t dt;
		do {
			dt = div(l, 10000);
			val.push_back(dt.rem);
			l = dt.quot;
		} while (l > 0); }
	inline BigInteger(long l) : pos(l >= 0) {
		if (!pos) l = -l;
		ldiv_t dt;
		do {
			dt = ldiv(l, 10000L);
			val.push_back((int) dt.rem);
			l = dt.quot;
		} while (l > 0); }
	inline BigInteger(long long l) : pos(l >= 0) {
		if (!pos) l = -l;
		lldiv_t dt;
		do {
			dt = lldiv(l, 10000LL);
			val.push_back((int) dt.rem);
			l = dt.quot;
		} while (l > 0); }
	inline BigInteger(unsigned int l) : pos(true) {
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0); }
	inline BigInteger(unsigned long l) : pos(true) {
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0); }
	inline BigInteger(unsigned long long l) : pos(true) {
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0); }
    
	/* assignment operators */
	inline const BigInteger& operator=(const char* c) { string s = c; fromString(s); return *this; }
	inline const BigInteger& operator=(const string& s) { fromString(s); return *this; }
	inline const BigInteger& operator=(int l) {
		pos = l >= 0;
		val.clear();
		if (!pos) l = -l;
		div_t dt;
		do {
			dt = div(l, 10000);
			val.push_back(dt.rem);
			l = dt.quot;
		} while (l > 0);
		return *this; }
	inline const BigInteger& operator=(long l) {
		pos = l >= 0;
		val.clear();
		if (!pos) l = -l;
		ldiv_t dt;
		do {
			dt = ldiv(l, 10000L);
			val.push_back((int) dt.rem);
			l = dt.quot;
		} while (l > 0);
		return *this; }
	inline const BigInteger& operator=(long long l) {
		pos = l >= 0;
		val.clear();
		if (!pos) l = -l;
		lldiv_t dt;
		do {
			dt = lldiv(l, 10000LL);
			val.push_back((int) dt.rem);
			l = dt.quot;
		} while (l > 0);
		return *this; }
	inline const BigInteger& operator=(unsigned int l) {
		pos = true;
		val.clear();
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0);
		return *this; }
	inline const BigInteger& operator=(unsigned long l) {
		pos = true;
		val.clear();
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0);
		return *this; }
	inline const BigInteger& operator=(unsigned long long l) {
		pos = true;
		val.clear();
		do {
			val.push_back(l % 10000);
			l = l / 10000;
		} while (l > 0);
		return *this; }
    
	/* unary increment/decrement operators */
	inline const BigInteger& operator++() {
		val[0] = val[0] + (pos ? 1 : -1);
		this->correct(false, true);
		return *this; }
	inline const BigInteger& operator--() {
		val[0] = val[0] - (pos ? 1 : -1);
		this->correct(false, true);
		return *this; }
	inline BigInteger operator++(int) {
        BigInteger result = *this;
		val[0] = val[0] + (pos ? 1 : -1);
		this->correct(false, true);
		return result; }
	inline BigInteger operator--(int) {
        BigInteger result = *this;
		val[0] = val[0] - (pos ? 1 : -1);
		this->correct(false, true);
		return result; }
    
	/* operational assignments */
	inline const BigInteger& operator+=(const BigInteger& rhs) {
		for (unsigned int i=0; i<val.size() || i<rhs.val.size(); i++) {
            if (i >= val.size()) val.push_back(i<rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
            else val[i] = (pos ? val[i] : -val[i]) + (i<rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0); }
		correct();
		return *this; }
	inline const BigInteger& operator-=(const BigInteger& rhs) {
		for (unsigned int i=0; i<val.size() || i<rhs.val.size(); i++) {
            if (i >= val.size()) val.push_back(i<rhs.val.size() ? (rhs.pos ? -rhs.val[i] : rhs.val[i]) : 0);
            else val[i] = (pos ? val[i] : -val[i]) - (i<rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0); }
		correct();
		return *this; }
	inline const BigInteger& operator*=(const BigInteger& rhs) {
        // TODO: optimize (do not use operator*)
        *this = *this * rhs;
		return *this; }
	inline const BigInteger& operator/=(const BigInteger& rhs) {
		if (rhs == zero) {cout << "division by zero" << endl; return *this;}
		BigInteger R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
        bool oldpos = pos;
        val.clear();
		for (int i = (int) N.val.size()-1; i >= 0; --i) {
			while (val.size() <= (unsigned int) i) val.push_back(0);
			R.val.push_front(0);
			R.val[0] = N.val[i];
			R.correct(true);
			short cnt = dinr(R, D);
			R -= D * cnt;
			val[i] += cnt; }
		correct();
		if (val.size() != 1 || val[0] != 0) pos = oldpos == rhs.pos;
        else pos = true;
		return *this; }
	inline const BigInteger& operator%=(const BigInteger& rhs) {
		if (rhs == zero) {cout << "division by zero" << endl; return zero;}
		BigInteger D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
        bool oldpos = pos;
        val.clear();
		for (int i = (int) N.val.size()-1; i >= 0; --i) {
			val.push_front(0);
			val[0] = N.val[i];
			correct(true);
			*this -= D * dinr(*this, D); }
		correct();
		if (val.size() != 1 || val[0] != 0) {
			pos = oldpos == rhs.pos;
			if (!rhs.pos) pos = !pos;
			if (!oldpos || !rhs.pos) *this += rhs; }
        else pos = true;
		return *this; }
    
	inline const BigInteger& operator*=(short rhs) {
		short factor = rhs < 0 ? -rhs : rhs;
        bool oldpos = pos;
		for (unsigned int i=0; i<val.size(); i++) {
			val[i] *= factor;}
		correct();
		if (val.size() != 1 || val[0] != 0) pos = oldpos == (rhs >= 0);
		return *this; }
    
	/* operations */
	inline BigInteger operator-() const {
		BigInteger result = *this;
		result.pos = !pos;
		return result; }
	inline BigInteger operator+(const BigInteger& rhs) const {
		BigInteger result;
		result.val.clear();
		for (unsigned int i=0; i<val.size() || i<rhs.val.size(); i++) {
			result.val.push_back((i<val.size() ? (pos ? val[i] : -val[i]) : 0) +
                                 (i<rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0)); }
		result.correct();
		return result; }
	inline BigInteger operator-(const BigInteger& rhs) const {
		BigInteger result;
		result.val.clear();
		for (unsigned int i=0; i<val.size() || i<rhs.val.size(); ++i) {
			result.val.push_back((i<val.size() ? (pos ? val[i] : -val[i]) : 0) -
                                 (i<rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0)); }
		result.correct();
		return result; }
	inline BigInteger operator*(const BigInteger& rhs) const {
		BigInteger result;
		result.val.clear();
		for (unsigned int digit = 0; ; digit++) {
			bool found = false;
			for (unsigned int i = 0; i <= digit; i++) {
				unsigned int j = digit - i;
				if (i < val.size() && j<rhs.val.size()) {
					if (found) result.val[i+j] += val[i] * rhs.val[j];
					else result.val.push_back(val[i] * rhs.val[j]);
					found = true; } }
			if (!found) break; }
		result.correct();
		if (result.val.size() != 1 || result.val[0] != 0) result.pos = pos == rhs.pos;
		return result; }
	inline BigInteger operator/(const BigInteger& rhs) const {
		if (rhs == zero) {cout << "division by zero" << endl; return zero;}
		BigInteger Q, R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
		for (int i = (int) N.val.size()-1; i >= 0; --i) {
			while (Q.val.size() <= (unsigned int) i) Q.val.push_back(0);
			R.val.push_front(0);
			R.val[0] = N.val[i];
			R.correct(true);
			short cnt = dinr(R, D);
			R -= D * cnt;
			Q.val[i] += cnt; }
		Q.correct();
		if (Q.val.size() != 1 || Q.val[0] != 0) Q.pos = pos == rhs.pos;
		return Q; }
	inline BigInteger operator%(const BigInteger& rhs) const {
		if (rhs == zero) {cout << "division by zero" << endl; return zero;}
		BigInteger R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
		for (int i = (int) N.val.size()-1; i >= 0; --i) {
			R.val.push_front(0);
			R.val[0] = N.val[i];
			R.correct(true);
			R -= D * dinr(R, D); }
		R.correct();
		if (R.val.size() != 1 || R.val[0] != 0) {
			R.pos = pos == rhs.pos;
			if (!rhs.pos) R.pos = !R.pos;
			if (!pos || !rhs.pos) R += rhs; }
		return R; }
    
	inline BigInteger operator*(short rhs) const {
		BigInteger result = *this;
		short factor = rhs < 0 ? -rhs : rhs;
		for (unsigned int i=0; i<result.val.size(); i++) {
			result.val[i] *= factor;}
		result.correct();
		if (result.val.size() != 1 || result.val[0] != 0) result.pos = pos == (rhs >= 0);
		return result; }
    
	/* relational operations */
	inline bool operator==(const BigInteger& rhs) const {
		if (pos != rhs.pos || val.size() != rhs.val.size()) return false;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] != rhs.val[i]) return false; }
		return true; }
	inline bool operator!=(const BigInteger& rhs) const {
		if (pos != rhs.pos || val.size() != rhs.val.size()) return true;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] != rhs.val[i]) return true; }
		return false; }
	inline bool operator<(const BigInteger& rhs) const {
		if (pos && !rhs.pos) return false;
		if (!pos && rhs.pos) return true;
		if (val.size() > rhs.val.size()) return pos ? false : true;
		if (val.size() < rhs.val.size()) return pos ? true : false;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] < rhs.val[i]) return pos ? true : false;
			if (val[i] > rhs.val[i]) return pos ? false : true; }
		return false; }
	inline bool operator<=(const BigInteger& rhs) const {
		if (pos && !rhs.pos) return false;
		if (!pos && rhs.pos) return true;
		if (val.size() > rhs.val.size()) return pos ? false : true;
		if (val.size() < rhs.val.size()) return pos ? true : false;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] < rhs.val[i]) return pos ? true : false;
			if (val[i] > rhs.val[i]) return pos ? false : true; }
		return true; }
	inline bool operator>(const BigInteger& rhs) const {
		if (pos && !rhs.pos) return true;
		if (!pos && rhs.pos) return false;
		if (val.size() > rhs.val.size()) return pos ? true : false;
		if (val.size() < rhs.val.size()) return pos ? false : true;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] < rhs.val[i]) return pos ? false : true;
			if (val[i] > rhs.val[i]) return pos ? true : false; }
		return false; }
	inline bool operator>=(const BigInteger& rhs) const {
		if (pos && !rhs.pos) return true;
		if (!pos && rhs.pos) return false;
		if (val.size() > rhs.val.size()) return pos ? true : false;
		if (val.size() < rhs.val.size()) return pos ? false : true;
		for (int i=(int) val.size()-1; i>=0; --i) {
			if (val[i] < rhs.val[i]) return pos ? false : true;
			if (val[i] > rhs.val[i]) return pos ? true : false; }
		return true; }
    
	/* other */
	inline BigInteger intsqrt() const {
		if (*this < zero) { cout << "intsqrt called with negative number" << endl; return zero; }
		BigInteger hi = *this / two, lo = zero, mid, mid2;
		do {
			mid = (hi + lo) / two; // 8 factor
			mid2 = mid*mid; // 1 factor
			if (mid2 < *this) lo = mid;
			else hi = mid;
		} while (lo < hi-one && mid2 != *this);
		return mid; }
    inline char digitat(unsigned long i) const {
        if (numberofdigits() <= i) { cout << "invalid digit index" << endl; return -1; }
        static int powersOfTen[] = { 1, 10, 100, 1000 };
        return (val[i / 4] / powersOfTen[i % 4]) % 10; }
    inline unsigned long numberofdigits() const {
        return (val.size()-1) * 4 + val.back() > 999 ? 4 : (val.back() > 99 ? 3 : (val.back() > 9 ? 2 : 1)); }
    inline string str() const {
        ostringstream oss;
        oss << *this;
        return oss.str(); }
    
private:
	inline void correct(bool justCheckLeadingZeros=false, bool hasValidSign=false) {
		if (!justCheckLeadingZeros) {
			for (unsigned int i=0; i<val.size(); ++i) { // truncate each to 4 digits
				if (val[i] >= 10000 || val[i] <= -10000) {
					div_t dt = div(val[i], 10000);
					val[i] = dt.rem;
					if (i+1 >= val.size()) val.push_back(dt.quot);
					else val[i+1] += dt.quot; } }
			//while (!all_of(val.begin(), val.end(), check_pos) && !all_of(val.begin(), val.end(), check_neg))
			for (int i=(int) val.size()-1; i>=0; --i) { // make all signs equal
				if (val[i] < 0) { // current number is negative
					int k = 0, index = i+k+1;
					while ((unsigned int) index < val.size() && val[index] == 0) { k++; index++; } // count adjacent zeros on left
					if ((unsigned int) index < val.size() && val[index] > 0) { // number on the left is positive
						val[index] -= 1; val[i] += 10000;
						for (; k>0; --k) val[i+k] = 9999; }
					else {
						k = 0, index = i-k-1;
						while (index >= 0 && val[index] == 0) { k++; index--; } // count adjacent zeros on right
						if (index >= 0 && val[index] > 0) { // number on the right is positive
							val[i] += 1; val[index] -= 10000;
							for (; k>0; --k) val[i-k] = -9999; } } } }
			if (all_of(val.begin(), val.end(), check_pos)) pos = hasValidSign ? pos : true;
			//else if (all_of(val.begin(), val.end(), check_neg)) pos = false;
			//else { pos = true; cout << "INTERNAL ERROR" << endl; sleep(1); exit(1); }
			else {
				pos = hasValidSign ? !pos : false;
				for (unsigned int i=0; i<val.size(); ++i) {
					val[i] = abs(val[i]); } } }
		for (int i=(int) val.size()-1; i>0; --i) { // remove leading 0's
			if (val[i] != 0) break;
			else val.erase(val.begin()+i); } }
	inline void fromString(const string& s) {
		pos = true;
		val.clear();
		int i = (int) s.size()-4;
		for (; i>=0; i-=4) {
			val.push_back(atoi(s.substr(i, 4).c_str())); }
		if (i > -4) {
			string ss = s.substr(0, i+4);
			if (ss.size() == 1 && ss[0] == '-') pos=false;
			else val.push_back(atoi(ss.c_str())); }
		if (val.back() < 0) {
			val.back() = -val.back(); pos=false; }
		correct(true); }
    inline static short dinr(const BigInteger& R, const BigInteger& D) {
        short min = 0, max = 9999;
        while (max - min > 0) {
            short avg = max + min;
            avg = avg % 2 ? (avg / 2 + 1) : (avg / 2);
            if (R >= D * avg) min = avg;
            else max = avg-1; }
        return min; }
    
	deque<int> val; // number with base 10000
	bool pos; // true if number is positive
};

BigInteger BigInteger::zero = BigInteger(0);
BigInteger BigInteger::one = BigInteger(1);
BigInteger BigInteger::two = BigInteger(2);

inline istream& operator>>(istream &s, BigInteger &n) {
    string str;
    s >> str;
    n.fromString(str);
    return s; }
inline ostream& operator<<(ostream &s, const BigInteger &n) {
	if (!n.pos) s << '-';
	for (int first = 1, i = (int) n.val.size()-1; i >= 0; --i, first = 0) {
		if (first)
			s << n.val[i];
		else
			for (int j=3; j>=0; --j) {
				static int powersOfTen[] = { 1, 10, 100, 1000 };
				s << (n.val[i] / powersOfTen[j]) % 10; } }
	return s; }

////////////////////////////////////////////////////////////////////////////////

void testbiginteger()
{
	start_time();
    
	BigInteger myint1 = "3418356018365183759254731254712361754715471695813896547912547915636130846142353463574685787635647568";
	BigInteger myint2 = 464518643414641LL;
	for (int i=0; i<100; i++)
	{
		BigInteger i1 = myint1++;
        assert(i1 == myint1-1);
        assert(i1-1 == --i1);
        assert(i1 == myint1-2);
        
		BigInteger i2 = myint2--;
        assert(i2 == myint2+1);
        assert(i2+1 == ++i2);
        assert(i2 == myint2+2);
        
		BigInteger root = myint1.intsqrt();
		BigInteger rootPlusOne = root + BigInteger::one;
		assert(root*root <= myint1 && myint1 <= rootPlusOne*rootPlusOne);
		assert((myint1*myint1).intsqrt() == myint1);
        assert((myint1/myint2) * myint2 + (myint1%myint2) == myint1);
        
        i1 = myint1; i1 += myint2;
        assert(i1 == myint1 + myint2);
        i1 = myint1; i1 -= myint2;
        assert(i1 == myint1 - myint2);
        i1 = myint1; i1 /= myint2;
        assert(i1 == myint1 / myint2);
        i1 = myint1; i1 *= myint2;
        assert(i1 == myint1 * myint2);
        i1 = myint1; i1 %= myint2;
        assert(i1 == myint1 % myint2);
	}
	cout << "end" << endl;
    
	end_time();
	print_time();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
 vector<int> v1, v2;
 
 for (int i=1; i<=10; i++) v1.push_back(i);
 cout << v1 << endl;
 
 // for_each sample
 for_each(v1.begin(), v1.end(), f);
 
 // transform sample
 v2.resize(v1.size());
 transform(v1.begin(), v1.end(), v2.begin(), f);
 
 // min, max & minmax samples
 cout << "min: " << *min_element(v1.begin(), v1.end()) << endl;
 cout << "max: " << *max_element(v1.begin(), v1.end()) << endl;
 cout << "min: " << *(minmax_element(v1.begin(), v1.end()).first) << endl;
 cout << "max: " << *(minmax_element(v1.begin(), v1.end()).second) << endl;
 
 // all_of - any_of - none_of - count_if - count
 cout << all_of(v1.begin(), v1.end(), p) << endl;
 cout << any_of(v1.begin(), v1.end(), p) << endl;
 cout << none_of(v1.begin(), v1.end(), p) << endl;
 cout << count_if(v1.begin(), v1.end(), p) << endl;
 cout << count(v1.begin(), v1.end(), 5) << endl;
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// includes & macro declarations here

// variables here

int X, Y;

string grid[201][201];
int jump=2;

inline void read()
{ // initialize variables of a case
    PROFILED_SCOPE
    cin >> X >> Y;
}

inline void solve()
{ // solves a case
    PROFILED_SCOPE
    if (grid[X+100][Y+100] != "") { cout << grid[X+100][Y+100]; return; }
    
    for (; ;++jump)
    {
        for (int i=0; i<201; i++)
            for (int j=0; j<201; j++)
                if (grid[i][j] != "" && grid[i][j].size() == jump-1)
                {
                    if (i+jump < 201) {
                        //if (grid[i+jump][j] == "")
                            grid[i+jump][j] = grid[i][j] + "E";
                        //cout << "e" << endl;
                    }
                    if (i-jump >= 0) {
                        //if (grid[i-jump][j] == "")
                            grid[i-jump][j] = grid[i][j] + "W";
                        //cout << "w" << endl;
                    }
                    if (j+jump < 201) {
                        //if (grid[i][j+jump] == "")
                            grid[i][j+jump] = grid[i][j] + "N";
                        //cout << "n" << endl;
                    }
                    if (j-jump >= 0) {
                        //if (grid[i][j-jump] == "")
                            grid[i][j-jump] = grid[i][j] + "S";
                        //cout << "s" << endl;
                    }
                }
        
        if (grid[X+100][Y+100] != "") { cout << grid[X+100][Y+100]; return; }
    }
}

int main(int argc, const char * argv[])
{
    for (int i=0; i<201; i++)
        for (int j=0; j<201; j++)
            grid[i][j] = "";
    grid[101][100] = "E";
    grid[99][100] = "W";
    grid[100][101] = "N";
    grid[100][99] = "S";

    PROFILED_SCOPE
    int noOfCases;
    cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++)
    {
        PROFILED_SCOPE_WITH_ID("loop")
        cout << "Case #" << i+1 << ": ";
        read();
        solve();
        cout << endl;
    }
    
    return 0;
}
