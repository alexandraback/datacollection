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

const int N = 4000;

char str[N];
LL x;
int RS;

struct node{
	int d0;
	int d_c;
	int attack0;
	int attack_c;
	int n;
	int begin,end;
	int move;

	bool operator < (const node & b) const{
		return this->d0 < b.d0;
	}

};


int n;

node arr[N];
node arr2[N];

int wall[N];
int wall2[N];

int num;
int mid;

	void inputing(){
		memset(wall,0,sizeof(wall));
		memset(wall2,0,sizeof(wall2));
		cin>>n;
		num = 0;
		FOR_I(0,n){
			RS = scanf("%d%d%d%d %d%d%d%d",&(arr[i].d0)
,&(arr[i].n)
,&(arr[i].begin),&(arr[i].end)
,&(arr[i].attack0)
,&(arr[i].d_c)
,&(arr[i].move)
,&(arr[i].attack_c)
			);

			arr2[num++] = arr[i];

			FOR_J(1,arr[i].n){
				node temp = arr2[num-1];

				temp.begin += temp.move;
				temp.end += temp.move;

				temp.d0 += temp.d_c;
				temp.attack0 += temp.attack_c;

				arr2[num++] = temp;
			}


		}
		sort(arr2,arr2+num);
	
	}

	void show(){
		FOR_I(0,num){
			printf("attack %d (%d %d) on day %d\n",arr2[i].attack0,arr2[i].begin,arr2[i].end,arr2[i].d0);
		}
	}

	bool check(int begin,int end,int attack){
		bool flag = false;
		FOR_I(begin,end){
			int x = i + mid;
			if ( wall[x]<attack ){
				flag = true;
			}
			wall2[ x ] = max(wall2[x],attack);
		}
		return flag;
	}

int sum = 0;

	void work(){
		mid = 2000;
		sum = 0;
		int i = 0;
		while (i<num){
			int j =i;
			int day = arr2[i].d0;
			memcpy(wall2,wall,sizeof(wall));
			for (;j<num;j++){
				if (arr2[j].d0 != day)
					break;

				node temp = arr2[j];
				bool result;
				result = check(temp.begin,temp.end,temp.attack0);
				if (result)
					sum++;
			}
			memcpy(wall,wall2,sizeof(wall2));
			i = j;
		}
	}


int main(){
	int cas;

	cin>>cas;
	FOR_I(0,cas){
		inputing();
		//show();
		work();
		cout<<"Case #"<<i+1<<": "<<sum<<endl;
	}

	return 0;
}





