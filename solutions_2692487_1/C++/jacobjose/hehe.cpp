// hehe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"

using namespace std;

unsigned int findd(vector<unsigned int> pmotes, unsigned int  count, unsigned int A) {
	unsigned int countd = count;
	unsigned int counta = count;

	// Delete biggest.
	countd++;
	vector<unsigned int> pd;
	for (int i = 0; i < pmotes.size()-1; i++)
		pd.push_back(pmotes[i]);
	if (pd.size() != 0) {
		countd = findd(pd, countd, A);
	}

	// Match the smallest
	unsigned int AA = A;
	do {
		counta++;
		AA += AA-1;
		if (AA == A) {
			counta = 0xFFFFFFFF;
			break;
		}
	}while (pmotes[0] >= AA) ;

	vector<unsigned int>::iterator itr = pmotes.end();
	for (int i = 0; i < pmotes.size(); ++i) {
		if (pmotes[i] >= AA)
			break;
		AA += pmotes[i];
		itr = pmotes.begin() + i;
	}
	if (itr != pmotes.end())
		pmotes.erase(pmotes.begin(), itr+1);


	if (pmotes.size() != 0 && counta != 0xFFFFFFFF) {
		counta = findd(pmotes, counta, AA);
	}

	return counta < countd ? counta : countd;
}


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int T = 0;
	cin >> T;
	//Sleep(10*1000);
	for (int c = 0; c < T; ++c) {
		unsigned int A = 0;
		cin >> A;
		unsigned int N = 0;
		cin >> N;
		vector<unsigned int> pmotes;
		for (int i = 0; i < N; ++i) {
			unsigned int temp = 0;
			cin >> temp;
			pmotes.push_back(temp);
		}

		sort(pmotes.begin(), pmotes.end());


		vector<unsigned int>::iterator itr = pmotes.end();
		for (int i = 0; i < N; ++i) {
			if (pmotes[i] >= A)
				break;
			A += pmotes[i];
			itr = pmotes.begin() + i;
		}
		if (itr != pmotes.end())
			pmotes.erase(pmotes.begin(), itr+1);
		
		unsigned int count = 0;
		if (pmotes.size() != 0) {
			count = findd(pmotes, count, A);
		}
		cout << "Case #" << c+1 << ": " << count << std::endl;


	}

	return 0;
}

