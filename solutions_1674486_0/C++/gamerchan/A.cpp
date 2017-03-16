#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<iomanip>

using namespace std;
typedef vector<int> VI;

#define R(i, n) for(int i=0; i<n; ++i)
#define PB push_back
#define ALL(c) (c).begin(),(c).end()

vector<vector<int> > val;
int N;
int flg;
int cnf[1001][1001];
bool g(int index, int i,int j){
	if((index==0)&&(i!=j)){
		cnf[i][j]=0;
		return false;
	}
	else if (cnf[i][j]==0)return false;
	else if(i==j){if(flg==1){return true;}
		else flg=1;
	}
		
	else{
		R(k,val[i].size()){
			if(g(index-1, val[i][k], j))return true;
		}
	}
	return false;
}	
 

int main(){
	int T,N,m=1;
	cin>>T;
	while(m<=T){
		int mi=0,flag=0,input;
		VI temp;
		val.clear();
		cin>>N;
		
		R(i,N){R(j,N){cnf[i][j]=1;}}
		
		cout<<"Case #"<<m<<": ";
		R(i,N){
			cin>>mi;
			temp.clear();
			R(j,mi){
				cin>>input;
				temp.PB(input-1);
			}
			val.PB(temp);
		}
		R(i,N){
			R(j,N){
				if(i!=j){
				flg=0;
				if(g(N,i,j)){
					flag=1;
					cout<<"Yes\n";
					break;
				}}
			}
			if(flag==1)break;
		}
		if(flag==0)cout<<"No\n";
		
		m++;
	}
	return 0;
}
