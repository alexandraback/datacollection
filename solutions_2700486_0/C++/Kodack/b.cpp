
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double getcombi(int n,int y){
	double val=1.0;
	for(int t=0;t<y;t++){
		val=val*(y-t)/(n-t);
	}
	return val;
}

double getpos(int n,int y){
	// n rest of dia
	// p height of mountain
	// y my height
	double cnt=0;
	double last=1;
	for(int i=0;i<n-y;i++){
		cnt+=last;
		last*=(1.0*(n-i))/(1.0*(i+1));
	}
	for(int i=0;i<n;i++){
		cnt*=0.5;
	}
	return cnt;
}

int main(){
	int nt;
	cin >> nt;
	for(int t=0;t<nt;t++){
		int n,x,y;
		cin >> n >> x >> y;
		x=abs(x);
		int p=0;
		while(2*p*p+3*p+1<=n){
			p++;
		}
		p--;
		n-=2*p*p+3*p+1;

		double pos;
		if(x+y<=2*p)pos=1.0;
		else if(x+y>=2*(p+2))pos=0.0;
		else{
			if(n==0)pos=0.0;
			else if(y==2*p+2)pos=0.0;
			else if(n>=2*p+2+y+1)pos=1.0;
			else{
				pos=getpos(n,y);
			}
		}
		cout << "Case #" << t+1 << ": " ;
		printf("%.8lf",pos);
		cout << endl;
	}
	return 0;
}