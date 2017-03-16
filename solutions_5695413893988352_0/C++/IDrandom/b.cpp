#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
#define MAX 200000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int dp[MAX+10];
int num[MAX+10];
char str1[20];
char str2[20];
char astr1[20];
char astr2[20];
LL mn,mn1,mn2;
int min(int a,int b)
{
	return a>b?b:a;
}
int Scan()
{
	int res = 0, ch, flag = 0;

	if((ch = getchar()) == '-')				//判断正负
		flag = 1;

	else if(ch >= '0' && ch <= '9')			//得到完整的数
		res = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';

	return flag ? -res : res;
}
LL ton(char s[]){
	LL r=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		r*=10;
		r+=(s[i]-'0');
	}
	return r;
}
void cp(int len){
	for(int i=0;i<len;i++){
		astr1[i]=str1[i];
		astr2[i]=str2[i];
	}
}
void dfs(int d,int flag,int len){
	if(d==len){
		LL a=ton(str1);
		LL b=ton(str2);
		if(abs(a-b)<mn){
			cp(len);
			mn=abs(a-b);
			mn1=a;
			mn2=b;
		}
		else if(abs(a-b)==mn){
			if(a<mn1){
				mn1=a;
				mn2=b;
				cp(len);
			}
			else if(a==mn1){
				if(b<mn2){
					cp(len);
					mn2=b;
				}
			}
		}
		return ;
	}
	char p1=str1[d];
	char p2=str2[d];
	if(flag==0){
		if(str1[d]=='?'){
			if(str2[d]=='?'){
				str1[d]=str2[d]='0';
				dfs(d+1,0,len);
				str1[d]='0';
				str2[d]='1';
				dfs(d+1,-1,len);
				str2[d]='0';
				str1[d]='1';
				dfs(d+1,1,len);
				str1[d]=p1;
				str2[d]=p2;
			}
			else {
				str1[d]=str2[d];
				dfs(d+1,0,len);
				if(str2[d]!='0'){
					str1[d]=str2[d]-1;
					dfs(d+1,-1,len);
				}
				if(str2[d]!='9'){
					str1[d]=str2[d]+1;
					dfs(d+1,1,len);
				}
				str1[d]=p1;
			}
		}
		else {
			if(str2[d]=='?'){
				str2[d]=str1[d];
				dfs(d+1,0,len);
				if(str1[d]!='9'){
				str2[d]=str1[d]+1;
				dfs(d+1,-1,len);
				}
				if(str1[d]!='0'){
					str2[d]=str1[d]-1;
					dfs(d+1,1,len);
				}
				str2[d]=p2;
			}
			else {
				if(str1[d]<str2[d]){
					dfs(d+1,-1,len);
				}
				else if(str1[d]>str2[d]){
					dfs(d+1,1,len);
				}
				else dfs(d+1,0,len);
			}
		}
	}
	else if(flag==-1){
		if(str1[d]=='?')
		str1[d]='9';
		if(str2[d]=='?')
			str2[d]='0';
		dfs(d+1,-1,len);
		str1[d]=p1;
		str2[d]=p2;
	}
	else {
		if(str1[d]=='?')
		str1[d]='0';
		if(str2[d]=='?')
			str2[d]='9';
		dfs(d+1,1,len);
		str1[d]=p1;
		str2[d]=p2;
	}
}
int main(void)
{
	int n,t,cas=0;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("b-little1.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str1);
		scanf("%s",str2);
		mn=mn1=mn2=1000000000000LL;
		memset(astr1,0,sizeof(astr1));
		memset(astr2,0,sizeof(astr2));
		int len=strlen(str1);
		dfs(0,0,len);
		printf("Case #%d: %s %s\n",++cas,astr1,astr2);
	}
	return 0;
}
