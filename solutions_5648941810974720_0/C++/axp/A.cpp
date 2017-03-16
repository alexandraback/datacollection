/* ***********************************************
Author        :axp
Created Time  :2016/5/1 0:10:19
TASK		  :A.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int T;
int n;
string s;
int num[200];
int ans[10];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		printf("Case #%d: ",kase);
		memset(num,0,sizeof num);
		memset(ans,0,sizeof ans);
		cin>>s;
		for(int i=0;i<s.size();i++)
			num[s[i]]++;
		
		//for(int i=0;i<10;i++)
		//	cout<<i<<' '<<ans[i]<<endl;
		//for(int i=0;i<26;i++)
		//	cout<<(char)(i+'A')<<' '<<num['A'+i]<<endl;
		ans[6]=num['X'];
		num['S']-=ans[6];
		
		ans[0]=num['Z'];
		num['E']-=ans[0];
		num['O']-=ans[0];

		ans[2]=num['W'];
		num['O']-=ans[2];
		num['T']-=ans[2];

		ans[4]=num['U'];
		num['O']-=ans[4];
		num['U']-=ans[4];

		ans[1]=num['O'];
		num['N']-=ans[1];
		num['E']-=ans[1];

		ans[7]=num['S'];
		num['E']-=2*ans[7];
		num['N']-=ans[7];
		num['V']-=ans[7];

		ans[5]=num['V'];
		num['E']-=ans[5];

		ans[9]=num['N']/2;
		num['E']-=ans[9];

		ans[3]=num['E']/2;
		num['T']-=ans[3];

		ans[8]=num['T'];

		//for(int i=0;i<10;i++)
		//	cout<<i<<' '<<ans[i]<<endl;
		for(int i=0;i<10;i++)
			while(ans[i]--)
			{
				//cout<<' '<<i<<' '<<ans[i]<<endl;
				putchar(i+'0');
			}
		putchar(10);
	}
    return 0;
}
