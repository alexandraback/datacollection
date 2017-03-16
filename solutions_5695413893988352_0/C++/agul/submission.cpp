#pragma comment(linker, "/STACK:66777216")

#include <cstdio>
#pragma warning(disable : 4996)
#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <functional>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <queue>
#include <cmath>
#include <random>
#include <sstream>
#include <numeric>
#include <limits>
#include <chrono>
#include <type_traits>
#pragma hdrstop

#ifdef _MSC_VER
#include <intrin.h>


#else
#define LLD "%lld"
#define LLU "%llu"
#define popcount(a) __builtin_popcount(a)
#define clz(a) __builtin_clz(a)
#define ctz(a) __builtin_ctz(a)
#endif


#define ll int64_t


const int INF = 0x3f3f3f3f;

const ll LINF = 0x3f3f3f3f3f3f3f3fLL;


template<class T> 
inline bool umin(T& a, const T& b) {
	return (b < a ? a = b, true : false);
}


#ifdef _MSC_VER


#endif


inline bool is_digit(const char ch) {
	return (ch >= '0' && ch <= '9');
}


class IO {
public:
	
	constexpr static const std::size_t kBufferSize = 1 << 18;

	IO() : read_bytes_count_(0), read_buffer_offset_(0), current_char_(0), eof_(false) {
		static_assert(kBufferSize > 32, "Size of a buffer must be greater than 32 due to comparison in IO::flush() method.");
	}

	~IO() {
		flush();
	}

	IO(const IO&) = delete;
	IO& operator=(const IO&) = delete;
	IO(const IO&&) = delete;
	IO& operator=(const IO&&) = delete;

	
	inline void shift_char();
	inline void skipws();
	

	inline int32_t next_int();
	
	
	inline void next_string(char* s);
	

	IO& operator >>(int32_t& x);
	
	
	IO& operator >>(char* s);

	inline void flush();
	inline void new_line();

	inline void print_int(const int32_t x);
	
	
	inline void print_char(const char ch);
	inline void print_string(const char* s);
	//inline void print_string(const std::string& s);
	
	//inline void print_line(const std::string& s);

	IO& operator <<(const int32_t x);
	
	
	IO& operator <<(const char x);
	IO& operator <<(const char* s);
	IO& operator <<(const std::string& s);

	// Intended to use with std::endl.
	IO& operator <<(std::ostream& (*)(std::ostream&));

	
	static void assign_files_input_txt();

private:
	using Buffer = std::array<char, kBufferSize>;
	Buffer read_buffer_;
	Buffer write_buffer_;
	std::size_t read_bytes_count_;
	std::size_t read_buffer_offset_;
	std::size_t write_buffer_offset_;
	bool eof_;
	char current_char_;

	inline void update_buffer();

	template<typename T>
	T read_number();

	template<typename T>
	void print_number(const T& value);

};

extern bool useFastIO;
extern std::istream * pin;
extern std::ostream * pout;
extern IO io;

inline int32_t next_int();


inline void next_string(char* s);


inline void new_line();

inline void print_int(const int32_t x);


inline void print_char(const char x);
inline void print_string(const char* s);
//inline void print_string(const std::string& s);

//inline void print_line(const std::string& s);


using namespace std;

int __;
IO io;

const int MAXN = 111111;

char s[MAXN], t[MAXN], as[MAXN], at[MAXN];
string ax, ay;

