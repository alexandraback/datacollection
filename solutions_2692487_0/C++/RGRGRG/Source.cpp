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

string S[101];
int I[101];
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
	for (int i = 1; i<= 100; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 I[i] = atoi(s.substr(last+1).c_str());
			 return;
		 }
		 I[i] = atoi(s.substr(last+1,pos-last-1).c_str());
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


void main2(int t)
{
	int i,j,k,l,m,n,x,y,z;
	string temp;

		getline (infile, temp,'\n');	
		AN(temp);
		int size = I[1];
		int motes = I[2];
		//cout << temp;
		getline (infile, temp,'\n');	
		AN(temp);		
		std::sort(I,I+motes+1); 
		int worst = motes;
		int added = 0;

		if (size == 1)
		{
			cout << "Case #" << t << ": " << motes;
			cout << endl;
			return;
		}

		for (j = 1; j<= motes; j++)
		{
			if (I[j] < size)
				size = size + I[j];
			else
			{
				worst = min(worst,added+(motes-j+1));
				size = 2*size - 1;
				added++;
				j--;
			}
		}
		worst = min(worst,added);
		//cout << endl;
	

	cout << "Case #" << t << ": " << worst;
	cout << endl;



}



int main(void){
	int T, t;
	string temp;
	infile.open("new  3.txt");
	getline (infile, temp);
	T = atoi(temp.c_str());
	for (int t = 1; t<= T; t++)
		main2(t);
	return(0);
}
