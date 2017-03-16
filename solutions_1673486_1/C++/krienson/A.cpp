/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

double OK[100005];
double AV[100005];
double PR[100005];

int main(){
	int T,A,B; 
	cin>>T ;
	cout.setf(ios::fixed);
	cout.precision(6);
	for (int kases = 1; kases <= T; kases++) {
		cin>>A>>B;
		int offs = B-A+1;
		double cal,cal2;
		for (int i=0; i<A ; i++) {
			cin>>OK[i];
			if(i) PR[i] = PR[i-1]*OK[i];
			else PR[i] = OK[i];
		}
		double res = B+2;// cout<<"ENTER: "<<res<<endl;
		cal = PR[A-1]*offs + ( (1.0 - PR[A-1] ) * (offs + B + 1) ); //cout<<"TYPE END: "<<cal<<endl;
		if(cal < res) res = cal;
		cal =  A + B + 1; //cout<<"ALL BACK: "<<cal<<endl;
		if(cal < res) res = cal;
		for (int pos = 1; pos<A ; pos++) {
			cal2 = (A-pos)*2 + offs;
			cal = ((1.0 - PR[pos-1]) * (cal2 + B + 1)) + ( PR[pos-1]*cal2 );
			if(cal < res) res = cal;
			//cout<<"POS: "<<pos<<" -> "<<res<<endl;
		}
		cout<<"Case #"<<kases<<": "<<res<<endl;
	}
}