void brute() {
	int ls = strlen(s);
	int best = INF;
	for (int i = 0; i < 1000; ++i) {
		std::string str = std::to_string(i);
		while (str.length() < ls) {
			str = "0" + str;
		}
		if (str.length() > ls) {
			break;
		}
		bool ok = true;
		for (int j = 0; j < ls; ++j) {
			if (s[j] != '?' && str[j] != s[j]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			continue;
		}
		for (int j = 0; j < 1000; ++j) {
			std::string str2 = std::to_string(j);
			while (str2.length() < ls) {
				str2 = "0" + str2;
			}
			if (str2.length() > ls) {
				break;
			}
			bool ok = true;
			for (int k = 0; k < ls; ++k) {
				if (t[k] != '?' && str2[k] != t[k]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			if (umin(best, abs(i - j))) {
				ax = str;
				ay = str2;
			}
		}
	}
}

void check_brute(const std::string& s, const std::string& t) {
	if (ax != s || ay != t) {
		std::cerr << "ERROR!" << std::endl;
		std::cerr << "Expected: " << ax << " " << ay << std::endl;
		std::cerr << "Found: " << s << " " << t << std::endl;
		exit(0);
	}
}

void update_score(const char * s, const char * t, ll& ax, ll& ay) {
	ll best = abs(ax - ay);
	ll cx = atoi(s);
	ll cy = atoi(t);
	if (umin(best, abs(cx - cy)) || (best == abs(cx - cy) && ax > cx) || (best == abs(cx - cy) && ax == cx && ay > cy)) {
		ax = cx;
		ay = cy;
	}
}

std::string make(ll x, int ls) {
	std::string s = to_string(x);
	while (s.length() < ls) {
		s = "0" + s;
	}
	return s;
}

void solve(istream& ins, ostream& out) {
	io.assign_files_input_txt();
	io >> __;
	for (int _ = 1; _ <= __; ++_) {
		std::cerr << _ << std::endl;
		io << "Case #" << _ << ": ";
		io >> s >> t;
		// brute();
		// io << ax << " " << ay << endl;
		// continue;
		int ls = strlen(s);
		int cur_ind = 0;
		while (cur_ind < ls) {
			if (s[cur_ind] != '?' && t[cur_ind] != '?' && s[cur_ind] != t[cur_ind]) {
				++cur_ind;
				break;
			}
			++cur_ind;
		}
		ll ax = 0, ay = LINF;
		for (int i = 0; i <= cur_ind; ++i) {
			if (i > 0) {
				if (s[i - 1] == '?' && t[i - 1] == '?') {
					s[i - 1] = t[i - 1] = '0';
				}
				else
				if (s[i - 1] == '?') {
					s[i - 1] = t[i - 1];
				}
				else
				if (t[i - 1] == '?') {
					t[i - 1] = s[i - 1];
				}
			}
			if (i == ls) {
				update_score(s, t, ax, ay);
				break;
			}
			char sx = '0', fx = '9';
			char sy = '0', fy = '9';
			if (s[i] != '?') {
				sx = fx = s[i];
			}
			if (t[i] != '?') {
				sy = fy = t[i];
			}
			for (char x = sx; x <= fx; ++x) {
				for (char y = sy; y <= fy; ++y) {
					if (x == y) {
						continue;
					}
					strcpy(as, s);
					strcpy(at, t);
					as[i] = x;
					at[i] = y;
					if (x < y) {
						for (int j = i + 1; j < ls; ++j) {
							if (as[j] == '?') {
								as[j] = '9';
							}
							if (at[j] == '?') {
								at[j] = '0';
							}
						}
					}
					else {
						for (int j = i + 1; j < ls; ++j) {
							if (as[j] == '?') {
								as[j] = '0';
							}
							if (at[j] == '?') {
								at[j] = '9';
							}
						}
					}

					update_score(as, at, ax, ay);
				}
			}
		}
		io << make(ax, ls) << ' ' << make(ay, ls) << endl;
		// check_brute(make(ax, ls), make(ay, ls));
	}
}


#include <fstream>


extern class IO io;
bool useFastIO = false;
istream * pin;
ostream * pout;


int main() {
    srand(time(NULL));
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;
    useFastIO = true;


    ostream& out = cout;

    out << fixed << setprecision(16);
    pin = &in; pout = &out;
    solve(in, out);
    return 0;
}


inline void IO::skipws() {
	while (!eof_ && (current_char_ == ' ' || current_char_ == '\n')) {
		shift_char();
	}
}


template<typename T>
T IO::read_number() {
	bool is_negative = false;
	while (!eof_ && !is_digit(current_char_) && (std::is_unsigned<T>() || current_char_ != '-')) {
		shift_char();
	}
	if (std::is_signed<T>() && current_char_ == '-') {
		is_negative = true;
		shift_char();
	}
	T result = 0;
	while (!eof_ && is_digit(current_char_)) {
		result = (result << 3) + (result << 1) + current_char_ - '0';
		shift_char();
	}
	return (is_negative ? result * -1 : result);
}

template<typename T>
void IO::print_number(const T& value) {
	T current_value = value;
	if (write_buffer_offset_ + 32 > kBufferSize) {
		flush();
	}
	if (current_value < 0) {
		write_buffer_[write_buffer_offset_++] = '-';
		current_value = abs(current_value);
	} else
	if (current_value == 0) {
		write_buffer_[write_buffer_offset_++] = '0';
		return;
	}
	std::size_t start_index = write_buffer_offset_;
	while (current_value != 0) {
		write_buffer_[write_buffer_offset_++] = current_value % 10 + '0';
		current_value /= 10;
	}
	std::reverse(write_buffer_.begin() + start_index, write_buffer_.begin() + write_buffer_offset_);
}


inline void IO::update_buffer() {
	if (read_buffer_offset_ == read_bytes_count_) {
		read_bytes_count_ = fread(&read_buffer_[0], sizeof(read_buffer_[0]), read_buffer_.size(), stdin);
		if (read_bytes_count_ == 0) {
			eof_ = true;
			return;
		}
		read_buffer_offset_ = 0;
	}
}

inline void IO::shift_char() {
	update_buffer();
	current_char_ = read_buffer_[read_buffer_offset_++];
}

inline int32_t IO::next_int() {
	return read_number<int32_t>();
}


inline void IO::next_string(char* s) {
	if (current_char_ == '\0') {
		shift_char();
	}
	skipws();
	std::size_t index = 0;
	while (!eof_ && current_char_ != ' ' && current_char_ != '\n') {
		s[index++] = current_char_;
		shift_char();
	}
	s[index] = 0;
}

IO& IO::operator >>(int32_t& x) {
	x = ::next_int();
	return *this;
}


IO& IO::operator >>(char* s) {
	::next_string(s);
	return *this;
}


void IO::assign_files_input_txt() {
	if (useFastIO) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
}

inline void IO::flush() {
	fwrite(&write_buffer_[0], sizeof(write_buffer_[0]), write_buffer_offset_, stdout);
	write_buffer_offset_ = 0;
}

inline void IO::new_line() {
	if (write_buffer_offset_ == kBufferSize) {
		flush();
	}
	write_buffer_[write_buffer_offset_++] = '\n';
}

inline void IO::print_int(const int32_t x) {
	print_number(x);
}


inline void IO::print_char(const char x) {
	if (write_buffer_offset_ == kBufferSize) {
		flush();
	}
	write_buffer_[write_buffer_offset_++] = x;
}

inline void IO::print_string(const char* s) {
	for (std::size_t i = 0; s[i] != '\0'; ++i) {
		if (write_buffer_offset_ == kBufferSize) {
			flush();
		}
		write_buffer_[write_buffer_offset_++] = s[i];
	}
}


IO& IO::operator <<(const int32_t x) {
	::print_int(x);
	return *this;
}


IO& IO::operator <<(const char x) {
	::print_char(x);
	return *this;
}

IO& IO::operator <<(const char* s) {
	::print_string(s);
	return *this;
}

IO& IO::operator <<(const std::string& s) {
	::print_string(s.c_str());
	return *this;
}

IO& IO::operator <<(std::ostream& (*)(std::ostream&)) {
	::new_line();
	return *this;
}

inline int32_t next_int() {
	if (useFastIO) {
		return io.next_int();
	}
	int32_t ret;
	*pin >> ret;
	return ret;
}


inline void next_string(char* s) {
	if (useFastIO) {
		io.next_string(s);
		return;
	}
	*pin >> s;
}


inline void new_line() {
	if (useFastIO) {
		io.new_line();
		return;
	}
	*pout << std::endl;
}

inline void print_int(const int32_t x) {
	if (useFastIO) {
		io.print_int(x);
		return;
	}
	*pout << x;
}


inline void print_char(const char x) {
	if (useFastIO) {
		io.print_char(x);
		return;
	}
	*pout << x;
}

inline void print_string(const char* s) {
	if (useFastIO) {
		io.print_string(s);
		return;
	}
	*pout << s;
}


