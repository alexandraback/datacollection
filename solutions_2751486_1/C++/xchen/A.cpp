#include <iostream>
#include <fstream>
#include <algorithm>
//#include <string>
//#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>

//#include <memory.h>


#define PI acos(-1)
#define eps 1e-9

#define out(x) (cout<<#x<<":"<<x<<" ")
#define outln(x) (cout<<#x<<":"<<x<<endl)
#define outs(x) (cout<<x)
#define outline (cout<<endl)
#define mssleep(time) usleep((time)*(10*1000))

#define FOR_I(begin,end) for (int i=begin;i<end;i++)
#define FOR_J(begin,end) for (int j=begin;j<end;j++)
#define FOR_K(begin,end) for (int k=begin;k<end;k++)
#define FOR_I_J(B1,E1,B2,E2) FOR_I(B1,E1) FOR_J(B2,E2)
#define FOR_I_J_K(B1,E1,B2,E2,B3,E3) FOR_I_J(B1,E1,B2,E2) FOR_K(B3,E3)
#define FOR(begin,end) FOR_I(begin,end)
#define FORN(end) FOR_I(0,end)

using namespace std;

	template <typename T>
	void debug_a(T * data,int begin,int end){
		for (int i=begin;i<end;i++) cout<<"["<<i<<"]: "<<data[i]<<"\t";cout<<endl;
	}
	template <typename T>
	void debug_a(T * data,int end){
		debug_a(data,0,end);
	}
	template <typename T>
	void debug_a2(T * data,int end1,int end2){
		for (int i=0;i<end1;i++){cout<<"row "<<i<<endl; for (int j=0;j<end2;j++) cout<<"["<<i<<","<<j<<"] "<<data[i][j]<<"\t";cout<<endl;} 
	}
	template <typename T>
	T checkmin(T & data,T value){
		data = min(data,value);
		return data;
	}
	
	inline double rand_double(double range){
		return  ((double)rand()/(double)RAND_MAX)*range;
	}

typedef long long LL;

const int N = 1001000;

char str[N];
LL x;

	void inputing(){
		cin>>str>>x;
		
	}

	bool isC(char x){
		if ('a' == x) return false;
		if ('e' == x) return false;
		if ('i' == x) return false;
		if ('o' == x) return false;
		if ('u' == x) return false;
		return true;
	}

LL sum = 0;
	void work(){
		LL len = strlen(str);
		LL cur = 0;
		
		sum = 0;
		LL con = 0;
		FOR_I(0,len){
			if ( isC(str[i])  ){
				con += 1;
				if ( con >=x ){
					//form a new one, add before
					//printf("meet %c at %d\n",str[i],i);
					//cout<<"before:----"<<endl;outln(cur);outln(sum);

					int temp = i+1-x+1;
					int oldcur = cur;
					cur = temp + cur-cur;
					sum += cur;
					//cout<<"after:----"<<endl;outln(cur);outln(sum);
				}
				else {
					sum += cur;
				}
			}
			else {
				con =0;
				sum += cur;
			}
			//cout<<i<<" at "<<sum<<endl;
		}

	}

int main(){
	int cas;
	if (false){
	cout<<1<<endl;
	FOR_I(0,1000000){
		cout<<"b";
	}
	cout<<" "<<2<<endl;

	return 0;
	}

	cin>>cas;
	FOR_I(0,cas){
		inputing();
		work();
		cout<<"Case #"<<i+1<<": "<<sum<<endl;
	}

	return 0;
}





