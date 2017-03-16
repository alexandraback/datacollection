#include<bits/stdc++.h>
using namespace std;
int arr[26];
string S[10];
int cnt[10];
int main()
{
	ifstream cin("1B1s.in");
	ofstream cout("1B1sA.txt");
	int i,j,k,t,m,n,ind=1,l;
	string str;
	S[0]="ZERO";
	S[1]="ONE";
	S[2]="TWO";
	S[3]="THREE";
	S[4]="FOUR";
	S[5]="FIVE";
	S[6]="SIX";
	S[7]="SEVEN";
	S[8]="EIGHT";
	S[9]="NINE";
	cin>>t;
	while(t--)
	{
		cin>>str;
		for(i=0;i<26;i++)
		arr[i]=0;
		for(i=0;i<10;i++)
		cnt[i]=0;
		l=str.length();
		for(i=0;i<l;i++)
		arr[str[i]-'A']++;
		
		cnt[0]=arr['Z'-'A'];
		l=S[0].size();
		for(i=0;i<l;i++)
		arr[S[0][i]-'A']-=cnt[0];
		
		
		cnt[2]=arr['W'-'A'];
		l=S[2].size();
		for(i=0;i<l;i++)
		arr[S[2][i]-'A']-=cnt[2];
		
		cnt[4]=arr['U'-'A'];
		l=S[4].size();
		for(i=0;i<l;i++)
		arr[S[4][i]-'A']-=cnt[4];
		
		cnt[5]=arr['F'-'A'];
		l=S[5].size();
		for(i=0;i<l;i++)
		arr[S[5][i]-'A']-=cnt[5];
		
		
		cnt[6]=arr['X'-'A'];
		l=S[6].size();
		for(i=0;i<l;i++)
		arr[S[6][i]-'A']-=cnt[6];
		
		
		cnt[7]=arr['S'-'A'];
		l=S[7].size();
		for(i=0;i<l;i++)
		arr[S[7][i]-'A']-=cnt[7];
		
		cnt[8]=arr['G'-'A'];
		l=S[8].size();
		for(i=0;i<l;i++)
		arr[S[8][i]-'A']-=cnt[8];
		
		
		cnt[3]=arr['T'-'A'];
		l=S[3].size();
		for(i=0;i<l;i++)
		arr[S[3][i]-'A']-=cnt[3];
		
		
		cnt[1]=arr['O'-'A'];
		l=S[1].size();
		for(i=0;i<l;i++)
		arr[S[1][i]-'A']-=cnt[1];
		
		cnt[9]=arr['E'-'A'];
		l=S[9].size();
		for(i=0;i<l;i++)
		arr[S[9][i]-'A']-=cnt[9];
		
		
		cout<<"Case #"<<ind++<<": ";
		for(i=0;i<10;i++)
		{
			for(j=0;j<cnt[i];j++)
			cout<<i;
		}
		cout<<endl;
	}
	
}
