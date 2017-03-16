/**
Author: Floris Kint
 **/


#include <cstdio>
#include <bitset>
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

bool cached[2500][50][50];
bool impossible[2500][50][50];
int cache[2500][50][50][2];

vector<int> answer;

bool divide_num(int n, int max_col_height, int max_cols){
	if(n==0)
		return true;
	if(max_col_height <= 0 || max_cols <= 0)
		return false;
	if(cached[n][max_col_height][max_cols]){
		if(impossible[n][max_col_height][max_cols]){
			return false;
		}else{
			int h = cache[n][max_col_height][max_cols][0];
			int w = cache[n][max_col_height][max_cols][1];
			divide_num(n-h*w, h-1, max_cols-w);
			for(int i = 0; i < cache[n][max_col_height][max_cols][1]; ++i){
				answer.push_back(cache[n][max_col_height][max_cols][0]);
			}
			return true;
		}
	}
	cached[n][max_col_height][max_cols]=true;
	/*if(max_cols == 1){
		if(max_col_height >= n && n > 1){
			cache[n][max_col_height][max_cols][0]=n;
			cache[n][max_col_height][max_cols][1]=1;
			answer.push_back(n);
			return true;
		}else{
			impossible[n][max_col_height][max_cols]=true;
			return false;
		}
	}else{*/
		for(int height = max_col_height; height >= 2; --height){
			for(int width = 1; width*height <= n && width <= max_cols; ++width){
				if(divide_num(n-height*width, height-1, max_cols-width)){
					cache[n][max_col_height][max_cols][0]=height;
					cache[n][max_col_height][max_cols][1]=width;
					for(int i = 0; i < width; ++i){
						answer.push_back(height);
					}
					return true;
				}
			}
		}
	//}
	impossible[n][max_col_height][max_cols]=true;
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
		int R, C, M;
		scanf("%d%d%d", &R, &C, &M);
		int X = R*C-M;
		printf("Case #%d:", current_case);
		//output answer
		printf("\n");
		//process
		answer.clear();
		//special cases
		if(X==1){
			printf("c");
			for(int i = 1; i < C; ++i){
				printf("*");
			}
			printf("\n");
			for(int i = 1; i < R; ++i){
				for(int j = 0; j < C; ++j){
					printf("*");
				}
				printf("\n");
			}
		}else if(R==1){
			printf("c");
			for(int i = 1; i < X; ++i){
				printf(".");
			}
			for(int i = X; i < C; ++i){
				printf("*");
			}
			printf("\n");
		}else if(C==1){
			printf("c\n");
			for(int i = 1; i < X; ++i){
				printf(".\n");
			}
			for(int i = X; i < R; ++i){
				printf("*\n");
			}
		}else{
			bool possible = false;
			for(int start_height = min(R, X/2); start_height >= 2; --start_height){
			if(divide_num(X-2*start_height, start_height, C-2)){
				answer.push_back(start_height);
				answer.push_back(start_height);
				for(int r = 0; r < R; ++r){
					for(int c = 0; c < C; ++c){
						if(r == 0 && c == 0){
							printf("c");
						}else{
							if(c>=answer.size()){
								printf("*");
							}else{
								if(answer[answer.size()-1-c]<=r){
									printf("*");
								}else{
									printf(".");
								}
							}
						}
					}
					printf("\n");
				}
				possible = true;
				break;
			}
			}
			if(!possible){
				printf("Impossible\n");
			}
	}



	//cout << endl;
}
return 0;
}
