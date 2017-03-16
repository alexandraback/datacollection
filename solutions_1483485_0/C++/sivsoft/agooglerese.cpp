// agooglerese.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
using namespace std;

void docase(const int n);

int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	getline(cin,line);
	const auto N=atoi(line.c_str());
	for(int n=1;n<=N;++n)
		docase(n);
	return 0;
}

//	ejp mysljylc kd kxveddknmc re jsicpdrysi
//	our language is impossible to understand

//	rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
//	there are twenty six factorial possibilities

//	de kr kd eoya kw aej tysr re ujdr lkgc jv
//	so it is okay if you want to just give up

const char gm[]={
	'y', //a
	'h', //b
	'e', //c
	's', //d
	'o', //e
	'c', //f
	'v', //g
	'x', //h
	'd', //i
	'u', //j
	'i', //k
	'g', //l
	'l', //m
	'b', //n
	'k', //o
	'r', //p
	'z', //q
	't', //r
	'n', //s
	'w', //t
	'j', //u
	'p', //v
	'f', //w
	'm', //x
	'a', //y
	'q', //z
};

void docase(const int n)
{
	cout<<"Case #"<<n<<": ";
	string line;
	getline(cin,line);
	auto p=line.c_str();
	while(*p){
		auto ch=*p!=' '?gm[*p-'a']:' ';
		cout<<ch;
		++p;
	}
	cout<<endl;
}
