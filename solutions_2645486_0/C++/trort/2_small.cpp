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

int E,R,N;
int v[11];

int get_max(int start,int remain){
	int max = 0;
	for(int i=0;i<=remain;i++){
		int new_remain = remain-i+R;
		if(new_remain>E) new_remain = E;
		int gain = i*v[start];
		if(start+1<N) gain += get_max(start+1,new_remain);
		if(gain>max){
			//fout<<start<<" "<<i<<endl;
			max = gain;
		}
	}
	return max;
}

void _main(){
	fin>>E>>R>>N;
	int i,j,k;
	for(i=0;i<N;i++) fin>>v[i];
	
	fout<<get_max(0,E);
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
