#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

long long maxasnwer = 0;
long long answerRatio = 0;
long long answer = 0;
int K, L, S;
string strk, strl;


void dfs(int strIndex, int tokenIndex, string tstr){

	if (strIndex == S)
	{
		answer++;
		long long tmax = 0;
		//	cout << tstr << endl;
		for (int i = 0; i <= S - L; i++)
		{
			if (strl == tstr.substr(i, L)){
 				answerRatio++;
			}
		}
 		return;
	}

	for (int i = 0; i < K; i++)
		dfs(strIndex + 1, i, tstr + strk[i]);
}

void getMaxLeng(){
	int iTMax = 0;
	bool tflag = true;
	for (int i = L - 1; i > 0; i--)
	{
		//	cout <<i<<"th	"<< strl.substr(0, i) << " " << strl.substr(L - i, i) << endl;
			if (strl.substr(0, i) == strl.substr(L - i, i)){
				iTMax = i;
				break;
			}
	}
	//cout << iTMax << endl;
	//cout << (S-L)/(L-iTMax) + 1 << endl;
	maxasnwer = (S - L) / (L - iTMax) + 1;
}

void solve(){
	answerRatio = 0;
	answer = 0;
	dfs(0, 0, "");
}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output21.txt", "w", stdout);

	int nTestCase = 0;
	cin >> nTestCase;

	for (int iTestCase = 0; iTestCase < nTestCase; iTestCase++)
	{
		int sortChar = 0;
		char charset[300] = { 0, };

		double solution = maxasnwer = answerRatio = answer = 0;
		cin >> K >> L >> S;
		cin >> strk >> strl;

		maxasnwer = S / L;
		for (int i = 0; i < strk.length(); i++)
			charset[strk[i]]++;
		for (int i = 0; i < strl.length(); i++){
			if (charset[strl[i]] == 0)
				maxasnwer = 0;;
		}
		for (int i = 0; i < strl.length()-1; i++){
			if (strl[i] != strl[i + 1])
				break;
			if (i == strl.length() - 1)
				maxasnwer = 0;
		}

		if (maxasnwer != 0){
			getMaxLeng();
			solve();
			solution = (double)maxasnwer - ((double)answerRatio / (double)answer);
		}

		cout << "Case #" << iTestCase + 1 << ": " << solution << endl;
	}
	return 0;
}