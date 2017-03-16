#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
unsigned long long A, B, K;
vector<int> bA, bB, bK;
unsigned long long ret;

void go(int st, unsigned long long prefA, unsigned long long prefB) {
	if (st==-1) {
		if ((prefA & prefB)<K) ret += 1;
		return;
	}
	if (bK[st]==1) {
		unsigned long long tmpminA = 0, tmpmaxA = 0;
		unsigned long long tmpminB = 0, tmpmaxB = 0;
		unsigned long long tcnt1 = 0;
		unsigned long long tcnt2 = 0;
		tmpminA = prefA;
		tmpmaxA = prefA + ((1 << st) - 1);
		tmpminB = prefB;
		tmpmaxB = prefB + ((1 << st) - 1);
		
		if (A<=tmpminA) tcnt1 = 0;
		else if (A<=tmpmaxA) tcnt1 = (A-tmpminA);
		else tcnt1 = tmpmaxA - tmpminA + 1;
		if (B<=tmpminB) tcnt2 = 0;
		else if (B<=tmpmaxB) tcnt2 = (B-tmpminB);
		else tcnt2 = tmpmaxB - tmpminB + 1;

		ret += tcnt1 * tcnt2;


		tmpminA = prefA + (1 << st);
		tmpmaxA = prefA + ((1 << (st+1)) - 1);
		tmpminB = prefB;
		tmpmaxB = prefB + ((1 << st) - 1);
		
		if (A<=tmpminA) tcnt1 = 0;
		else if (A<=tmpmaxA) tcnt1 = (A-tmpminA);
		else tcnt1 = tmpmaxA - tmpminA + 1;
		if (B<=tmpminB) tcnt2 = 0;
		else if (B<=tmpmaxB) tcnt2 = (B-tmpminB);
		else tcnt2 = tmpmaxB - tmpminB + 1;

		ret += tcnt1 * tcnt2;


		tmpminA = prefA;
		tmpmaxA = prefA + ((1 << st) - 1);
		tmpminB = prefB + (1 << st);
		tmpmaxB = prefB + ((1 << (st+1)) - 1);
		
		if (A<=tmpminA) tcnt1 = 0;
		else if (A<=tmpmaxA) tcnt1 = (A-tmpminA);
		else tcnt1 = tmpmaxA - tmpminA + 1;
		if (B<=tmpminB) tcnt2 = 0;
		else if (B<=tmpmaxB) tcnt2 = (B-tmpminB);
		else tcnt2 = tmpmaxB - tmpminB + 1;

		ret += tcnt1 * tcnt2;

		int prefAn = prefA; 
		int prefBn = prefB;
		prefAn += (1 << st);
		prefBn += (1 << st);

		if (prefAn<A && prefBn<B) go(st-1, prefAn, prefBn);
	}
	else {
		go(st-1, prefA, prefB);
		int prefAn = prefA; 
		int prefBn = prefB;
		prefAn += (1 << st);
		prefBn += (1 << st);
		if (prefAn<A) go(st-1, prefAn, prefB);
		if (prefBn<B) go(st-1, prefA, prefBn);
	}
}

int main()
{
    fstream fin("B-large.in",ifstream::in);
    fstream fout("B-large.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> A >> B >> K;
		ret = 0;
		if (K>=A && K>=B) ret = A*B;
		else {
			unsigned long long tmp = A;
			tmp = max(tmp, B);
			bA.resize(0);
			while (tmp>0) { bA.push_back(tmp%2); tmp /= 2; }
			bB.resize(bA.size());
			bK.resize(bA.size());
			rep(i,bA.size()) { bA[i] = bB[i] = bK[i] = 0; }
			tmp = A;
			int ind = 0;
			while (tmp>0) { bA[ind] = tmp%2; tmp /= 2; ind++; }
			tmp = B;
			ind = 0;
			while (tmp>0) { bB[ind] = tmp%2; tmp /= 2; ind++; }
			tmp = K;
			ind = 0;
			while (tmp>0) { bK[ind] = tmp%2; tmp /= 2; ind++; }
			go(bA.size()-1, 0, 0);
		}
		
		cout << "Case #" << tc << ": " << ret << "\n";
		fout << "Case #" << tc << ": " << ret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
