
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;







int main()
{

	string a1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string a2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string a3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

	string b1 = "our language is impossible to understand";
    string b2 = "there are twenty six factorial possibilities";
	string b3 = "so it is okay if you want to just give up";

	char maps[26];
	int i,j,k,l,m,n;

	for (i=0;i<b1.length();i++)
		if (b1[i] !=' ')
		maps[a1[i]-'a'] = b1[i];

		for (i=0;i<b2.length();i++)
		if (b2[i] !=' ')
		maps[a2[i]-'a'] = b2[i];

	for (i=0;i<b3.length();i++)
		if (b3[i] !=' ')
		maps[a3[i]-'a'] = b3[i];

	maps['q'-'a'] = 'z';


	maps['z'-'a'] = 'q';

	//sort(maps,maps+26);

	//for(i=0;i<26;i++)
	//	cout<<maps[i];



	freopen("A-small-attempt4.in","r", stdin);
	freopen("a.out","w", stdout);

	int N;
	//char c;
	cin>>N;
	getchar();
	string tt; 
	//char c;
	//cin>>c;
	for (i=0;i<N;i++)
	{
		string str;
		getline(cin,str);
		for(j=0; j<str.length();j++)
			if (str[j] !=' ')
				str[j] = maps[str[j] - 'a'];

		cout<<"Case #"<<i+1<<": " <<str<<endl;
	}





	fclose(stdin);
	fclose(stdout);
	
	
	


}
