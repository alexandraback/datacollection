

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
long int I[2001];
double D[101];
int ANS[1000001];

int pos = 1;

ofstream myfile;

void AN(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 2000; i++)
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

void AN2(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 2000; i++)
	{
		 pos = s.find("/",last+1);
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
void main3(int t)
{
		myfile << t << " " << ANS[t];	
		myfile << endl;	
}


void main2(int t)
{



	string temp2, temp3;
	getline (infile, temp2);
	AN(temp2);

	//int X = I[1];



//	for (int i = 1; i<= X; i++)
//	{
	//	getline (infile, temp2);
		//AD(temp2);
		//Xunit[i] = D[1];
		//Yunit[i] = D[2];
	//}

	myfile << "Case #" << t << ": " << ANS[I[1]]  ;
	myfile << endl;	

}


int min(int a,int b)
{
	if (a>b && b>0)
		return b;
	return a;
}

int swap(int c)
{
	if (c%10 == 0)
		return 0;

	if (c >= 100000){

	int b = c/100000;
	int d = (c%100000)/10000;
	int e = (c%10000)/1000;
	int f = (c%1000)/100;
	int g = (c%100)/10;
	int h = (c%10)/1;

	return (100000*h + 10000*g + 1000*f + 100 *e + 10 *d + 1*b);
	}
	if (c >= 10000){

	int d = (c%100000)/10000;
	int e = (c%10000)/1000;
	int f = (c%1000)/100;
	int g = (c%100)/10;
	int h = (c%10)/1;

	return (10000*h + 1000*g + 100*f + 10 *e + 1 *d);
	}
	if (c >= 1000){

	int e = (c%10000)/1000;
	int f = (c%1000)/100;
	int g = (c%100)/10;
	int h = (c%10)/1;

	return (1000*h + 100*g + 10*f + 1 *e);
	}
	if (c >= 100){

	int f = (c%1000)/100;
	int g = (c%100)/10;
	int h = (c%10)/1;

	return (100*h + 10*g + 1*f);
	}

	
	if (c >= 10){

	int g = (c%100)/10;
	int h = (c%10)/1;

	return (10*h + 1*g);
	}

	if (c >= 1){

	int h = (c%10)/1;

	return (1*h);
	}

}

void ans(int i)
{
	if (i <= 12)
		ANS[i] = i;
	else 
		ANS[i] = min(ANS[i-1], ANS[swap(i)]) + 1;

}



int main(void){

	 
	myfile.open ("RGoutput.txt");
	int T, t;
	string temp;

	infile.open("inputhere2.txt");
	getline (infile, temp);

	T = atoi(temp.c_str());
	


	while (1){
		int changes = 0;
		for (int i = 1; i<= 1000000; i++)
		{
			int temp = ANS[i];
			ans(i);
			if (temp != ANS[i])
				changes++;
		}
		if (changes == 0)
			break;
	}


	for (int t = 1; t<= T; t++)
		main2(t);
	
	infile.close();


	return(0);

}

