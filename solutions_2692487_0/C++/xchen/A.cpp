#include <iostream>
#include <fstream>
#include <algorithm>
//#include <string>
//#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

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


const int N = 1000;

int arr[N];
int result;
int n,a;

	void inputing(){
		cin>>a>>n;
		FOR_I(0,n)
		cin>>arr[i];
	}

	void work(){
		result = n;
		if (a == 1)
			return;
		sort(arr,arr+n);
		int cur = a;
		int add =0;
		FOR_I(0,n){
			//after eat ith
			while (cur <= arr[i]){
				cur += cur-1;
				add++;
			}
			cur += arr[i];
			//printf("cur: %d  add:%d  arr[i]:%d\n",cur,add,arr[i]);
			int temp = n-i-1;
			result = min(result,temp+add);
		}
	}

int main(){
	int cas;
	cin>>cas;
	FOR_I(0,cas){
		inputing();
		work();
		printf("Case #%d: %d\n",i+1,result);
	}


	return 0;
}
