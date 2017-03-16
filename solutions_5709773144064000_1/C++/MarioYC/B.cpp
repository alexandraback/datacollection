#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

double calc(double C, double F, double X, int n){
    double ret = X / (F * n + 2);
    
    for(int i = 1;i <= n;++i)
        ret += C / (F * (i - 1) + 2);
    
    return ret;
}

int main(){
    //ios::sync_with_stdio(0);
    
    int TC;
    double C,F,X;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> C >> F >> X;
        
        //double best = X / 2;
        //cout << 0 << " " << best << endl;
        /*int cont = 0,maxbest = 0;
        
        for(int i = 1;i <= 2000;++i){
            double aux = X / (F * i + 2);
            
            for(int j = 1;j <= i;++j)
                aux += C / (F * (j - 1) + 2);
            
            if(aux <= best){
                maxbest = i;
                ++cont;
            }
            
            best = min(best,aux);
            //cout << i << " " << aux << endl;
        }*/
        
        int lo = 0,hi = 1000000,mi1,mi2;
        
        while(hi - lo > 4){
            mi1 = (2 * lo + hi) / 3;
            mi2 = (lo + 2 * hi) / 3;
            
            if(calc(C,F,X,mi1) <= calc(C,F,X,mi2)) hi = mi2;
            else lo = mi1;
        }
        
        double best = X / 2;
        
        for(int i = lo;i <= hi;++i)
            best = min(best,calc(C,F,X,i));
        
        //cout << maxbest << " " << cont << endl;
        
        cout << "Case #" << tc << ": ";
        printf("%.10f",best);
        cout << endl;
    }
    
    return 0;
}
