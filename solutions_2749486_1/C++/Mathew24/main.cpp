#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b) for(int a=0; a<b; a++)
#define ABS(a) ((a)<0 ? (-(a)) : (a))

using namespace std;

vector < char > solution;

int tryN(int n, int x, int y){
	solution.resize(0);
	while (n>0){
		if(ABS(x) > ABS(y)){
			if(x>0){
				x-=n;
				solution.push_back('E');
			}else{
				x+=n;
				solution.push_back('W');
			}
		}else{
			if(y>0){
				y-=n;
				solution.push_back('N');
			}else{
				y+=n;
				solution.push_back('S');
			}
		}
		n--;
	}
	
	return x==0 && y==0;
}

int Len(int n, int x, int y){
	return tryN(n, x,y) || tryN(n-2, x,y);
}

void solveCase(){
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	
	int lowB=0;
	int upB=1;
	
	while(!Len(upB, x ,y))
		upB*=2;
	
	while (upB-lowB>4){
		if(Len((upB+lowB)/2, x ,y))
			upB=(upB+lowB)/2;
		else
			lowB=(upB+lowB)/2;
	}
	
	int min=10000000;
	for(int i = lowB-2; i<upB+2; i++)
		if(tryN(i, x, y)){
			min=i;
			break;
		}
	
	FOR(i, solution.size())
		printf("%c", solution[solution.size()-i-1]);
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(i,T){
		printf("Case #%d: ", i+1);
		solveCase();
		printf("\n");
	}
}
