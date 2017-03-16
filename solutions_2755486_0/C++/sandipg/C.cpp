/*
 * C.cpp
 *
 *  Created on: 04-May-2013
 *      Author: sandip
 */


#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <set>
#include<string.h>


using namespace std;
static void solution(ifstream &in ,ofstream &out);



int C_main()
{
	long long nTestCase = 0;

	string strPath = "/home/sandip/Downloads/";
	string strInput = strPath + "C-small-attempt0.in";
	string strOutput = strPath + "C-small-attempt0.out";
	//string strInput = strPath + "temp.in";
	//string strOutput = strPath + "temp.out";

	ifstream in(strInput.c_str(),ifstream::in);
	ofstream out(strOutput.c_str(),ofstream::out);

	string strTestCase;
	getline(in,strTestCase);
	nTestCase = atoll(strTestCase.c_str());

	for(int i=0; i< nTestCase; i++)
	{
		out<<"Case #"<<i+1<<": ";
		solution(in, out);
		out<<endl;
	}

	in.close();
	out.close();
	return 0;
}
typedef struct Attack
{
	int Day;
	int Strength;
	int W;
	int E;
}Attack;

void solution(ifstream &in, ofstream &out)
{

	int Wall[1000000*2];
	for(int i=0;i<1000000*2;i++)
		Wall[i]=0;
	int nTribes;
	in>>nTribes;
	std::multimap<int,Attack> Attacks;
	std::set<int> keys;
	//memset(Wall,'0',1000000*2);
	for(int i=0;i<nTribes;i++)
	{
		int FA;
		int TA;
		int FW;
		int FE;
		int FS;
		int DD;
		int DP;
		int DS;

		in>> FA;
		in>> TA;
		in>> FW;
		in>> FE;
		in>> FS;
		in>> DD;
		in>> DP;
		in>> DS;

		for(int j=0;j<TA;j++)
		{
			Attack attack;
			attack.Day = FA +(j*DD);
			attack.Strength = FS + (j*DS);
			attack.W = FW + (DP*j);
			attack.E = FE + (DP*j);
			Attacks.insert(make_pair(attack.Day,attack));
			keys.insert(attack.Day);
		}
	}

	int TSA =0;
	for(set<int>::iterator a =keys.begin();a!= keys.end();a++)
	{
		int Count = Attacks.count(*a);
		std::multimap<int,Attack>::iterator start = Attacks.find(*a);
		for(int i=0;i<Count;i++)
		{
			Attack attack = (*start).second;
			for(int j=attack.W;j<attack.E;j++)
			{
				if(Wall[j+1000000]<attack.Strength)
				{
					TSA++;
					break;
				}
			}
			start++;
		}
		start = Attacks.find(*a);
		for(int i=0;i<Count;i++)
		{
			Attack attack = (*start).second;
			for(int j=attack.W;j<attack.E;j++)
			{
				if(Wall[j+1000000]<attack.Strength) Wall[j+1000000] = attack.Strength;
			}
			start++;
		}
	}
	out<<TSA;

}




