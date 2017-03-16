#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

#define MAXN 1020
#define X 2
#define BUCO 1

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
int matrix[MAXN][MAXN];
int T, N, M, K;
int coperti, usati;
bool fatti[MAXN][MAXN];

void Espandi(int r, int c) {
	//cout<<"Espando da "<<r<<" "<<c<<endl;
	//cout<<"Coperti: "<<coperti<<" Usati: "<<usati<<endl;
	coperti++;
	fatti[r][c]=true;
	for(int i=0; i < 4; i++) {
		int nr = r + dr[i], nc=c+dc[i];
		if(nr < 0 || nr > N || nc < 0 || nc > M) continue;
		if(matrix[nr][nc] == 0) { matrix[nr][nc] = X; usati++; }
		else if(matrix[nr][nc] == X);
		else if(!fatti[nr][nc])Espandi(nr, nc);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
    //ofstream out("output.txt");
	cin >> T;
	for(int i=0; i < T; i++) {
		cin >> N >> M >> K;
		//cout<<"Caso "<<i+1<<endl;
		memset(matrix, 0, sizeof(matrix));
		int mass = (N-1) * (M-1);
		int sol = K, tmp=K;
		int partiriga = 1, particolonna=1;
		for(int j=1; j <= mass; j++) {
			//cout<<"J: "<<j<<endl;
			memset(fatti, false, sizeof(fatti));
			//cout<<"Riga: "<<partiriga<<" Colonna: "<<particolonna<<endl;
			
			coperti=usati=tmp=0;
			matrix[partiriga][particolonna] = BUCO;
			Espandi(partiriga, particolonna);
			//cout<<"C: "<<coperti<<" U: "<<usati<<endl;
			if((coperti+usati) < K) tmp =K;
			else tmp=usati;
			if(tmp < sol) sol=tmp;
			//else if(tmp > sol) break;
			particolonna++;
			if(particolonna >= M) { partiriga++; particolonna=1; }
			if(partiriga >= N) break;
			//cout<<"Con "<<j<<" buchi: "<<tmp<<endl;
			for(int k=0; k <= N; k++) 
				for(int h=0; h <= M; h++) if(matrix[k][h] != BUCO) matrix[k][h]=0;
		}
		cout<<"Case #"<<i+1<<": "<<sol<<endl;
	}
	return 0;
}
