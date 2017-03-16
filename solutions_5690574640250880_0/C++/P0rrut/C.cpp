#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int R,C,M,T,N;
char tab[60][60];
void fillA(){
	for(int i2=0;i2<R;i2++)
		for(int j2=0;j2<C;j2++)
			if(tab[i2][j2]==0)
				tab[i2][j2]='*';
}
void fill1(){
	tab[0][0]='c';
	if(R==1 && N!=1){
		for(int j=1;j<N;j++) tab[0][j]='.';
		for(int j=N;j<C;j++) tab[0][j]='*';
	}
	else if(N!=1){
		for(int j=1;j<N;j++) tab[j][0]='.';
		for(int j=N;j<R;j++) tab[j][0]='*';
	}
}

void fillP(){
	int i=0;int j=2;
	N-=4;
	tab[0][0]='c';
	tab[1][0]=tab[1][1]=tab[0][1]='.';
	
	if(C==2) i=2,j=0;
	while(N){
		if(!j)
			tab[i][j]=tab[i][j+1]='.';
		
		else if(j==1)
			tab[i+1][j-1]=tab[i+1][j]='.';

		else
			tab[i][j]=tab[i+1][j]='.';
			
		j++;	
		N-=2;

		if(j==C) j=0,i+=2;
		if(i>=R-1) break;
	}
	if(i>=R-1 && N){
		while(N){
			tab[i][j++]='.';
			N--;
		}
	}
}

void fillI(){
	int i=0;int j=3;
	N-=9;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			tab[i][j]='.';
	tab[1][1]='c';
	while(N>0 && j<C){
		tab[i][j]=tab[i+1][j]='.';
		N-=2;
		j++;
	}
	i+=2;
	j=3;
	while(N>0 && j+1<C) tab[i][j]=tab[i][j+1]='.',N-=2,j+=2;
	bool modo = true;
	if(j==C-1) modo = false;
	i++;
	j=0;
	if(modo){
		while(N && i<R-1){
			if(!j)
				tab[i][j]=tab[i][j+1]='.';
		
			else if(j==1)
				tab[i+1][j-1]=tab[i+1][j]='.';
	
			else
				tab[i][j]=tab[i+1][j]='.';
				
			j++;	
			N-=2;

			if(j==C) j=0,i+=2;
			if(i>=R-1) break;
		}
		if(i>=R-1 && N){
			while(N){
				tab[i][j++]='.';
				N--;
			}
		}

	}
	else{
		while(N && i<R-1){
			if(!j)
				tab[i][j]=tab[i][j+1]='.';
		
			else if(j==1)
				tab[i+1][j-1]=tab[i+1][j]='.';
			else if(j==2)
				tab[i][j]=tab[i-1][C-1]='.';
			else
				tab[i][j]=tab[i+1][j-1]='.';
				
			j++;	
			N-=2;

			if(j==C) j=0,i+=2;
			if(i>=R-1) break;
		}
		if(i>=R-1 && N){
			if(N==1)
				tab[i-1][C-1]='.',N--;
			else{
				tab[i][0]=tab[i][1]='.';
				N-=2;
				if(N) tab[i-1][C-1]='.',N--;
			}
			j=2;
			while(N){
				tab[i][j++]='.';
				N--;
			}
		}
	}


}

void pTab(){
	for(int j=0;j<R;j++)
			cout << tab[j] << endl;
}

int main(){
	cin >> T;
	for(int i=0;i<T;i++){
		cout << "Case #" << i+1 << ": "<<endl;
		cin >> R >> C >> M;
		memset(tab,0,sizeof tab);
		N = R*C - M;
		if(R==1 || C==1 || N==1) fill1();
		else if(2==N || 3==N || 5==N || 7==N || (N%2==1 && (R==2 || C==2))) {cout << "Impossible" << endl;continue;}
		else if(N%2==0) fillP();
		else fillI();
		fillA();
		pTab();	
	}


	return 0;
}
