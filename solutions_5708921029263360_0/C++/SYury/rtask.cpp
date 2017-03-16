#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

const int inf = 1e9;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase

int t, j, p, s, k;

void solve(int testc){
    scanf("%d%d%d%d", &j, &p, &s, &k);
    printf("Case #%d: ", testc);
    if(k >= s){
        printf("%d\n", j * p * s);
        F(i, 1, j + 1)
            F(z, 1, p + 1)
                F(l, 1, s + 1)
                    printf("%d %d %d\n", i, z, l);
        ret;
    }
    if(k == 1 || s == 1){
        printf("%d\n", p * j);
        F(i, 1, j + 1){
            F(z, 1, p + 1){
                if(i == 1){
                    printf("%d %d %d\n", i, z, z);
                    cont;
                }
                if(i == 2){
                    if(s == 3)
                        printf("%d %d %d\n", i, z, (z == 3) ? 1 : (z + 1));
                    else
                        printf("%d %d %d\n", i, z, 3 - z);
                    cont;
                }
                if(i == 3){
                    printf("%d %d ", i, z);
                    if(z == 1)
                        printf("3\n");
                    if(z == 2)
                        printf("1\n");
                    if(z == 3)
                        printf("2\n");
                }
            }
        }
        ret;
    }
    printf("%d\n", 2 * p * j);
    if(j == 1){
        if(p == 3){
            printf("1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 3 3\n1 3 1\n");
        }
        if(p == 1){
            printf("1 1 1\n1 1 2\n");
        }
        if(p == 2){
            printf("1 1 1\n1 1 2\n1 2 1\n1 2 2\n");
        }
        ret;
    }
    if(j == 2){
        if(p == 2)
        {F(i, 1, j + 1)
            F(z, 1, p + 1)
                printf("%d %d %d\n%d %d %d\n", i, z, 1, i, z, 2);
        }
        else{
            F(i, 1, j + 1)
                F(z, 1, p + 1)
                {
                    if(z == 1)
                        printf("%d %d %d\n%d %d %d\n", i, z, 1, i, z, 2);
                    if(z == 2)
                        printf("%d %d %d\n%d %d %d\n", i, z, 1, i, z, 3);
                    if(z == 3)
                        printf("%d %d %d\n%d %d %d\n", i, z, 2, i, z, 3);
                }
        }
        ret;
    }
        F(i, 1, j + 1){
            F(z, 1, p + 1){
                if(i == 1){
                    printf("%d %d %d\n", i, z, z);
                    cont;
                }
                if(i == 2){
                    if(s == 3)
                        printf("%d %d %d\n", i, z, (z == 3) ? 1 : (z + 1));
                    else
                        printf("%d %d %d\n", i, z, 3 - z);
                    cont;
                }
                if(i == 3){
                    printf("%d %d ", i, z);
                    if(z == 1)
                        printf("3\n");
                    if(z == 2)
                        printf("1\n");
                    if(z == 3)
                        printf("2\n");
                }
            }
        }
        F(i, 1, j + 1){
            F(z, 1, p + 1){
                if(i == 1){
                    int mm[4] = {0, 3, 1, 2};
                    printf("%d %d %d\n", i, z, mm[z]);
                    cont;
                }
                if(i == 2){

                    printf("%d %d %d\n", i, z, z);
                    cont;
                }
                if(i == 3){
                    int mm[4] = {0, 2, 3, 1};
                    printf("%d %d %d\n", i, z, mm[z]);
                }
            }
        }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    F(i, 0, t)
        solve(i + 1);
    ret 0;
}
