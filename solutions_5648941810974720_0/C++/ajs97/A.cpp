#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
string d[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
pair<char,int> a[10];
char num[10];
int cnt[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<=9;i++)
		num[i]=(char)('0'+i);
	a[0].x='Z',a[0].y=0;
	a[1].x='W',a[1].y=2;
	a[2].x='U',a[2].y=4;
	a[3].x='X',a[3].y=6;
	a[4].x='G',a[4].y=8;
	a[5].x='R',a[5].y=3;
	a[6].x='F',a[6].y=5;
	a[7].x='V',a[7].y=7;
	a[8].x='O',a[8].y=1;
	a[9].x='I',a[9].y=9;
	string str="Case #";
	for(int i1=1;i1<=t;i1++)
	{
		string s;
		cin>>s;
		//sort(s.begin(),s.end());
		int n=s.size();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
			cnt[s[i]-'A']++;
		string number="";
		for(int i=0;i<=9;i++)
		{
			char ch=a[i].x;int z=a[i].y;
			int dec=cnt[ch-'A'];
			for(int j=0;j<d[z].size();j++)
				cnt[d[z][j]-'A']-=dec;
			for(int j=1;j<=dec;j++)
				number+=num[z];
		}
		sort(number.begin(),number.end());
		cout<<str<<i1<<": "<<number<<endl;
	}


	return 0;
}