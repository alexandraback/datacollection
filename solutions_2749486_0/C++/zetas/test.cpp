#include<iostream>
#include<fstream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

int T=1;

int main()
{
	fin >> T;
	int x, y;
	for(int i = 1; i <= T; i++){
		fin >> x >> y;
		fout << "Case #" << i << ": ";
		if(x < 0){
			for(int j = 0; j > x; j--)
				fout << "EW";
		}
		else{
			for(int j = 0; j < x; j++)
				fout << "WE";
		}
		if(y < 0){
			for(int j = 0; j > y; j--)
				fout << "NS";
		}
		else{
			for(int j = 0; j < y; j++)
				fout << "SN";
		}
		if(i < T) fout << endl;
	}
	return 1;
}