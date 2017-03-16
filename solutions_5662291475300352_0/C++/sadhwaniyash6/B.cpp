/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/


int m1,m2,p1,p2;

int N;

inline void ReadInput(void){
	si(N);
	if(N==1){
		int a,b,c;
		si(a); si(b); si(c);
		if(b==1){
			p1=a; m1=c;
		}
		else if(b==2){
			p1=p2=a; m1=c; m2=c+1;
			N=2;
		}
	}
	else{
		int a,b,c;
		si(a); si(b); si(c);
		p1=a; m1=c;
		si(a); si(b); si(c);
		p2=a; m2=c;
	}
}

inline void solve(int turn){
	if(N==1){
		cout<<"Case #"<<turn<<": "<<0<<endl;
	}
	else if(N==2){
		if(p1<p2 or (p1==p2 and m1<m2)){
			swap(p1,p2);
			swap(m1,m2);
		}
		//cout<<m1<<" "<<m2<<endl;
		//cout<<tmkc<<" "<<bkl<<endl;
		if(m1>m2){
			double tmkc=360-p2;
		tmkc/=360;
		tmkc+=1;
		tmkc*=m2;
		double bkl=360-p1;
		bkl/=360;
		//bkl+=1;
		bkl*=m1;	
		
			if(tmkc>bkl){
				cout<<"Case #"<<turn<<": "<<0<<endl;
			}
			else if(tmkc+m2>bkl+m1){
				cout<<"Case #"<<turn<<": "<<1<<endl;
			}else{
				cout<<"Case #"<<turn<<": "<<1<<endl;
			}
		}else{
			double tmkc=360-p2;
		tmkc/=360;
		//tmkc+=1;
		tmkc*=m2;
		double bkl=360-p1;
		bkl/=360;
		bkl+=1;
		bkl*=m1;	
		
			if(bkl>tmkc){
				cout<<"Case #"<<turn<<": "<<0<<endl;
			}
			else if(bkl+m1>tmkc+m2){
				cout<<"Case #"<<turn<<": "<<1<<endl;

			}else{
				cout<<"Case #"<<turn<<": "<<1<<endl;
			}
		}
	}
}

inline void Refresh(void){

}

int main()
{
	int t; si(t);
	for(int i=1;i<=t;i++){
		ReadInput();
		solve(i);
	}
	return 0;
}
