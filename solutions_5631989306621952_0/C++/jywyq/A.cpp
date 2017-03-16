/*
 * Author:Õı”Ì«Ô(jywyq) 
 * Date:20160416
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define LL long long
char s[4000];
char a[4000];
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("dataout.txt","w",stdout);
	int t,n,cas=0;
	int l,r;
	cin>>t;
	while(t--){
		scanf("%s",a);int len=strlen(a);
		l=r=2000;
		s[r++]=a[0];
		for(int i=1;i<len;i++){
			int j=l;
			while(a[i]==s[j])j++;
			if(a[i]>s[j])s[--l]=a[i];
			else s[r++]=a[i];
		}
		s[r]='\0';
		printf("Case #%d: %s\n",++cas,s+l);
	}
}
