#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

#define FOR0(i,N) for(int i=0; i<(N); i++)
#define FOR1(i,N) for(int i=1; i<=(N); i++)

struct _compare {
	bool operator()(int i, int j) {
		return i>j;
	}
};

int K, L, S;
char ks[101];
char l[101];
map<char,double> k;
map<char,double>::iterator it;
bool possible;
int bcount;

double match_str() {
	double retval = 1.0;
	FOR0(i,L) {
		it = k.find(l[i]);
		retval *= it->second;
	}
	return retval;
}

int main()
{
//	freopen("1c/sample.in", "r", stdin);
	freopen("1c/B-small-attempt0.in", "r", stdin);
//	freopen("1c/B-large.in", "r", stdin);
	freopen("1c/outputB", "w", stdout);

	int test_case;

	int repeat;

	scanf("%d", &test_case);
	double Ans;
	FOR1(T,test_case) {
		Ans=0.0;
		bcount = 0;
		possible = true;
		k.clear();
		scanf("%d %d %d\n", &K, &L, &S);
		repeat = L;
		gets(ks);
		gets(l);
		FOR0(i,K) {
			if( (it=k.find(ks[i])) == k.end()) {
				k[ks[i]] = 1.0/K;
			}
			else {
				it->second += 1.0/K;
			}
		}
		FOR0(i,L) {
			if( k.find(l[i]) == k.end() ) {
				possible = false;
				Ans = 0.0;
				break;
			}
		}
		if(possible) {
			FOR1(i,L-1) {
				if(strncmp(l, &l[i], L-i) == 0) {
					repeat = i;
					break;
				}
			}
			int ii=0;
			while( S-ii >= L ) {
				bcount++;
				ii += repeat;
			}
			Ans = (double)bcount * (1.0-match_str());
		}
		printf("Case #%d: %.7f\n", T, Ans);
	}
	return 0;
}






