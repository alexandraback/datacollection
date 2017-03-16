#include "Rank_and_File.h"
#include <iostream>
#include<string>
#include <algorithm>
#include<fstream>
#include <vector>
#include<cstdio>
#include<math.h>
#include<utility>
#include<queue>
#include<iomanip>



using namespace std;



	FILE *stream;

	int nums[1000000];

int main(){
	//freopen_s(&stream,"C:\\Users\\Sherif\\Desktop\\output.txt", "w", stdout);
	int T; cin >> T;
	for (int k = 0; k < T; k++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < (n*2-1)*n; i++)
		{
			int x;
			cin >> x;
			nums[x - 1]++;
		}
		vector<int> ans;
		for (int i = 0; i < 1000000; i++)
		{
			if (nums[i] != 0){
				if (nums[i] % 2 != 0){
					ans.push_back(i + 1);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << k + 1 << ": ";
		for (int i = 0; i < ans.size(); i++)
		{
			if (i == ans.size() - 1){
				cout << ans[i];
			}
			else{
				cout << ans[i] << " ";
			}
		}
		cout << endl;
	}
	
	
}