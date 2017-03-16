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

char s[1005];
int isb[1005];

int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qqq,1,qn){
		printf("Case #%d: ",qqq);
		scanf("%s",s);
		int ls = strlen(s);
		char mc = -1;
		memset(isb,0,sizeof(isb));
		rep(i,ls){
			if(s[i]>=mc){
				isb[i]=1;
				mc = s[i];
			}
		}
		
		string sf(""),sb("");
		irep(i,ls){
			if(isb[i])sf = sf + s[i];
			else sb = s[i] + sb;
		}
		sf = sf + sb;
		printf("%s\n",sf.c_str());
	}

	return 0;
}




