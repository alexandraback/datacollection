#include <iostream>

using namespace std;

string googlerese="z y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string englishese="q a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

char tab[260];
char r_tab[260];

int main()
{
	ios_base::sync_with_stdio(0);
	
	for(int i=0; i<googlerese.length(); i++)//preprocessing
	{
		tab[googlerese[i]]=englishese[i];
		r_tab[englishese[i]]=googlerese[i];
	}
	
	//input & output
	
	int t;
	cin>>t;
	
	for(int i=1; i<=t; i++)
	{
		string a="";
		while(a.length()==0)getline(cin, a);
		for(int j=0; j<a.length(); j++)
			if(a[j]>='a' && a[j]<='z')a[j]=tab[a[j]];
		cout<<"Case #"<<i<<": "<<a<<"\n";
	}
		
	return 0;
}
