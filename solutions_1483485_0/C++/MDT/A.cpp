#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

/*problems
*/

/*plans
*/

//classes


//constants
ifstream fin;
ofstream fout;
int T;

//variables

//data structures
char rule[26];
string S[30];

//functions

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\A-small-attempt0.in");
	fout.open("C:\\Users\\fumi\\Downloads\\A-small-answer.txt");

	memset(rule,0,sizeof(rule));
	string s[3], t[3];
	s[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	t[0]="our language is impossible to understand";
	t[1]="there are twenty six factorial possibilities";
	t[2]="so it is okay if you want to just give up";

	rule['q'-'a']='z';
	rule['z'-'a']='q';
	for(int i=0; i<3; i++){
		for(int j=0; j<(signed)s[i].size(); j++){
			rule[s[i][j]-'a']=t[i][j];
		}
	}

	fin>>T;
	string b;
	getline(fin,b);

	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		getline(fin,S[i]);

		for(int j=0; j<(signed)S[i].size(); j++){
			if(S[i][j]==' ')fout<<' ';
			else fout<<rule[S[i][j]-'a'];
		}
		fout<<endl;
	}

	system("pause");
	return 0;
}

