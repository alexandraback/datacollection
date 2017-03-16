#include<bits/stdc++.h>

using namespace std;

int h[105],ans[105];

string s;

int main()
{
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("aa.txt","w",stdout);
	
	int t;
	
	cin >> t;
	
	for(int tt=0;tt<t;tt++)
	{
		cout << "Case #" << tt+1 << ": ";
		
		cin >> s;
		
		for(int i=0;i<26;i++)
			h[i]=0;
			
		for(int i=0;i<26;i++)
			ans[i]=0;
		
		for(int i=0;i<s.size();i++)
			h[s[i]-65]++;
			
		if(h[25])
		{
			h['E'-65]-=h[25];
			h['R'-65]-=h[25];
			h['O'-65]-=h[25];
			ans[0]+=h[25];
			h[25]=0;
		}
		
		
		if(h['G'-65])
		{
			h['E'-65]-=h['G'-65];
			h['I'-65]-=h['G'-65];
			h['H'-65]-=h['G'-65];
			h['T'-65]-=h['G'-65];
			ans[8]+=h['G'-65];
			h['G'-65]=0;
		}	
		
		if(h['U'-65])
		{
			h['F'-65]-=h['U'-65];
			h['O'-65]-=h['U'-65];
			h['R'-65]-=h['U'-65];
			ans[4]+=h['U'-65];
			h['U'-65]=0;
		}	
		
		if(h['X'-65])
		{
			h['S'-65]-=h['X'-65];
			h['I'-65]-=h['X'-65];
			ans[6]+=h['X'-65];
			h['X'-65]=0;
		}	
		
		if(h['W'-65])
		{
			h['T'-65]-=h['W'-65];
			h['O'-65]-=h['W'-65];
			ans[2]+=h['W'-65];
			h['W'-65]=0;
		}	
		
		if(h['F'-65])
		{
			h['I'-65]-=h['F'-65];
			h['V'-65]-=h['F'-65];
			h['E'-65]-=h['F'-65];
			ans[5]+=h['F'-65];
			h['F'-65]=0;
		}	
		
		if(h['V'-65])
		{
			h['S'-65]-=h['V'-65];
			h['E'-65]-=2*h['V'-65];
			h['N'-65]-=h['V'-65];
			ans[7]+=h['V'-65];
			h['V'-65]=0;
		}	
		
		if(h['T'-65])
		{
			h['H'-65]-=h['T'-65];
			h['E'-65]-=2*h['T'-65];
			h['R'-65]-=h['T'-65];
			ans[3]+=h['T'-65];
			h['T'-65]=0;
		}	
		
		if(h['O'-65])
		{
			h['N'-65]-=h['O'-65];
			h['E'-65]-=h['O'-65];
			ans[1]+=h['O'-65];
			h['O'-65]=0;
		}	
		
		if(h['I'-65])
		{
			h['N'-65]-=2*h['I'-65];
			h['E'-65]-=2*h['I'-65];
			ans[9]+=h['I'-65];
			h['I'-65]=0;
		}	
		
		
		for(int i=0;i<10;i++)
			for(int j=0;j<ans[i];j++)
				cout << i;
			
		cout << endl;	
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
