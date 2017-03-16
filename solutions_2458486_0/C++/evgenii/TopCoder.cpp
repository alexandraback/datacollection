// TopCoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include <fstream>

void genTests() {
	std::ofstream tests("test.txt");
	tests << "1000" << std::endl;
	for (int i = 0; i < 1000; ++i)
		tests << "1 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << std::endl;
	tests.close();
}

vector<int> keys;
vector<int> locks;
vector<vector<int> > chest;
int path[201];
int dp[1 << 21];

void findPath(int mask) {
	if (dp[mask] != 0)
		return;
	int n = chest.size();
	int pidx = 0;
	while(path[pidx] != -1)
		++pidx;
	if (pidx == n)
		return;
	multiset<int> keyset;
	for (int i = 0; i < keys.size(); ++i)
		keyset.insert(keys[i]);
	for (int i = 0; i < n; ++i) {
		if (((1 << i) & mask) == 0)
			continue;
		for (int j = 0; j < chest[i].size(); ++j)
			keyset.insert(chest[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		if (((1 << i) & mask) == 0)
			continue;
		multiset<int>::iterator it = keyset.find(locks[i]);
		if (it != keyset.end())
			keyset.erase(it);
	}
	for (int i = 0; i < n; ++i) {
		if (((1 << i) & mask) != 0)
			continue;
		if (keyset.find(locks[i]) == keyset.end())
			continue;
		path[pidx] = i + 1;
		findPath(mask | (1 << i));
		int pidx2 = 0;
		while(path[pidx2] != -1)
			++pidx2;
		if (pidx2 == n)
			return;
		path[pidx] = -1;
	}
	dp[mask] = 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//genTests();
	std::ifstream ifs("test.txt");
	std::ofstream ofs("ans.txt");

	int t = 0;
	ifs >> t;
	for (int idx = 0; idx < t; ++idx) {
		memset(path, -1, sizeof(path));
		memset(dp, 0, sizeof(dp));		
		int k, n;
		ifs >> k;
		ifs >> n;
		keys.clear();
		keys.resize(k, 0);
		for (int i = 0; i < k; ++i)
			ifs >> keys[i];
		locks.clear();
		locks.resize(n, 0);
		chest.clear();
		chest.resize(n);
		for (int i = 0; i < n; ++i) {
			ifs >> locks[i];
			int ni;
			ifs >> ni;
			if (ni > 0)
				chest[i].resize(ni);
			for (int j = 0; j < ni; ++j)
				ifs >> chest[i][j];
		}

		findPath(0);
		if (path[0] == -1) {
			ofs << "Case #" << idx + 1 << ": IMPOSSIBLE" << std::endl;
			continue;
		}
		ofs << "Case #" << idx + 1 << ":";
		int pidx = 0;
		while (path[pidx] != -1) {
			ofs << " " << path[pidx];
			++pidx;
		}
		ofs << std::endl;
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

