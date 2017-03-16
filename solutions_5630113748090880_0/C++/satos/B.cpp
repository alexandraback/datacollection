#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int d[3000];

int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qqq,1,qn){
		printf("Case #%d: ",qqq);
		memset(d,0,sizeof(d));
		int n;
		scanf("%d",&n);
		rep(i,n*2-1){
			rep(j,n){
				int a;
				scanf("%d",&a);
				d[a]++;
			}
		}
		vector<int> ans;
		rep(i,2800){
			if(d[i]%2)ans.push_back(i);
		}
		int ls = ans.size();
		rep(i,ls){
			printf("%d%c",ans[i],i+1==ls?'\n':' ');
		}
	}
		
	return 0;
}




