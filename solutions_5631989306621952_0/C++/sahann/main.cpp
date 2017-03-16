#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

ifstream cin("/Users/Nagi2/Downloads/GCJ2016/A-small-attempt0.in");
ofstream cout("/Users/Nagi2/Downloads/rrrr.txt");




int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        string s;
        cin >> s;
        string s2;
        for(int i=0;i<s.size();i++){
            if(i==0) s2+=s[0];
            else{
                string s3,s4;
                s3=s.substr(i,1) + s2;
                s4= s2 + s.substr(i,1);
                s2 = max(s3,s4);
            }
        }
        cout << "Case #" << t+1 << ": " << s2 << endl;
    }
    return 0;
}
