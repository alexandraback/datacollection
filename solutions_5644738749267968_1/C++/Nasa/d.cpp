#include <iostream>
#include <algorithm>

using namespace std;

float a[1000],b[1000];
int n;

int calcwar(float *a, float *b, int n){
	int i,j;
	for (i=j=0; i<n && j<n; i++,j++){
		while(j<n && b[j]<=a[i]) j++;
		if (j==n) break;
	}
	return n-i;
}

int main(){
	int t,u,i,j,war,dwar;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		for (i=0; i<n; i++) cin>>b[i];
		sort (a,a+n);
		sort (b,b+n);
		//for (i=0; i<n; i++) printf("%.03f ",a[i]); cout<<endl;
		//for (i=0; i<n; i++) printf("%.03f ",b[i]); cout<<endl;
		war=calcwar(a,b,n);
		dwar=n-calcwar(b,a,n);
		//for (i=1; i<=n && a[i-1]<b[n-i]; i++) 
		//	dwar=max(dwar,calcwar(a+i,b,n-i));
		cout<< "Case #"<< (u+1)<<": "<<dwar<<" "<<war<<endl;
	}
	return 0;
}
