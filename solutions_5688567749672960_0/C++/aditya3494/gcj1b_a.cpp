#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
typedef long long lli;

#define pb push_back
#define mp make_pair

lli getval(lli x)
{

    lli ans = 1;
    for(int i = 1;i <= x;i++) {
        ans = ans * 10;
    }
    return ans;
}

int numdig(lli val)
{

    int ans = 0;
    while(val > 0) {
        ans++;
        val/=10;
    }
    return ans;
}

lli revnum(lli num)
{

    lli ans = 0;
    while(num > 0) {
        ans = ans*10 + num%10;
        num/=10;
    }
    return ans;
}

int main()
{
    freopen("abc3.in", "r", stdin);
    freopen("out3.txt", "w", stdout);

    int t;
    cin >> t;
    lli N;
    lli dig10[16];
    dig10[1] = 10;
    for(lli i = 2; i <= 15;i++) {
        lli x = dig10[i-1] + 9 + getval(i-1);
        dig10[i]=x;
    }

    for(int kase = 1;kase <= t;kase++) {

        cin >> N;
        if(N <= 10) {
            printf("Case #%d: %lld\n", kase, N);
            continue;
        }
        int dig = numdig(N);
        if(N==(getval(dig-1))) {
             printf("Case #%d: %lld\n", kase, dig10[dig-1]);
             continue;
        }
        lli ans = 0;



        if( N%(getval(dig-1)) != 0) {
            lli ans1, ans2 = 10000000000000000LL;
            lli c1, c2;
            ans1 = dig10[dig-1];
            c1 = getval(dig-1);
            if(c1 != N) {
                ans1 = ans1 + N/getval(dig-1) ;
                c1 += N/getval(dig-1);
                if((N/getval(dig-1)) == 1 && c1 != N) {
                    ans1--;
                }
                if(c1 != N) {
                    ans1 += N%getval(dig-1);
                }
            }

            lli v = N;

            if(N%10 != 0) {
                N = revnum(N);

                if(v != N) {
                    ans2 = 1 + dig10[dig-1];
                    c2 = getval(dig-1);
                    if(c2 != N) {
                        ans2 = ans2 + N/getval(dig-1) ;
                        c2 += N/getval(dig-1);
                        if((N/getval(dig-1)) == 1 && c2 != N) {
                            ans2--;
                        }
                        if(c2 != N) {
                            ans2 += N%getval(dig-1);
                        }
                    }
                }
            }

            ans = min(ans1, ans2);
        } else {
            N = N - getval(dig-1) + 1;
            lli ans1, ans2 = 10000000000000000LL;
            lli c1, c2;
            ans1 = dig10[dig-1];
            c1 = getval(dig-1);
            if(c1 != N) {
                ans1 = ans1 + N/getval(dig-1) ;
                c1 += N/getval(dig-1);
                if((N/getval(dig-1)) == 1 && c1 != N) {
                    ans1--;
                }
                if(c1 != N) {
                    ans1 += N%getval(dig-1);
                }
            }

            lli v = N;

            if(N%10 != 0) {
                N = revnum(N);

                if(v != N) {
                    ans2 = 1 + dig10[dig-1];
                    c2 = getval(dig-1);
                    if(c2 != N) {
                        ans2 = ans2 + N/getval(dig-1) ;
                        c2 += N/getval(dig-1);
                        if((N/getval(dig-1)) == 1 && c2 != N) {
                            ans2--;
                        }
                        if(c2 != N) {
                            ans2 += N%getval(dig-1);
                        }
                    }
                }
            }

            ans = min(ans1, ans2) + getval(dig-1)-1;

        }

        printf("Case #%d: %lld\n", kase, ans);
    }

    return 0;
}
