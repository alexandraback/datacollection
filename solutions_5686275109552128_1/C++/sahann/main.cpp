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
#include <iterator>
#include <fstream>

using namespace std;
//can D be 0 ? this should be checked

ifstream cin("/users/naginahas/Documents/B-large.in");
ofstream cout("/users/naginahas/Documents/B-largeout.txt");

int main(){
    int T=0;
    cin >> T;
    for(int t=0;t<T;t++){
        int D;
        cin >> D;
        vector <int> vi;
        for(int i=0;i<D;i++){
            int x;
            cin >> x;
            vi.push_back(x);
        }
        //try all possible maxr
        int best = 1000*1000*1000;
        int mx = *max_element(vi.begin(),vi.end());
        for(int mxr=mx;mxr>=1;mxr--){
            int special = 0;
            for(int i=0;i<vi.size();i++){
                int z = vi[i]/mxr;
                if(z*mxr!=vi[i]) z++;
                if(z>0) z--;
                special+=z;
            }
            if(special+mxr < best) best = special + mxr;
        }
        cout << "Case #" << t+1 << ": " << best << endl;
        
    }
    
}


