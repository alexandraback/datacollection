#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("A2.in");
FILE * fout = fopen("A2.out","w");

const int MAX=1000000;
double c[MAX], w[MAX];
double dp[MAX];

void solve(int t){
    int A,B; fin >> A >> B;
    for(int i=0; i<A; i++){
	fin >> c[i]; w[i]=1-c[i];
    }
    /*
    dp[A]=B-A+1;
    for(int i=A-1; i>=0; i--){
	dp[i]=c[i]*dp[i+1]
	     +w[i]*(2*(A-i+1)+B-A+1);
    }

    dp[0] = min(dp[0],(double)B+2);
    */
    dp[0]=1;
    for(int i=1; i<=A; i++){
	dp[i]=dp[i-1]*c[i-1];
    }

    double best=B+2;
    for(int i=A; i>=0; i--){
	double cur= (B-A+1+2*(A-i))+(1-dp[i])*(B+1);
	//cout << cur << endl;
	best = min (best,cur);
    }

    fprintf(fout,"Case #%d: %.6f\n",t, best);
    
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
