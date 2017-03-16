#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
	int R,N,M,K;
	int product[20];
	int i,j,k;
	int digit[20];
	int possible[5000];
	int count;
	
	fin>>R>>N>>M>>K;
	for(int line=0;line<R;line++){
            cout<<line<<endl;
		for(i=0; i<K; i++) fin>>product[i];
		
		bool contain[10];
		for(i=0; i<K; i++) for(j=2;j<=8;j++){
			if(product[i]%j == 0) contain[j] = true;
			else contain[j] = false;
		}
		int Max=1000;
		for(int attempt = 0; attempt < Max; attempt ++){
			int start = 0;
			if(contain[7]) digit[start++] = 7;
			if(contain[5]) digit[start++] = 5;
			for(i=start; i<N; i++) digit[i]=(rand()%(M-1)) + 2;
			bool has[10];
			int all = 1;
			for(i=0; i<N; i++) all *= digit[i];
			for(j=2;j<=8;j++){
				if(all%j == 0) has[j] = true;
				else has[j] = false;
			}
			bool reasonable = true;
			for(j=2;j<=8;j++){
				if(contain[j] && !has[j])
					reasonable = false;
			}
			if(!reasonable) continue;
			count = 0;
			for(j=0;j<(1<<N);j++){
				int p = 1;
				for(k=0;k<N;k++){
					if(j & (1<<k)) p*=digit[k];
				}
				possible[count++] = p;
			}
			bool all_good = true;
			for(i=0; i<K; i++){
				bool good = false;
				for(j=0; j<count; j++) if(possible[j]==product[i]) {
					good = true;
					break;
				}
				if(!good){
					all_good = false;
					break;
				}
			}
			if(all_good) break;
		}
		for(i=0; i<N; i++) fout<<digit[i];
		fout<<endl;
	}
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":"<<endl;
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
