#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int nn; 
    cin >> nn;
    for (int i = 1; i<=nn; i++) {
        cout << "Case #"<<i<<":";
        int N;
        cin >> N;
        map<int,int> V;
        for (int i = 0 ; i < (N+N-1)*N; i++) {
            int t;
            cin >> t; V[t] ++;
        }
        for (auto a:V) {
            if (a.second % 2 != 0)
            cout <<" "<<a.first;
        }
        cout << endl;

            
        /*
        vector< vector<int> > mm;
        for (int i = 0; i<N+N-1; i++) {
            vector<int> mt;
            for (int j = 0 ; j < N; j++) {
                int t; cin >> t; mt.push_back(t);
            }
            mm.push_back(mt);
        }
        vector <int> vmin, vmax;
        for (auto a: mm) {
            vmin.push_back(a.begin());
            vmax.push_back(a.rbegin());
        }
        sort(vmin.begin(),vmin.end());
        sort(vmax.begin(),vmax.end());
        bool revflag = false;
        if (vmin[0]!=vmin[1]) {
            revflag = true;
            for (int i = 0 ; i < N+N-1; i++)
                for (int j = 0 ; j < N; j++)
                    mm[i][j] = -mm[i][j];
        }*/

         
    }
    

    
}
