
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

//#define VARPRINT(abc) cout << #abc " " << (abc) <<  endl;
#define VARPRINT()
#define forn(i,n) for(int i = 0; i < n; ++i)
#define forn2(i,d,n) for(int i = d; i < n; ++i)

int maxBanana(string const& target, int const& S){
	int const length = target.length();
	int count = 0;
	int first = 0;
	forn2(i, 1, length + 1){
		VARPRINT(target.substr(i))
			VARPRINT(target.substr(0, length - i))
		if (target.substr(i) == target.substr(0, length - i)){
			first = i;
			break;
		}
	}
	return (S - (length - first)) / first;
}

void solve(){
	int K, L, S;
	cin >> K >> L >> S;
	string keys;
	string target;
	cin >> keys >> target;
	VARPRINT(keys)
	VARPRINT(target)
	forn (i, L) {
		VARPRINT(keys.find(target.substr(i, 1)))
		if (keys.find(target.substr(i,1)) == string::npos){
			cout << 0;
			return;
		}
	}
	auto maxBana = maxBanana(target, S);
	VARPRINT(maxBana)
	double prop = 1;
	for (int i = 0; i < target.length(); ++i) {
		prop *= static_cast<double>(count(keys.begin(), keys.end(), target[i])) / K;
	}
	VARPRINT(prop)
	auto useBana = prop * (S - L + 1);
	VARPRINT(useBana)
	cout << maxBana - useBana;
}

void testCase(void(*aFunction)()){
	size_t testCaseMax;
	cin >> testCaseMax;
	for (size_t i = 0; i < testCaseMax; ++i){
		cout << "Case #" << i + 1 << ": ";
		aFunction();
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	//solve();
	testCase(&solve);
	return 0;
}

