#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", t);
		int my_x = 0, my_y = 0;
		while(my_x < x){
			printf("WE");
			my_x++;
		}
		while(my_x > x){
			printf("EW");
			my_x--;
		}
		while(my_y < y){
			printf("SN");
			my_y++;
		}
		while(my_y > y){
			printf("NS");
			my_y--;
		}
	
		printf("\n");
	

	}
	return 0;
}
