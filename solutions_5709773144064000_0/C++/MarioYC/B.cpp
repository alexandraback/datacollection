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

int main(){
    //ios::sync_with_stdio(0);
    
    int TC;
    double C,F,X;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> C >> F >> X;
        
        double best = X / 2;
        //cout << 0 << " " << best << endl;
        
        for(int i = 1;i <= 20000;++i){
            double aux = X / (F * i + 2);
            
            for(int j = 1;j <= i;++j)
                aux += C / (F * (j - 1) + 2);
            
            best = min(best,aux);
            //cout << i << " " << aux << endl;
        }
        
        cout << "Case #" << tc << ": ";
        printf("%.10f",best);
        cout << endl;
    }
    
    return 0;
}
