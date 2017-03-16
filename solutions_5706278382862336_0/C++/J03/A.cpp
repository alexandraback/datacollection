// QA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
#include<algorithm>
#include<bitset>
#include<functional>
#include <boost\multiprecision\cpp_int.hpp>

//typedef unsigned int uint;
using namespace std;
//typedef long long int lint;
typedef boost::multiprecision::cpp_int lint;

int _tmain(int argc, _TCHAR* argv[])
{

	int Ndata;
	ifstream infile("good.in");
	ofstream OF("output2.txt");
	
	lint t[80]; 
	lint tot=1;
	for(int i=0;i<81;i++){
		t[i]=tot;
		//cout<<i<<"	"<<t[i]<<endl;
		tot*=2;
		
	}

   
	string buf;

	 infile>>Ndata;

	 getline(infile,buf);
	 for(int idat=0;idat<Ndata;idat++){
		 getline(infile,buf);
		 stringstream ss;
		 
		replace(buf.begin(), buf.end(), '/', ' ');
		//cout<<buf<<endl;
		ss.str(buf);
		lint p,q;
		ss>>p>>q;
		lint buf=t[40]/q;
		
		//if(buf*q!=t[40]) cout<<idat<<q<<" IMP"<<endl;
		//p*=t[40];
		lint A=p*t[40];
		lint B=A/q;
		lint C=B*q;

		if(A!=C) {
			cout<<"Case #"<<idat+1<<": impossible"<<endl;
		}else{
			for(int i=1;i<40;i++){
				
				if(t[40-i]<=B){
					cout<<"Case #"<<idat+1<<": "<<i<<endl;
					break;
				}
			}


		}
	 }

	 


	 infile.close();
	 OF.close();


	return 0;
}



