#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <list>
#include <map> // contains multimap
#include <queue> // contains priority_queue
#include <deque>
#include <stack>


using namespace std;

unsigned long * sett;
unsigned long N;
unsigned long maxx;
list<unsigned long> s1, s2;

bool solve(unsigned long idx, unsigned long sum1, unsigned long sum2, unsigned long cmaxx) { 
    if (sum1 == sum2 && s1.size() != 0) {
        return true;
    } else if (idx == N) {
        return false;
    }

    unsigned long next = sett[idx];
    if (solve(idx+1, sum1, sum2, cmaxx-next))
        return true;

    if (sum1 + 2*next <= sum2 + cmaxx) {
        s1.push_back(next);
        if (solve(idx+1, sum1+next, sum2, cmaxx-next))
            return true;
        s1.pop_back();
    } 
    if (sum2 + 2*next <= sum1 + cmaxx) {
        s2.push_back(next);
        if(solve(idx+1, sum1, sum2+next, cmaxx-next))
            return true;
        s2.pop_back();
    } 
    
    return false;//solve(idx+1, sum1, sum2, cmaxx-next);
}

bool solve() {
    s1.clear();
    s2.clear();

    s1.push_back(sett[0]);
    if (solve(1, sett[0], 0, maxx))
        return true;
    s1.pop_back();

    if (solve(1, 0, 0, maxx))
        return true;
    

    return false;
}


unsigned long main() {
    unsigned long numcase;
    unsigned long tmp;

    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    cin >> numcase;
    for (unsigned long i = 0; i < numcase; ++i) {
        cin >> N;
        sett = new unsigned long[N];
        maxx = 0;
        for (unsigned long j = 0; j < N; ++j) {
            cin >> tmp;
            sett[j] = tmp;
            maxx += tmp;
        }
        cout << "Case #" << i + 1 << ":"<<endl;
        if (solve()) {
            list<unsigned long>::iterator it;
            for (it=s1.begin(); it!=s1.end(); ++it)
                cout << *it<< " ";
            cout << endl;
            for (it=s2.begin(); it!=s2.end(); ++it)
                cout << *it << " ";
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }
        delete [] sett;
    }

    return 0;
}
