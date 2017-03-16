/*
 * a.cpp
 *
 *  Created on: 2012-4-14
 *      Author: dabao
 */

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

char rule[50];

string in="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
string out="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
string trans="ejp mysljylc kd kxveddknmc re jsicpdrysi";
string res="";

void init()
{
	for(int i=0;i<26;++i)
		rule[i]=i+'a';

	rule['q'-'a']='z';
	rule['e'-'a']='o';
	rule['y'-'a']='a';
	rule['z'-'a']='q';
	rule['o'-'a']='e';
	rule['a'-'a']='y';
	for(int i=0,n=in.size();i<n;++i)
	{
		//if(rule[in[i]-'a']==0)
			rule[in[i]-'a']=out[i];
	}


	//for(int i=0;i<26;++i)
	//	cout<<(char)('a'+i)<<" "<<rule[i]<<endl;
}

void solve()
{
	res="";
	for(int i=0,n=trans.size();i<n;++i)
	{
		if(trans[i]==' ')
			res+=' ';
		else
			res+=rule[trans[i]-'a'];
	}
	cout<<res<<endl;
}

int cases;

int main()
{
	cin>>cases;
	cin.ignore();
	init();
	char buf[1000];
	for(int ii=1;ii<=cases;++ii)
	{
		cin.getline(buf,1000);
		trans=buf;
		cout<<"Case #"<<ii<<": ";
		solve();
	}
}


