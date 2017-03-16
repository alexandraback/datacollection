//Template for Dev-C++ 5.3.0.4 by unlimitedsky
//2013 March 4 20:58 (UTC +07.00)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

#define EPS 0.0000001
double c, f, x;
int tc, bound, seth;
double score[100005], farm[100005], temp;

int main(){
	scanf("%d", &tc);
	INC(i,1,tc){
		reset(score,0);
		reset(farm,0);
		scanf("%lf %lf %lf", &c, &f, &x);
		farm[0] = 0.0;
		score[0] = (double)x/2.0;
		INC(j,1,(int)x){
			temp = (double)c/(double)(2.0 + (double)(j-1)*(double)f);
			farm[j] = farm[j-1] + temp;
			temp = (double)x/(double)(2.0 + (double)j * f);
			score[j] = farm[j] + temp;
		}
		seth = score[0];
		for (int j = 0; j <= (int)x; j++){
			if (score[j] < score[seth]) seth = j;
		}
		printf("Case #%d: %.7lf\n", i, score[seth]);
	}
	
	return 0;
}
