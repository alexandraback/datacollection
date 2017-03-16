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



void Do(fstream &cin, fstream &cout) {
    int b;
    int64 m;
    cin >> b >> m;
    
    vector<string> g(b, string(b, '0'));
    
    for (int i = 1; i < b - 1; ++i) {
        for (int j = i + 1; j < b; ++j) {
            assert(i < b);
            assert(j < b);
            g[i][j] = '1';
        }
    }
    g[0][b - 1] = '1';
    --m;
    int v = b - 2;
    while (m != 0 && v > 0) {
        if (m % 2 == 1) {
            assert(v < b && v >=0);
        	g[0][v] = '1';
        }
        m /= 2;
        v--;
    }
    
    if (m != 0) {
        cout << " IMPOSSIBLE" << endl;
       
    }
    else {
        cout << " POSSIBLE" << endl;
        F2(i, g) {
            cout << g[i] << endl;
        }
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

