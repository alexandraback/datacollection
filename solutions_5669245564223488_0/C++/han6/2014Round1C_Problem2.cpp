#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;

typedef vector<size_t> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<double> vd;
typedef vector<string> vs;
const size_t END = 26;
const size_t MOD = 1000000007;

string getShort(const string &str)
{
	string shortStr;
	char prevChar;
	for (size_t i = 0; i < str.size(); i++) {
		if (i == 0 || str[i] != prevChar) {
			shortStr.push_back(str[i]);
			prevChar = str[i];
		}
	}
	return shortStr;
}

bool checkHiddenCharacter(size_t N, const vs &trains)
{
	for (size_t i = 0; i < N; i ++) {
		const string &train = trains[i];
		if (train.size() <= 2) {
			continue;
		} else {
			set<char> S;
			for (size_t j = 0; j < train.size(); j ++) {
				S.insert(train[j]);
			}
			if (S.size() < train.size()) {
				return false;
			}
			S.erase(train[0]);
			S.erase(train[train.size()-1]);
			for (size_t n = 0; n < N; n ++) {
				if (n != i) {
					const string &other = trains[n];
					for (size_t j = 0; j < other.size(); j ++) {
						if (S.find(other[j]) != S.end()) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool getChains(size_t N, const vs &trains, size_t single[], vector<list<size_t>> &VL)
{
	size_t prev[END], next[END];
	for (size_t i = 0; i < END; i ++) {
		prev[i] = END;
		next[i] = END;
		single[i] = 0;
	}
	for (size_t i = 0; i < N; i ++) {
		const string &train = trains[i];
		size_t front = train[0] - 'a';
		size_t back = train[train.size() - 1] - 'a';
		if (front != back) {
			if (prev[back] == END) {
				prev[back] = front;
			} else {
				return false;
			} if (next[front] == END) {
				next[front] = back;
			} else {
				return false;
			}
		} else {
			single[front] ++;
		}
	}

	queue<size_t> Q;
	for (size_t i = 0; i < END; i ++) {
		if (prev[i] == END && next[i] != END) {
			Q.push(i);
		}
	}
	
	size_t listLocator[END];
	for (size_t i = 0; i < END; i ++) {
		listLocator[i] = END;
	}

	while (! Q.empty()) {
		size_t v1 = Q.front();
		Q.pop();
		size_t v2 = next[v1];
		if (v2 != END) {
			if (listLocator[v1] == END) {
				list<size_t> L;
				L.push_back(v1);
				listLocator[v1] = VL.size();
				L.push_back(v2);
				listLocator[v2] = VL.size();
				VL.push_back(L);
			} else {
				VL[listLocator[v1]].push_back(v2);
				listLocator[v2] = listLocator[v1];
			}
			next[v1] = END;
			prev[v2] = END;
			Q.push(v2);
		}
	}

	for (size_t i = 0; i < END; i ++) {
		if (single[i] > 0 && listLocator[i] == END) {
			list<size_t> L;
			L.push_back(i);
			listLocator[i] = VL.size();
			VL.push_back(L);
		}
	}

	for (size_t i = 0; i < END; i ++) {
		if (prev[i] != END) {
			return false;
		}
		if (next[i] != END) {
			return false;
		}
	}

	return true;
}

string solve(size_t N, vs &trains)
{
	for (size_t i = 0; i < N; i ++) {
		trains[i] = getShort(trains[i]);
	}

	ll result;
	size_t single[END];
	vector<list<size_t>> VL;
	if(! checkHiddenCharacter(N, trains)) {
		result = 0;
	} else if (! getChains(N, trains, single, VL)) {
		result = 0;
	} else {
		result = 1;
		ll fac[150];
		fac[0] = 1;
		for (size_t i = 1; i < 150; i ++) {
			fac[i] = fac[i-1] * i % MOD;
		}
		for (size_t i = 0; i < END; i ++) {
			result = result * fac[single[i]] % MOD;
		}
		result = result * fac[VL.size()] % MOD;
	}

	char answer[50];
	sprintf(answer, "%lld", result);
	return answer;
}

void preprocess(){}

void readinput(size_t &N, vs &trains)
{
	cin>>N;
	trains.resize(N);
	for (size_t i = 0; i < N; i ++) {
		cin>>trains[i];
	}
}

vs getoutput()
{
	size_t N;
	vs trains;
	readinput(N, trains);
	string answer = solve(N, trains);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	freopen("test\\B-small-attempt0.in", "r", stdin);freopen("test\\B-small-attempt0.out", "w", stdout);
//	freopen("test\\B-large.in", "r", stdin);freopen("test\\B-large.out", "w", stdout);
	size_t testcase;
	cin>>testcase;
	preprocess();
	for(size_t i = 1; i <= testcase; i ++)
	{
		cout<<"Case #"<<i<<": ";
		vs answer = getoutput();
		for(size_t j = 0; j < answer.size(); j ++)
			cout<<answer[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}