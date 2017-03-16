// ConsoleApplication8.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, Smax;
	string s;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		cin >> Smax;
		cin >> s;
		int num = 0, result = 0;
		for (int j = 0; j < Smax;){
			num += s[j] - '0';
			if (num < ++j){
				result++;
				num++;
			}
		}
		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}

