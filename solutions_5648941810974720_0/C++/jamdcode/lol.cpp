#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str,ss;
map<ll,string>mp;
map<ll,char>mpp;
map<char,ll>mm;
ll arr[1000];
ll ans[100000];
int main()
{
	ll t,i,j;
	FILE * pFile;
	pFile = fopen ("output.txt","w");
	cin>>t;
	mp[0]="ZERO";
	mp[1]="ONE";
	mp[2]="TWO";
	mp[3]="THREE";
	mp[4]="FOUR";
	mp[5]="FIVE";
	mp[6]="SIX";
	mp[7]="SEVEN";
	mp[8]="EIGHT";
	mp[9]="NINE";
	mpp[0]='Z';
	mpp[1]='O';
	mpp[2]='W';
	mpp[3]='R';
	mpp[4]='U';
	mpp[5]='F';
	mpp[6]='X';
	mpp[7]='V';
	mpp[8]='G';
	mpp[9]='I';
	arr[1]=0;
	arr[2]=2;
	arr[3]=4;
	arr[4]=6;
	arr[5]=3;
	arr[6]=5;
	arr[7]=7;
	arr[8]=8;
	arr[9]=9;
	arr[10]=1;
	ll s;
	ll cc=0;
	
	while(t--)
	{
		cc++;
			fprintf (pFile, "Case #%lld: ",cc);
		memset(ans,0,sizeof(ans));
		mm.clear();
		cin>>str;
		ll n=str.size();
		for(i=0;i<n;i++)
		{
			mm[str[i]]++;
		}
		ll mini;
		for(i=1;i<=10;i++)
		{
			s=arr[i];
			mini=999999LL;
		//	cout<<arr[i]<<" ";
			ll sss=mm[mpp[s]];
			ans[s]=sss;
			ss=mp[s];
			for(ll k=0;k<sss;k++)
			for(j=0;j<ss.size();j++)
			{
				mm[ss[j]]--;
			}
		}
	
	
		for(i=0;i<=9;i++)
		{
			if(ans[i])
			{
				for(j=0;j<ans[i];j++)
				{
						fprintf (pFile, "%lld",i);
				}
			}
		}
			fprintf (pFile, "\n");
	}
}
