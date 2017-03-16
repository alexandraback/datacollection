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
bool V[2000005];
int A,B,digi;

long long calc_dig(int a){
	long long res=1;
	while(a){
		res*=10;
		a/=10;
	}
	return res/10;
}

long long calculate(int a){
	int next = digi*(a%10) + (a/10);
	int curr = a;
	long long res=0;
	while(next != a){
		if((curr%10) == 0){ // no count
			curr = next;
			next = digi * (curr%10) + (curr/10);
		}
		else{ //count if A<=...<=B
			if(next >= A && next<= B && next >= a){//&& !V[next]){
				V[next] = true;
				res++;
			}
			curr = next;
			next = digi * (curr%10) + (curr/10);
		}
	}
	/*if(res>1){ 
		cout<<"A: "<<a<<" res: "<<res<<endl;
		return res*(res-1)/2;
	}*/
	return res;
}

int main(){
	int T; cin>>T;
	for (int kases= 1; kases<=T; kases++) {
		long long res=0;
		cin>>A>>B;
		digi = calc_dig(A);
		for (int i=A; i<=B ; i++) {
			V[i] = false;
		}
		for (int i=A; i<=B ; i++) {
			//if(V[i]) continue;
			res += calculate(i);
		}
		cout<<"Case #"<<kases<<": "<<res<<endl;
	}
}