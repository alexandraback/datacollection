#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define NOL 100
int tc,t,x,y,p;
char lol[303];
int main(){
	scanf("%d",&t);		
	for (tc = 1; tc <=t; ++tc){
		scanf("%d %d",&x,&y);
		if (abs(x) <= abs(y)){
			//int maks = abs(x);
			lol[abs(x)] = (x>0)?'E':'W';
			p = 1;
			for (int i = 0; i < abs(y); ++i){
				if (p == abs(x)){
					++p;
					if (y >0){
						lol[p+1] = 'N';
						lol[p] = 'S';
					}
					else{
						lol[p+1] = 'S';
						lol[p] = 'N';
					}
					p+=2;
				}
				else if (p+1 == abs(x)){
					++i;
					if (y >0){
						lol[p+2] = 'N';
						lol[p] = 'S';
					}
					else{
						lol[p+2] = 'S';
						lol[p] = 'N';
					}
					p+=3;
				}
				else{
					if (y >0){
						lol[p+1] = 'N';
						lol[p] = 'S';
					}
					else{
						lol[p+1] = 'S';
						lol[p] = 'N';
					}
					p+=2;
				}
			}
		}
		else{
			lol[abs(y)] = (y>0)?'N':'S';
			p = 1;
			for (int i = 0; i < abs(x); ++i){
				if (p == abs(y)){
					++p;
					if (x >0){
						lol[p+1] = 'E';
						lol[p] = 'W';
					}
					else{
						lol[p+1] = 'W';
						lol[p] = 'E';
					}
					p+=2;
				}
				else if (p+1 == abs(y)){
					++i;
					if (x >0){
						lol[p+2] = 'E';
						lol[p] = 'W';
					}
					else{
						lol[p+2] = 'W';
						lol[p] = 'E';
					}
					p+=3;
				}
				else{
					if (x >0){
						lol[p+1] = 'E';
						lol[p] = 'W';
					}
					else{
						lol[p+1] = 'W';
						lol[p] = 'E';
					}
					p+=2;
				}
			}
		}
		printf("Case #%d: ",tc);
		for (int i = 1; i < p; ++i){
			printf("%c",lol[i]);
		}
		puts("");
	}


}