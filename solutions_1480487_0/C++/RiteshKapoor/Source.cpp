#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<climits>
#include <string>
#include <sstream>

typedef unsigned long long int ULONG;
typedef long long int LONG;
typedef unsigned int UINT;

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)

#ifndef ONLINE_JUDGE
#include <time.h>
#endif

#include<stdio.h>
#include<iostream>
#include<math.h>

template <class T>
inline void swap(T & a,T & b){
	T z=a;
	a=b;
	b=z;
}
template <class T>
void GaussJordanInverse(T o[][],int m,int n){
	/*float A[][8]={ 
	4,8,4,0,1,0,0,0,
	1,4,7,2,0,1,0,0,
	1,5,4,-3,0,0,1,0,
	1,3,0,-2,0,0,0,1
	};*/

/*
	float A[][8]={ 
			11.000,43.000, 5.000, 6.000,1,0,0,0,
	 3.000,78.000,45.000, 6.000,0,1,0,0,
	 3.000, 4.000,56.000,75.000,0,0,1,0,
	34.000,54.000,43.000,45.000,0,0,0,1
	};

	m=4,n=8;
	*/


	int i=0,j=0,k=0,z=0,u=0;
	for(i=0;i<m;i++){
		for(j=0;j<i;j++){
			double t=A[i][j];
			for(z=0;z<n;z++){
				A[i][z]-=t*A[j][z];
			}
		}
		
		double t=A[i][i];
		for(z=0;z<n;z++){
			A[i][z]/=t;
		}
	}

	for(i=m-1;i>=0;i--){
		for(j=m-1;j>i;j--){
			double t=A[i][j];
			for(z=0;z<n;z++){
				A[i][z]-=t*A[j][z];
			}
		}		
	}
}

int main(){
	freopen("input.in","r",stdin);
#ifndef _DEBUG 
	freopen ("output.txt","w",stdout);
#endif
	clock_t start = clock();


	int T;
	scanf("%d",&T);	
	FOR(tT,0,T){
		int N,S=0;
		int A[202];
		scanf("%d",&N);
		FOR(i,0,N)scanf("%d",&A[i]);
		FOR(i,0,N)S+=A[i];

		double a[203][203];
		FOR(i,0,203){
			FOR(j,0,203){
				a[i][j]=0;				
			}
		}

		FOR(i,0,N)a[i][0]=1;
		FOR(i,0,N)a[i][i+1]=-S;
		FOR(i,0,N)a[i][N+1]=A[i];

		FOR(i,1,N+1)a[N][i]=1;
		a[N][N+1]=1;
		
		{
			int m=N+1,n=N+2;
			int i=0,j=0,k=0,z=0,u=0;
			for(i=0;i<m;i++){
				for(j=0;j<i;j++){
					double t=a[i][j];
					for(z=0;z<n;z++){
						a[i][z]-=t*a[j][z];
					}
				}

				double t=a[i][i];
				for(z=0;z<n;z++){
					a[i][z]/=t;
				}
			}

			for(i=m-1;i>=0;i--){
				for(j=m-1;j>i;j--){
					double t=a[i][j];
					for(z=0;z<n;z++){
						a[i][z]-=t*a[j][z];
					}
				}		
			}
		}

		int l=0;
		double e=0;
		FOR(i,1,N+1){
			if(a[i][N+1]<0){
				l++;
				e+=a[i][N+1];
			}
		}
		FOR(i,1,N+1){
			if(a[i][N+1]<0)a[i][N+1]=0;
			else a[i][N+1]+=e/(N-l);
		}
		


		printf("Case #%d: ",tT+1);
		FOR(i,1,N+1)printf("%.6f ",a[i][N+1]*100);
		printf("\n");

	}
	
#ifdef _DEBUG 	
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}






