#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;
vector<long long> v;

long long reverse(long long num){
	long long p=0;
	while(num!=0){
		p=p*10+num%10;
		num/=10;
	}
	return p;
}

int digits(long long num){
	int i=0;
	while(num!=0){
		i++;
		num/=10;
	}
	return i;
}

bool square_check(long long num){
	long long res=num*num,re=res;
	int d=digits(res);
	long long res2=0;
	for(int i=0;i<d/2;i++){
		res2=res2*10+res%10;
		res/=10;
	}
	if(d%2!=0){
		res2=res2*10+res%10;
	}
	if(res2==res)
		v.push_back(re);
}

bool palindrome(long long num){
	long long res=num,re=res;
	int d=digits(res);
	long long res2=0;
	for(int i=0;i<d/2;i++){
		res2=res2*10+res%10;
		res/=10;
	}
	if(d%2!=0){
		res2=res2*10+res%10;
	}
	if(res2==res)
		return true;
	return false;
}

void preprocess(){
	for(long long i=1;i<=10000000;i++){
		if(palindrome(i) && palindrome(i*i))
			v.push_back(i*i);
	}
	/*
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	for(int i=1;i<999;i++){
		if(i%10!=0){
			long long p=reverse(i);
			int d=digits(i);
			square_check(p*pow(10,d)+i);
			for(int j=0;j<9;j++){
				square_check(p*pow(10,d+1)+j*pow(10,d)+i);
			}
		}
	}
	sort(v.begin(),v.end());
	*/
}

int main(){
	preprocess();
	int t;
	long long a,b;
	cin>>t;
		
	for(int T=1;T<=t;T++){
		cout<<"Case #"<<T<<": ";
		cin>>a>>b;
		std::vector<long long>::iterator low,up;
		low=lower_bound (v.begin(), v.end(), a); 
  		up= upper_bound (v.begin(), v.end(), b);
		cout<<(up-low)<<endl;

	}
	return 0;
}
		
