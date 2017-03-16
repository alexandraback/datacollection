#include<bits/stdc++.h>

int solve(int n);


using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int n;
        int ret;
        
        cin >> n;
        ret = solve(n);
        
        if (ret == -1){
            cout << "Case #" << i + 1 << ": " << "INSOMNIA" << endl;        
        }else{
            cout << "Case #" << i + 1 << ": " << ret << endl;
        }
    }
}

int solve(int n){
    if (n == 0){
        return -1;
    }
    
    vector< int > used;
    used.resize(10);
    
    for (int i = 0; i < 10; i++){
        int a = 1;
        while(used[i] == 0){
            int currend = a * n;
            for (int j = 1; currend > 0; j++){
                if (currend % 10 == i){
                    used[i] = a;
                }
                currend = currend / 10;
            }
            a++;
        }
    }
    
    int maxi = 0;
    for (int i = 0; i < 10; i++){
        maxi = max(maxi, used[i]);
    }
    
    return maxi * n;
}