#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char _buffer[2048];

#define FILE_NAME "A"
#define ULL unsigned long long
#define CASET int _t=0, case_num;cin>>case_num;while(++_t<=case_num)

typedef vector<int> VI;
typedef vector<VI> VVI;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'E', 'S', 'W', 'N'};

bool solve()
{
	return false;
}	

int main()
{
	sprintf(_buffer, "%s.in", FILE_NAME);
	freopen(_buffer, "r", stdin);
	sprintf(_buffer, "%s.out", FILE_NAME);
	freopen(_buffer, "w", stdout);

	CASET
	{
		string input, ans;
		cin>>input;
		ans.insert(0,1,input[0]);
		for(int i=1;i<input.length();i++){
			if(input[i]>=ans[0])
				ans.insert(0, 1, input[i]);
			else
				ans+=input[i];
		}
		
		cout<<"Case #"<<_t<<": "<<ans<<endl;
	}
		
	return 0;
}