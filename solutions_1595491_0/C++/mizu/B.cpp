#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <strstream>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vii;
typedef vector<vector<string> > vss;
typedef pair<int, int> pii;
#define x first
#define y second
#define INF 0x7fffffff
//#define INFLL 0x7fffffffffffffff
#define INFLL LLONG_MAX
#define SIZE(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,x) for(int i=0;i<x;i++)
#define FORic(i,y,x) for(int i=y;i<=x;i++)
#define FORdc(i,y,x) for(int i=y;i>=x;i--)
#define FILL(a,v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846

int main()
{
	char buf[256];
	int T;
	gets(buf);
	string sb = buf;
	istrstream istr(sb.data());
	istr >> T;
	FOR(ttt,T){
		gets(buf);
		sb = buf;
		istrstream cins(sb.data());
		int N;
		int S;
		int p;
		cins>>N>>S>>p;
		int ans = 0;
		int kouho = 0;
		FOR(i,N){
			int t;
			cins>>t;
			int point = t/3;
			if(point >= p){
				ans++;
			} else {
				if(t%3==0){
					if(point+1 >= p){
						if(t>=3) kouho++;
					}
				} else if(t%3==1){
					if(point+1 >= p){
						ans++;
					}
				} else {
					if(point+1 >= p){
						ans++;
					} else if(point+2 >= p){
						kouho++;
					}
				}
			}
		}
		ans += min(kouho,S);

		printf("Case #%d: %d\n", ttt+1, ans);
	}
}
