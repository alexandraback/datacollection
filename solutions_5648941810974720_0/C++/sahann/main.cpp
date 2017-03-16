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
ofstream cout("/Users/Nagi2/Downloads/qwertyA.txt");




int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        string s;
        
        cin >>s;
        int cnt[10]={0};
        cnt[2] = count(s.begin(),s.end(),'W');
        cnt[8] = count(s.begin(),s.end(),'G');
        cnt[6] = count(s.begin(),s.end(),'X');
        cnt[3] = count(s.begin(),s.end(),'H')-cnt[8];
        cnt[4] = count(s.begin(),s.end(),'U');
        cnt[7] = count(s.begin(),s.end(),'S')- cnt[6];
        cnt[5] = count(s.begin(),s.end(),'V') - cnt[7];
        cnt[0] = count(s.begin(),s.end(),'Z');
        cnt[1] = count(s.begin(),s.end(),'O')-cnt[4]-cnt[2]-cnt[0];
        cnt[9] = (count(s.begin(),s.end(),'N')-cnt[1]-cnt[7])/2;
        
        string s2;
        for(int i=0;i<10;i++){
            for(int j=0;j<cnt[i];j++){
                s2+= i+'0';
            }
        }
        cout << "Case #" << t+1 << ": " << s2<< endl;
    }
    return 0;
}
