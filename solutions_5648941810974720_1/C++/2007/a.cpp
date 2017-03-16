#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	string s;
	cin>>T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin>>s;
		cout<<"Case #"<<tc<<": ";
		int count[10],val[126];
		fill(val,val+126,0);
		fill(count,count+10,0);
		for(int i=0; i<s.length(); i++)
			val[s[i]]++;
		//Z
		count[0]+=val['Z'];
		val['E']-=val['Z'];
		val['R']-=val['Z'];
		val['O']-=val['Z'];

		//W
		count[2]+=val['W'];
		val['T']-=val['W'];
		val['O']-=val['W'];

		//U
		count[4]+=val['U'];
		val['F']-=val['U'];
		val['O']-=val['U'];
		val['R']-=val['U'];

		//O
		count[1]+=val['O'];
		val['N']-=val['O'];
		val['E']-=val['O'];

		//R
		count[3]+=val['R'];
		val['T']-=val['R'];
		val['H']-=val['R'];
		val['E']-=val['R'];
		val['E']-=val['R'];

		//F
		count[5]+=val['F'];
		val['I']-=val['F'];
		val['V']-=val['F'];
		val['E']-=val['F'];

		//X
		count[6]+=val['X'];
		val['S']-=val['X'];
		val['I']-=val['X'];

		//S
		count[7]+=val['S'];

		//T
		count[8]+=val['T'];
		val['I']-=val['T'];

		//I
		count[9]+=val['I'];

		for(int i=0; i<10; i++)
		{
			for(int j=0; j<count[i]; j++)
				cout<<i;
		}
		cout<<"\n";
	}
}