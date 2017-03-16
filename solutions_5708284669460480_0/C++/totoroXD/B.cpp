#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <string>
typedef long long LL;
int MOD=1000000007;
using namespace std;
int n;
int k,l,s;
int fail[111];
char key[111],str[111];
double pr[33];
double dp[111][111][111];//[i][match j][times]

void mp(const char *pat, int m){
	fail[0]=-1;
	for(int i=1,j=-1; i<m; i++){
		while(0<=j && pat[j+1]!=pat[i]) j=fail[j];
		if(pat[i]==pat[j+1])j++;
		fail[i] = j;
	}
}

void input(){
    scanf("%d%d%d",&k,&l,&s);
    scanf("%s%s",key,str);
}

void solve(){
	mp(str,l);
	static int cas=1;
	printf("Case #%d: ",cas++);
	for(int i=0; i<26; i++)pr[i]=0.0;
	for(int i=0; key[i]; i++)pr[key[i]-'A']+=1;
	for(int i=0; str[i]; i++)if(pr[str[i]-'A']<=1e-3){
		printf("%f\n",0.0);
		return;
	}
	for(int i=0; i<26; i++)pr[i]/=k;
	for(int i=0; i<=s; i++){
		for(int j=0; j<=s; j++){
			for(int k=0; k<=s; k++){
				dp[i][j][k]=0;
			}
		}
	}
	dp[0][0][0]=1.0;
	for(int i=0; i<=s; i++){
		for(int j=0; j<=l; j++){
			for(int k=0; k<=s; k++){
				int jj=j;
				if(jj==l)jj=fail[l-1]+1;
				// if(dp[i][j][k]>0.1)printf("%d,%d,%d=%f %d\n",i,j,k,dp[i][j][k],jj);
				for(char ch='A'; ch<='Z';ch++){
					if(ch==str[jj]){
						if(jj==l-1){
							dp[i+1][jj+1][k+1]+= dp[i][j][k]*pr[ch-'A'];
							// if(0<pr[ch-'A'] && dp[i][j][k]>0)printf("->%d,%d,%d\n",i+1,jj+1,k+1);
						}
						else{
							dp[i+1][jj+1][k]+= dp[i][j][k]*pr[ch-'A'];
							// if(0<pr[ch-'A'] && dp[i][j][k]>0)printf("|->%d,%d,%d\n",i+1,jj+1,k);
						}
					}else{
						dp[i+1][jj==0?0:fail[jj-1]+1][k]+=dp[i][j][k]*pr[ch-'A'];
						// if(0<pr[ch-'A'] && dp[i][j][k]>0)printf("||->%d,%d,%d\n",i+1,jj==0?0:fail[jj-1]+1,k+1);
					}

				}
			}
		}
	}

	double res=0;
	for(int i=0; i<=s; i++)
		for(int j=0; j<=l; j++)
			res+= dp[s][j][i]*i;
	// printf("%d, %f\n",1+(s-l)/(l-1-fail[l-1]), res);
	int res1=1+(s-l)/(l-1-fail[l-1]);
	printf("%f\n",res1-res);
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
	    solve();
	}
}

/*
5 2
-1 1 2 -1 1
*/