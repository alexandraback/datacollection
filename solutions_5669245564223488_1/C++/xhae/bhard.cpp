#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
string str[100];
long long fact[101];
const long long MOD = 1000000007;
int onlys[26], start[26], _end[26];
bool isInside[26];
bool isProcessed[100];

int main(void)
{
	fact[0] = 1;
	for(int i = 1; i <= 100; i++) fact[i] = fact[i - 1] * i % MOD;

	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin >> n;
		for(int i = 0; i < n; i++) 
		{
			cin >> str[i];
			for(int j = 0; j < str[i].size(); j++) str[i][j] -= 'a';
		}

		memset(onlys, 0, sizeof(onlys));
		memset(isInside, false, sizeof(isInside));
		memset(start, -1, sizeof(start));
		memset(_end, -1, sizeof(_end));
		memset(isProcessed, 0, sizeof(isProcessed));

		bool isAble = true;
		for(int i = 0; i < n; i++)
		{
			string cur = str[i];
			cur.erase(unique(cur.begin(), cur.end()), cur.end());
			if(cur.size() == 1) 
			{
				onlys[cur[0]]++;
				isProcessed[i] = true;
			}
			if(cur.size() > 2)
			{
				for(int j = 1; j < cur.size() - 1; j++)
				{
					int ch = cur[j];
					if(isInside[ch] == false) isInside[ch] = true;
					else 
					{ 
					//	printf("err1\n"); 
						isAble = false; 
					}
				}
			}
			if(cur.size() >= 2)
			{
				char sch = cur[0], ech = cur[cur.size() - 1];
				if(start[sch] == -1) start[sch] = i;
				else 
				{ 
				//	printf("err2\n"); 
					isAble = false; 
				}
				if(_end[ech] == -1) _end[ech] = i;
				else 
				{ 
				//	printf("err3\n"); 
					isAble = false; 
				}
			}
		}

		for(int i = 0; i < 26; i++) 
		{
			if(isInside[i] && (start[i] >= 0 || _end[i] >= 0)) isAble = false;
			if(start[i] >= 0 && _end[i] >= 0 && start[i] == _end[i]) isAble = false;
		}

		vector <long long> pieces;
		for(int i = 0; i < 26 && isAble; i++)
		{
			if(start[i] >= 0 && _end[i] == -1)
			{
//				printf("course: ");

				long long curAns = fact[onlys[i]];
				int cur = i;
				while(true)
				{
					isProcessed[start[cur]] = true;
					int next = str[start[cur]][str[start[cur]].size() - 1];
//					printf("%d %d, ", cur, next);
					if(next == i) { isAble = false; break; }
					curAns = curAns * fact[onlys[next]] % MOD;
					if(start[next] == -1) break;
					isProcessed[start[next]] = true;
					cur = next;
				}
//				printf("\n");

				pieces.push_back(curAns);
			}
		}

		for(int i = 0; i < n; i++) if(isProcessed[i] == false) isAble = false;

		cout << "Case #" << kase << ": ";
		if(isAble == false) { cout << "0" << endl; continue; }

		for(int i = 0; i < 26; i++)
			if(start[i] == -1 && _end[i] == -1 && onlys[i] > 0)
				pieces.push_back(fact[onlys[i]]);
			
		long long ans = fact[pieces.size()];
		for(auto v: pieces) ans = ans * v % MOD;
		cout << ans << endl;
//		for(auto v: pieces) printf("%lld ", v);
//		printf("\n");
	}

	return 0;
}
