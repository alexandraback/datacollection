#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
long long t,n;
char s[1000001];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	//ifstream cin;
	//ofstream cout;
	//cin.open(".in");
	//cout.open(".out");
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
	    scanf("%s",s);
	    scanf("%lld",&n);
	    int l=0;
	    int m=strlen(s);
	    int br=0;
	    long long ans=0;
	    for(int i=0; i<=m-1; i++)
	    {
	        if(s[i]=='a'||s[i]=='e'||s[i]=='u'||s[i]=='o'||s[i]=='i') {br=0;}
	        else
	        {
	            br++;
	            if(br>=n) {ans+=(i-n+2-l)*(m-i); l=i-n+2;}
	        }
	    }
	    printf("Case #%d: %lld\n",o,ans);
	}
	//cin.close();
	//cout.close();
	return 0;
}
