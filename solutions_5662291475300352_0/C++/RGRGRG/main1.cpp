

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
long long int I[2001];
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

	int Hl = I[1];

		int start1;
		int start2;
		long long int speed1;
		long long int speed2;


	for (int i = 1; i<= Hl; i++)
	{
		getline (infile, temp2);
		AN(temp2);

		long long int X = I[1];
		long long int Y = I[2];
		long long int Z = I[3];

	
		if (Y == 2)
		{
			start1 = X;
			start2 = X;
			speed1 = Z;
			speed2 = Z+1;
		}
		else if (i == 1)
		{
			start1 = X;
			speed1 = Z;

			if (Hl == 1)
			{			
				myfile << "Case #" << t << ": " << 0  ;
				myfile << endl;	


				return;
			}
		}
		else
		{
			start2 = X;
			speed2 = Z;
		}
	}



	if (speed2 < speed1){
		long long int temp = speed2;
		speed2 = speed1;
		speed1 = temp;

		temp = start2;
		start2= start1;
		start1 = temp;

	}

//	while (speed1 > 10000 && speed2 > 10000)
	//{
		//speed1 = speed1 / 100;
		//speed2 = speed2 / 100;
	//}

	// learn faster hits
	long long int hitfaster1 = (360 - start1)*speed1;
	long long int hitfaster2 = hitfaster1 + speed1*360;

	// slower
	long long int hitslower1 = (360 - start2)*speed2;

	if (hitfaster2 <= hitslower1 || hitslower1 < 0)
	{
				myfile << "Case #" << t << ": " << 1  ;
				myfile << endl;	


				return;
	}
	else
	{
						myfile << "Case #" << t << ": " << 0  ;
				myfile << endl;	


				return;
	}

}


int main(void){

	 
	myfile.open ("RGoutput.txt");
	int T, t;
	string temp;

	infile.open("inputhere2.txt");
	getline (infile, temp);

	T = atoi(temp.c_str());
	



	for (int t = 1; t<= T; t++)
		main2(t);
	
	infile.close();


	return(0);

}

