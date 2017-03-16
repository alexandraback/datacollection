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

map<char, int64> GetMap(string &str) {
    map<char, int64> m;
    F2(i, str) {
        ++m[str[i]];
    }
    
    return m;
}

void Do(fstream &cin, fstream &cout) {
    string str;
    cin >> str;
    map<char, int64> m = GetMap(str);
    
    //vector<string> data = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    vector<string> data ={"ZERO", "TWO", "SIX", "FOUR", "FIVE", "EIGHT", "THREE","NINE", "ONE", "SEVEN", };
    vector<int> dataMap = {0, 2, 6 , 4, 5 , 8, 3, 9, 1, 7};
    vector<int> result;
    vector<map<char, int64>> maps;
    F2(i, data) {
        maps.push_back(GetMap(data[i]));
    }
    
    F2(i, data) {
        int64 res = -1;
        auto currMap = maps[i];
        for (auto j = currMap.begin(); j != currMap.end(); ++j) {
            char c = j->first;
      	    int k = j->second;
            if (res == -1) {
                res = m[c] / k;
            }
            else {
                res = min(res, m[c] / k);
            }
        }
        for (auto j = currMap.begin(); j != currMap.end(); ++j) {
            char c = j->first;
            int k = j->second;
            m[c] -= res * k;
        }
        for (int j = 0; j < res; ++j) {
            result.push_back(dataMap[i]);
        }
    }
    sort(result.begin(), result.end());
    F2(i, result) {
        cout << result[i];
    }
    for (auto j = m.begin(); j != m.end(); ++j) {
        assert(j->second == 0);
    }
    cout << endl;
    
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    
    fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
    fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
    
   	int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Do(cin, cout);
    }
    return 0;
}