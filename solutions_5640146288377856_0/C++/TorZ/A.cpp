#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10000000

//freopen("A.in", "r", stdin);
//freopen("A.out", "w", stdout);

int GetCnt(){
	int tcnt;scanf("%d",&tcnt);
	return tcnt;
}
int main(int argc,char **argv){

	int cnt=GetCnt();
	int rnum,cnum,wnum;
	for(int ncnt=1;ncnt<=cnt;ncnt++){
		scanf("%d %d %d",&rnum,&cnum,&wnum);
		int mnum=int(cnum/wnum);int nx=0;
		if(cnum%wnum==0){nx=1;}
		int res_num=wnum+rnum*mnum-nx;
		printf("Case #%d: %d\n",ncnt,res_num); 
	}
} 
