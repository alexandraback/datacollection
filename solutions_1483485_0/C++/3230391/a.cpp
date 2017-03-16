# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <map>
using namespace std;
char s[110][110];
int vis[110];
map <char , char > turn;
int main (void)
{
	int t;
	strcpy(s[0],"ejp mysljylc kd kxveddknmc re jsicpdrysi");
	strcpy(s[1],"our language is impossible to understand");
	strcpy(s[2],"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	strcpy(s[3],"there are twenty six factorial possibilities");
	strcpy(s[4],"de kr kd eoya kw aej tysr re ujdr lkgc jv");
	strcpy(s[5],"so it is okay if you want to just give up");
	
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-attempt3.out","w",stdout);
	turn['z']='q';
	vis['q'-'a']=1;
	for (int i=0;i<3;i++)
	{
		for (unsigned int j=0;j<strlen(s[2*i]);j++)
		{
			turn[s[2*i][j]]=s[2*i+1][j];
			vis[s[i+i+1][j]-'a']=1;
		}
	}
	for (int i=0;i<26;i++)
		if (!vis[i])
			turn['q']='a'+i;
	int ys=0;
	cin>>t;
	getchar();
	char ss[500];
	while (t--)
	{
		gets(ss);
		printf("Case #%d: ",++ys);
		for (unsigned int i=0;i<strlen(ss);i++)
			cout<<turn[ss[i]];
		cout<<endl;
	}
	return 0;
}
