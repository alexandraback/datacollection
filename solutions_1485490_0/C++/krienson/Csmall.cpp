/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int N,M;
long long a[105];
int A[105];
long long b[105];
int B[105];

long long R[105][105];

int main(){
	int T; cin>>T;
	for (int kases=1; kases<=T ; kases++) {
		cin>>N>>M;
		for (int i=1; i<=N ; i++) {
			cin>>a[i]>>A[i];
		}
		for (int i=1; i<=M ; i++) {
			cin>>b[i]>>B[i];
		}
		long long res=0,aux;
		if(N == 1){
			for(int i=1;i<=M;i++){
				if( A[1] == B[i] ){
					res += MIN(a[1],b[i]);
					a[1]-=b[i];if(a[1]<0) a[1] = 0;
				}
			}
		}
		else if(N == 2){
			long long a1=a[1],a2=a[2];
			long long bb[105];
			for (int i=1; i<= M ; i++) {
				a1 = a[1]; a2 = a[2];
				for(int j=1;j<=M;j++) bb[j] = b[j];
				long long ac_res=0;
				for(int j=1;j<=M;j++){
					if(j<=i && A[1] == B[j]){
						aux = a1;
						ac_res+= MIN(a1,bb[j]);
						a1 -= bb[j]; if(a1<0) a1=0;
						bb[j] -= aux; if(bb[j]<0) bb[j] = 0;
					}
					if(j>=i && A[2] == B[j]){
						aux = a2;
						ac_res+=MIN(a2,bb[j]);
						a2 -= bb[j]; if(a2<0) a2 = 0;
						bb[j] -= aux; if(bb[j]<0) bb[j] = 0;
					}
				}
				res = MAX(res,ac_res);
			}
		}
		else{//N == 3
			long long a1=a[1],a2=a[2],a3=a[3];
			long long bb[105];
			for (int i=1; i<= M ; i++) {
				for(int j=i;j<=M;j++){
					long long ac_res= 0;
					a1 = a[1]; a2 = a[2]; a3 = a[3];
					for(int k=1;k<=M;k++) bb[k] = b[k];
					// [1,i] - [i,j] - [j,M]
					for (int k=1; k<=M ; k++) {
						if(k<=i && A[1] == B[k]){
							aux = a1;
							ac_res+= MIN(a1,bb[k]);
							a1 -= bb[k]; if(a1<0) a1=0;
							bb[k] -= aux; if(bb[k]<0) bb[k] = 0;
						}
						if(k>=i && k<=j && A[2] == B[k]){
							aux = a2;
							ac_res+=MIN(a2,bb[k]);
							a2 -= bb[k]; if(a2<0) a2 = 0;
							bb[k] -= aux; if(bb[k]<0) bb[k] = 0;
						}
						if(k>=j && A[3] == B[k]){
							aux = a3;
							ac_res+=MIN(a3,bb[k]);
							a3 -= bb[k]; if(a3<0) a3 = 0 ;
							bb[k] -= aux; if(bb[k]<0) bb[k] = 0;
						}
					}
					res = MAX(res,ac_res);
				}	
			}
		}
		cout<<"Case #"<<kases<<": "<<res<<endl;
	}
}