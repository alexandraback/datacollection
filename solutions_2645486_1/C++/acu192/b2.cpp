#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

typedef uint64_t Long;



Long endWithAll(const Long e, const Long r, const vector<Long>& v, Long& currE)
{
    assert(currE >= 0);
    assert(currE <= e);

    if (v.size() == 0)
        return 0;
    if (v.size() == 1)
    {
        Long spend = 0;
        if (currE + r > e)
            spend = currE + r - e;
        currE = currE - spend + r;
        assert(currE >= 0);
        assert(currE <= e);
        //cout << "1Spending " << spend << " on " << v[0] << endl;
        return spend*v[0];
    }

    size_t maxindex = 0;
    for (size_t i = 1; i < v.size(); i++)
        if (v[i] > v[maxindex])
            maxindex = i;

    vector<Long> left(v.begin(), v.begin()+maxindex);
    Long leftRes = endWithAll(e, r, left, currE);

    Long canRegain = r * (v.size() - maxindex);
    Long spend = 0;
    if (currE + canRegain > e)
        spend = currE + canRegain - e;
    if (spend > currE)
        spend = currE;
    currE = currE - spend + r;
    if (currE > e)
        currE = e;
    assert(currE >= 0);
    assert(currE <= e);
    //cout << "2Spending " << spend << " on " << v[maxindex] << endl;
    Long hereRes = spend*v[maxindex];

    vector<Long> right(v.begin()+maxindex+1,v.end());
    Long rightRes = endWithAll(e, r, right, currE);

    return leftRes + rightRes + hereRes;
}


Long endWithNone(const Long e, const Long r, const vector<Long>& v, Long& currE)
{
    assert(currE >= 0);
    assert(currE <= e);

    if (v.size() == 0)
        return 0;
    if (v.size() == 1)
    {
        //cout << "3Spending " << currE << " on " << v[0] << endl;
        Long res = currE*v[0];
        currE = r;
        assert(currE >= 0);
        assert(currE <= e);
        return res;
    }

    size_t maxindex = 0;
    for (size_t i = 1; i < v.size(); i++)
        if (v[i] > v[maxindex])
            maxindex = i;

    vector<Long> left(v.begin(), v.begin()+maxindex);
    Long leftRes = endWithAll(e, r, left, currE);

    //cout << "4Spending " << currE << " on " << v[maxindex] << endl;
    Long hereRes = currE*v[maxindex];
    currE = r;
    if (currE > e)
        currE = e;
    assert(currE >= 0);
    assert(currE <= e);

    vector<Long> right(v.begin()+maxindex+1,v.end());
    Long rightRes = endWithNone(e, r, right, currE);

    return leftRes + rightRes + hereRes;
}


void solve()
{
    Long e, r, n;
    cin >> e >> r >> n;
    vector<Long> v(n,0);
    for (Long i = 0; i < n; i++)
        cin >> v[i];
    Long currE = e;
    cout << endWithNone(e, r, v, currE) << endl;
}


int main()
{
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        cout << "Case #" << caseNum << ": ";
        solve();
    }

    return 0;
}
