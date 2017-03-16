//#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

ifstream cin("C-small-attempt0.in");
ofstream cout("mik.txt");

int rev(int i){
	int rev=0;
	int reminder;
	while(i!=0){
		reminder=i%10;
		rev=rev*10+reminder;
		i=i/10;
	}
	return rev;
}

bool pal(int i){
	int r=rev(i);
	return !(i-r);
}

int main(){
	int T; cin>>T;
	vector<int> fs;
	for(int i=1;i<=10000000;i++){
		if(pal(i) && pal(i*i)) fs.push_back(i*i);
	}
	for(int t=1;t<=T;t++){
		int A,B;
		cin>>A>>B;
		int cnt=0;
		for(int i=0;i<fs.size();i++){
			if(fs[i]>=A && fs[i]<=B) cnt++;
		}
		cout<<"Case #"<<t<<": "<<cnt<<endl;
	}
}