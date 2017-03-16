#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long tt = 0, nn = 0, xx = 0, yy = 0;

int CC(int n, int m){
	int s = 1,nn=n;
	for (int i=0;i<m;i++)
	{
		s*=nn;nn--;
	}
	nn=1;
	for (int i=0;i<m;i++)
	{
		s/=nn;nn++;
	}
	return s;
}

int main(){
	ifstream fin("e:/B-small-attempt1.in");
	ofstream fout("e:/output");
	fin>>tt;
	double result = 0, temp = 0;
	long long newrow, row;
	for (long long t=0;t<tt;t++)
	{
		result = 1;
		fin >> nn >> xx >> yy;
		xx = xx>0?xx:-xx;
		row = (xx+yy+1)*(xx+yy+2)/2;
		if(nn >= row) {
			result = 1;
		}
		else{
			if(xx+yy>0) nn -= (xx+yy-1)*(xx+yy)/2;
			
			if(nn < yy) result = 0;
			else if(xx==0 && nn<=yy*2) result = 0;
			else if(xx==0 && nn==yy*2+1) result = 1;
			else{
				int nnn = nn, yyy = yy;
				while(nn > xx+yyy && yyy >= 0){
					nnn-=2; yyy -=1;
				}
				if(yyy < 0) result = 1;
				else{
					result = 0;
					for(int j = yy; j<xx+yy-1;j ++)
					{
						if(nn-j>0){
						temp=1;
						for (int i=0;i<nn;i++)
						{
							temp*=2;
						}
						result+=CC(nn,nn-yy)*CC(nn,yy+1)/(double)temp;
						}
					}
					if(nn > yy+xx-1){
						temp=1;
for (int i=0;i<nn;i++)
						{
							temp*=2;
						}
result+=1/(double)temp;
					}
				}
			}
		}
		fout<<"Case #"<<t+1<<": "<<result<<endl;
	}
	system("pause");
}