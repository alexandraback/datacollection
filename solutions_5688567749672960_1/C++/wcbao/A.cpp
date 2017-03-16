//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <vector>
//#include <cstring>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <map>
//#include <queue>
//#include <set>
//#define gcd(A,B) __gcd(A,B)
//#define lcm(A,B) (A/gcd(A,B)*B)
//#define clr(A) memset(A,0,sizeof(A))
//
//
//using namespace std;
//
//typedef long long LL;
//typedef pair<int,int> P;
//typedef pair<P,int> pp;
//const int mod = 1000000007;
//const int root = 1;
//const int mm = 1000005;
//
//
//int A[100],C[100];
//LL fac[100];
//int open(LL x, int a[]){
//    int res = 0;
//    while(x){
//        a[res++] = x % 10;
//        x /= 10;
//    }
//    return res;
//}
//
//LL calc(int l,int a[]){
//    LL res = 0;
//    for(int i = l-1; i>=0;i--)
//        res = res * 10 + a[i];
//    return res;
//}
//
//LL solve(LL s,LL e){
//    int A[100],B[100],C[100];
//    if(s >= e) return 0;
//    int l1 = open(s,A),
//        l2 = open(e,B);
//    int l = l1, r = 0;
//    LL res = 0;
//    for(int i = l-1; i >= 0; i--){
//        if(l-1-i >= i){
//            res += calc(l,B) - calc(l,A);
//            return res;
//        }
//        for(int j = l-1; j >= 0; j--) C[j] = A[j];
//        int f = 0;
//        for(int j = l-1; j >= i; j--) {
//            if(A[j] != B[j]) f = 1;
//            C[l-1-j] = B[j];
//        }
//        if(f==0) continue;
//        LL d = calc(l-1,C) - calc(l-1,A);
//        if(d) res += d+1;
//        for(int j = l-1; j >= 0; j--) A[l-1-j] = C[j];
//    }
//    return res;
//}
//
//int main()
//{
//   freopen("wcbao.in","r",stdin);
//   freopen("wcbao.out","w",stdout);
//    int T = 0, cas = 0;
//    fac[0] = 1;
//    for(int i = 1; i <= 15; i++)
//        fac[i] = fac[i-1] * 10;
//    cin >> T;
//    while(T--)
//    {
//        printf("Case #%d: ",++cas);
//        LL n;
//        cin >> n;
//        LL ans = 0;
//        int l = open(n,A);
//        for(int i = 0; i < l-1;i++) {
//            ans += solve(fac[i],fac[i+1]-1);
//            ans ++;
//        }
//        LL d = solve(fac[l-1],n);
//        cout << ans+d+1<< endl;
//    }
//    return 0;
//}
