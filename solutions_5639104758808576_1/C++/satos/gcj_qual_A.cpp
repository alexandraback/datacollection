#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX


char s[1010];
int qn;
int main(void){
	scanf("%d",&qn);
	rep(qq,qn){
		int n;
		scanf("%d%s",&n,s);
		vector<lli> dat;
		rep(i,n+1){
			dat.push_back((lli)(s[i]-'0'));
		}
	
		lli ans=0, np=0;	
		rep(i,dat.size()){
			if(np<i){
				ans+=i-np;
				np=i;
			}
			np+=dat[i];
		}
		printf("Case #%d: %lld\n",qq+1,ans);		
	}
	return 0;
}




