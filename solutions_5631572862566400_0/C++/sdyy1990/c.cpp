#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int VV[1024];
int cid[1024];
int main() {
    int nn; 
    cin >> nn;
    for (int jjj = 1; jjj<=nn; jjj++) {
        int n;
        cout <<"Case #"<<jjj<<": ";
        cin >> n;
        memset(VV,0,sizeof(VV));
        for (int i = 1; i<= n ; i++)
            cin >> VV[i];
        memset(cid,0,sizeof(cid));
        int ccnt = 0;
        map<int,int> clength;
        map<int,int> taillength;
        int maxlength = 0;
        for (int i = 1; i<= n; i++) 
            if (cid[i]==0) {
                int p = i;
                ++ccnt;
                while (cid[p] ==0 ){
                    cid[p] = ccnt;
                    p = VV[p]; 
                } 

                //cid[p] !=0,
                if (cid[p] != ccnt) continue;
                int q = VV[p];
                int cirlength = 1;
                while (q!=p) {
                    cirlength ++;
                    q = VV[q];
                }
                clength[q] = cirlength;
                if (cirlength ==2) clength[VV[q]] = 2;
                if (cirlength > maxlength) maxlength = cirlength;
           
            }
        for (int i = 1; i<=n; i++) {
            int p = i;
            int tt = 1;
            while (clength.find(p) == clength.end()) { p = VV[p]; tt++;} 
            if (clength[p] == 2) if (taillength[p] < tt) taillength[p] = tt;
        }

    //    for (auto a: clength) 
    //        cout << "C "<<a.first <<"  " << a.second << endl;
        int ans= 0 ;        
        for (auto a: taillength)
            //cout << "T "<<a.first <<"  " << a.second << endl;
            ans += a.second;
      //  cout << endl;
      //  cout << endl;
            if (maxlength > ans) cout << maxlength; else cout << ans;
            cout << endl;
        
                    
    }
    

    
}
