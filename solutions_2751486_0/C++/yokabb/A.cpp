
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

int vowels(char a){
	if(a=='a' || a=='e'|| a=='i' || a=='o' || a=='u'){
		return 1;
	}
	return 0;
}

bool solve(){
	string str;
	int n;
	cin>> str>> n;
	
	int m = str.size();
	vector<int> a(m,1);
	for(int i=0;i<m;i++){
		if(vowels(str[i])){
			a[i]--;
		}
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=i;j<m;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				if(a[k]){
					cnt++;
				}else{
					cnt=0;
				}
				if(cnt>=n){
					ans++;
					break;		//Ç±ÇÍÇ©Åc
				}
			}
		}
	}
	
	cout<< ans<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		cout<<"Case #"<< i+1<< ": ";
		solve();
	}
	
	return 0;
}

 