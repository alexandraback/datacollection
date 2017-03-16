// codejam3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;


bool is_pali(long long t)
{
	stringstream ss;
	string s;
	ss<<t;
	ss>>s; // or s = ss.str();
	int l = s.length();
	for (int i=0;i<l/2;++i)
	{
		if (s[i]!=s[l-1-i])
			return false;
	}
	return true;
}

long long ans[100];
int nn;

int main()
{
	char buffer[20];
	for(int i=1;i<9999;++i)
	{
		_itoa_s(i, buffer, 10);
		//cout<<strlen(buffer)<<endl;
		char t1[20];
		int l = strlen(buffer);
		for(int i=0;i<l;++i)
			t1[i] = buffer[i];
		for(int i=0;i<l;++i)
			t1[2*l-1-i] = buffer[i];
		t1[2*l] = '\0';
		long long k = atoi(t1);
		if (is_pali(k*k))
		{
			ans[nn++] = k*k;
			//cout<<k<<' '<<k*k<<endl;
		}
		for(int i=0;i<l;++i)
			t1[i] = buffer[i];
		for(int i=0;i<l-1;++i)
			t1[2*l-2-i] = buffer[i];
		t1[2*l-1] = '\0';
		k = atoi(t1);
		if (is_pali(k*k))
		{
			ans[nn++] = k*k;
			//cout<<k<<' '<<k*k<<endl;
		}
	}
	ofstream fout("d:\\out.txt");
	ifstream fin("d:\\in.txt");
	int n(0);
	fin>>n;
	for (int i=0;i<n;++i)
	{
		long long p,q;
		fin>>p;
		fin>>q;
		int res(0);
		for(int i=0;i<nn;++i)
			if (ans[i]>=p&&ans[i]<=q)
				res++;
		fout<<"Case #"<<i+1<<": "<<res<<endl;
	}
	return 0;
}