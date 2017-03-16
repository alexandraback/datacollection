#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cfloat>
#include <cstdint> 

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,n) for((i)=1;(i)<=(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF 1.0E+15

ifstream infile;
ofstream myfile;
  
string S[101];
unsigned long long I[10001];
double D[101];

void binary(long long int number) {
	long long int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number / 2);    
	cout << remainder;
}

void AN(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 10000; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 I[i] = _atoi64(s.substr(last+1).c_str());
			 return;
		 }
		 I[i] = _atoi64(s.substr(last+1,pos-last-1).c_str());
		 last = pos;
	}
	return;
}

void AS(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 100; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 S[i] = s.substr(last+1);
			 return;
		 }
		 S[i] = s.substr(last+1,pos-last-1);
		 last = pos;
	}
	return;
}

void AD(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 100; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 D[i] = atof(s.substr(last+1).c_str());
			 return;
		 }
		 D[i] = atof(s.substr(last+1,pos-last-1).c_str());
		 last = pos;
	}
	return;
}


void main2(int q)
{
		myfile << "Case #" << q << ":\n" ;

	for (int qwe = 1; qwe <= 8000; qwe++){
string temp;

	int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll;
	aa = 2;
	bb = 2;
	cc = 2;
	dd = 3;
	ee = 3;
	ff = 4;
	gg= 4;
	hh = 5;
	ii = 5;
	jj= 5;
	kk = 4;
	ll=4;
	int maxsuccesses = 0;
		getline (infile, temp,'\n');	
		AN(temp);
		int count = 0;

	for (int a = 2; a <= 2; a++)
	{
	for (int b = a; b <= 3; b++)
	{
	for (int c = b; c <= 3; c++)
	{
	for (int d = c; d <= 3; d++)
	{
	for (int e = d; e <= 4; e++)
	{
	for (int f = e; f <= 5; f++)
	{
	for (int g = 5;g <= 5; g++)
	{
	for (int h = 5; h<= 6; h++)
	{
	for (int i = h; i <= 6; i++)
	{
	for (int j = i; j <= 7; j++)
	{
	for (int k = j; k <= 8; k++)
	{
	for (int l = k; l <= 8; l++)
	{
		int sucproduct = 1;
		for (int p = 1; p<=4; p++)
		{
			int success=1;
			for (int q = 1; q <= 15; q++)
			{
				int mult = 1;

					if (rand() > .5*RAND_MAX)
						mult = mult*a;
										if (rand() > .5*RAND_MAX)
						mult = mult*b;
					if (rand() > .5*RAND_MAX)
						mult = mult*c;
										if (rand() > .5*RAND_MAX)
						mult = mult*d;

					if (rand() > .5*RAND_MAX)
						mult = mult*e;
										if (rand() > .5*RAND_MAX)
						mult = mult*f;
					if (rand() > .5*RAND_MAX)
						mult = mult*g;
										if (rand() > .5*RAND_MAX)
						mult = mult*h;


					if (rand() > .5*RAND_MAX)
						mult = mult*i;
										if (rand() > .5*RAND_MAX)
						mult = mult*j;
					if (rand() > .5*RAND_MAX)
						mult = mult*k;
										if (rand() > .5*RAND_MAX)
						mult = mult*l;

				if (mult == I[p])
					success++;




			}
			sucproduct = sucproduct * success;
		}
		if (sucproduct > maxsuccesses)
		{
			maxsuccesses = sucproduct;
			aa = a;
			bb = b;
			cc = c;
			dd = d;
			ee = e; 
			ff = f;
			gg = g;
			hh = h;
			ii = i; 
			jj = j;
			kk = k;
			ll = l;
		}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}


	myfile << aa << bb << cc<<dd<<ee<<ff<<gg<<hh<<ii<<jj<<kk<<ll<< endl ;


	}
}



int main(void){

	myfile.open ("example2.txt");
	int T, t;
	string temp;
	infile.open("new  3.txt");
	getline (infile, temp);
	T = atoi(temp.c_str());
	getline (infile, temp);
	for (int t = 1; t<= T; t++)
		main2(t);
	return(0);
}
