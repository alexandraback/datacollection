/*
* Filename:    A.cpp
* Desciption:  Desciption
* Created:     2016年04月16日 09时00分42秒 星期六
* Author:      JIngwei Xu [mail:xu_jingwei@outlook.com]
*
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

//Init Const
const int INF=1e9;
const int maxn=1000+7;
char s[maxn];
string outstr;
//Global Variables
int n,m,t,ans;

//Function Declaration


//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("A-small-attempt0.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	//Input
	scanf("%d",&t);
	for (int i = 1; i <=t; i += 1)
	{
		scanf("%s",s);
		int len=strlen(s);
		outstr="";
		outstr=outstr+s[0];
		int maxas=s[0]-'A';
		for (int j = 1; j < len; j += 1)
		{
			int tmp=s[j]-'A';
			if(tmp>=maxas){
				outstr=s[j]+outstr;
				maxas=tmp;
			}else{
				outstr=outstr+s[j];
			}
		}
		printf("Case #%d: ",i);
		printf("%s\n",outstr.c_str());
		
	}
	return 0;
}

