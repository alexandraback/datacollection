#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;
int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		int J, P, S, K;
		cin>>J>>P>>S>>K;
		
		int res = J*P*S;
		int caseNO = 0;
		if(J*P>K){
			caseNO = 1;
			res = min(res, J*P*K);
		}
		if(J*S>K){	
			caseNO = 2;
			res = min(res, J*S*K);
		}
		if(P*S>K){
			caseNO = 3;
			res = min(res, P*S*K);
		}
		cout<<"Case #"<<itest+1<<": "<<res<<endl;
		if(caseNO == 0 ){
			for(int i=1; i<=J; i++){
				for(int j=1; j<=P; j++){
					for(int k=1; k<=S; k++){
						cout<<i<<" "<<j<<" "<<k<<endl;
					}
				}
			}
		}
		else if(caseNO == 1 ){
			for(int i=1; i<=J; i++){
				for(int j=1; j<=P; j++){
					for(int k=1; k<=K; k++){
						cout<<i<<" "<<j<<" "<<k<<endl;
					}
				}
			}
		}
		else if(caseNO == 2 ){
			for(int i=1; i<=J; i++){
				for(int j=1; j<=K; j++){
					for(int k=1; k<=S; k++){
						cout<<i<<" "<<j<<" "<<k<<endl;
					}
				}
			}
		}
		else {
			for(int i=1; i<=K; i++){
				for(int j=1; j<=P; j++){
					for(int k=1; k<=S; k++){
						cout<<i<<" "<<j<<" "<<k<<endl;
					}
				}
			}
		}

	}
	return 0;
}
