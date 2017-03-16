#include <iostream>
#include <queue>
#include<stdio.h>
#define MAX 1111111

using namespace std;

int DP[MAX];

int rev(int in)
{
	int ou = 0;
	while (in > 0){
		ou = ou * 10 + (in % 10);
		in /= 10;
	}

	return ou;
}

queue<int> qu;
int main()
{
	int t;
    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	qu.push(1);
	DP[1] = 1;
	while (!qu.empty()){
		int x = qu.front();
		qu.pop();
		if(x + 1 < MAX and DP[x + 1] == 0){
			DP[x + 1] = DP[x] + 1;
			qu.push(x + 1);
		}
		if(rev(x) < MAX and DP[rev(x)] == 0){
			DP[rev(x)] = DP[x] + 1;
			qu.push(rev(x));
		}
	}

	cin >> t;
	for(int i=1;i<=t;++i){
		long long n;
		cin >> n;
		cout<<"Case #"<<i<<": "<<DP[n]<<endl;
	}
}
