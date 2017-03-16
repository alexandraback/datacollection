#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXHEGIHT = 2505;
const int MAX = 50;
int height[MAXHEGIHT];
int list[(2 * MAXHEGIHT -1) * MAXHEGIHT];

int main()
{
	int t,cas=1;
	cin >> t;
	while(t--) {
		memset(height,0,sizeof(height));
		int n;
		cin >> n;
		for(int i = 0 ; i < (2*n-1) * n; i ++) {
			cin >> list[i];
			height[list[i]]++;
		}
		printf("Case #%d:",cas++);
		for(int i = 0 ; i < MAXHEGIHT; i ++) 
			if(height[i] % 2 == 1)
				cout << " " << i;
		cout << endl;
	}
	return 0;
}

