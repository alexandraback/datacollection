/*
* Filename:    B.cpp
* Desciption:  B
* Created:     2016年04月16日 09时28分29秒 星期六
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
const int maxn=50+7;

//Global Variables
int n,m,T;
ll tmp;
map<ll,int> ans;
map<ll,int>::iterator it;
//Function Declaration
void solve();

//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	//Input
	scanf("%d",&T);
	for (int Tcase = 1; Tcase <=T; Tcase += 1)
	{
		scanf("%d",&n);
		ans.clear();
		for (int i = 0; i < 2*n-1; i += 1)
		{
			for (int j = 0; j < n; j += 1)
			{
				scanf("%lld",&tmp);
				ans[tmp]++;
			}
		}
		printf("Case #%d:",Tcase);
		solve();
		printf("\n");
	}
	
	
	//Solve
	
	
	return 0;
}
void solve(){
	priority_queue<ll,vector<ll>,greater<ll> > q; 
	for(it=ans.begin();it!=ans.end();++it){
		int value=it->second;
		if(value%2){
			q.push(it->first);
		}
	}
	while (!q.empty())
	{
		ll ls=q.top();
		q.pop();
		printf(" %lld",ls);
	}
}
