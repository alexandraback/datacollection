#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits.h>
#include <time.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const double eps = 1e-11;

int solve1(vector<double> a, vector<double> b){
	int res = 0, n = a.size();
	vector<char> used(n, false);
	for(int i=0; i<n; i++){
		double x = a[i];
		bool fl = false;
		for(int j=0; j<n; j++){
			double y = b[j];
			if(!used[j]){
				if(x > y){
					fl = true;
					break;
				}
			}
		}
		if(fl){
			res++;
			for(int j=0; j<n; j++){
				if(!used[j]){
					used[j] = true;
					break;
				}
			}
		}
		else{
			for(int j=n-1; j>=0; j--){
				if(!used[j]){
					used[j] = true;
					break;
				}
			}
		}
	}
	return res;
}

int solve2(vector<double> a, vector<double> b){
	int res = 0, n = a.size();
	vector<char> used(n, false);
	for(int i=0; i<n; i++){
		double x = a[i];
		bool fl = false;
		for(int j=0; j<n; j++){
			double y = b[j];
			if(!used[j]){
				if(y > x){
					fl = true;
					used[j] = true;
					break;
				}
			}
		}
		if(!fl){
			res++;
			for(int j=0; j<n; j++){
				if(!used[j]){
					used[j] = true;
					break;
				}
			}
		}
	}
	return res;
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(0));
	int test;
	cin>>test;
	for(int tt = 0; tt < test; tt++){
		int n = 10;
		cin>>n;
		vector<double> a(n), b(n);
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int res1 = solve1(a, b), res2 = solve2(a, b);
		
		cout<<"Case #"<<tt+1<<": ";
		cout<<res1<<" "<<res2<<"\n";
	}
    return 0;
}