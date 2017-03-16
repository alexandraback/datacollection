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

ifstream cin("/Users/Nagi2/Downloads/GCJ2016/C-small-attempt0.in");
ofstream cout("/Users/Nagi2/Downloads/jjjj.txt");


bool check(vector <int> &vg, vector <int> &ord,int &q){
    if(q<ord.size()){
        int j= (q+1) %ord.size();
    int k = (q+ord.size()-1) %ord.size();
    int qp = ord[q];
    int jp = ord[j];
    int kp = ord[k];
    if(vg[qp]!=jp && vg[qp]!=kp){
        return false;
    }
    }
    bool b=true;

    for(int i=0;i<ord.size();i++){
        int j= (i+1) %ord.size();
        int k = (i+ord.size()-1) %ord.size();
        int ip = ord[i];
        int jp = ord[j];
        int kp = ord[k];
        if(vg[ip]!=jp && vg[ip]!=kp){
            q = ip;
            b = false;
            break;
        }
    }
    return b;
}

//bool check2(vector <int> &vg, vector <int> &ord)
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        vector <int> vi;
        int N;
        cin >> N;
        for(int i=0;i<N;i++){
            int z;
            cin >> z;
            vi.push_back(z-1);
        }
        int best = 0;
        
        for(int i=1;i<(1<<N);i++){
            vector <int> vj;
            for(int j=0;j<N;j++){
                if( ( i &  (1<<j)) != 0) vj.push_back(j);
            }
            if(vj.size()<best) continue;
            bool b = true;
            sort(vj.begin(),vj.end());
            int q = 0;
            while(b){
                
                bool z = check(vi,vj,q);
                //if(z && vj.size() == 7){
                    //cout << "AARGH" << endl;
                //}
                if(z) best = max(best,int(vj.size()));
                if(z) break;
                b = next_permutation(vj.begin(),vj.end());
            }
        }
        cout << "Case #" << t+1 << ": " << best << endl;
    }
    return 0;
}