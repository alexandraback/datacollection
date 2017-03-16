//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x)((x)*(x))
#define clr(x)memset(x,0,sizeof(x))
#define clr1(x)memset(x,-1,sizeof(x))
#define clr80(x)memset(x,0x80,sizeof(x))
#define clr7F(x)memset(x,0x7F,sizeof(x))

#define ll long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int,int>
#define pip pair<int,pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>inline bool chkmin(T&a,T&b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T&a,T&b){return a<b?a=b,1:0;}
#define modadd(a,b,c)(((a)+(b))%(c))
#define modmul(a,b,c)((int)(((ll)(a)*(b))%(c)))

#define P 1000000007

char str[5][5];

void run(){
	static char x[10];
	gets(str[0]);
	gets(str[1]);
	gets(str[2]);
	gets(str[3]);
	gets(x);
	bool v=0;
	for(int i=-1;++i!=4;){
		int flag=0,q=0;
		for(int j=-1;++j!=4;){
			if(str[i][j]=='.')v=1;
			if(str[i][j]=='X')flag++;
			else if(str[i][j]=='O')flag--;
			else if(str[i][j]=='T')q++;
		}if(flag==4||flag==-4||q==1&&(flag==3||flag==-3)){
			if(flag>0){
				puts("X won");
				return;
			}
			else{
				puts("O won");
				return;
			}
		}
	}
	for(int j=-1;++j!=4;){
		int flag=0,q=0;
		for(int i=-1;++i!=4;){
			if(str[i][j]=='X')flag++;
			else if(str[i][j]=='O')flag--;
			else if(str[i][j]=='T')q++;
		}if(flag==4||flag==-4||q==1&&(flag==3||flag==-3)){
			if(flag>0){
				puts("X won");
				return;
			}
			else{
				puts("O won");
				return;
			}
		}
	}
	int flag=0,q=0;
	for(int i=-1;++i!=4;){
		if(str[i][i]=='X')flag++;
		else if(str[i][i]=='O')flag--;
		else if(str[i][i]=='T')q++;
	}if(flag==4||flag==-4||q==1&&(flag==3||flag==-3)){
		if(flag>0){
			puts("X won");
			return;
		}
		else{
			puts("O won");
			return;
		}
	}
	flag=0,q=0;
	for(int i=-1;++i!=4;){
		if(str[3-i][i]=='X')flag++;
		else if(str[3-i][i]=='O')flag--;
		else if(str[3-i][i]=='T')q++;
	}if(flag==4||flag==-4||q==1&&(flag==3||flag==-3)){
		if(flag>0){
			puts("X won");
			return;
		}
		else{
			puts("O won");
			return;
		}
	}if(v)puts("Game has not completed");
	else puts("Draw");
}

int main(){
	int t;
	scanf("%d\n",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		run();
	}
	return 0;
}
