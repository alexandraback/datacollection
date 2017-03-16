#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cstdio>
#include "stdlib.h"
using namespace std;

typedef double blk_t;
typedef list<blk_t> blks_t;

void print_blks(blks_t& blks) {
	blks_t::iterator it;
	for (it=blks.begin(); it!=blks.end(); ++it) {
		cout << *it << ' ';
	}
    cout << endl;
}

int war(blks_t nblocks, blks_t kblocks, bool deceit) {
	blks_t::iterator nit, kit;
	int nwins = 0;
//	print_blks(nblocks); print_blks(kblocks);
	if (deceit) {
		while (!nblocks.empty()) {
			if (nblocks.front() < kblocks.front()) {
				nblocks.pop_front(); kblocks.pop_back();
			} else {
				nwins++;
				nblocks.pop_front(); kblocks.pop_front();
			}
		}
	} else {
		while (!nblocks.empty()) {
			if (nblocks.back() > kblocks.back()) {
				nwins++;
				nblocks.pop_back(); kblocks.pop_front();
			} else {
				nblocks.pop_back(); kblocks.pop_back();
			}
		}
	}
//	for (nit=nblocks.begin(),kit=kblocks.begin(); nit!=nblocks.end(); ++nit,++kit) {
//		if (*nit > *kit) { nwins++; }
//	}
	return nwins;
}

void do_something() {
	int blocks;
	blk_t temp;
	blks_t nblocks;
	blks_t kblocks;
	cin >> blocks;
	for (int i=0; i<blocks; i++) { cin >> temp; nblocks.push_back(temp); }
	for (int i=0; i<blocks; i++) { cin >> temp; kblocks.push_back(temp); }
	nblocks.sort(); kblocks.sort();
	cout << war(nblocks,kblocks,true) << ' ' << war(nblocks,kblocks,false) << endl;
}

int main(int argc, char **argv)
{
	int tests;
	cin >> tests;

	for (int i=1; i <= tests; ++i) {
	  cout << "Case #" << i << ": ";
	  do_something();
	}
	return 0;
}
