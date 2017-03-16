#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;
int K,N;
int type[205];	//type for each chest
int num[205];	//keys for each chest
int contain[205][405];	//keys in chests
//vector<int> keys;	//keys in hand
int keystack[205];	//keys in hand
bool unopen[205];
int remain;
vector<int> sequence;
int have[205],need[205];

bool try_open(int index){
	//do open
	sequence.push_back(index);
	remain -= 1;
	if(remain == 0) return true;
	unopen[index] = false;
	keystack[type[index]] -= 1;
	for(int i=0;i<num[index];i++) keystack[contain[index][i]] += 1;
	have[type[index]]-=1;
	need[type[index]]-=1;
	//check possible
	for(int i=0;i<N;i++){
		if(unopen[i] && keystack[type[i]]==0){
			for(int j=0;j<num[i];j++) have[contain[i][j]] -= 1;
			bool possible=true;
			if(have[type[i]]==0) possible=false;
			for(int j=0;j<num[i];j++) have[contain[i][j]] += 1;
			if(!possible){	//undo
				sequence.pop_back();
				remain += 1;
				unopen[index] = true;
				keystack[type[index]] += 1;
				for(int i=0;i<num[index];i++) keystack[contain[index][i]] -= 1;
				have[type[index]]+=1;
				need[type[index]]+=1;
				return false;
			}
		}
	}
	//recursion
	for(int i=0;i<N;i++){
		if(unopen[i] && keystack[type[i]]>0){
			if(try_open(i)){
				return true;
			}
		}
	}
	//undo
	sequence.pop_back();
	remain += 1;
	unopen[index] = true;
	keystack[type[index]] += 1;
	for(int i=0;i<num[index];i++) keystack[contain[index][i]] -= 1;
	have[type[index]]+=1;
	need[type[index]]+=1;
	return false;
}

void _main(){
	int i,j,k;
	int temp;
	
	fin>>K>>N;
	//fout<<"\t"<<K<<" "<<N<<endl<<"\t\t\t";
	//keys.clear();
	sequence.clear();
	for(i=0;i<N;i++) unopen[i]=true;
	for(i=0;i<=200;i++){
		keystack[i]=0;
		have[i]=0;
		need[i]=0;
	}
	remain=N;
	//read
	for(i=0;i<K;i++){
		fin>>temp;
		//keys.push_back(temp);
		keystack[temp]+=1;
		have[temp]+=1;
	}
	for(i=0;i<N;i++){
		fin>>type[i]>>num[i];
		need[type[i]]+=1;
		for(j=0;j<num[i];j++){
			fin>>contain[i][j];
			have[contain[i][j]]+=1;
		}
	}
	//check
	bool possible=true;
	for(i=0;i<=200;i++){
		if(have[i]<need[i]){
			possible=false;
			break;
		}
	}
	if(!possible){
		fout<<" IMPOSSIBLE";
		return;
	}
	//recursion
	for(i=0;i<N;i++){
		if(unopen[i] && keystack[type[i]]>0){
			if(try_open(i)){
				for(j=0;j<sequence.size();j++) fout<<" "<<sequence[j]+1;
				return;
			}
		}
	}
	fout<<" IMPOSSIBLE";
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
