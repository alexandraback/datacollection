#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <climits>
using namespace std;

//long long int Boxnum[100];
int Boxtype[100];

//long long int Toynum[100];
int Toytype[100];

long long int maxx = -1;

void f(int box, int toy, int N, int M, long long int sum,  vector<long long int> Boxnum, vector<long long int> Toynum) {
    if(box == N || toy == M) {
        maxx = max(maxx, sum);
        return;
    }
    if(Boxtype[box] == Toytype[toy]) {
        long long int newsum = sum;
        if(Boxnum[box] < Toynum[toy]) {
            Toynum[toy] -= Boxnum[box];
            newsum += Boxnum[box];
            f(box+1, toy, N, M, newsum, Boxnum, Toynum);
        }
        else if(Boxnum[box] > Toynum[toy]) {
            Boxnum[box] -= Toynum[toy];
            newsum += Toynum[toy];
            f(box, toy+1, N, M, newsum, Boxnum, Toynum);
        }
        else if(Boxnum[box] == Toynum[toy]) {
            newsum += Toynum[toy];
            f(box+1, toy+1, N, M, newsum, Boxnum, Toynum);
        }
    }
    else {
        f(box+1, toy, N, M, sum, Boxnum, Toynum);
        f(box, toy+1, N, M, sum, Boxnum, Toynum);
    }
}

int main(){
	
	freopen("input.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    
	int i,j,k,l;
    int N,M,t;
    long long int a,b;
	int flag=0;
	cin>>t;

    vector<long long int> Boxnum(100);
    vector<long long int> Toynum(100);

    for ( k=1; k<=t; k++) {
        maxx = -1;
        cin>>N>>M;
        for (int i = 0; i < N; ++i) {
            cin>>a>>b;
            Boxnum[i] = a;
            Boxtype[i] = b;
        }
        for (int i = 0; i < M; ++i) {
            cin>>a>>b;
            Toynum[i] = a;
            Toytype[i] = b;
        }

        f(0, 0, N, M, 0, Boxnum, Toynum);

        cout<<"Case #"<<k<<": "<<maxx<<endl;

    }
	
	return 0;
	
}
		
			
			
			
			
			
			

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
