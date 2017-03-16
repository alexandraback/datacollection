#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

struct game{
	int num;
	int x;
	int y;
	bool marked1;
	bool marked2;
	};

bool cmp1(const game a, const game b){
	if(a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
	};

bool cmp2(const game a, const game b){
	if(a.y == b.y)
		return a.x > b.x;
	return a.y < b.y;
	};
	
game games[1010];
game games_by_1[1010];
game games_by_2[1010];
		
int main(){
	int testnum;
	scanf("%d", &testnum);
	for(int test = 0; test < testnum; test++){
		int n;
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &games[i].x, &games[i].y);
			games[i].num = i;
			games[i].marked1 = false;
			games[i].marked2 = false;
			games_by_1[i] = games[i];
			games_by_2[i] = games_by_1[i];
			}
		
		sort(games_by_1, games_by_1 + n, cmp1);
		sort(games_by_2, games_by_2 + n, cmp2);
		//for(int i = 0; i < n; i++)
	//		cout << games_by_2[i].x << " " <<  games_by_2[i].y << endl;
			
		int medals = 0, two = 0, one = 0, turns = 0, marked_as_two = 0;
		bool success = true;
		for(; marked_as_two < n; ){
			two = -1;
			for(int i = 0; i < n; i++)
				if(!games[games_by_2[i].num].marked1 && games[games_by_2[i].num].y <= medals){
					two = i;
					break;
					}
			if(two == -1)
				for(int i = 0; i < n; i++)
					if(!games[games_by_2[i].num].marked2 && games[games_by_2[i].num].y <= medals){
						two = i;
						break;
						}
			if(two != -1 && !games[games_by_2[two].num].marked2 && games[games_by_2[two].num].y <= medals){
				if(!games[games_by_2[two].num].marked1)
					medals++;
				medals++;
				games[games_by_2[two].num].marked2 = true;
				games[games_by_2[two].num].marked1 = true;
				//cout << games[games_by_2[two].num].x <<  games[games_by_2[two].num].y << endl;
				two++;
				turns++;
				marked_as_two++;
				continue;
				}
			one = -1;
			for(int i = n-1; i >= 0; i--)
				if(!games[games_by_2[i].num].marked1 && games[games_by_2[i].num].x <= medals){
					one = i;
					break;
					}
			if(one != -1 && games[games_by_2[one].num].x <= medals){
				medals++;
				games[games_by_2[one].num].marked1 = true;
				//cout << games[games_by_1[one].num].x <<  games[games_by_1[one].num].y << endl;
				//one++;
				turns++;
				continue;
				}
			success = false;
			break;
			}
		
		if(!success)
			printf("Case #%d: Too Bad\n", test+1);
		else
			printf("Case #%d: %d\n", test + 1, turns);
		}
	return 0;
}
