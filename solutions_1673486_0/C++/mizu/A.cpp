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
#include <list>
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
	int T;
	cin>>T;
	for(int pnum=0; pnum<T; pnum++){
		int A, B;
		cin>>A>>B;
		vector<double> p;
		FOR(i,A){
			double pp;
			cin>>pp;
			p.push_back(pp);
		}
		vector<double> misn;
		double dn = 1.0;
		FOR(i,A){
			misn.push_back(dn*(1.0-p[i]));
			dn *= p[i];
		}
		misn.push_back(dn);

		vector<double> misn_sum;
		double tmp = 0;
		reverse(ALL(misn));
		FOR(i,SIZE(misn)){
			tmp += misn[i];
			misn_sum.push_back(tmp);
		}
		double ans = 1000000000;

		//cout<<"ans list - ";
		FOR(n,A+2){
			double tmp = 0.0;
			if(n==0){
				tmp = misn_sum[0]*(B-A+1) + (1.0-misn_sum[0])*((B-A+1)+B+1);
				ans = min(ans, tmp);
			}else if(n==A+1){
				tmp = B + 2;
				ans = min(ans, tmp);
			} else {
				tmp = misn_sum[n]*(n*2+B-A+1) + (1.0-misn_sum[n])*(n*2+(B-A+1)+B+1);
				ans = min(ans, tmp);
			}
			//cout<<tmp<<" ";
		}
		//cout<<endl;
		printf("Case #%d: %f\n", pnum+1, ans);


	}
}
