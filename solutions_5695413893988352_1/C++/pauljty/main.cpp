#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#define mem(a) memset( a, 0, sizeof(a) )
using namespace std;
typedef __int64 ll;


char cc[20], jj[20], ansa[20], ansb[20], ta[20], tb[20];
int a[20], b[20], tpa[20], tpb[20];
int vis[1000], num[15], n;
ll min1 = 999999999999999999, ra, rb;
void dfs( int cnt, ll la, ll lb )
{
    if( cnt == n ){
        if( abs(la-lb) < min1 ){
            strcpy( ansa, ta );
            strcpy( ansb, tb );
            min1 = abs(la-lb);
            ra = la;
            rb = lb;
        }
        else if( abs(la-lb) == min1 ){
            if( la < ra ){
                strcpy( ansa, ta );
                strcpy( ansb, tb );
                min1 = abs(la-lb);
                ra = la;
                rb = lb;
            }
            else if( la == ra ){
                if( lb < rb ){
                    strcpy( ansa, ta );
                    strcpy( ansb, tb );
                    min1 = abs(la-lb);
                    ra = la;
                    rb = lb;
                }
            }
        }
        return;
    }
    la *= 10;lb *= 10;
    if( cc[cnt] != '?' && jj[cnt] != '?' ){
        la += cc[cnt]-'0';ta[cnt] = cc[cnt];
        lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
        dfs( cnt+1, la, lb );
        return;
    }
    if( cc[cnt] == '?' && jj[cnt] == '?' ){
        if( la == lb ){
        la += 0;ta[cnt] = '0';
        lb += 0;tb[cnt] = '0';
        dfs( cnt+1, la, lb );
        la += 1;ta[cnt] = '1';tb[cnt] = '0';
        dfs( cnt+1, la, lb );
        la --;
        lb ++;ta[cnt] = '0';tb[cnt] = '1';
        dfs( cnt+1, la, lb );
        return;
        }
        else if( la > lb ){
            la += 0;ta[cnt] = '0';
            lb += 9;tb[cnt] = '9';
            dfs( cnt+1, la, lb );
            return;
        }
        else if( la < lb ){
            la += 9;ta[cnt] = '9';
            lb += 0;tb[cnt] = '0';
            dfs( cnt+1, la, lb );
            return;
        }
    }
    if( cc[cnt] == '?' && jj[cnt] != '?' ){
        if( la == lb ){
            la += jj[cnt]-'0';ta[cnt] = jj[cnt];
            lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
            dfs( cnt+1, la, lb );
            la -= jj[cnt]-'0';
            lb -= jj[cnt]-'0';
            if( jj[cnt] == '9' ){
                la += jj[cnt]-'0'-1;ta[cnt] = jj[cnt]-1;
                lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
                dfs( cnt+1, la, lb );
            }
            else if( jj[cnt] == '0' ){
                la += jj[cnt]-'0'+1;ta[cnt] = jj[cnt]+1;
                lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
                dfs( cnt+1, la, lb );
            }
            else{
                la += jj[cnt]-'0'-1;ta[cnt] = jj[cnt]-1;
                lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
                dfs( cnt+1, la, lb );
                la -= jj[cnt]-'0'-1;lb -= jj[cnt]-'0';
                la += jj[cnt]-'0'+1;ta[cnt] = jj[cnt]+1;
                lb += jj[cnt]-'0';tb[cnt] = jj[cnt];
                dfs( cnt+1, la, lb );
            }
        }
        else if( la > lb ){
            lb += jj[cnt]-'0';
            ta[cnt] = '0'; tb[cnt] = jj[cnt];
            dfs( cnt+1, la, lb );
        }
        else{
            la += 9;
            lb += jj[cnt]-'0';
            ta[cnt] = '9'; tb[cnt] = jj[cnt];
            dfs( cnt+1, la, lb );
        }
        return;
    }
    if( cc[cnt] != '?' && jj[cnt] == '?' ){
        if( la == lb ){
            la += cc[cnt]-'0';ta[cnt] = cc[cnt];
            lb += cc[cnt]-'0';tb[cnt] = cc[cnt];
            dfs( cnt+1, la, lb );
            la -= cc[cnt]-'0';
            lb -= cc[cnt]-'0';
            if( cc[cnt] == '9' ){
                la += cc[cnt]-'0';ta[cnt] = cc[cnt];
                lb += cc[cnt]-'0'-1;tb[cnt] = cc[cnt]-1;
                dfs( cnt+1, la, lb );
            }
            else if( cc[cnt] == '0' ){
                la += cc[cnt]-'0';ta[cnt] = cc[cnt];
                lb += cc[cnt]-'0'+1;tb[cnt] = cc[cnt]+1;
                dfs( cnt+1, la, lb );
            }
            else{
                la += cc[cnt]-'0';ta[cnt] = cc[cnt];
                lb += cc[cnt]-'0'-1;tb[cnt] = cc[cnt]-1;
                dfs( cnt+1, la, lb );
                la -= cc[cnt]-'0';lb -= cc[cnt]-'0'-1;
                la += cc[cnt]-'0';ta[cnt] = cc[cnt];
                lb += cc[cnt]-'0'+1;tb[cnt] = cc[cnt]+1;
                dfs( cnt+1, la, lb );
            }
        }
        else if( la > lb ){
            la += cc[cnt]-'0';ta[cnt] = cc[cnt];
            lb += 9;tb[cnt] = '9';
            dfs( cnt+1, la, lb );
        }
        else{
            la += cc[cnt]-'0';
            ta[cnt] = cc[cnt];tb[cnt] = '0';
            dfs( cnt+1, la, lb );
        }
        return;
    }
}

int main()
{
    int T, i, k, p, m, cas = 1;
                       //4??7?????550?2???9 ?4?1??53194828?7??
    //printf("%I64d\n", -439790999550929899+440100531948289700);
    //printf("%I64d\n", -439799999550929999+440100531948280700);
    freopen("B-large.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    scanf("%d", &T);
    while( T -- ){
        min1 = 999999999999999999;
        ra = rb = 999999999999999999;
        memset( cc, '\0', sizeof(cc) );
        memset( jj, '\0', sizeof(jj) );
        scanf("%s %s", cc, jj);
        printf("Case #%d: ", cas++);
        memset( ansa, '\0', sizeof(ansa) );
        memset( ansb, '\0', sizeof(ansb) );
        memset( ta, '\0', sizeof(ta) );
        memset( tb, '\0', sizeof(tb) );
        n = strlen(cc);
        ll la = 0, lb = 0;
        dfs( 0, la, lb );
        printf("%s %s\n", ansa, ansb);
    }
}
