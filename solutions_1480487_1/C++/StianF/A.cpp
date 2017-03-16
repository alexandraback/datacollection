#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int t;
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i+1);
		scanf("%d", &n);
		int total = 0;
		int cont[n];
		int last = -1;
		int next_to_last = -1;
		for(int j = 0; j < n; j++){
			scanf("%d", &cont[j]);
			total += cont[j];
		}
		int temp_n = n;	
		int temp_total = total;
		for(int j = 0; j < n; j++){
			double distance = ((double)(total*2)/n)-cont[j];
			if(distance < 0){
				temp_n--;
				temp_total -= cont[j];
			}
		}
		for(int j = 0; j < n; j++){
			double distance = ((double)(temp_total+total)/temp_n)-cont[j];
			if(distance < 0){
				printf("%f ", 0.0);
				continue;	
			}			
			printf("%f ", ((double)100/total) * distance);
		}
		printf("\n");
	}
	return 0;
}
