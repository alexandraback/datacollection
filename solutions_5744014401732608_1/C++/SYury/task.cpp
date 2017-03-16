#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

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
#define y1 adjf

vector<int> cnt(26, 0);
int n, t;
set<pair<int, int>, greater<pair<int, int> > > curr;
int tot;
lint m;

void solve(int testc){
    printf("Case #%d: ", testc);
    scanf("%d%lld", &n, &m);
    lint maxb = 1ll << (n - 2);
    if(m > maxb){
        printf("IMPOSSIBLE\n");
        ret;
    }
    printf("POSSIBLE\n");
    if(m == maxb){
        F(i, 0, n){
            F(j, 0, n){
                if(i < j)
                    printf("1");
                else
                    printf("0");
            }
            printf("\n");
        }
        ret;
    }
    F(i, 0, n){
        F(j, 0, n){
            if(i != 0){
                if(i < j)
                    printf("1");
                else
                    printf("0");
            }
            else{
                if(j == n - 1){
                    printf("0");
                    cont;
                }
                int id = n - 2 - j;
                lint p2 = 1ll << id;
                if(m & p2){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &t);
    F(i, 0, t){
        solve(i + 1);
    }
    ret 0;
}
