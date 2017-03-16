#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
using namespace std;

#define d_pi 57.2957795
#define LL __int64
#define LarN 100000

int board[4][4] = 
{{0, 1, 2, 3},{1, 0, 3, 2},{2,3,0,1},{3,2,1,0}};
int sigBoard[4][4] =
{{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

int readNum[10005];
int buf[10005];
int sigBuf[10005];
int stepChar[5] = {0,1,3,0,0};
void solve(){
	string read;
	int L;
	LL X;
	cin>>L>>X;
	cin>>read;

	for(int i = 0; i < L; i ++)readNum[i] = read[i] - 'h';

	int preX = 0, preIdx = -1, curX = 1, curIdx;
	int preChar = 0, preSig = 1;
	int step = 1;
	while(curX - preX < 5 && curX <= X){
		curIdx = preIdx + 1;
		for(int i = 0; i < L; i ++){
			if(curIdx >= L){
				curIdx -= L;
				curX ++;
				if(curX > X)break;
			}
			buf[curIdx] = board[preChar][readNum[curIdx]];
			sigBuf[curIdx] = sigBoard[preChar][readNum[curIdx]] * preSig;
			preChar = buf[curIdx];
			preSig = sigBuf[curIdx];
			if(buf[curIdx] == stepChar[step] && sigBuf[curIdx] == 1){
				preIdx = curIdx;
				preX = curX;
				step ++;
				break;
			}
			preIdx = curIdx;
			curIdx ++;
		}
		if(curX - preX >= 5 || curX > X || step == 3)break;
	}
	if(step < 3){
		printf("NO\n");
		return;
	}
	if(preIdx == L -1 && curX == X){
		printf("NO\n");
	}
	preSig = 1;
	preChar = 0;
	for(int i = 0; i < L; i ++){
		buf[i] = board[preChar][readNum[i]];
		sigBuf[i] = sigBoard[preChar][readNum[i]] * preSig;
		preChar = buf[i];
		preSig = sigBuf[i];
	}
	if(preChar == 0 ){
		if(preSig == 1){
			printf("NO\n");
			return;
		}
		if(X%2 == 0){
			printf("NO\n");
			return;
		}
		printf("YES\n");
		return;
	}
	if( X%2 == 1){
		printf("NO\n");
		return;
	}
	X /= 2;
	if( X%2 == 1){
		printf("YES\n");
	}
	else printf("NO\n");
}

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}

int main(){
#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
#endif
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d: ",i_case);
		solve();
	}
	return 0;
}
