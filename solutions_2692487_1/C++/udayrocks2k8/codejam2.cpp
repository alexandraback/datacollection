#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
int mSizes[MAX];
int nMotes;

int calculate(long long int aSize, int i) {
    for (;i < nMotes; i++) {
        if (mSizes[i] < aSize) {
            aSize += mSizes[i];
        } else {
            break;
        }
    }
    int fCount = (nMotes - i);
    if (i == nMotes || aSize == 1) {
        return fCount;
    }
    
    int sCount = 0;
    while (aSize <= mSizes[i]) {
        aSize += (aSize - 1);
        sCount++;
    }
    sCount += calculate(aSize, i);
    return min(fCount, sCount);
}

void getResult() {
    long long int aSize;
    cin >> aSize >> nMotes;
    for (int i = 0; i < nMotes; i++) {
        cin >> mSizes[i];
    }
    sort(mSizes, mSizes + nMotes);
    cout << calculate(aSize, 0) << endl;
}



int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}