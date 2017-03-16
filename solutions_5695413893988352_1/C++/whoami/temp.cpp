#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
char A[25], B[25];
int su[2][25], n, temp[2][25];
long long min_diff, gob[25];
int ans[2][25];

void fill_max(int arr[], int type, int aft){
	for (int i = aft; i < n; i++){
		if (type == 0 && A[i] != '?')
			arr[i] = A[i] - '0';
		else if (type == 1 && B[i] != '?')
			arr[i] = B[i] - '0';
		else
			arr[i] = 9;
	}
}

void fill_min(int arr[], int type, int aft){
	for (int i = aft; i < n; i++){
		if (type == 0 && A[i] != '?')
			arr[i] = A[i] - '0';
		else if (type == 1 && B[i] != '?')
			arr[i] = B[i] - '0';
		else
			arr[i] = 0;
	}
}

void calc_diff(){
	long long temp_ans = 0;
	for (int i = 0; i < n; i++){
		temp_ans += (temp[0][i] - temp[1][i])*gob[i];
	}

	if (min_diff == abs(temp_ans)){
		long long ans_A = 0, ans_B = 0, temp_A = 0, temp_B = 0;
		for (int i = 0; i < n; i++){
			ans_A += ans[0][i] * gob[i];
			ans_B += ans[1][i] * gob[i];
			temp_A += temp[0][i] * gob[i];
			temp_B += temp[1][i] * gob[i];
		}
		if (ans_A>temp_A || (ans_A == temp_A && ans_B > temp_B)){
			for (int i = 0; i < n; i++){
				ans[0][i] = temp[0][i];
				ans[1][i] = temp[1][i];
			}
		}
	}

	if (min_diff > abs(temp_ans)){
		min_diff = abs(temp_ans);
		for (int i = 0; i < n; i++){
			ans[0][i] = temp[0][i];
			ans[1][i] = temp[1][i];
		}
	}
}

void pro(int k){
	if (k == n){
		calc_diff();
		return;
	}

	//a=b+1
	if (A[k] == '?' && B[k] == '?'){
		temp[0][k] = 1;
		temp[1][k] = 0;
	}
	else if (A[k] == '?'){
		temp[1][k] = B[k] - '0';
		temp[0][k] = temp[1][k] + 1;
		if (temp[0][k]>9)
			temp[0][k] = 9;
	}
	else if (B[k] == '?'){
		temp[0][k] = A[k] - '0';
		temp[1][k] = temp[0][k] - 1;
		if (temp[1][k] < 0)
			temp[1][k] = 0;
	}
	else{
		temp[0][k] = A[k] - '0';
		temp[1][k] = B[k] - '0';
	}
	fill_min(temp[0], 0, k + 1);
	fill_max(temp[1], 1, k + 1);
	calc_diff();
	
	//b=a+1
	if (A[k] == '?' && B[k] == '?'){
		temp[0][k] = 0;
		temp[1][k] = 1;
	}
	else if (A[k] == '?'){
		temp[1][k] = B[k] - '0';
		temp[0][k] = temp[1][k] - 1;
		if (temp[0][k]<0)
			temp[0][k] = 0;
	}
	else if (B[k] == '?'){
		temp[0][k] = A[k] - '0';
		temp[1][k] = temp[0][k] + 1;
		if (temp[1][k] >9)
			temp[1][k] = 9;
	}
	else{
		temp[0][k] = A[k] - '0';
		temp[1][k] = B[k] - '0';
	}

	fill_max(temp[0], 0, k + 1);
	fill_min(temp[1], 1, k + 1);
	calc_diff();

	//a=b
	if (A[k] == '?' && B[k] == '?'){
		temp[0][k] = 0;
		temp[1][k] = 0;
	}
	else if (A[k] == '?'){
		temp[1][k] = B[k] - '0';
		temp[0][k] = temp[1][k];
	}
	else if (B[k] == '?'){
		temp[0][k] = A[k] - '0';
		temp[1][k] = temp[0][k];
	}
	else{
		temp[0][k] = A[k] - '0';
		temp[1][k] = B[k] - '0';
	}
	pro(k + 1);

}

int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	gob[17] = 1;
	for (int i = 16; i >= 0; i--)
		gob[i] = gob[i + 1] * 10;

	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		scanf("%s %s", A, B);
		n = strlen(A);
		min_diff = 1LL << 62;
		memset(ans, 0, sizeof(ans));
		memset(temp, 0, sizeof(temp));
		pro(0);

		printf("Case #%d: ", test);
		for (int i = 0; i < n; i++)
			printf("%d", ans[0][i]);
		printf(" ");
		for (int i = 0; i < n; i++)
			printf("%d", ans[1][i]);
		printf("\n");
	}
	return 0;
}
