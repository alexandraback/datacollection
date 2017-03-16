#include<vector>
#include<fstream>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

ifstream ifs("A-small-attempt0.in");
ofstream ofs("output.out");

long long gcd(long long p, long long q){
	if(q == 0)return p;
	return gcd(q, p%q);
}
bool isJe(long long num){
	long long tmp = 2;
	for(int i = 0; i<40; i++){
		if(tmp == num)return true;
		tmp *= 2;
	}
	return false;
}
void main(){
	

	int numC = 0;
	ifs>>numC;

	
	
	for(int c = 0; c<numC; c++){
		string S;
		ifs>>S;

		int i = S.size()-1;
		long long l = 0, r = 0,digits = 1;
		
		while(S[i] != '/'){
			r += (long long)((int)S[i]-48)*digits;
			digits *= (long long)10;
			i--;
		}
		i--;
		digits = 1;
		while(i >= 0){
			l += (long long)((int)S[i]-48)*digits;
			digits *= (long long)10;
			i--;
		}
		bool hasAns = false;
		long long g = gcd(l, r);
		l = l/g, r = r/g;

		if(isJe(r))hasAns = true;
		ofs<<"Case #"<<c+1<<": ";
		if(hasAns){
			int cnt = 0;
			while(l < r){
				l*=(long long)2;
				cnt++;
			}
			ofs<<cnt<<endl;
		}else{
			ofs<<"impossible"<<endl;
		}
		
		
	}
	system("pause");
}