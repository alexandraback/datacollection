#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int A, B;
		double p[100001];
		p[0] = 1.0;

		scanf("%d%d", &A, &B);

		double res = B + 2;

		for(int i=1; i<=A; i++){
			double prob;
			cin >> prob;
			
			p[i] = (double)p[i-1] * prob;

			int left = B-A+1;

			double tmp = (double)p[i] * (left + 2*(A-i)) + (double)(1.0 - p[i]) * (left + 2*(A-i) + B + 1);
			if( tmp < res ){
				res = tmp;
			}
		}



		printf("%.6f\n", res);
	}

	return 0;
}
