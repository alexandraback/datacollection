#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	
	freopen("d:\\3.in", "r", stdin);
	freopen("d:\\3.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		int row, col, target;
		cin>>row>>col>>target;
		
		if(row > col)
			swap(row, col);
			
		if(row <= 2 || target < 5)
		{
			cout<<"Case #"<<kase<<": "<<target<<endl;
			continue;
		}
		
		int maxup = (row - 1) / 2;
		int maxdown = (row) / 2;
	//	int maxleft = (col - 1) / 2;
		int maxright = (col - 1) ;
		
		int up = 1, down = 1, left = 0, right = 2;
		int ans = 4;
		int cnt = 5;
		while(cnt < target)
		{
			if(right < maxright)
			{
				if(down < maxdown && (right-left) % 2 == 1)
				{
					ans++;
					cnt += (down+1);
					down++;
				}
				else
				{
					ans++;
					cnt += down;
				}
				
				if(cnt >= target)
					break;
					
				if(up < maxup && (right-left) % 2 == 1)
				{
					ans++;
					cnt += (up + 2);
					up++;
				}
				else
				{
					ans++;
					cnt += (up + 1);
				}
				
				if(cnt >= target)
					break;
				right++;
			}
			else
			{
				break;
			}
		}
		
		vector<int> cur;
		cur.push_back(maxdown);
		cur.push_back(maxdown);
		cur.push_back(maxup);
		cur.push_back(maxup);
		int idx = 0;
		
		while(cnt < target)
		{
			ans ++;
			cnt += cur[idx];
			cur[idx]--;
			idx = (idx+1) % 4;
		}
		
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
	
	return 0;
}
