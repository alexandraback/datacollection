#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
const int N=2015;
const int mod=1e9+7;

deque<char> x;
int main() {
    int t;
    string s;
    deque<char>::iterator pos;
    ifstream ifile;
    ofstream ofile;
    ofile.open("/Users/lijiechen/Downloads/in1.txt",ios::out);
    ifile.open("/Users/lijiechen/Downloads/in2.txt",ios::out);
    ifile>>t;
    int kase=0;
    while (t--) {
        ifile>>s;
        kase++;
        int len=s.length();
        int maxx=0;
        for (int i=0; i<len; i++) {
            if (s[i]-'A'>=maxx) {
                x.push_front(s[i]);
                maxx=s[i]-'A';
            } else {
                x.push_back(s[i]);
            }
        }
        ofile<<"Case #"<<kase<<": ";
        for (pos=x.begin(); pos!=x.end(); pos++) {
            ofile<<*pos;
            x.pop_front();
        }
        ofile<<endl;
    }
    return 0;
}