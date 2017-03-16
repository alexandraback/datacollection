#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<utility>

using namespace std;

#define PB push_back
#define LE length()
#define SZ size()
#define MP make_pair
#define X first
#define Y second

int N, M, K;

bool A[20][20];
char V[20][20];

int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};

int countbits(int a){
	int r = 0;
	while(a){
		r += (a&1);
		a>>=1;
	}
	return r;
}

bool valid(int a){
	int r = 0;
	for(int i=0;i<N;i++){
		for(int j = 0; j < M; j++){
			A[i][j] = (a&(1<<(i*M + j)))>0;
			if(A[i][j]){ r++; V[i][j] = 1;}
			else V[i][j] = 0;
			//cout<<A[i][j]<<" ";			
		}//cout<<endl;
	}
	if(r > K) return false;
	//cout<<"NO FALSE"<<endl;
	for(int i = 0; i < N; i++){
		for(int j=0;j<M;j++){
			if(V[i][j]==1) continue;
			bool ok = true;
			vector<int> bfs; bfs.PB(i); bfs.PB(j); 
			V[i][j] = 1;
			int p = 0, t = 2, ai, aj, nx , ny;
			while(p < t){
				ai = bfs[p++]; aj = bfs[p++];
				//cout<<"E "<<ai<<" "<<aj<<endl;
				if(ai == 0 || ai+1 == N || aj == 0 || aj+1 == M){ok=false;}
				for(int q = 0; q <4;q++){
					nx = ai + mx[q];
					ny = aj + my[q];
					if(nx >= 0 && nx < N && ny >= 0 && ny < M && V[nx][ny]==0){
						V[nx][ny] = 1;
						bfs.PB(nx); bfs.PB(ny); t+= 2;
					}
				}
			}
			//cout<<i<<" "<<j<<" "<<ok<<" "<<t<<endl;
			if(ok) r+= (t/2);
			//for(int q=0; q <N; q++) for(int p=0;p<M;p++) if(V[q][p] == 2) V[q][p] = 0;
		}
	}
	//cout<<"R: "<<r<<endl;
	return r==K;
}

int main(){
	int kases; cin>>kases;
	for(int kase = 1; kase <= kases;kase++){
		cin>>N>>M>>K;
		int p = 1<<(N*M);
		int res = 100000000;
		//int i = (1<<18)|(1<<17)|(1<<14)|(1<<11)|(1<<8)|(1<<7);
		for(int i = 0; i < p; i++){ //cout<<i<<endl;
			if(valid(i)){
				res = min(res, countbits(i));
			}
		}
		cout<<"Case #"<<kase<<": "<<res<<endl;
	}
}
