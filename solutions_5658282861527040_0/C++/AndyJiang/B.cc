#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set> 
#include<cstdlib>
#include<cmath>
#include<string> 
#include<sstream>
#include<queue>
#include<stack>
#include<list>

using namespace std; 

long long work(int a,int b , int k){
    //cout << a << " " << b << " " << k << endl;
    long long re = 0; 
    for(int i = 0; i < a ; i ++)
        for(int j = 0; j < b; j++)
            if((i&j) < k )
                ++re;
    return re;
}

int main(){
    int T; 
    cin >> T; 
    for(int t = 1; t <= T; t++){
        int a,b,k; 
        cin >> a >> b >> k; 
        long long re = work(a,b,k); 
        cout << "Case #" << t << ": "; 
        cout << re << endl; 
    }
}
