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

bool ok(vector<int> &t, int gdzie, double val, int sum){
	int n = t.size();
	return (double)val * n * sum < (double)2.0 * sum - (double)n * t[gdzie];
}

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int n, sum=0;
		scanf("%d", &n);

		vector<int> t;

		for(int i=0; i<n; i++){
			int tmp;
			scanf("%d", &tmp);

			sum += tmp;
			t.push_back(tmp);
		}	

		vector<double> res(n);
	
		for(int i=0; i<n; i++){
			res[i] = (double)2/n - (double)t[i]/sum;
			res[i] = (double)100 * res[i];
		}

		for(int i=0; i<n; i++){
			printf("%.7f ", res[i]);
		}
		printf("\n");
	}

	return 0;
}
