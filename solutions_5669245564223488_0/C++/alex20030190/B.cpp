#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define PB push_back
#define PF push_front
#define _PB pop_back
#define _PF pop_front
#define F first
#define S second
#define PI 3.1415926535897
#define _e 2.718281828
#define FIN(i,a,b) for(int i=a;i<=b;i++)
#define FEX(i,a,b) for(int i=a;i<b ;i++)
#define DIN(i,a,b) for(int i=a;i>=b;i--)
#define DEX(i,a,b) for(int i=a;i>b ;i--)
#define DEBUG printf
#define MOD 1000000007
bool testing = false;
char s[101][101],c;
int cc[27][27],occ[27][4];
int floyd[27][27];
int n,t,len[101],comp;
LL fact[101],ans;
int main(){
	if(!testing){
		freopen("B-small-attempt1.in","r",stdin);
		freopen("B.out","w",stdout);
	}
	fact[0]=1;
	for(int i=1;i<=100;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		//reset
		printf("Case #%d: ",i);
		memset(cc,0,sizeof(cc));
		memset(occ,0,sizeof(occ));
		//input
		scanf("%d",&n);
		FEX(j,0,n){
			scanf("%c%s",&c,s[j]);
			len[j]=strlen(s[j]);
			int cnt=0,x=-1;
			FEX(k,1,len[j]) if(s[j][k]!=s[j][k-1]) cnt++,x=max(x,k);
			//XY, X or in-between?
			if(cnt>=2){
				if(s[j][0]==s[j][len[j]-1]){printf("0\n");goto gg;}
				FEX(k,1,len[j]) if(s[j][k]!=s[j][k-1] && x>k) occ[s[j][k]-'a'][3]++;
			}
			cc[s[j][0]-'a'][s[j][len[j]-1]-'a']++;
			if(cnt==0) occ[s[j][0]-'a'][1]++;
			else occ[s[j][0]-'a'][0]++,occ[s[j][len[j]-1]-'a'][2]++;
		}
		//check for impossible
		FIN(i,0,25){
			int sum=occ[i][0]+occ[i][1]+occ[i][2]+occ[i][3];
			bool sad=false;
			if(occ[i][3]>0 && sum>1) sad=1;
			if(occ[i][0]>1) sad=1;
			if(occ[i][2]>1) sad=1;
			if(sad){
				printf("0\n");
				goto gg;
			}
		}
		//check for cycle
		FIN(i,0,25){
			FIN(j,0,25){
				if(i==j && cc[i][i]>0) floyd[i][i]=1;
				else if(i!=j && cc[i][j]>0) floyd[i][j]=1;
				else floyd[i][j]=9999;
			}
		}
		FIN(k,0,25) FIN(i,0,25) FIN(j,0,25){
			if(floyd[i][j]>floyd[i][k]+floyd[k][j]) floyd[i][j]=floyd[i][k]+floyd[k][j];
		}
		FIN(i,0,25) FIN(j,0,25)
			if(i!=j && floyd[i][j]<100 && floyd[j][i]<100){
				printf("0\n");
				goto gg;
			}
		comp=0;
		FIN(i,0,25){
			int sum=occ[i][1]+occ[i][2];
			if(sum>0 && occ[i][0]==0) comp++;
		}
		ans=1;
		ans*=fact[comp];
		FIN(i,0,25) ans=(ans*fact[occ[i][1]])%MOD;
		cout << ans << endl;
		gg:;
	}
	return 0;
}
