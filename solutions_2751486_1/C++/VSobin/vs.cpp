#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define N 10000000

using namespace std;

int n,x,T,a[N];

long long ans;

string s;

int main(void){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T ;
	int v=0;
	while (T--){
		cin >> s >> x;
		n=s.size();
		v++;
		a[n+1]=a[n+2]=a[n]=0;
		for (int i=n-1;i>=0;i--) if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') a[i+1]=0;else a[i+1]=a[i+2]+1;
		ans=0;
		int r=0;
		for (int l=1;l<=n;l++){
			if (r<l) r=l;
			while (r<=n && a[r]<x) r++;
			if (r>n) break;
			ans+=(n-r-x+2);
		}
		cout << "Case #" << v << ": " << ans << endl;
	}
	return 0;
}
                    