#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <limits>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

int main (){
    ifstream fin("C-small-attempt1.in");
    ofstream fout("C.out");
    int cpt; fin>>cpt;
    for (int z=1;z<=cpt;++z){
        int n,m,k;
        fin>>n>>m>>k;
        if (n>m){
            int tp=n;
            n=m;
            m=tp;
        }
        int act=5,p=1,q=1,ans=4;
        bool fst,snd;
        while (act<k){
            //fout<<p<<"  "<<q<<"  "<<act<<"  "<<ans<<endl;
            if (act==k-1) {
                ans++;
                act=k;
            }
            if (act<k){
                if (p<q){
                    fst=true;
                    if (p+1>=n) fst=false;
                    else {
                        p++;
                        act+=2+q;
                        ans+=2;
                        //fout<<p<<"  "<<act<<"  "<<ans<<endl;
                    }
                    snd=true;
                    if (!fst) {
                        if (q+1>=m) snd=false;
                        else {
                            q++;
                            act+=2+p;
                            ans+=2;
                        }
                    }
                } else {

                    fst=true;
                        if (q+1>=m) snd=false;
                        else {
                            q++;
                            act+=2+p;
                            ans+=2;
                        }
                    snd=true;
                    if (!fst) {
                    if (p+1>=n) snd=false;
                    else {
                        p++;
                        act+=2+q;
                        ans+=2;
                        //fout<<p<<"  "<<act<<"  "<<ans<<endl;
                    }}
                }

                if (!fst && !snd) {
                    //fout<<"here"<<endl;
                    ans+=(k-act);
                    act=k;
                }
            }
        }
        //fout<<p<<"  "<<q<<"  "<<act<<"  "<<ans<<endl;
        fout<<"Case #"<<z<<": "<<ans<<endl;
    }
    return 0;
}
