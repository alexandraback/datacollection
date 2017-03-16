#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
typedef pair<int,int> pi;
queue<int> q;
int arr[1000001];

int reverse(int a){
	
	int num = 0;
	while (a > 0){
		num = num*10 + (a%10);
		a = a/10;
	}
	
	return num;
}

int main(){
	
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	
	int T, N;
	cin >> T;
	
	memset(arr, -1, sizeof(arr));
	q.push(1);
	arr[1] = 1;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		int a = reverse(cur);
		if (arr[a] == -1){
			arr[a] = arr[cur] + 1;
			q.push(a);
		}
		
		if (arr[cur + 1] == -1 && cur + 1 <= 1000000){
			arr[cur + 1] = arr[cur] + 1;
			q.push(cur + 1);
		}
		
	}
	
	for (int i = 0; i < T; i++){
		
		cin >> N;
		cout << "Case #" << i + 1 << ": " << arr[N] << endl;
	}
	
	
}
