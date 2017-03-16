#include<iostream>
#include<string>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	char dictionary[26];
	string instrings[]={"y","e","q","ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string outstrings[]={"a","o","z","our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
	bool tab[26];
	REP(i,26) tab[i]=false;
	REP(i,6)
	{
		REP(j,instrings[i].length())
		{
			if(instrings[i][j]!=' ') dictionary[int(instrings[i][j])-97]=outstrings[i][j];
			tab[int(outstrings[i][j])-97]=true;
		}
	}
	REP(i,26)
	{
		if(dictionary[i]<'a'||dictionary[i]>'z')
		{
			REP(j,26)
			{
				if(!tab[j])
				{
					dictionary[i]=char(j+97);
				}
			}
		}
	}
	int T;
	cin>>T;
	cin.ignore();
	string line;
	string out;
	REP(i,T)
	{
		getline(cin,line);
		out="";
		REP(j,line.length())
		{
			if(line[j]==' ') out+=' ';
			else out+=dictionary[int(line[j])-97];
		}
		printf("Case #%d: %s\n",i+1,out.c_str());
	}
	return 0;
}