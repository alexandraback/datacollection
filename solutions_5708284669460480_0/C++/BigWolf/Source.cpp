#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <functional>
#include <memory>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cctype>
#include <limits.h>
using namespace std;
#define ll long long
#define ull unsigned ll
const int INF = 1e9 + 7;
const double Pi = 2 * acos(0.);
const double EPS = 1e-13;
template<class T> inline T sqr(const T& x){ return x*x; }
struct point{
	double x, y;
	point(double a = 0, double b = 0) :x(a), y(b){}
};
inline point lineFunc(const point& a, const point& b){
	point result;
	result.x = (b.y - a.y) / (b.x - a.x);
	result.y = a.y - a.x*result.x;
	return result;
}
template<class T>
inline void in(const T& start, const T& end){
	for (T it = start; it != end; ++it){
		cin >> *it;
	}
}
template<class T>
inline void out(const T& start, const T& end){
	for (T it = start; it != end; ++it){
		cout << *it << " ";
	}
}
inline double dist(const point& a, const point& b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline double vectorLenth(const point& a){
	return sqrt(sqr(a.x) + sqr(a.y));
}
void run();
int main(){
	ios_base::sync_with_stdio(0);
#ifdef TRAINING
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cout.precision(6);
	cout.setf(cout.fixed);
	run();
	return 0;
}
int connected(string word, int s){
	if (word.size() == 1)
		return s;	
	int j = 1;
	for (j; j < word.size(); ++j){
		bool founded = true;
		for (int t = 0; j + t < word.size(); ++t)
			if (word[t] != word[j + t]){
				founded = false;
				break;
			}
		if (founded)
			break;
	}
	return s/j;
}
void smallRun();
void run(){
	return smallRun();
	int t, k, l, s;
	cin >> t;
	string letters, word;
	for (int p = 1; p <= t; ++p){
		vector<long double> words(26, 0);
		cin >> k >> l >> s;	
		cin >> letters >> word;
		long double pr = 1;
		for (int i = 0; i < letters.size(); ++i)
			words[letters[i] - 'A']++;
		for (int i = 0; i < word.size(); ++i){
			pr *= words[word[i] - 'A'] / k;

		}
		int maxCount = connected(word, s);
		if (abs(pr - 1.0) < EPS || abs(pr) < EPS){
			cout << "Case #" << p << ": " << 0 << endl;
		}
		else{
			pr *= (pow(pr, maxCount - 1) - 1) / (pr - 1);
			cout << "Case #" << p << ": " << double(maxCount)*(1.0 - pr) << endl;
		}
		
			
	}
}
vector<int> banans(9, 0);
int howMuchWord(const string& in, const string& word){
	int counted = 0;
	for (int i = 0; i + word.size() - 1 < in.size(); ++i){
		bool founded = true;
		for (int j = 0; j < word.size(); ++j){
			if (in[i + j] != word[j]){
				founded = false;
				break;
			}
		}
		counted += founded;
	}
	return counted;
}
void dfs(const string& letter, const string& word, string& makeWord, int pos){
	if (pos == makeWord.size()){
		banans[howMuchWord(makeWord, word)]++;
		return;
	}
	for (int i = 0; i < letter.size(); ++i){
		makeWord[pos] = letter[i];
		dfs(letter, word, makeWord, pos + 1);
	}
	return;
}
long double calculateResult(){
	long double all = 0;
	for (int i = 0; i < banans.size(); ++i){
		all += banans[i];
	}
	long double result = 0;
	for (int i = 0; i < banans.size(); ++i)
		result += i*double(banans[i]) / all;
	int maxi;
	for (maxi = banans.size() - 1; maxi >= 0; --maxi)
		if (banans[maxi])
			break;
	return long double(maxi) - result;
}
void smallRun(){
	int t, k, l, s;
	cin >> t;
	string letters, word;
	for (int p = 1; p <= t; ++p){
		banans.assign(9, 0);
		cin >> k >> l >> s;
		cin >> letters >> word;
		string makeWord(s, '0');
		dfs(letters, word, makeWord, 0);
		cout << "Case #" << p << ": " << calculateResult() << endl;
	}
}