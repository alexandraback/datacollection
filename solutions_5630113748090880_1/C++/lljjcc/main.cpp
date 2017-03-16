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

int num[2505];
int main() {
    int t,n;
    int x,y,z;
    ifstream ifile;
    ofstream ofile;
    ofile.open("/Users/lijiechen/Downloads/out1.txt",ios::out);
    ifile.open("/Users/lijiechen/Downloads/B-large.in.txt",ios::out);
    ifile>>t;
    int kase=0;
    while (t--) {
        ifile>>n;
        kase++;
        memset(num, 0, sizeof(num));
        for (int i=1; i<2*n; i++) {
            for (int j=0; j<n; j++) {
                ifile>>x;
                num[x]++;
            }
        }
        ofile<<"Case #"<<kase<<": ";
        int sum=0;
        for (int i=1; i<=2500; i++) {
            if (num[i]%2==1) {
                ofile<<i<<" ";
                sum++;
            }
        }
        ofile<<endl;
    }
    return 0;
}