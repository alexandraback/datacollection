#include <bits/stdc++.h>
using namespace std;

typedef int ll;
ll t,n,i,a[20],j,tt=1;
map< char , ll >ma;
string s,ss;

int main()
{
	// freopen("C:\Users\SHIVAM\Desktop\in.txt", "r", stdin);
	// freopen("C:\Users\SHIVAM\Desktop\out.txt", "w", stdour);
    freopen("C:/Users/SHIVAM/Desktop/A-large (3).in", "r", stdin);
	freopen("C:/Users/SHIVAM/Desktop/out.txt", "w", stdout);

	cin>>t;
	while(t--)
	{
		cin>>s;
		n = s.size();
		for(i=0;i<n;i++)
		{
			ma[s[i]]++;
		}
		a[2] = ma['W'];
		a[0] = ma['Z'];
		a[8] = ma['G'];
		a[4] = ma['U'];
		a[6] = ma['X'];

		ss = "TWO";
		for(i=0;i<ss.size();i++)
		{
			ma[ss[i]]-=a[2];
		}
		ss = "SIX";
		for(i=0;i<ss.size();i++)
		{
			ma[ss[i]]-=a[6];
		}
		ss = "ZERO";
		for(i=0;i<ss.size();i++)
		{
			ma[ss[i]]-=a[0];
		}
		ss = "EIGHT";
		for(i=0;i<ss.size();i++)
		{
			ma[ss[i]]-=a[8];
		}
		ss = "FOUR";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[4];
		}
		a[1] = ma['O'];
		ss = "ONE";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[1];
		}
		a[3] = ma['H'];
		ss = "THREE";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[3];
		}
		a[5] = ma['F'];
		ss = "FIVE";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[5];
		}
		a[7] = ma['V'];
		ss = "SEVEN";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[7];
		}
		a[9] = ma['I'];
		ss = "NINE";
		for(i=0;i<ss.size();i++)
		{

			ma[ss[i]]-=a[9];
		}
		cout<<"Case #"<<tt<<": ";
		for(i=0;i<=9;i++)
		{
			if(a[i]!=0)
			{
				for(j=0;j<a[i];j++)
				{
					cout<<i;
				}
			}
		}
		cout<<"\n";
		memset(a,0,sizeof(a));
		ma.clear();
		tt++;
	}
	return 0;
}
