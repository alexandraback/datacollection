#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> 
#include <cstdlib> 
#include <limits.h> 
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <functional> 
#include <stack>
#include <queue>
using namespace std;

typedef long long LL;

#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57) 
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

#define pb push_back
#define np next_permutation
#define all(a) (a).begin(),(a).end()

bool reached[51][51];

const int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};

bool valid_pt(int x, int y, int r, int c){
	return (x>=0 && y>=0 && x<r && y<c);
}

int main()
{
	int t = read_int();
	for(int cn=1;cn<=t;cn++){
		int r,c,m,i,j;
		cin>>r>>c>>m;
		string s;
		for(i=0;i<m;i++)
			s.pb('*');
		for(;i<(r*c);i++)
			s.pb('.');
		sort(all(s));
		bool poss = false;
		do{
			for(i=0;i<r*c;i++){
				if(s[i]=='.'){
					memset(reached,0,sizeof(reached));
					reached[i/c][i%c] = true;
					queue<int> q;
					q.push(i);
					while(!q.empty()){
						int pos = q.front();
						q.pop();
						if(s[pos]=='*')
							continue;
						bool v = true;
						int px = pos/c, py = pos%c;
						for(j=0;j<8;j++){
							int nx = px + dx[j], ny = py + dy[j];
							if(valid_pt(nx,ny,r,c)){
								if(s[nx*c+ny]!='.'){
									v = false;
									break;
								}
							}
						}
						if(!v)
							continue;
						for(j=0;j<8;j++){
							int nx = px + dx[j], ny = py + dy[j];
							if(valid_pt(nx,ny,r,c) && !reached[nx][ny]){
								q.push(nx*c+ny);
								reached[nx][ny] = true;
							}
						}
					}
					poss = true;
					for(j=0;j<r*c;j++){
						if(s[j]=='.'&&!reached[j/c][j%c]){
							poss = false;
							break;
						}
					}
				}
				if(poss) break;
			}
			if(poss) break;
		}while(next_permutation(all(s)));
		printf("Case #%d:\n",cn);
		if(!poss)
			printf("Impossible\n");
		else{
			s[i] = 'c';
			for(i=0;i<r;i++){
				for( j=0;j<c;j++)
					printf("%c",s[i*c+j]);
				printf("\n");
			}
		}
	}
	return 0;
}




