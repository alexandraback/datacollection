#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long tt = 0, nn = 0, mm = 0, ss = 0;
vector<long long> list, minlist;

int main(){
	ifstream fin("e:/A-large.in");
	ofstream fout("e:/output");
	fin>>tt;
	for (long long t=0;t<tt;t++)
	{
		fin >> mm >> nn;
		list.clear();minlist.clear();
		for (long long n=0;n<nn;n++)
		{
			long long temp;
			fin>>temp;
			list.push_back(temp);
		}
		sort(list.begin(),list.end());
		ss = 0;
		for (long long n=0;n<nn;n++)
		{
			if(mm > list[n]){
				mm += list[n];
			}
			else {
				if(mm == 1) {ss = nn; break;}
				mm=mm+mm-1;
				minlist.push_back(nn-n+ss);
				n--;ss++;
			}
		}
		minlist.push_back(ss);
		sort(minlist.begin(),minlist.end());
		fout<<"Case #"<<t+1<<": "<<minlist[0]<<endl;
	}
	system("pause");
}