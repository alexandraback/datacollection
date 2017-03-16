#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define SQR(x) ((x)*(x))
#define LL long long
char buffer[501];
LL X, Y;
bool visited[402][402][101];
bool solve(LL x, LL y, int prof){
	if(ABS(x)>200||ABS(y)>200){
		return false;
	}
	if((x==X)&&(y==Y)){
		buffer[prof]=0;
		return true;
	}else if(prof>=100){
		return false;
	}
	if(visited[x+200][y+200][prof]){
		return false;
	}
	visited[x+200][y+200][prof]=true;
	bool ok=false;
	int step=prof+1;
	if(!ok ){
		buffer[prof]='E';
		ok=solve(x+step, y, step);
	}
	if(!ok ){
		buffer[prof]='W';
		ok=solve(x-step, y, step);
	}
	if(!ok ){
		buffer[prof]='N';
		ok=solve(x, y+step, step);
	}
	if(!ok ){
		buffer[prof]='S';
		ok=solve(x, y-step, step);
	}
	return ok;
}

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>X>>Y;
		memset(visited, 0, sizeof(visited));
		bool ok=solve(0,0,0);
		if(!ok){
			printf("Case #%d: !!\n", c);
		}
		printf("Case #%d: %s\n", c, buffer);
	}
	return 0;
}

