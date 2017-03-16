/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
int A[70][2];
int main(){
	int T,N,S,P; cin>>T;
	for (int i=0; i<70; i++) {
		A[i][0] = A[i][1] = 0;
	}
	for (int i=0; i<11; i++) {
		int v1 = i*3; //6 6 6 //no
		int v2 = i*3 + 1;// 6 6 7 //no
		int v3 = i*3 + 2;// 6 6 8 //si
		int v4 = i*3 + 2;// 6 7 7 //no
		int v5 = i*3 + 3;// 6 7 8 //si
		A[v1][0] = MAX(A[v1][0],i);
		A[v2][0] = MAX(A[v2][0],i+1);
		A[v3][1] = MAX(A[v3][1],i+2);
		A[v4][0] = MAX(A[v4][0],i+1);
		A[v5][1] = MAX(A[v5][1],i+2);
	}
	for (int kases=1; kases<=T ; kases++) {
		cin>>N>>S>>P;
		int res=0,val;
		for (int i=0; i<N ; i++) {
			cin>>val;
			if(A[val][0] >= P) res++;
			else if(A[val][1] >= P && S>0){ S--; res++;}
		}
		cout<<"Case #"<<kases<<": "<<res<<endl;;
	}
}