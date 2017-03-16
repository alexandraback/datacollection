#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

double A[1001];
double B[1001];

int main() {
  ifstream fin("D.in");
	ofstream fout("D.out");
	int t;
	fin>>t;
	for( int p=1; p<=t; p++) {
		int n;
		fin>>n;
		int ans1=0;
		int ans2=n;
		for(int i=0; i<n; i++) {
		  fin>>A[i];
		}
		for(int i=0; i<n; i++) {
		  fin>>B[i];
		}
		sort(A, A+n);
		sort(B, B+n);
		for( int i=0; i<n; i++) {
		  int count = 0;
		  for( int j=0; i+j<n; j++) {
			  if(A[i+j]>B[j]) {
				  count++;
				}
			}
			if(ans1<count) {
			  ans1=count;
			}
		}
		int index=0;
		bool flag = false;
		for(int i=0; i<n; i++) {
		  while(B[index]<A[i]) {
			  index++;
				if(index >=n) {
				  break;
				}
			}
			if(index>=n) {
			  break;
			}
			index++;
			ans2--;
		}
		fout<<"Case #"<<p<<": "<<ans1<<" "<<ans2<<endl;
	}
}