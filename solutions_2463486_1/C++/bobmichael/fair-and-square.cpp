//#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

ifstream cin("C-large-1.in");
ofstream cout("mik.txt");

long long rev(long long i){
	long long rev=0;
	long long reminder;
	while(i!=0){
		reminder=i%10;
		rev=rev*10+reminder;
		i=i/10;
	}
	return rev;
}

bool pal(long long i){
	long long r=rev(i);
	return !(i-r);
}

int main(){
	long long T; cin>>T;
	vector<long long> fs;
	for(long long i=1;i<=10000000;i++){
		if(pal(i) && pal(i*i)) fs.push_back(i*i);
	}
	for(long long t=1;t<=T;t++){
		long long A,B;
		cin>>A>>B;
		long long cnt=0;
		for(long long i=0;i<fs.size();i++){
			if(fs[i]>=A && fs[i]<=B) cnt++;
		}
		cout<<"Case #"<<t<<": "<<cnt<<endl;
	}
}