#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;
typedef long long LL ;
const int maxn = 10050 ;

int sub_mul[4][4] = {
0,1,2,3,
1,4,3,6,
2,7,4,1,
3,2,5,4
};
char bufin[maxn] ;
int v[maxn] , pre[maxn] , suf[maxn], L ;
LL X ;

int Mul(int a, int b) {
    int add = 0 ;
    if(a >= 4) add += 4 , a -= 4 ;
    if(b >= 4) add += 4 , b -= 4 ;
    return ( sub_mul[a][b] + add ) % 8 ;
}

int Pow(int a, LL n) {
    if(n == 0) return 0 ;
    if(n == 1) return a ;
    int tmp = Pow(a , n/2) ;
    if(n&1) return Mul(Mul(tmp , tmp) , a) ;
    else return Mul(tmp , tmp) ;
}

int ID(string s) {
    if(s == "1") return 0 ;
    if(s == "i") return 1 ;
    if(s == "j") return 2 ;
    if(s == "k") return 3 ;
    if(s == "-1") return 4 ;
    if(s == "-i") return 5 ;
    if(s == "-j") return 6 ;
    if(s == "-k") return 7 ;
    assert(0) ;
}


int main()
{

    //freopen("C-large.in", "r" ,stdin);
    //freopen("large.txt", "w", stdout) ;

    int T, cas = 1;
    cin>>T ;
    while(T--) {
        cin>>L>>X;
        cin>>bufin;
        pre[0] = suf[L+1] = 0 ;
        for(int i=1; i<=L; i++) {
            string tmp = "";
            tmp += bufin[i-1] ;
            v[i] = ID(tmp) ;
            pre[i] = Mul(pre[i-1]  , v[i]) ;
        }
        for(int i=L;  i>=1; i--) suf[i] = Mul(v[i] , suf[i+1]) ;

        LL ln = -1 , lp = -1 ,rn = 0 , rp = 0 ;
        bool foundi = false ,foundj = false , foundk = false;

        int tmp  = 0 ;
        for(LL i=1; i<=4 && i<=X; i++) {
            for(int j=1; j<=L ;j++) {
                tmp = Mul(tmp , v[j]) ;
                if(tmp == 1) {
                    foundi = true ;
                    ln = i;
                    lp = j ;
                    break ;
                }
            }
            if(foundi) break ;
        }

        tmp = 0 ;
        for(LL i=X; i>X-4 && i>=1; i--) {
            for(int j=L; j>=1; j--) {
                tmp = Mul(v[j] , tmp) ;
                if(tmp == 3) {
                    foundk = true ;
                    rn = i ;
                    rp = j ;
                    break ;
                }
            }
            if(foundk) break ;
        }

        if(foundi && foundk && (ln*L+lp < rn*L+rp)) {
            if(ln == rn) {
                tmp = 0 ;
                for(int i=lp+1; i<rp; i++)  tmp = Mul(tmp , v[i]) ;
                if(tmp == 2) foundj = true ;
            }
            else {
                int left = suf[lp+1];
                int right = pre[rp-1] ;
                int mid = Pow(pre[L] , rn-ln-1) ;
                int sum = Mul(left , mid) ;
                sum = Mul(sum , right) ;
                if(sum == 2) foundj = true ;
            }
        }

        if(foundi && foundj && foundk) printf("Case #%d: YES\n", cas++ );
        else printf("Case #%d: NO\n", cas++) ;

    }

    return 0;
}
