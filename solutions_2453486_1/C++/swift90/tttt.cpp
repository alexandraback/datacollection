#include<cstdio>
const int N=4;
char nr[5][10];
int check(char X){
	int ok;
	for(int i=0;i<N;++i){
		ok=1;
		for(int j=0;j<N;++j)
			if(nr[i][j]!=X)
				ok=0;
		if(ok)
			return 1;
	}
	for(int j=0;j<N;++j){
		ok=1;
		for(int i=0;i<N;++i)
			if(nr[i][j]!=X)
				ok=0;
		if(ok)
			return 1;
	}
	ok=1;
	for(int i=0;i<N;++i)
		if(nr[i][i]!=X)
			ok=0;
	if(ok)
		return 1;
	ok=1;
	for(int i=0;i<N;++i)
		if(nr[i][N-i-1]!=X)
			ok=0;
	return ok;
}
void solve(int test){
	int i,j;
	int xt,yt;
	xt=yt=4;
	int cnt=0;
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			if(nr[i][j]=='T'){
				xt=i;
				yt=j;
			}
			if(nr[i][j]=='.')
				++cnt;
		}
	}
	nr[xt][yt]='X';
	if(check('X')){
		printf("Case #%d: X won\n",test);
		return;
	}
	nr[xt][yt]='O';
	if(check('O')){
		printf("Case #%d: O won\n",test);
		return;
	}
	if(!cnt){
		printf("Case #%d: Draw\n",test);
		return;
	}
	printf("Case #%d: Game has not completed\n",test);
}
int main(){
	freopen("ttt.in","r",stdin);
	freopen("ttt.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		fgets(nr[0],10,stdin);
		for(int i=0;i<N;++i)
			fgets(nr[i],10,stdin);
		solve(test);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
