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

#define FILE_NAME "B"
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

map<string, int> mp;

int main()
{
	sprintf(_buffer, "%s.in", FILE_NAME);
	freopen(_buffer, "r", stdin);
	sprintf(_buffer, "%s.out", FILE_NAME);
	freopen(_buffer, "w", stdout);

	CASET
	{
		int N;
		cin>>N;
		map<int,int> dic;
		for(int i=0;i<(2*N-1)*N;i++){
			int num;
			cin>>num;
			if(dic.count(num)==0)
				dic[num] = 1;
			else
				dic[num]+=1;
		}

		cout<<"Case #"<<_t<<":";
		for(map<int,int>::iterator it = dic.begin();it!=dic.end();it++){
			if(it->second%2)
				cout<<' '<<it->first;
		}
		cout<<endl;
	}
		
	return 0;
}