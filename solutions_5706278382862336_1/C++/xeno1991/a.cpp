#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<boost/rational.hpp>
using namespace std;

typedef unsigned long long ull;

int getbit(ull n){
    int res=0;
    while(n){
        n = n>>1;
        res++;
    }
    return res;
}

//2のn乗かチェック
bool check(ull n){
    int count=0;
    while(n){
        count += (n&1);
        n = n>>1;
    }
    return count==1;
}


//solver
unsigned long long solve(ull P,ull Q){
    ull res=0;
    boost::rational<ull> a(P,Q);

    P = a.numerator();
    Q = a.denominator();

    if(!check(Q)){
        return 0;
    }

    //Pの最上位ビットの位置を探す
    int p=getbit(P);
    int q=getbit(Q);

    return q-p;
}

int main(){
    int CASE;
    cin >> CASE;
    for(int tcase=1;tcase<=CASE;tcase++){
        
        //input
        ull P,Q;
        scanf("%llu/%llu",&P,&Q);

        //solve 
        auto ans = solve(P,Q);

        if(ans==0 || ans>40){
           cout << "Case #" << tcase << ": " << "impossible"<< endl;
        }
        else{
           cout << "Case #" << tcase << ": " << ans << endl;
        }
    }

    return 0;
}
