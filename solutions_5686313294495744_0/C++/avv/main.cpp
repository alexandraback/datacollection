#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include <climits>
#include <cstring>
#include <list>
#include <iomanip>

using namespace  std;

#define int64 unsigned long long
#define F(vec, index) for (int index=0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index=0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int indexfrom + 1; index  < vec.size(); ++index)


vector<pair<int, int>> edges;
vector<bool> was;


int ma = 0;

void rec(int p, int edgeC, int vC) {
    if (vC == was.size()) {
        ma = max(ma, int(edges.size()) - edgeC);
        return;
    }
    if (p >= edges.size()) return;
    
    
    
    int v1 = edges[p].first;
    int v2 = edges[p].second;
    
    if (!was[v1] && !was[v2]) {
        was[v1] = true;
        was[v2] = true;
        rec(p + 1, edgeC + 1, vC + 2);
        was[v1] = false;
        was[v2] = false;

    }
    else if (!was[v1] && was[v2]) {
        was[v1] = true;
        rec(p + 1, edgeC + 1, vC + 1);
        was[v1] = false;
    }
    else if (was[v1] && !was[v2]) {
        was[v2] = true;
        rec(p + 1,  edgeC + 1, vC + 1);
        was[v2] = false;
    }
    rec(p + 1, edgeC, vC);
    
    
}

void Do(fstream &cin, fstream &cout) {
    int n;
    cin >> n;
    
    vector<pair<string, string>> data(n);
    F2(i, data) {
        cin >> data[i].first >> data[i].second;
    }
    
    map<string, int> k1;
    map<string, int> k2;
    
    F2(i, data) {
        if (k1.count(data[i].first) == 0) {
            k1.insert({data[i].first, k1.size()});
        }
    }
    F2(i, data) {
        if (k2.count(data[i].second) == 0) {
            k2.insert({data[i].second, k1.size() + k2.size()});
        }
    }
    int N = k1.size() + k2.size();
    edges.clear();
    was.clear();
    was.resize(N, false);

    
    F2(i, data) {
        int v1 = k1[data[i].first];
        int v2 = k2[data[i].second];
        edges.push_back({v1, v2});
    }
    ma = 0;
    rec(0, 0, 0);
    cout << ma << endl;
   
    

    
    
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    
    fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
    fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
    
   	int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        //std::cout << i << endl;
        cout << "Case #" << i + 1 << ": ";
        Do(cin, cout);
    }
    return 0;
}