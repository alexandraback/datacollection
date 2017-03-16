#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	map<char,char> m;
	char *so1="ejp mysljylc kd kxveddknmc re jsicpdrysi",*sc1="our language is impossible to understand",
		*so2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",*sc2="there are twenty six factorial possibilities",
		*so3="de kr kd eoya kw aej tysr re ujdr lkgc jv",*sc3="so it is okay if you want to just give up";
	for(int i=0;i<strlen(so1);i++)
		m[so1[i]]=sc1[i];
	for(int i=0;i<strlen(so2);i++)
		m[so2[i]]=sc2[i];
	for(int i=0;i<strlen(so3);i++)
		m[so3[i]]=sc3[i];
	map<char,char>::iterator p;
	m['q']='z';
	m['z']='q';
	m[' ']=' ';
	int n;
	int ind=0;
	char G[200];
	cin>>n;
	getchar();
	/*cin.clear();
	cin.sync();*/
	for(int i=1;i<=n;i++)
	{
		//cin.getline(G,100);
		gets(G);
		//cout<<G<<endl;
		ind=0;
		cout<<"Case #"<<i<<": ";
		while(G[ind])
			cout<<m[G[ind++]];
		cout<<endl;
	}
	return 0;
}