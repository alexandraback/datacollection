#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <set>
using namespace std;
int n;
string a;
int arr[27];
int no[10];

int g(char a){
	return (int)a - 65;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("alarge.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		memset(arr, 0, sizeof(arr));
		memset(no, 0, sizeof(no));
		cin >> a;
		for (int j = 0; j < a.length(); j++){
			arr[(int)a[j] - 65] += 1;
		}
		
		no[0] = arr[g('Z')];
		no[2] = arr[g('W')];
		no[8] = arr[g('G')];
		no[6] = arr[g('X')];
		no[7] = arr[g('S')] - no[6];
		no[5] = arr[g('V')] - no[7];
		no[4] = arr[g('F')] - no[5];
		no[3] = arr[g('H')] - no[8];
		no[9] = arr[g('I')] - no[8] - no[6] - no[5];
		no[1] = arr[g('N')] - no[7] - no[9]*2;
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < no[j]; k++){
				printf("%d", j);
			}
		}
		printf("\n");
		
	}
}
