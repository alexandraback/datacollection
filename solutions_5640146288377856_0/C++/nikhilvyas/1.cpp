#include <bits/stdc++.h>

using namespace std;

int f(int i){
	if (i = 1) return 0;
	if (i = 2) return 1;
	int ans = 0;
	return 1+f((i+1)/2);
}
		

int main(){
	int d[21];
	d[1] = 0;
	d[2] = 1;
	int e;
	cin>>e;
	for(int g=1;g<=e;g++){
		int ans = 0;
		int r,c,w;
		cin>>r>>c>>w;
		int tmp = 0;
		double rr=r,cc=c,ww=w;
		int t = c/w;
		ans = ans + (r-1)*t;
		if(c % w == 0) ans = ans + t + w - 1;
		else ans = ans + t + w;
		/*int yy = c%w + 1;
		int ans2 = ans + t + f(yy);
		int ans3 = ans;
		if(t > 1) ans3 = ans3 + (t-1) + f(w);
		if(ans3 > ans2) ans = ans3;
		else ans = ans2;*/
		cout<<"Case #"<<g<<": "<<ans<<endl;
	}
}
