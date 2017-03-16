
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


#define FOR(i,n) for(int i=0; i<n;++i)


char mp[110][110];

int R,C,M;

void out()
{
	mp[R-1][C-1]='c';
	FOR(i,R)mp[i][C]=0;
	FOR(i,R)puts(mp[i]);
}

bool consume()
{
    if(M){
        --M;
        return true;    
    }    
    return false;
}

int main()
{
	int T,cs=0;
	cin>>T;
	while(++cs <= T){
		cin>>R>>C>>M;

		printf("Case #%d:\n",cs);

		if(M+1 == R*C || R==1 || C==1){
			FOR(i,R)FOR(j,C) mp[i][j] = consume() ? '*' : '.';
			out();
			continue;
		}
		
		FOR(i,R)FOR(j,C)mp[i][j]='.';
		FOR(i,R-2)FOR(j,C-2) if(consume())mp[i][j] ='*';

        if(M%2 || M > 2*(R+C-4)){
            puts("Impossible");
            continue;
        }		

        FOR(i,R-2)FOR(j,2) if(consume()) mp[i][C-2+j] = '*';
        FOR(j,C-2)FOR(i,2) if(consume()) mp[R-2+i][j] = '*';
 
        out();
	}
	
	return 0;	
}
