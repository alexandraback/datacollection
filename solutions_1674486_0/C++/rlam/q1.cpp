#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <string>
using namespace std;
int isYes(int i, short** mc, short* np, short* m) {
	for (int j = 0; j < m[i]; j++) {
		np[mc[i][j]]++;
		if (np[mc[i][j]] > 1) return 1;
	}
	for (int j = 0; j < m[i]; j++) {
		int yes = isYes(mc[i][j], mc, np, m);
		if (yes) return 1;
	}
	return 0;
}

int main()
{
	int case_num = 0;
	int N = 0;
	int M = 0;
	short ** mc;
	mc = new short*[1001];
	for (int i = 0; i < 1001; i++)
		mc[i] = new short[1001];
	short m[1001];
	short np[1001];


	cin >> case_num;
	for (int cn = 0; cn < case_num; cn++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> m[i];
			for (int j = 0; j < m[i]; j++)
				cin >> mc[i][j];
		}
		
		int yes = 0;
		
		for (int i = 1; i <= N && !yes; i++) {
			for (int j = 0; j <= N; j++)
				np[j] = 0;
			for (int j = 0; j < m[i]; j++) {
				np[mc[i][j]]++;
			}
			for (int j = 0; j < m[i] && !yes; j++) {
				yes = isYes(mc[i][j], mc, np, m);
			}
		}				

		cout << "Case #" << cn + 1 << ": ";
		if (yes)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;			
	}
}



