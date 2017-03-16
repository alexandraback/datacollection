#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <queue>
#include <fstream>
using namespace std;
int ar[]={1,2,3,4,5};
int reverse(int num){
	int rev = 0;
	while (num > 0){
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return rev;
}

int bfs(int x){
	queue<int> myq;
	myq.push(1);
	vector<int> vis(1005001, 0);
	vis[1] = 1;
	while (!myq.empty())
	{
		int v = myq.front();
		myq.pop();
		if (v == x){
			return vis[v];
			break;
		}
		if (v + 1 <= 1e6 && !vis[v + 1]) {
			vis[v + 1] = vis[v] + 1;
			myq.push(v + 1);
		}
		int r = reverse(v);
		if(r <= 1e6 && !vis[r]) {
			vis[r] = vis[v]+1;
			myq.push(r);
		}

	}
	return -1;
}

int main(){
	int tc;
	cin >> tc;
	for (int i = 1; i<= tc; i++)
	{
		int n;
		cin >> n;
		int x = bfs(n);
		cout << "Case #" << i  << ": " << x << endl;
	}
	return 0;
}
