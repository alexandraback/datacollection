#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;
char s[1001111];
int n,cnt=0;
bool isCon(char ch){
	return ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u';
}
void input(){
	scanf("%s%d",&s,&n);
}
void solve(){
	long long res=0, last=0, has=0;
	int len = strlen(s);
	for(int i=0; i<len; i++){
		if(isCon(s[i])){
			last++;
			if(n<=last){
				//printf("%c\n",s[i]);
				has = max((long long)i-n+2,has);
			}
		}
		else last=0;
		res+= has;
	}
	printf("Case #%d: %I64d\n",++cnt,res);
}
int main ()
{
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A-small-attempt0.out","w", stdout);
	int zz;
	cin>>zz;
	while(zz--){
		input();
		solve();
	}
	return 0;
}

/*
4
2 2
2 1
1 4
1 1 1 1
2 4
2 1 1 6
10 4
25 20 9 100
*/
