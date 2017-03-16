#include <iostream>
#include <fstream>
#include <algorithm>
//#include <string>
//#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <unistd.h>
#include <sys/time.h>
#include <memory.h>

#include <omp.h>

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

//for mpi
#define MCW MPI_COMM_WORLD

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
	double get_sec(const struct timeval & tval){
		return ((double)(tval.tv_sec*1000*1000 + tval.tv_usec))/1000000.0;
	}

	template <typename T>
	T checkmin(T & data,T value){
		data = min(data,value);
		return data;
	}
struct Watch{
	timeval begin,end;
	void start(){gettimeofday(&begin,NULL);}
	double time(){return get_sec(end)-get_sec(begin);}
	double stop(){gettimeofday(&end,NULL);return time();}
};
	
	inline double rand_double(double range){
		return  ((double)rand()/(double)RAND_MAX)*range;
	}

int r,n,m,k;

int v[100];

int arr[200];
int used[200];


	void inputing(){
		memset(v,0,sizeof(v));
		FOR_I(0,k){
			cin>>arr[i];
		}
	}

	void work(){
		FOR_I(0,k){
			if ( arr[i] == 1 ) continue;
			FOR_J(2,m+1){
				if ( arr[i] % j ==0 ){
					v[j]++;
				}
			}
		}
		int sum = 0;

	

		FOR_I(2,m+1)
			sum += v[i];
		if (sum ==0){
			FOR_I(0,n)
				cout<<2;
			cout<<endl;
			return;
		}
		memset(used,0,sizeof(used));
		FOR_I(1,100){
			v[i] += v[i-1];
		}
		//debug_a(v,6);
		FOR_I(0,n){
			int temp = rand() % sum;
			FOR_J(2,m+1){
				if (v[j] == 0) continue;
				if (temp <= v[j]){
					cout<<j;
					break;
				}
			}
		}
		cout<<endl;

	}

int main(){
	int cas;
	srand(12);
	cin>>cas;
	FOR_I(0,cas){
		cin>>r>>n>>m>>k;
		cout<<"Case #"<<i+1<<":"<<endl;
		FOR_J(0,r){
		inputing();
		work();
		}
	}
	return 0;
}




