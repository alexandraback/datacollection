#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

typedef vector<int> IntVec;
typedef vector<double> DoubleVec;
typedef vector<long double> LDVec;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

template<class T> void PrintVec(const vector<T>& v, const char* s=NULL) {
    if (s)
	cout << s << ' ';
    forall (i, v.size())
	cout << v[i] << ' ';
    cout << endl;
}

template<class T> void PrintVec(const char* s, const vector<T>& v) {
    PrintVec(v, s);
}

typedef LDVec ProbChar;

void Prob(LDVec& v, ProbChar& pc, const string& word, int i) {
    const int len = word.size();
    v = LDVec(len+1, 0.);
    if (len == 0) {
	v[0] = 1;
	return;
    }
    if (i == 0) {
	v[1] = pc[(int)word[0]];
	v[0] = 1 - v[1];
	return;
    }
    vector<bool> vbBusy(256, false);
    ld p0 = 1.;
    for (int j=i+1; j>=1; j--) {
	if (j > len)
	    continue;
	char c = word[j-1];
	if (vbBusy[c])
	    continue;
	if (word.substr(0, j-1) != word.substr(i-(j-1), j-1))
	    continue;
	assert(v[j] == 0.);
	ld prob = pc[(int)c];
	v[j] = prob;
	p0 -= prob;
	vbBusy[c] = true;
    }
    v[0] = p0;
}

void Expect(ld& expect, int& best, const vector<LDVec>& vv, int nChars) {
    const int len1 = vv.size(); // word.size()+1
    assert(len1 > 0);
    const int len = len1 - 1;

    LDVec vp(len1, 0.);
    vp[0] = 1.;

    expect = 0.;
    best = 0;
    int ind = 0;

    forall (i, nChars) {
	LDVec vpNew(len1, 0.);
	vector<bool> vbNew(len1, false);
	forall (j, len1)
	    forall (k, len1) {
		vpNew[k] += vp[j] * vv[j][k];
	    }
	expect += vpNew[len];
	vp = vpNew;
	int indNew = 0;
	for (int j=len; j>=0; j--)
	    if (vv[ind][j]>0) {
		indNew = j;
		break;
	    }
	ind = indNew;
	if (ind == len)
	    best++;
    }
}

int main() {
    cout << setprecision(10);
    LDVec pc;
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int K, L, S;
	string key, word;
	cin >> K >> L >> S;
	cin >> key >> word;
	assert((int)key.size() == K);
	assert((int)word.size() == L);
	pc = LDVec(256, 0.);
	forall (i, K)
	    pc[(int)key[i]] += (ld)1 / K;
	vector<LDVec> vvProb(L+1);
	forall (i, L+1) {
	    Prob(vvProb[i], pc, word, i);
	}
	ld expect;
	int best;
	Expect(expect, best, vvProb, S);
	cout << "Case #" << iTask << ": " << best-expect << '\n';
    }
}
