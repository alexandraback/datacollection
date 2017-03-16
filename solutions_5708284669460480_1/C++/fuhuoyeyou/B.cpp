#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int const N=105;
char b[N];

int nxt[N];

double p[2][105];


double pro[26];

char key[N];

void Deal_key(int n){
    for(int i = 0; i < 26; i++)
        pro[i] = 0.0;

    scanf("%s", key);

    double pp = 1.0 / n;

    for(int i = 0; key[i]; i++)
        pro[key[i] - 'A'] += pp;

   // for(int i = 0; i < 26; i++)
  //      printf("%c %lf, ", i+'A', pro[i]*n);

}



void init()
{
    nxt[0]=-1;
    int j=-1;

    for(int i=0;b[i];i++)
    {
        b[i] -= 'A';

        while(j!=-1 && b[j]!=b[i])j=nxt[j];
        nxt[i+1] = ++j;

     //   cout << nxt[i+1] <<" ";
    }
 //   cout << endl;
}


double get_lease(int L, int len){
    int cur, nxt_id;
    memset(p, -1, sizeof(p));

    p[1][0] = 0;

    double ans = 0;

    int st;

    for(int step = 1; step <= L; step++){
        cur = step % 2;
        nxt_id = ! cur;

        for(int i = 0; i <= len; i++)
            p[nxt_id][i] = -1;

        for(int i = 0; i <= len; i++){
        if(p[cur][i] != -1){
                for(int j = 0; j < 26; j++)
                    if(pro[j] > 0.0){
                        st = i;
                       // cout << i << " " << endl;
                        while( st == len || st != -1 && b[st] != j){
                            st = nxt[st];
                       //     cout << st << " ";
                        }
                      //  cout << st << endl;

                        double f = p[cur][i] + (st+1 == len);

                        p[nxt_id][st+1] = max(p[nxt_id][st+1], f);
                        ans = max(ans,  p[nxt_id][st+1]);
                    }
                }
        }

      //  cout << "\nstep:" << step << endl;
      //   for(int i = 0; i <= len; i++){
       //     cout << i << ": " << p[nxt_id][i] << endl;
     //    }

    }
   // cout << "lease: " << ans << endl;
    return ans;
}





double doCase(int L, int len){
    int cur, nxt_id;
    memset(p, 0, sizeof(p));

    p[1][0] = 1.0;

    double ans = 0;

    int st;

    for(int step = 1; step <= L; step++){
        cur = step % 2;
        nxt_id = ! cur;

        for(int i = 0; i <= len; i++)
            p[nxt_id][i] = 0;


        for(int i = 0; i <= len; i++){
            for(int j = 0; j < 26; j++)
            if(pro[j] > 0.0){
                st = i;
                while( st == len || st != -1 && b[st] != j){
                    st = nxt[st];
                }
                p[nxt_id][st+1] += p[cur][i] * pro[j];
            }
        }

//         cout << "\nstep:" << step << endl;
//         for(int i = 0; i <= len; i++){
//            cout << i << ": " << p[nxt_id][i] << endl;
//         }

        ans += p[nxt_id][len];


    }
   //  cout << "doCase: " << ans << endl;
    return ans;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);

    int K, L, S;

    for(int cas = 1; cas <= T; cas++){

        printf("Case #%d: ", cas);
        scanf("%d%d%d", &K, &L, &S);

        Deal_key(K);

        scanf("%s", b);

      //  cout << key << " " << b << endl;
        int len = strlen(b);

        init();

       // cout << b << " " << strlen(b) << endl;
        double ans = get_lease(S, len) - doCase(S, len);
        printf("%.6lf\n", ans);

    }

    return 0;
}
