#include <iostream>
using namespace std;

int a, b;
double p[10100];

//double cal(int back){
//	double ans = 0;
//	for(int fal = 0; fal<=a; fal++){
//		double pro = 1;
//		if(fal != 0){
//
//		}
//		ans += back+
//	
//	}
//	return 2 + 
//
//}

double cal(int back){
	double ans;

	if(back == 0){
		if(a == 1){
			ans = b*p[0]+(b+b+1)*(1-p[0]);
		}
		else if(a == 2){
			ans = (b-1) * p[0]*p[1];
			ans += (b-1+b+1) * ( 1-p[0] + p[0]*(1-p[1]));
		}
		else if(a == 3){
			ans = (b-2) * p[0]*p[1]*p[2];
			ans += (b-2+b+1) * (1-p[0] + p[0]*(1-p[1]) + p[0]*p[1]*(1-p[2]));
		}
	}
	else if(back == 1){
		if(a == 1){
			ans = b+2;
		}
		else if(a == 2){
			ans = (b+1) * p[0];
			ans += (b+1+b+1) * (1-p[0]);
		}
		else if(a == 3){
			ans = b * p[0]*p[1];
			ans += (b+b+1) * (1-p[0] + p[0]*(1-p[1]));
		}
	}
	else if(back == 2){
		if(a == 2){
			ans = b+3;
		}
		else if(a == 3){
			ans = (b+2) * p[0];
			ans += (b+2+b+1) * (1-p[0]);
		}
	}
	else if(back == 3){
		//else if(a == 3){
		ans = b+4;
	}
	
	return ans;
}

void main(){
	//*
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	//*/

	int T;
	cin>>T;

	cout.setf(ios::fixed);
	cout.precision(6);

	for(int tc=1;tc<=T;tc++){
		cin>>a>>b;
		for(int i=0;i<a;i++) cin>>p[i];

		double ans = b+2; // enter
		for(int back=0;back<=a;back++)
			ans = min(ans, cal(back));


		cout<<"Case #"<<tc<<": "<<ans;
		cout<<endl;
	}
}
/*
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1


*/