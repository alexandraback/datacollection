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

ifstream cin("/Users/Nagi2/Downloads/GCJ2016/B-large.in");
ofstream cout("/Users/Nagi2/Downloads/uuuu.txt");




int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        int N;
        cin >> N;
        int mp[2600] = {0};
        for(int i=0;i<2*N-1;i++){
            for(int j=0;j<N;j++){
                int z;
                cin >> z;
                mp[z]++;
            }
            
        }
        vector <int> vi;
        for(int i=0;i<2600;i++){
            if(mp[i]%2==1)
                vi.push_back(i);
        }
        cout << "Case #" << t+1 << ":" ;
        for(int i=0;i<vi.size();i++){
            cout << " " << vi[i];
            
        }
        cout << endl;
    }
    return 0;
}
