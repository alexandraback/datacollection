#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int _main(){
	int N;
	int a[1001],b[1001];
	int finish[1001];
	fin>>N;
	int i, j, k;
	for(i = 0; i<N; i++){
		fin>>a[i]>>b[i];
	}
	for(i = 0; i<N; i++) finish[i] = 0;
	
	int star = 0;
	int count = 0;
	int done = 0;
	bool update = false;
	while(1){
		update = false;
		if(done == N) return count;
		
		//2
		for(i = 0; i<N; i++){
			if(b[i] <= star && finish[i] == 0){
				//do this
				//fout<<"2 for "<<i<<endl;
				finish[i] = 2;
				star += 2;
				count ++;
				done ++;
				update = true;
				break;
			}
		}
		if(update) continue;
		
		//2-1
		for(i = 0; i<N; i++){
			if((b[i] <= star && finish[i] == 1))
			{
				//fout<<"2-1 for "<<i<<endl;
				finish[i] = 2;
				star += 1;
				count ++;
				done ++;
				update = true;
				break;
			}
		}
		if(update) continue;
		
		//1
		int index = -1,best = 0;
		for(i = 0; i<N; i++){
			if((a[i] <= star && finish[i] == 0))
			{
				if(b[i] - star > best){
					best = b[i] - star;
					index = i;
				};
				/*
				//fout<<"1 for "<<i<<endl;
				finish[i] = 1;
				star += 1;
				count ++;
				//done ++;
				update = true;
				break;
				*/
			}
		}
		if(index != -1){
			i = index;
			finish[i] = 1;
			star += 1;
			count ++;
			//done ++;
			update = true;
		}
		if(update) continue;
		
		if(!update) return -1;
	}
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing";
			int ans = _main();
			if(ans >= 0) fout<<ans;
			else if(ans == -1) fout<<"Too Bad";
			else cout<<"error!";
            fout<<endl;
    }
}
