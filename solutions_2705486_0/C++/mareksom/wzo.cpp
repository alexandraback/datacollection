#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector<string>dict;

char nap[55];

int n;

int tab[55][55];

pair<int,pair<int,int> >dopasuj(string st,int s,int p)
{
	const pair<int,pair<int,int> >nie=make_pair(-1,make_pair(-1,-1));
	if(s+st.length()>n) return nie;
	int ost=p-5;
	int l=0;
	for(int i=0;i<st.length();i++)
	{
		if(nap[s+i]!=st[i])
		{
			l++;
			if(i-ost<5) return nie;
			ost=i;
		}
	}
	return make_pair(l,make_pair(ost,s+st.length()));
}

int f(int s,int p)
{
	if(tab[s][p]>=0) return tab[s][p];
	if(s==n) return tab[s][p]=0;
	tab[s][p]=n+2;
	for(int i=0;i<dict.size();i++)
	{
		pair<int,pair<int,int> >x=dopasuj(dict[i],s,p);
		if(x.first<0) continue;
		tab[s][p]=min(tab[s][p],x.first+f(x.second.second,max(0,5-(x.second.second-x.second.first))));
	}
	return tab[s][p];
}

int przyp()
{
	scanf("%s",nap);
	for(int i=0;i<55;i++) for(int j=0;j<55;j++) tab[i][j]= -1;
	for(n=0;nap[n];n++);
	return f(0,0);
}

int main()
{
	FILE *f=fopen("garbled_email_dictionary.txt","r");
	while(fscanf(f,"%s",nap)!=EOF) dict.push_back(nap);
	fclose(f);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Case #%d: %d\n",i,przyp());
	return 0;
}
