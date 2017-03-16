#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
double chance[10001][10003];
double precalc(){
	for(int i = 1; i < 10001; ++i){
		for(int j = 0; j < 10003; ++j){
			if(j == 0){
				chance[i][j]=chance[i-1][j]+1.0/2.0*(1.0-chance[i-1][j]);
			}else{
				chance[i][j]=chance[i-1][j]+1.0/2.0*(1.0-chance[i-1][j])*chance[i-1][j-1];
			}
		}
	}
}
double calculate(int height, int diamonds){
	if(height>=diamonds){
		return 0;
	}
	return chance[diamonds][height];
}
int main(){
	precalc();
	int T;
	scanf("%d", &T);
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		int N, X, Y;
		scanf("%d%d%d", &N, &X, &Y);
		int certain_triangle_bottom_size = 1;
		int current_step = 5;
		int current_size = 1;
		int xstart = 0;
		while(current_size + current_step <= N){
			current_size += current_step;
			current_step += 4;
			certain_triangle_bottom_size += 2;
			xstart -= 2;
		}
		//if coordinates inside triangle -> 1
		xstart -= 2;
		double result=0.5;
		if(Y<X-xstart && Y<-X-xstart){
			result = 1.0;
		}
		//if coordinates outside triangle + new border -> 0
		else if(Y==X-xstart || Y==-X-xstart){
			int diamonds_to_fall = N-current_size;
			int top = -xstart;
			if(X==0&&Y==top){
				result = 0.0;	
			}else if(diamonds_to_fall > top){
				if(Y < diamonds_to_fall-top){
					result=1.0;
				}else{
					result = calculate(Y-(diamonds_to_fall-top), diamonds_to_fall-2*(diamonds_to_fall - top));
				}
			}else{
				if(Y>=diamonds_to_fall){
					result = 0.0;
				}else{
					result = calculate(Y, diamonds_to_fall);
				}
			}
		}
		//if coordinates on new border of triangle -> calculate
		else{
			result = 0.0;
		}
		printf("Case #%d: %.6lf\n", curr_case, result);
	}
    return 0;
}
