#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
   // freopen("2.out", "w", stdout);
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int n, s, p;
        cin >> n >> s >> p;
        int tmp;
        int cnt = 0;
        while(n--){
            cin >> tmp;
            if(tmp == 0){
                if(p == 0)
                    cnt++;
            }
            else if((tmp + 2) / 3 >= p)
                cnt++;
            else if(s > 0 && (tmp + 4) / 3 >= p)
                cnt++, s--;
        }
        cout << "Case #" << k << ": " << cnt << endl;
    }
    return 0;
}
