#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
//#define debug 1

char mul(char a, char b){
	if(a == '1') return b;
	if(b == '1') return a;
	if(a == b) return '1';
	if(a == 'i'){
		if(b == 'j') return 'k';
		return 'j';
	}
	if(a == 'j'){
		if(b == 'i') return 'k';
		return 'i';
	}
	if(b == 'i') return 'j';
	return 'i';
}

int sign(char a, char b){
	if(a == '1' || b == '1') return 1;
	if(a == b) return -1;
	if(a == 'i'){
		if(b == 'j') return 1;
		return -1;
	}
	if(a == 'j'){
		if(b == 'k') return 1;
		return -1;
	}
	if(b == 'i') return 1;
	return -1;
}

char getNetChar(char arr[], int l){
	char res = '1';
	for(int i=0; i<l; i++){
		res = mul(res, arr[i]);
	}
	return res;
}
char getNetSign(char arr[], int l){
	char res = '1';
	int sig = 1;
	for(int i=0; i<l; i++){
		sig *= sign(res, arr[i]);
		res = mul(res, arr[i]);
	}
	return sig;
}

int getMinI(char arr[], int l){
	char res = '1';
	int sig = 1;
	for(int i=0; i<l*4; i++){
		sig *= sign(res, arr[i%l]);
		res = mul(res, arr[i%l]);
		if(res == 'i' && sig == 1) return i+1;
	}
	return -1;
}

int getMinK(char arr[], int l){
	char res = '1';
	int sig = 1;
	for(int i=l*4 - 1; i>=0; i--){
		sig *= sign(arr[i%l], res);
		res = mul(arr[i%l], res);
		if(res == 'k' && sig == 1) return 4*l - i;
	}
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int iiii = 1; iiii<=t; iiii++){
		int l, x;
		scanf("\n%d %d\n", &l, &x);
		char arr[l];
		for(int i=0; i<l; i++){
			scanf("%c", &arr[i]);
		}
		char mul = arr[0];
		char net = getNetChar(arr, l);
		int sig = getNetSign(arr, l);
		if(!((net == '1' && sig == -1 && x%2 == 1) || (net != '1' && x%2 == 0 && x%4 != 0))){
			cout<<"Case #"<<iiii<<": NO"<<endl;
			continue;
		}
		int iMin = getMinI(arr, l);
		int kMin = getMinK(arr, l);
		long long max = (long long) x * (long long) l;
		if(max > iMin + kMin && iMin>0 && kMin > 0) cout<<"Case #"<<iiii<<": YES"<<endl;
		else cout<<"Case #"<<iiii<<": NO"<<endl;
		
		//cout<<"Case #"<<iiii<<": "<<ans<<endl;
	}
}
