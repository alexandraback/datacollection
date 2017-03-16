#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>

#define FI first
#define SE second
#define MP make_pair

using namespace std;

char a[6][6];
int tnum;

char winner(){
	map<char,int> mp;
	for (int i=0; i<4; i++){
		mp['X']=mp['O']=mp['T']=0;
		for (int j=0; j<4; j++) if (a[i][j]!='.') mp[a[i][j]]++;
		if (mp['X']+mp['T']==4) return 'X';
		if (mp['O']+mp['T']==4) return 'O';
		
		mp['X']=mp['O']=mp['T']=0;
		for (int j=0; j<4; j++) if (a[j][i]!='.') mp[a[j][i]]++;
		if (mp['X']+mp['T']==4) return 'X';
		if (mp['O']+mp['T']==4) return 'O';
	}
	
	mp['X']=mp['O']=mp['T']=0;	
	for (int i=0; i<4; i++) if (a[i][i]!='.') mp[a[i][i]]++;
	
	if (mp['X']+mp['T']==4) return 'X';
	if (mp['O']+mp['T']==4) return 'O';	
	
	
	mp['X']=mp['O']=mp['T']=0;	
	for (int i=0; i<4; i++) if (a[i][3-i]!='.') mp[a[i][3-i]]++;
	
	if (mp['X']+mp['T']==4) return 'X';
	if (mp['O']+mp['T']==4) return 'O';		
	
	return 0;
}

int main(){
	scanf("%d", &tnum);
	for (int t=1; t<=tnum; t++){
		for (int i=0; i<4; i++) scanf("%s", a[i]);
		
		int ans=0;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++){
				if (a[i][j]=='.') ans=-1;
			}
			
		printf("Case #%d: ",t);
		
		char win = winner();
		if (win){
			printf("%c won\n",win);
		}
		else
			if (ans==0) printf("Draw\n");
			else
				printf("Game has not completed\n");
	}
	return 0;
}
