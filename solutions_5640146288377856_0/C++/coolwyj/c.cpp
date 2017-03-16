#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

#define LL long long 
using namespace std;

int main(){
	int T,cas=1;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin>>T;
	while(T--)
	{
		int r,c,w;
		fin>>r>>c>>w;
		int res = 0;
		int find = c/w + (c%w==0?0:1);
		res = find * r;
		res += w-1;
		fout<<"Case #"<<cas++<<": "<<res<<endl;
	}
	fout.close();
	fin.close();
    return 0;
}