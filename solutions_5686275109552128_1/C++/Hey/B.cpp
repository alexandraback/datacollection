#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;




int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		//建立放数据的容器
		//建立数据的行列下标索引
		int nonempty;
		scanf("%d", &nonempty);

		vector<int> can;
		for (int i = 0; i < nonempty; i++){
			int temp;
			scanf("%d", &temp);
			can.push_back(temp);
		}
		sort(can.begin(), can.end());
		int maxvalue = can[can.size() - 1];
		int min_minites = maxvalue;
		
		

		for (int i = 2; i <= maxvalue; i++){
			int sum = 0;
			for (int j = 0; j < can.size(); j++){
				if (can[j]>i){
					int temp = ceil((double)can[j] / i);
					sum += (temp - 1);
				}
			}
			if (sum+i<min_minites)
				min_minites = i + sum;
		}
		printf("Case #%d: %d\n", t, min_minites);
	}
}