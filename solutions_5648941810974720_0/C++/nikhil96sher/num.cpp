#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define in(n) scanf("%d",&n)

int main()
{
	int t,k,i;
	string s;

	cin>>t;
	for(k=0;k<t;k++)
		{
		
		int freq[27];
		int come[10];
		
		for(i=0;i<27;i++)
			freq[i]=0;
		for(i=0;i<10;i++)
			come[i]=0;
		cin>>s;
		for(i=0;i<s.length();i++)
		{
			freq[s[i]-'A']++;
		}

		come[0] = freq['Z'-'A'];
		come[2] = freq['W'-'A'];
		come[4] = freq['U'-'A'];
		come[6] = freq['X'-'A'];
		come[8] = freq['G'-'A'];		
		come[7] = freq['S' - 'A'] - come[6];
		come[5] = freq['V'-'A'] - come[7];
		come[9] = freq['I'-'A'] - come[5] - come[6] - come[8];
		come[3] = freq['H'-'A'] -come[8];
		come[1] = freq['N'-'A'] - come[7] - 2*come[9];

		cout<<"Case #"<<k+1<<": ";
		for(i=0;i<10;i++)
			while(come[i])
				{
				cout<<i;
				come[i]--;
				}
		cout<<endl;
	}
}