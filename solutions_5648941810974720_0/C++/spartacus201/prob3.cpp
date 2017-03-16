#include<bits/stdc++.h>

using namespace std;

char str[2000007];
string arr[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int cnt[100],tot[100];
int main()
{
	int t,k,i,j,len,n;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>str;
		len=strlen(str);
		for(i=0;i<26;i++)
			cnt[i] = tot[i] = 0;
		for(i=0;i<len;i++)
		{
			cnt[str[i]-'A']++;
		}
		tot[0] = cnt['Z' - 'A'];
		tot[2] = cnt['W' - 'A'];
		tot[4] = cnt['U'-'A'];
		tot[6] = cnt['X' - 'A'];
		tot[8] = cnt['G' - 'A'];
		for(i=0;i<=8;i+=2)
		{
			for(j=0;j<arr[i].size();j++)
			{
				cnt[arr[i][j] - 'A']-=tot[i];
			}
		}
		tot[1] = cnt['O' - 'A'];
		tot[3] = cnt['R' - 'A'];
		tot[5] = cnt['F' - 'A'];
		tot[7] = cnt['S' - 'A'];
		for(i=1;i<=7;i+=2)
		{
			for(j=0;j<arr[i].size();j++)
			{
				cnt[arr[i][j] - 'A']-=tot[i];
			}
		}
		tot[9] = cnt['I' - 'A'];
		cout<<"Case #"<<k<<": ";
		for(i=0;i<=9;i++)
		{
			while(tot[i]--)
			{
				cout<<i;
			}
		}
		cout<<"\n";
	}
	return 0;
}
