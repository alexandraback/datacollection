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
#include <unordered_map>


using namespace  std;

#define int64 long long
#define F(vec, index) for (int index=0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index=0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int indexfrom + 1; index  < vec.size(); ++index)
#define _GLIBCXX_DEBUG
/*
void Do(fstream &cin, fstream &cout) {
    
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    
    fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
    fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
    
   	int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << i << endl;
        cout << "Case #" << i + 1 << ": ";
        Do(cin, cout);
    }
    return 0;
}*/



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
#include <unordered_map>


using namespace  std;

#define int64  long long
#define F(vec, index) for (int index=0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index=0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int indexfrom + 1; index  < vec.size(); ++index)
#define _GLIBCXX_DEBUG

int b;
int m;
bool loop;
int path = 0;

void rec2(vector<string> &g, int v,  vector<bool> &was) {
    if (loop) return;
    if (was[v]) {
        loop = true;
        return;
    }
    if (v == b - 1) {
        ++path;
        return;
    }

    was[v] = true;
    F2(i, g[v]) {
        if (g[v][i] == '1')
        	rec2(g, i, was);
    }
    was[v] = false;
}
//Loop(vector<string> &g, int v,  vector<bool> &was)

bool Add(vector<string> &g, int v, int k) {
    for (int j = 0; j < b; ++j) {
        if (((k >> j) & 1) == 1) {
            assert(v < g.size());
            assert(j < g[0].size());
            g[v][j] = '1';
            if (v == j) return false;
        }
        else {
            g[v][j] = '0';
        }
    }
    return true;
}

vector<bool> was(b, false);
void rec(vector<string> &g, int v, fstream &cout) {
    if (path == m) {
        return;
    }
    if (v == b - 1) {
        
        was.assign(b, false);
        loop = false;
        path = 0;
        rec2(g, 0, was);
        if (loop) {
            path = -1;
            return;
        }
        if (path == m) {
            cout << " POSSIBLE" << endl;
            F2(i, g) {
                cout << g[i] << endl;
            }
        }
        return;
    }
    vector<string> newG = g;
    for (int k = 0; k < (1 << b); ++k) {
       
         
        if (Add(newG, v, k)) {
         	rec(newG, v + 1, cout);
        }
     }
    
}

void Do(fstream &cin, fstream &cout) {
    cin >> b >> m;
    
    vector<string> g(b, string(b, '0'));
    path = -1;
    rec(g, 0, cout);
    if (path != m) {
        cout << " IMPOSSIBLE" << endl;
    }
    
}
 
int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
 	fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
 	fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
 
	int t;
 	cin >> t;
 	for (int i = 0; i < t; ++i) {
 		std::cout << i << endl;
 		cout << "Case #" << i + 1 << ":";
 		Do(cin, cout);
	}
	return 0;
}

