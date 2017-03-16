#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int q = 0 ; q < t; q++){
        int a, b, k;
        cin >> a >> b >> k;
        int licznik=0;
        for(int i = 0 ; i < a; i++){
            for(int j = 0; j < b; j++){
                int x=i&j;
                if(x<k){
                    //cout << i << " " << j << " " << k << "\n";
                    licznik++;
                }
            }
        }
        //cout << licznik << "\n";
        printf("Case #%d: %d\n", q+1, licznik);
    }
}
