// 2012Round!A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "windows.h"


using namespace std;

size_t arr[1000][1000];
vector<size_t> Ms;
bool diamond = false;
size_t N;
size_t checker;

void check(size_t index) {
	const size_t M = Ms[index];
	vector<size_t> childs;
	for (size_t i = 0 ; i < N; ++i) {
		if (arr[i][index] == 1) {
			childs.push_back(i);

			for (size_t j =0 ; j < N; ++j) {
				if (j!= checker) continue;
				if (arr[index][j] == 1) {
					if (arr[i][j] == 1) {
						diamond = true;
						return;
					} else {
						arr[i][j] = 1;
					}
				}
			}


		}
	}
	for (vector<size_t>::iterator itr = childs.begin(); itr != childs.end(); ++itr) {
		check(*itr);
		if (true == diamond) return;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	size_t T;
	cin >> T;
	//Sleep(10*1000);
	for (size_t i = 0; i < T; ++i) {

		
		cin >> N;

		for (size_t j = 0 ; j < 1000; ++j) {
			for (size_t k = 0; k < 1000; ++k) {
				arr[j][k] = 0;
			}
		}

		size_t val;
		Ms.clear();
		diamond = false;
		for (size_t j = 0; j < N; ++j) {
			size_t M;
			cin >> M;
			Ms.push_back(M);
			for (size_t k = 0; k < M; ++k) {
				cin >> val;
				arr[j][val-1] = 1;
			}
		}
		

		for (size_t j = 0; j < N; ++j) {
			const size_t M = Ms[j];
			if (M == 0) {
				checker = j;
				check(j);
			}
		}
		
		char *str = (true == diamond) ? "Yes" : "No";

		cout << "Case #" << i+1 <<": " << str << std::endl;
	}
}