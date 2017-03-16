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

int64 diff;
string ma, mb;

void rec(string &str1, string &str2,  int p) {
    if (p >= str1.size()) {
        stringstream stream;
        stream << str1 << ' ' << str2;
        int a, b;
        stream >> a >> b;
        if (abs(a - b) < diff) {
            diff = abs(a - b);
            ma = str1;
            mb = str2;
        }
        return;
    }
    for (char c1 = '0'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
            if (str1[p] == '?' && str2[p] == '?') {
                str1[p] = c1;
                str2[p] = c2;
                rec(str1, str2, p + 1);
                str1[p] = '?';
                str2[p] = '?';
            }
            else if (str1[p] == '?') {
                str1[p] = c1;
                rec(str1, str2, p + 1);
                str1[p] = '?';
            }
            else if (str2[p] == '?') {
                str2[p] = c2;
                rec(str1, str2, p + 1);
                str2[p] = '?';
            }
            else {
                rec(str1, str2, p + 1);
            }
        }
    }
   
}

void Do(fstream &cin, fstream &cout) {
    string str1;
    string str2;
    cin >> str1 >> str2;
    diff = 9999999;
    rec(str1, str2, 0);
    cout << ma << ' ' << mb << endl;
    
    
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
}