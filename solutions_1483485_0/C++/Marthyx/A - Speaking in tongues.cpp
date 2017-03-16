#include <iostream>
#include <string>
#include <map>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[])
{
	freopen("S.in","rt+",stdin);
	freopen("S.out","w+",stdout);
	string Pmuestra,Smuestra,test;
	int N,caso=1;
	map<char,char> mapa;
	mapa['z']='q';
	mapa['q']='z';
	Pmuestra="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	Smuestra="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	int i;
	for(i=0;i<Pmuestra.size();i++)
	{
		mapa[Pmuestra.at(i)]=Smuestra.at(i);
	}
	cin>>N;
	cin.ignore();
	while(N--)
	{
		getline(cin,test);
		cout<<"Case #"<<caso<<": ";
		caso++;
		for(i=0;i<test.size();i++)
		{
			cout<<mapa[test.at(i)];
		}
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

