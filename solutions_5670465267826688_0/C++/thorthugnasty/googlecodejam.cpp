#include <bits/stdc++.h>
using namespace std;
const int i = 2,j = 3,k = 4;
string S;
int pmult[10001];
int table[5][5];
//i - 2, j - 3, k - 4

int mult(int a,int b)
{
    int sign = a/abs(a) * b/abs(b);
    a = abs(a);
    b = abs(b);
    return sign * table[a][b];
}

int inv(int a,int b)
{
    int sign = a/abs(a)*b/abs(b);
    a = abs(a);
    b = abs(b);
    if (table[b][1]*sign == a) return 1;
    if (table[b][1]*sign == -a) return -1;
    if (table[b][i]*sign == a) return i;
    if (table[b][i]*sign == -a) return -i;
    if (table[b][j]*sign == a) return j;
    if (table[b][j]*sign == -a) return -j;
    if (table[b][k]*sign == a) return k;
    if (table[b][k]*sign == -a) return -k;
}

int main()
{
    table[1][1] = 1;
    table[1][i] = i;
    table[1][j] = j;
    table[1][k] = k;
    table[i][1] = i;
    table[j][1] = j;
    table[k][1] = k;
    table[1][1] = 1;
    table[i][i] = -1;
    table[i][j] = k;
    table[i][k] = -j;
    table[j][i] = -k;
    table[j][j] = -1;
    table[j][k] = i;
    table[k][i] = j;
    table[k][j] = -i;
    table[k][k] = -1;

    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    cin >> T;
    for (int qq=0;qq<T;qq++)
    {
        int L,X;
        cin >> L >> X;
        cin >> S;
        int last = 1;
        for (int i=0;i<X;i++)
        {
            for (int j=0;j<L;j++)
            {
                int xx;
                if (S[j]=='i') xx = 2;
                if (S[j]=='j') xx = 3;
                if (S[j]=='k') xx = 4;
                pmult[i*L+j] = mult(last,xx);
                last = pmult[i*L+j];
            }
        }
        bool ans = false;
        for (int d1=0;d1<L*X;d1++)
        {
            if (ans) break;
            for (int d2=d1+1;d2<L*X;d2++)
            {

                if (pmult[d1]==i){
                    if (inv(pmult[d2],pmult[d1])==j){

                        if (inv(pmult[L*X-1],pmult[d2])==k)
                        {
                            ans = true;
                            break;
                        }

                    }
                }
            }
        }
        if (ans) printf("Case #%d: YES\n",qq+1);
        else printf("Case #%d: NO\n",qq+1);
    }
}
