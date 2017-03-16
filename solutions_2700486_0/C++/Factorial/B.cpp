#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <iomanip>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	//ifstream be("B-small-attempt1.in");
	ifstream be("B-small-attempt2.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int n,x,y; be>>n>>x>>y;
		int a=0, preva=-1;
		int xy=0; //x+y, amit elerunk
		int nov=1;
		while(a<n){
			preva=a;
			a+=nov;
			nov+=4;
			xy+=2;
		}
		a=preva;
		xy-=2;
		nov-=4;
		double res=-1;
		if(xy<x+y)
			res=0;
		else if(xy>x+y)
			res=1;
		else{
			int l=nov/2; //szelhossz
			n-=a;
			
			//cout<<"a";
			
			vector<vector<double> > p(l+2, vector<double>(l+2));
#define P(i,j) (((i)<0 || (j)<0) ? 0 : p[i][j])
			p[0][0]=1;
			//for(int k=1; k<=n; k++){
			//for(int k=2; k<=n+1; k++){
			for(int k=1; k<=n; k++){ //legutobbi
				//for(int i=0; i<=k; i++){
				//k+=1;
				for(int i=0; i<=k; i++){
					//if(i<l+2 && k-i<l+2){
					if(i<l+1 && k-i<l+1){
						p[i][k-i]=
							P(i-1, k-i)*0.5+
							P(i, k-i-1)*0.5;
					}else{
						if(i==l+1)
							p[i][k-i]=
								P(i-1, k-i)*0.5+
								P(i, k-i-1);
						else if(k-i==l+1)
							p[i][k-i]=
								P(i-1, k-i)+
								P(i, k-i-1)*0.5;
					}
				}
				//k-=1;
			}

			double sum=0;
			for(int i=y+1; i<=l+1; i++)
				if(0<=n-i && n-i<=l+1)
					sum+=p[i][n-i];

			res= x ? sum : (n==2*l+1 ? 1 : 0);

		}
		
		ki<<"Case #"<<tt+1<<": "<<setprecision(9)<<res<<endl;
		cout<<"Case #"<<tt+1<<": "<<setprecision(9)<<res<<endl;
	}
	

	ki.close();

	system("pause");
	return 0;
}