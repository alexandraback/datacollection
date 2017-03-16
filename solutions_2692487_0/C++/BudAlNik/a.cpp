#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long t, n, a, num;
vector <long long> mas;

pair <int, long long> func(int a, int num){
    int ans = 0;
    while(a <= num){
        ++ans;
        a += a - 1;
    }
    return make_pair(ans, a);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    
    for(int k = 0; k < t; ++k){
        
        cin >> a >> n;
        for(int i = 0; i < n; ++i){
            cin >> num;
            mas.push_back(num); 
        }
        sort(mas.begin(), mas.end());
        int ans = 0;
        if(a == 1){
            ans = n;
        }
        else{
            ans = n;
            for(int i = 0; i < n; ++i){   
                long long nows = a;
                int nowans = 0;
                for(int j = 0; j <= i; ++j){
                    pair <int, long long> p = func(nows, mas[j]);
                    nows = p.second + mas[j];
                    nowans += p.first;    
                } 
                nowans += n - 1 - i;
                ans = min(ans, nowans);
            }
        }
        cout << "Case #" << k + 1 << ": " << ans << "\n";
        mas.clear();
    }
    return 0;
}                                       