#include <bits/stdc++.h>

using namespace std;

const int maxN = 23;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n;
long long pot10[maxN];
int dirA[maxN][2] , dirB[maxN][2];
string a , b;

long long dp[maxN][2];
long long solve(int pos,int iguales){
    if(pos == n){
        return 0;
    }
    if(dp[pos][iguales] != -1){
        return dp[pos][iguales];
    }

    long long answer = inf;
    for(char x = '0'; x <= '9'; x++){
        if(a[pos] != '?' && a[pos] != x){
            continue;
        }

        for(char y = '0'; y <= '9'; ++y){
            if(b[pos] != '?' && b[pos] != y){
                continue;
            }
            if(iguales){
                    if( x < y){
                        long long tmp = (y  - x) * pot10[n - pos - 1] + solve(pos+1,0);
                        if(tmp < answer){
                            answer = tmp;
                            dirA[pos][iguales] = x - '0';
                            dirB[pos][iguales] = y - '0';
                        }
                    }else{
                        if(x == y){
                         long long tmp = (y - x) * pot10[n - pos - 1] + solve(pos+1,1);
                          if(tmp < answer){
                            answer = tmp;

                            dirA[pos][iguales] = x - '0';
                            dirB[pos][iguales] = y - '0';
                          }
                        }
                    }
            }else{
                long long tmp = (y - x) * pot10[n - pos - 1] + solve(pos+1,iguales);
                if(tmp < answer){
                    answer = tmp;
                    dirA[pos][iguales] = x - '0';
                    dirB[pos][iguales] = y - '0';
                }
            }
        }
    }

    return dp[pos][iguales] = answer;
}

int main(){

    pot10[0] = 1;
    for(int i = 1; i < 23; ++i){
        pot10[i] = 10 * pot10[i - 1];
    }

    freopen("B-small-attempt3.in","r",stdin);
    freopen("on2.c","w",stdout);

    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++){
        cin >>  a >> b;
        n = a.size();

        memset(dp,-1,sizeof dp);
        string s1 , s2;
        long long sol1 = solve(0 , 1);
        if(sol1 < inf){
            string p  , q;
            int pos = 0 , iguales = 1;
            while(pos < n){
                p.push_back(dirA[pos][iguales] + '0');
                q.push_back(dirB[pos][iguales] + '0');
                if(iguales == 1){
                    if(p.back() < q.back()){
                        iguales = 0;
                    }
                }
                pos++;
            }
            s1 = p;
            s2 = q;
        }


        memset(dp,-1,sizeof dp);
        swap(a , b);
        long long sol2 = solve(0 , 1);
        if(sol2 <= sol1 ){
            string p  , q;
            int pos = 0 , iguales = 1;
            while(pos < n){
                p.push_back(dirA[pos][iguales] + '0');
                q.push_back(dirB[pos][iguales] + '0');
                if(iguales == 1){
                    if(p.back() < q.back()){
                        iguales = 0;
                    }
                }
                pos++;
            }
            swap(p , q);
            if(s1 == "" || sol2 < sol1){
                s1 = p;
                s2 = q;
            }else{
                if(p < s1 || (p == s1 && q < s2)){
                    s1 = p;
                    s2 = q;
                }
            }
        }


        printf("Case #%d: ",tt);
        cout << s1 <<" "<<s2<<endl;
    }






    return 0;
}
