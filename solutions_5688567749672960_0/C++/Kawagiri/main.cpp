//
//  main.cpp
//  GCJRoundB－A
//
//  Created by 冥途雨中旅 on 15/5/3.
//  Copyright (c) 2015年 Gensokyou. All rights reserved.
//

#include <iostream>
using namespace std;

int f[2000000];

int inverse(int biu){
    int k = 0;
    for(;biu != 0;biu /= 10)
        k *= 10,k += biu  % 10;
    return k;
}

long long first_(long long k){
    long long ret = 1;
    for(;k >= 10;k /= 10)ret *= 10;
    return k * ret;
}

long long second_(long long k){
    long long ret = 1;
    for(;k >= 100; k /= 10)ret *= 10;
    return k % 10 * ret;
}

long long second_2(long long k){
    long long ret = 1;
    for(;k >= 100; k /= 10)ret *= 10;
    return ret;
}

int first(long long k){
    for(;k >= 10;k /= 10);
    return (int)k;
}

int second(long long k){
    for(;k >= 100; k /= 10);
    return k % 10;
}

long long pp(long long k){
    long long yo = 9900;
    for(;yo * 10+1 < k;yo *= 10);
    return yo + 1;
}



long long hou3(long long k){
    return k - first_(k) - second_(k);
    
}

long long calc(long long k){
    if(k < 10000)
        return f[k];
    
    int a = first(k);
    int b = second(k);
    if(a == 1 && b == 0){
        long long hei  = pp(k);
        return k - hei  +  calc(hei);
    }
    long long hei = pp(k);
    //cout << k << "    " << first(k) << "    "  << calc(hei) << "  "  << second_2(k) << endl;
    return first(k) + second(k) * 10 + hou3(k) - 1 + calc(hei) + second_2(pp(k));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("../../../../GCJRoundB－A/in","r",stdin);
    freopen("../../../../GCJRoundB－A/out","w",stdout);
    int T;
    cin >> T;
    memset(f, 63,sizeof f);
    f[1] = 1;
    for(int i = 2; i<= 1000000; ++ i){
        
        
        if(f[i-1] + 1 < f[i]){
            f[i] = f[i - 1] + 1;
        }
        if(i % 10)
            f[i] = min(f[i],f[inverse(i)] + 1);
    }
    
    
/*    for(int i = 1;i < 60000 ; ++i){
        if(f[i] != f[i- 1] + 1)
            cout << i<< ':' << f[i];
        else if( f[i] != f[i +1] - 1){
            cout << " " << i << ':'  << f[i] << endl;
        }
    }
   */
  
    for(int l = 1;l <= T; ++l){
        long long n;
        cin >> n;
        cout << "Case #" << l << ": " << f[n] << endl;
    }
    return 0;
}
