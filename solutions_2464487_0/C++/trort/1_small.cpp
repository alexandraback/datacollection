#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
	__int64 r,t;
	fin>>r>>t;
	__int64 min=0,max=200000;
	__int64 sum=0;
	__int64 sum_min = (2*r + 2*min + 1)*(min+1);
	__int64 sum_max = (2*r + 2*max + 1)*(max+1);
	while(max-min>1){
		__int64 mid = (min+max)/2;
		__int64 sum_mid = (2*r + 2*mid + 1)*(mid+1);
		//fout<<endl<<mid<<" "<<sum_mid;
		if(sum_mid<t) min = mid;
		else if(sum_mid>t) max = mid;
		else if(sum_mid == t){
            fout<<mid+1;
			return;
		}
	}
	fout<<min+1;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
