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

#define PI atan2(0,-1)

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
		//process
        unsigned long long winning = 0;
        for(int a = 0; a < A; ++a){
            for(int b = 0; b < B; ++b){
                if((a&b)<K){
                    ++winning;
                }
            }
        }





		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";

        printf(" %llu", winning);


		//output answer
		printf("\n");
		//cout << endl;
	}
    return 0;
}
