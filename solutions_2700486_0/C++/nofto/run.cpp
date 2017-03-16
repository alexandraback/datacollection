#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class Akt{ 
public: 
  int v;
  int por;
  bool operator<(const Akt& other) const { 
    return v > other.v || (v==other.v && por<other.por);
  }
};
double p[2000][2000];
int k;

double P(int A,int B){
	if(B>=k) return 0;
	if(A>=k) return 0;
	if(A<0) return 0.0;
	if(B<0) return 0.0;
	if(p[A][B]>=0.0) return p[A][B];
	double kA=0.5;
	double kB=0.5;
	if(B==k-1) kB=1.0;
	if(A==k-1) kA=1.0;
	p[A][B]=P(A-1,B)*kB+P(A,B-1)*kA;
	return p[A][B];
	
}

int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int t=1; t<=T; t++)
	{
		int N,X,Y;
		scanf("%d %d %d\n",&N,&X,&Y);  
        k=1;
        int s=1;
        while(s<N){
        	k+=2;
        	s+=2*k-1;
        }
        if(abs(X)+Y<=k-3) printf("Case #%d: 1.0\n",t);
		else{
			if(abs(X)+Y>=k+1) printf("Case #%d: 0.0\n",t);
			else{
				if(s==N) printf("Case #%d: 1.0\n",t);
				else{
					s-=2*k-1;
					int navyse=N-s;
					//printf("|%d|%d|",navyse,k);
					if(X==0) printf("Case #%d: 0.0\n",t);
					else{
				        for(int i=0;i<k;i++) for(int j=0;j<k;j++) p[i][j]=-1.0;
				        p[0][0]=1;
						for(int i=1;i<k;i++) {
						    p[0][i]=p[0][i-1]*0.5;
						    p[i][0]=p[0][i];
					    }
						double pr=0.0;
						for(int i=Y+1;i<=k-1;i++) {
						    pr+=P(i,navyse-i);
						    //printf("|%f|",P(i,navyse-i));
						}
						printf("Case #%d: %1.9f\n",t,pr);
					}
				}
			}
		}		
	}

  
  return 0;
}
