#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
typedef vector<string> vstr;
typedef vector<string>::iterator vstri;
typedef string::iterator sitr;
typedef map<char,char> mch;
typedef map<char,char>::iterator mchi;
typedef pair<char,char> cpair;
mch gendic(vstr cyp,vstr decy)
{
	set<char> from,to;
	char temp='a';
	for(int i=0;i<26;i++)
	{
		from.insert(temp+i);to.insert(temp+i);
	}
	mch ret;
	ret.insert(cpair('q','z'));to.erase(to.find('z'));from.erase(from.find('q'));
	ret.insert(cpair('z','q'));to.erase(to.find('q'));from.erase(from.find('z'));
	for(vstri vi1=cyp.begin(),vi2=decy.begin();vi1!=cyp.end()&&vi2!=decy.end();vi1++,vi2++)
	{
		for(sitr si1=(*vi1).begin(),si2=(*vi2).begin();si1!=(*vi1).end()&&si2!=(*vi2).end();si1++,si2++)
		{
			if(from.find((*si1))!=from.end())
			{
				ret.insert(cpair((*si1),(*si2)));from.erase(from.find((*si1)));to.erase(to.find((*si2)));
			}
		}
	}
	if(!from.empty())ret.insert(cpair((*from.begin()),(*to.begin())));
	//for(int i=0;i<26;i++)cout<<ret[temp+i]<<endl;
	return ret;
}
string decypher(mch d,string k)
{
	string ret;
	for(sitr si=k.begin();si!=k.end();si++)
	{
		ret+=d[(*si)];
	}
	return ret;
}
int main()
{
	ifstream gin("A-small-attempt3.in");
	ofstream gout("gypAsmall.out");
	vstr word,cypher;
	word.push_back("our");word.push_back("language");word.push_back("is");word.push_back("impossible");word.push_back("to");word.push_back("understand");
	word.push_back("there");word.push_back("are");word.push_back("twenty");word.push_back("six");word.push_back("factorial");word.push_back("possibilities");
	word.push_back("so");word.push_back("it");word.push_back("is");word.push_back("okay");word.push_back("if");word.push_back("you");word.push_back("want");
	word.push_back("to");word.push_back("just");word.push_back("give");word.push_back("up");
	cypher.push_back("ejp");cypher.push_back("mysljylc");cypher.push_back("kd");cypher.push_back("kxveddknmc");cypher.push_back("re");cypher.push_back("jsicpdrysi");
	cypher.push_back("rbcpc");cypher.push_back("ypc");cypher.push_back("rtcsra");cypher.push_back("dkh");cypher.push_back("wyfrepkym");cypher.push_back("veddknkmkrkcd");
	cypher.push_back("de");cypher.push_back("kr");cypher.push_back("kd");cypher.push_back("eoya");cypher.push_back("kw");cypher.push_back("aej");cypher.push_back("tysr");
	cypher.push_back("re");cypher.push_back("ujdr");cypher.push_back("lkgc");cypher.push_back("jv");
	mch dict=gendic(cypher,word);
	word.clear();cypher.clear();
	int T;
	gin>>T;
	for(int i=0;i<T;i++)
	{
		gout<<"Case #"<<i+1<<": ";
		int line=1;
		while(line)
		{
			string s;gin>>s;gout<<decypher(dict,s);
			if(gin.peek()=='\n'&&gin.peek()!=' ')
			{
				line=0;
			}
			else if(gin.peek()==' ')gout<<' ';
		}
		gout<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
