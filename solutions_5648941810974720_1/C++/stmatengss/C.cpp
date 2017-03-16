#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

int t;
string s;
string ss;
map<int,int>num;

int main()
{
	int i,j,k;
	int tcase=1;

	freopen("C+.in","r",stdin);
	freopen("C+","w",stdout);

	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>s;
		num.clear();
		int len=s.length();
		for(j=0;j<len;j++)
		{
			num[s[j]]++;
		}
//		for(j='A';j<='Z';j++)
//			cout<<j<<":"<<num[j]<<endl;
		num['4']=num['U'];
		num['2']=num['W'];
		num['0']=num['Z'];
		num['1']=num['O']-num['0']-num['2']-num['4'];
		num['3']=num['R']-num['0']-num['4'];
		num['5']=num['F']-num['4'];
		num['8']=num['T']-num['2']-num['3'];
		num['7']=num['V']-num['5'];
		num['6']=num['X'];
		num['9']=num['I']-num['5']-num['6']-num['8'];
		
		cout<<"Case #"<<i<<": ";
		
		for(j='0';j<='9';j++)
		{
			for(k=0;k<num[j];k++)
			{
				cout<<char(j);
			}
		}
		cout<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
