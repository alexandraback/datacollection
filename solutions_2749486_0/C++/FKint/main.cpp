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
#include <bitset>


using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		int X, Y;
		scanf("%d%d", &X, &Y);		
		printf("Case #%d: ", curr_case);
		if(X<0){
			for(int i = 0; i < -X; ++i){
				printf("EW");
			}
		}else if(X > 0){
			for(int i = 0; i < X; ++i){
				printf("WE");
			}
		}
		if(Y<0){
			for(int i = 0; i < -Y; ++i){
				printf("NS");
			}
		}else if( Y >0){
			for(int i= 0; i < Y; ++i){
				printf("SN");
			}
		}
		printf("\n");
	}
    return 0;
}
