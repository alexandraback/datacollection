#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

string IntToString(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

double a[1111];
double b[1111];

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"+IntToString(i+1)+": ";
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		int num1=0,num2=0;

		bool used[1111];

		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]>b[j] && !used[j]){
					used[j]=1;
					num1++;
					break;
				}
			}
		}
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]<b[j] && !used[j]){
					used[j]=1;
					break;
				}
				if(j==n-1)num2++;
			}
		}
		cout<<num1<<" "<<num2<<endl;
	}
}