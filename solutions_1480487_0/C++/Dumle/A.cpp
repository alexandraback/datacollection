#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int sum, n;
struct pr{
	int z, i;
	};
struct pr2{
	int i;
	double z;
	};
bool cmp(pr a,pr b){
	return (a.z < b.z);
	}
bool cmp2(pr2 a, pr2 b){
	return (a.i < b.i);
	}

vector <pr> a;

bool prove(int x, double q){
	double r = double(a[x].z) + sum*q;
	double p = 1.0 - q;
	int i = 0;
	while(double(a[i].z) < r && i < n){
		if(i != x){	 
			p -= (r - double(a[i].z))/double(sum);
			if(p < 0.0) return true;
		}
		i++;
		}
	return false;
	}
	
double bs(int x, double l, double r){
	if(fabs(r-l) < 0.0000000001) return r;
	if(prove(x,(r+l)/2.0))
		return bs(x, l, fabs(r+l)/2.0);
	else
		return bs(x, fabs(r+l)/2.0, r);
	}

int main(){
	int t;
	pr x;
	pr2 y;
	vector <pr2> ans;
	freopen("A-small-0.in", "r", stdin);
	freopen("A-small-0.out", "w", stdout);
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		sum = 0;
		a.resize(0);
		ans.resize(0);
		for(int j=0;j<n;j++){
			cin >>  x.z;
			x.i = j;
			a.push_back(x);
			sum += a[j].z;
			}
		sort(a.begin(),a.end(), cmp);
		for(int j=0;j<n;j++){
			y.z = bs(j, 0.0, 1.0);
			y.i = a[j].i;
			ans.push_back(y);
			}
		sort(ans.begin(),ans.end(), cmp2);
		printf("Case #%d:", i+1);
		for(int j=0;j<n;j++)
			printf(" %f", ans[j].z*100);
		printf("\n");
		}
	return 0;
	}
