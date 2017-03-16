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


void UpdateRes(string &str1, string &str2) {
    stringstream stream;
    stream << str1 << ' ' << str2;
    int a, b;
    stream >> a >> b;
    if (abs(a - b) < diff) {
        diff = abs(a - b);
        ma = str1;
        mb = str2;
    }
}

void SecondBigger(string str1, string str2, int p) {
    for (int i = p; i < str1.size(); ++i) {
        if (str1[i] == '?') {
            str1[i] = '9';
        }
        if (str2[i] == '?') {
            str2[i] = '0';
        }
    }
    UpdateRes(str1, str2);
}

void FirstBigger(string str1, string str2, int p) {
    for (int i = p; i < str1.size(); ++i) {
        if (str2[i] == '?') {
            str2[i] = '9';
        }
        if (str1[i] == '?') {
            str1[i] = '0';
        }
    }
    UpdateRes(str1, str2);
}

void rec(string &str1, string &str2,  int p) {
    if (p >= str1.size()) {
        UpdateRes(str1, str2);
        return;
    }
    
    if (str1[p] == '?' && str2[p] == '?') {
        str1[p] = '1';
        str2[p] = '0';
        FirstBigger(str1, str2, p);
        
        str1[p] = '0';
        str2[p] = '1';
        SecondBigger(str1, str2, p);
        
        str1[p] = '0';
        str2[p] = '0';
        rec(str1, str2, p + 1);
    }
    else if (str1[p] == '?' && str2[p] != '?') {
        if (str2[p] != '9') {
            str1[p] = str2[p] + 1;
            FirstBigger(str1, str2, p);
        }
        if (str2[p] != '0') {
            str1[p] = str2[p] - 1;
            SecondBigger(str1, str2, p);
        }
        str1[p] = str2[p];
        rec(str1, str2, p + 1);
    }
    else if (str2[p] == '?' && str1[p] != '?') {
        if (str1[p] != '9') {
            str2[p] = str1[p] + 1;
            SecondBigger(str1, str2, p);
        }
        if (str1[p] != '0') {
            str2[p] = str1[p] - 1;
            FirstBigger(str1, str2, p);
        }
        str2[p] = str1[p];
        rec(str1, str2, p + 1);
    }
    else {
        F2(i, str1) {
            if (str1[i] > str2[i]) {
                FirstBigger(str1, str2, i);
                return;
            }
            else if (str1[i] < str2[i]) {
                SecondBigger(str1, str2, i);
                return;
            }
            else  if(i == str1.size() - 1) {
                FirstBigger(str1, str2, i);
                return;
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