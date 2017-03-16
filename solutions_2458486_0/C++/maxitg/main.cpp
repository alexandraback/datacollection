//
//  main.cpp
//  CodeJam.2013.Q.4
//
//  Created by Maxim Piskunov on 13.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

struct chest {
    int T;
    int K;
    vector <int> keys;
};

struct test_case {
    int K;
    int N;
    vector <int> keys;
    vector <chest> chests;
};

void read(vector <test_case> *tests)
{
    ifstream in("input.txt");
    
    int T;
    in >> T;
    tests->resize(T);
    for (int i = 0; i < T; i++) {
        in >> (*tests)[i].K >> (*tests)[i].N;
        (*tests)[i].keys.resize((*tests)[i].K);
        for (int j = 0; j < (*tests)[i].K; j++) {
            in >> (*tests)[i].keys[j];
            (*tests)[i].keys[j]--;
        }
        (*tests)[i].chests.resize((*tests)[i].N);
        for (int j = 0; j < (*tests)[i].N; j++) {
            in >> (*tests)[i].chests[j].T >> (*tests)[i].chests[j].K;
            (*tests)[i].chests[j].T--;
            (*tests)[i].chests[j].keys.resize((*tests)[i].chests[j].K);
            for (int k = 0; k < (*tests)[i].chests[j].K; k++) {
                in >> (*tests)[i].chests[j].keys[k];
                (*tests)[i].chests[j].keys[k]--;
            }
        }
    }
    
    in.close();
}

void write(vector <vector <int> > *results)
{
    ofstream out("output.txt");
    
    out << "Case #1:";
    if ((*results)[0].size() == 0) out << " IMPOSSIBLE";
    for (int i = 0; i < (*results)[0].size(); i++) {
        out << " " << (*results)[0][i]+1;
    }
    for (int i = 1; i < results->size(); i++) {
        out << endl << "Case #" << i+1 << ":";
        if ((*results)[i].size() == 0) out << " IMPOSSIBLE";
        for (int j = 0; j < (*results)[i].size(); j++) {
            out << " " << (*results)[i][j]+1;
        }
    }
    
    out.close();
}

int cntcnt = 0;

int openedIndex(int n) {
    return pow(2, n);
}

bool openedValue(int opened, int i) {
    opened /= openedIndex(i);
    return opened%2;
}

bool dfs(test_case *test, int *opened, vector <int> *keys, vector <int> *road, set <int> *visited) {
    visited->insert(*opened);
    
    cntcnt++;
    if (cntcnt % 100000 == 0) cout << cntcnt << endl;
    
    bool done = true;
    
    for (int i = 0; i < test->N; i++) {
        if (openedValue(*opened, i)) continue;
        done = false;
        if (!(*keys)[test->chests[i].T]) continue;
        (*opened) += openedIndex(i);
        if (!visited->count(*opened)) {
            (*keys)[test->chests[i].T]--;
            for (int j = 0; j < test->chests[i].keys.size(); j++) {
                (*keys)[test->chests[i].keys[j]]++;
            }
            road->push_back(i);
            if (dfs(test, opened, keys, road, visited)) return true;
            road->pop_back();
            for (int j = 0; j < test->chests[i].keys.size(); j++) {
                (*keys)[test->chests[i].keys[j]]--;
            }
            (*keys)[test->chests[i].T]++;
        }
        (*opened) -= openedIndex(i);
    }
    
    return done;
}

vector <int> solve_test (test_case test)
{
    int opened = 0;
    vector <int> keys(200, 0);
    for (int i = 0; i < test.K; i++) {
        keys[test.keys[i]]++;
    }
    vector <int> road(0);
    set <int> visited;
    dfs(&test, &opened, &keys, &road, &visited);
    return road;
}

void solve(vector <test_case> *tests, vector <vector <int> > *results)
{
    results->resize(tests->size());
    for (int i = 0; i < tests->size(); i++) {
        cout << "test " << i << endl;
        (*results)[i] = solve_test((*tests)[i]);
    }
}

int main(int argc, const char * argv[])
{
    vector <test_case> tests;
    vector <vector <int> > results;
    
    read(&tests);
    solve(&tests, &results);
    write(&results);
    
    return 0;
}