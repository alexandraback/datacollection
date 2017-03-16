#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct pair{
    int la;
    int lb;
    bool da;
    bool db;
    pair(){
        da = db = false;
    }
}tow[1010];

int main(){
    freopen("2.out", "w", stdout);
    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        int n;
        cin >> n;
        
        
        for(int i = 0; i < n; i++){
            cin >> tow[i].la >> tow[i].lb;
            tow[i].da = tow[i].db = false;
        }

        int cnt = 0;
        int star = 0;
        bool flag = true;
        int solve = 0;
        while(flag && solve < n){
            flag = false;
            for(int i = 0; i < n; i++){
                if(tow[i].db == false && star >= tow[i].lb){
                    star += tow[i].da ? 1 : 2;
                    tow[i].db = tow[i].da = true;
                    solve++;
                    cnt++;
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            for(int i = 0; i < n; i++){
                if(tow[i].da == false && star >= tow[i].la){
                    star += 1;
                    tow[i].da = true;
                    flag = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << "Case #" << cases <<  ": ";
        if(solve != n)
            cout << "Too Bad" << endl;
        else
            cout << cnt << endl;
    }
    return 0;
}
