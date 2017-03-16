#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int a[2000005];
int s[21];
int i,j,k,l,m,n,t;

int main(){
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>t;
	for (int ii=1;ii<=t;ii++){
		cin>>n;
		double sum=0;
		for (i=0;i<n;i++){
			cin>>s[i];
		}

		for (i=0;i<2000005;i++)
			a[i]=0;
		cout<<"Case #"<<ii<<": \n";
		int d=0;
		for (i=1;i<(1<<n);i++){
			int cur =0;
			for (j=0;j<n;j++)
				if ((i&(1<<j))>0){
					cur+=s[j];
				}
				if (a[cur]>0){
					d=1;
					int mask1 = a[cur];
					int mask2 = i;
					for (j=0;j<n;j++)
						if ((mask1 & (1<<j))>0){
							cout<<s[j]<<" ";
						}
					cout<<"\n";
					for (j=0;j<n;j++)
						if ((mask2 & (1<<j))>0){
							cout<<s[j]<<" ";
						}
					break;
				} else
				{
					a[cur]=i;
				}
		}
		if (!d) cout<<"Impossible\n"; else
			cout<<"\n";
	}
	return 0;
}