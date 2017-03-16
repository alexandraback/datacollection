/*
* Filename:    A.cpp
* Desciption:  Desciption
* Created:     2016年05月01日 00时05分28秒 星期日
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
map<char,int> alpha;
//Global Variables
int n,m,t,ans;
string s;
int num[10];
//Function Declaration


//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d",&t);
	for (int tcase = 1; tcase<=t; tcase += 1)
	{
		printf("Case #%d: ",tcase);
		alpha.clear();
//		memset(num,0,sizeof(num));
		cin>>s;
		for (int i = 0; i < s.length(); i += 1)
		{
			alpha[s[i]]++;
		}
		num[6]=alpha['X'];
		alpha['X']-=num[6];
		alpha['S']-=num[6];
		alpha['I']-=num[6];
		
		num[7]=alpha['S'];
		alpha['S']-=num[7];
		alpha['E']-=num[7]*2;
		alpha['V']-=num[7];
		alpha['N']-=num[7];
		
		num[2]=alpha['W'];
		alpha['T']-=num[2];
		alpha['W']-=num[2];
		alpha['O']-=num[2];
		
		num[0]=alpha['Z'];
		alpha['Z']-=num[0];
		alpha['E']-=num[0];
		alpha['R']-=num[0];
		alpha['O']-=num[0];
		
		num[4]=alpha['U'];
		alpha['F']-=num[4];
		alpha['O']-=num[4];
		alpha['U']-=num[4];
		alpha['R']-=num[4];
		
		num[1]=alpha['O'];
		alpha['O']-=num[1];
		alpha['N']-=num[1];
		alpha['E']-=num[1];
		
		num[9]=alpha['N']/2;
		alpha['N']-=num[9]*2;
		alpha['I']-=num[9];
		alpha['E']-=num[9];
		
		num[5]=alpha['V'];
		alpha['F']-=num[5];
		alpha['I']-=num[5];
		alpha['V']-=num[5];
		alpha['E']-=num[5];
		
		num[8]=alpha['G'];
		alpha['E']-=num[8];
		alpha['I']-=num[8];
		alpha['G']-=num[8];
		alpha['H']-=num[8];
		alpha['T']-=num[8];
		
		num[3]=alpha['T'];
		
		for (int i = 0; i < 10; i += 1)
		{
			if(num[i]!=0){
				while (num[i]--)
				{
					cout<<i;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

