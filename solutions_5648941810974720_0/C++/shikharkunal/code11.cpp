#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
map <char,ll> y;

string s;

map<char,int>error;
main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	ll t;
	cin>>t;
	for(ll cases=1;cases<=t;cases++)
	{
		error.clear();
		
		int total[110];
		for(int i=0;i<101;i++)
			total[i]=0;
		cin>>s;
		cout<<"Case #"<<cases<<": ";
	
		for(int i =0 ;i<s.length();i++)
			error[s[i]]++;
		total[0]=max(0,error['Z']);
		total[6]=max(0,error['X']);
		total[8]=max(0,error['G']);
		total[4]=max(0,error['U']);
		total[2]=max(0,error['W']);
		total[3]=max( 0 ,error['T']-error['W']-error['G']);
		total[7]= max(0,error['S']-error['X']);
		total[5]=max(0,error['V']-total[7]);
		total[1]=max(0,error['O']-total[2]-total[4]-total[0]);
		total[9]=(max(0,error['N']-total[1]-total[7]))/2;
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<total[i];j++)
			  cout<<i;
		}
		cout<<endl;
	}
	return 0;
}