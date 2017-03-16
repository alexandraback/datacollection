#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <assert.h>
#include <stack>
#include <sstream>
#include <list>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))

#define fr(x,a,b) for( int x=a; x < b; ++x )
#define frr(x,a,b) for( int x=a;x>=b;--x)

#define pf printf
#define sf scanf

#define pb push_back
#define mp make_pair

int main()
{
	map<char,char> mapping;
	string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	fr(i,0,a.size())
	{
		mapping[a[i]]=b[i];
	}
	mapping['z']='q';
	mapping['q']='z';
	/*
	for(map<char,char>::iterator it = mapping.begin(); it != mapping.end(); ++it )
	{
		pf("%c->%c\n",it->first,it->second);
	}
	*/
	string output;
	char input[1000];
	int n;
	sf("%d",&n);
	gets(input);
	fr(i,0,n)
	{
		gets(input);
		int len = strlen(input);
		output="";
		fr(j,0,len)
			output += mapping[input[j]];
//		cout<<input<<endl;
		cout<<"Case #"<<i+1<<": "<<output<<endl;
	}
}
