#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"
#include "iomanip"

using namespace std;

long double dp[102][102];
bool vis[102][102];

long double dp2[102][102];
bool vis2[102][102];

int kmpTable[102];

long double keys[30];

string input;
int inputLen, k, s;
long double ka;

long double solve(int idx, int kmpIdx)
{
	if(idx == s)
		return 0.0;
	if(vis[idx][kmpIdx + 1]) return dp[idx][kmpIdx + 1];
	
	//cout << idx << " " << kmpIdx << endl;

	vis[idx][kmpIdx + 1] = true;
	long double ans = 0.0;

	for(char x = 'A'; x<= 'Z'; x++) 
	{
		int kp = kmpIdx;

		while(kp != -1 && (kp == inputLen || input[kp] != x)) kp = kmpTable[kp];
		kp++;
		ans += (solve(idx+1, kp) + (kp == inputLen)) * keys[x - 'A'] / ka;
	}

	return dp[idx][kmpIdx + 1] = ans;
}

long double solve2(int idx, int kmpIdx)
{
	if(idx == s)
		return 0.0;
	if(vis2[idx][kmpIdx + 1]) return dp2[idx][kmpIdx + 1];
	
	//cout << idx << " " << kmpIdx << endl;

	vis2[idx][kmpIdx + 1] = true;
	long double ans = 0.0;

	for(char x = 'A'; x<= 'Z'; x++) 
	{
		if(keys[x - 'A'] > 0.0) {
			int kp = kmpIdx;

			while(kp != -1 && (kp == inputLen || input[kp] != x)) kp = kmpTable[kp];
			kp++;
			ans = max(ans, (solve2(idx+1, kp) + (kp == inputLen)));
		}
	}

	return dp2[idx][kmpIdx + 1] = ans;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int test = 1;test<=t;test++)
	{
		scanf("%d%d%d", &k, &inputLen, &s);
		ka = (long double)(k * 1.0);

		string key;
		cin >> key;

		memset(keys, 0, sizeof(keys));
		memset(vis, false, sizeof(vis));
		memset(vis2, false, sizeof(vis));
		
		for(int i=0;i<k;i++)
			keys[key[i] - 'A'] += 1.0;

		cin >> input;
		
		kmpTable[0] = -1;

		for(int i = 1; i <= inputLen; i++)
		{
			//cout << "test" << i << endl;

			int pos = kmpTable[i - 1];
			while(pos != -1 && input[pos] != input[i - 1]) pos = kmpTable[pos];
			kmpTable[i] = pos + 1;
		}

		//cout << "OK" << endl;

		printf("Case #%d: ", test);
		cout << setprecision(9) << solve2(0,0) - solve(0, 0) << endl;		
	}
}

