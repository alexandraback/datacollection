#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int i,j,k,l,m,n,t;
int ans;
int a[205];

int main(){
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>t;
	for (int ii=1;ii<=t;ii++){
		cin>>n;
		double sum=0;
		for (i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		cout<<"Case #"<<ii<<": ";
		double left = 0.0, right = 1000.0;
		double middle;
		for (i=0;i<100;i++){
			middle = (left+right)/2.0;
			double percent=0;
			for (j=0;j<n;j++){
				if (middle>=a[j])
					percent += 1.0*(middle-a[j])/sum;
			}
			if (percent<1.0) left = middle; else right = middle;
		}
		for (j=0;j<n;j++){
			if (left>=a[j]) cout<<100.0*(left-a[j])/sum; else cout<<0;
			cout<<" ";
		}
		cout<<'\n';
	}
	return 0;
}