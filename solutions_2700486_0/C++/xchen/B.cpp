#include <iostream>
#include <fstream>
#include <algorithm>
//#include <string>
//#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <memory.h>


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

int arr[N][N];
int C[N][N];
int n,X,Y;
int mid = 400;

int divx;

	void inputing(){
		cin>>n>>X>>Y;
		memset(arr,0,sizeof(arr));
	}

	void init(){
		C[0][0] = 1;
		FOR_I(0,mid)
			FOR_J(0,i+1){
				if (i ==0 || 0 == j)
					C[i][j] = 1;
				else C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
	}

	void markfull(int i){
		FOR_J(0,i){
			int x = -i-1+j+2;
			FOR_K(0,i-j){
				int y = j;
	//			printf("%d %d as -1\n",x,y);//debug
				arr[x + mid][y] = -1;
				x += 2;
			}
		}
	}

int prob;

double result;

	void fillleft(int n, int i){
		FOR_J(0,n){
			int x = -i-1+j;
			int y = j;
	//		printf("fill left %d %d as prob\n",x,y);//debug
			arr[x+mid][y] += prob;
		}
	}

	void fillright(int n, int i){
		FOR_J(0,n){
			int x = i+1-j;
			int y = j;
			//printf("fill right %d %d as prob\n",x,y);//debug
			arr[x+mid][y] += prob;
		}
	
	}

	void show(int i){
		FOR_J(0,i){
			FOR_K(0,j+1){
				int x = -j+2*k;
				int y = i - j-1;
				//printf("[%d %d %d]\n",x,y,arr[x+mid][y]);//debug
				printf("\t%d",arr[x+mid][y]);

			}
			printf("\n");
		}
	}


	void work(){
		int cur = n;
		int i=1;
		for (i=1;;i+=2){
			if ( i*(i+1)/2 >= n )
				break;
		}

		if (  i*(i+1)/2 == n){
			markfull(i);
		}
		else {
			i-=2;

		markfull(i);

		int temp = i*(i+1)/2;
		temp = n - temp;


		for (int left =0 ; left <= temp;left++){
			int right = temp - left;
			prob = C[temp][left];
			//printf("C[ %d %d ] %d\n",temp,left,prob);//debug
			//show(i+2);
			if (left >= i+1){
				fillleft( i+1,i );
				fillright( temp-(i+1),i );
				//cout<<"LEFT"<<endl;
				continue;
			}
			if (right >= i+1){
				fillright( i+1,i );
				fillleft( temp-(i+1),i );
				//cout<<"RIGHT"<<endl;
				continue;
			}
			fillleft(left,i);
			fillright(right,i);
		}
		//show(i+2);
		}

		divx = 1<<(i+2);


		if (X>=mid || X<=-mid){
			result = 0;
		}
		else if ( Y>=mid )
			result =0;
		else if (arr[X+mid][Y] == -1){
			result = 1;
		}
		else if ( arr[X+mid][Y] == divx ){
			result = 1;
		}
		else {
			result = (double)arr[X+mid][Y] / (double)divx + eps;
		}
	}



int main(){
	int cas;
	cin>>cas;
	FOR_I(0,cas){
		init();
		inputing();
		work();
		printf("Case #%d: %lf\n",i+1,result);
	}

	return 0;
}
