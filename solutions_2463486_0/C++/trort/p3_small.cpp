#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>
#include<sstream>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;
vector<__int64> nums;

bool invb(__int64 x){
	stringstream ss;
	ss<<x;
	string a = ss.str();
	int n = a.size();
	bool good = true;
	for(int i = 0; i<(n+1)/2; i++){
		if(a[i]!=a[n-1-i]){
			good = false;
			break;
		}
	}
	return good;
}

void prepare(){
	__int64 a,b;
	nums.clear();
    for(int i=1;i<10;i++){
        a = i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++){
        a = i*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++){
        a = i*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++){
        a = i*1000 + j*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++){
        a = i*10000 + j*1000 + k*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++){
        a = i*100000 + j*10000 + k*1000 + k*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) for(int l=0;l<10;l++){
        a = i*1000000 + j*100000 + k*10000 + l*1000 + k*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
	for(int i=1;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) for(int l=0;l<10;l++){
        a = i*10000000 + j*1000000 + k*100000 + l*10000 + l*1000 + k*100 + j*10 + i;
		b = a * a;
		if(invb(b)) nums.push_back(b);
    }
}

int _main(){
	__int64 A,B;
	fin>>A>>B;
	int count = 0;
	for(int i=0;i<nums.size();i++){
		if(A<=nums[i] && nums[i]<=B) count ++;
	}
	return count;
}

int main(){
	prepare();
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout<<_main();
            fout<<endl;
    }
}
