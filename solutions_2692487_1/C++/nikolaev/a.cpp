#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check(int pos, int n, vector<int> v, int size, int ans) {
	if (pos==n) return ans;

	int res=ans;
		for (int j=pos; j<n; j++) {
			if (size>v[j]) {
				size+=v[j];
			}
			else if (size+size-1>v[j]) {
				size+=size-1;
				size+=v[j];
				res++;
			}
			else {
				if (size==1) {
					res=res+n-j;
					break;
				}
				int k=size;
				int c=0;
				while (k<=v[j]) {
					k+=k-1;
					c++;
				}
				res = min(res+n-j, check(j+1,n,v,k+v[j],res+c));
				break;
			}
		}
	return res;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int size;
		cin>>size;
		int n;
		cin>>n;
		vector<int> v(n);
		for (int j=0; j<n; j++) {
			cin>>v[j];
		}
		sort(begin(v),end(v));

		cout<<"Case #"<<i+1<<": "<<check(0,n,v,size,0)<<'\n';
	}
	return 0;
}