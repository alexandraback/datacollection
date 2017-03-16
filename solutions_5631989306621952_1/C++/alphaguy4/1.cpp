#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define si(i) scanf("%d",&i)
#define fs first
#define sc second
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define REP(i,k) for(int i=0;i<k;i++)
#define FORR(i,j,k) for(int i=n;i>=k;i--)
#define MOD 1000000007
using namespace std;
int main()
{
	int t;
	si(t);
	char s[1005];
	int Case =1;
	while(t--)
	{
		scanf("%s",s);
		string str="";
		str += s[0];
		int l=strlen(s);
		FOR(i,1,l)
		{
			if(s[i] >= str[0])
			{
				str = s[i] + str;
			}
			else
				str += s[i];
		}
		cout << "Case #"<< Case++ <<": " << str << endl;
	}
	return 0;
}