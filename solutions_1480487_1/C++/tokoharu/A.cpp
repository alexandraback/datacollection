#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;


int main() {
	int t;
	int T;
	cin>>t;
	T=t;
	for(;t;t--) {
		
		int n;
		cin>>n;
		
		int sum = 0;
		vector<PII>input;
		vector<double>output;
		for(int a=0; a<n; a++) {
			int p;
			cin>>p;
			input.push_back(MP(p,a));
			sum += p;
		}
		input.push_back(MP(1000,10000));
		
		sort(input.begin(),input.end());
		
		for(int b=0; b<n; b++) {
			double k = (double)sum;
			for(int a=0; a<=b; a++) k += (double) input[a].first;
//			k = (double)k/(b+1);
			
			
			if( k<=(b+1)*input[b+1].first ) {
				output.clear();
				k /= (b+1);
				for(int a=0; a<=b; a++) {
					output.push_back((double)100*(k-input[a].first)/sum);
					
				}
				for(int a=b+1; a<n; a++) output.push_back(0);
				
				
				cout<<"Case #"<<T-t+1<<": ";
				for(int a=0; a<n; a++) {
					for(int c=0; c<n; c++) if(input[c].second==a) printf("%.10lf",output[c]);
					if(a==n-1) cout<<endl;
					else cout<<" ";
				}
				break;
			}
			
		}
		
		/*
		double k = (double)sum/n;
		k *= 2;
		
		
		for(int a=0; a<n; a++) {
//			cout<<(double)100*(k-input[a])/sum;
			double p = (double)100*(k-input[a])/sum;
			if(p<0) p=0;
			printf("%.10lf",p);
			if(a==n-1) cout<<endl;
			else cout<<" ";
		}
		
		*/
		
	}
	return 0;
	
}


