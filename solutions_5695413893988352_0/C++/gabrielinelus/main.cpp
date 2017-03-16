#include <bits/stdc++.h>

using namespace std;
long long rez1,rez2,bestdiff = 999999999,fin1,fin2;
string s1,s2,final1,final2;
int N;
char r1[10],r2[10];

void check()
{
    long long x1 = 0,x2 = 0;
    for(int i = 0; i <= N; ++i)
    {
        x1 = x1 * 10 + r1[i] - 48;
        x2 = x2 * 10 + r2[i] - 48;
    }
    if(x1 < x2 && bestdiff >= x2 - x1)
    {
        if(bestdiff == x2 - x1)
        {
            if(fin1 > x1 || fin1 == x1 && fin2 > x2)
            {
                fin1 = x1;
                fin2 = x2;
                final1 = string(r1);
                final2 = string(r2);
            }
        }
        else
        {
            fin1 = x1;
            fin2 = x2;
            final1 = string(r1);
            final2 = string(r2);
            bestdiff = x2 - x1;
        }
        return;
    }
    if(x2 <= x1 && bestdiff >= x1 - x2)
    {
        if(bestdiff == x1 - x2)
        {
            if(fin1 > x1 || fin1 == x1 && fin2 > x2)
            {
                fin1 = x1;
                fin2 = x2;
                final1 = string(r1);
                final2 = string(r2);
            }
        }
            else
            {
                fin1 = x1;
                fin2 = x2;
                final1 = string(r1);
                final2 = string(r2);
                bestdiff = x1 - x2;
            }
    }


}

void Back(int k,int l)
{
    if(k == N + 1 && l == N + 1)
    {
        check();
        return;
    }
    if(k <= N)
    {
        if(s1[k] != '?')
        {
            r1[k] = s1[k];
            Back(k+1,l);
        }
        else
        {
            for(int i = 0; i <= 9; ++i)
            {
                r1[k] = (i +'0');
                Back(k+1,l);
            }
        }
    }
    else
    {
        if(s2[l] !='?')
        {
            r2[l] = s2[l];
            Back(k,l+1);
        }
        else
        {
            for(int i = 0; i <= 9; ++i)
            {
                r2[l] = (i+'0');
                Back(k,l+1);
            }
        }
    }

}

int main()
{
    int T;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >>T;
    for(int tst = 1; tst <= T; ++tst){
        bestdiff = 999999;
        cin >> s1;
        cin >> s2;
        N = s1.length() - 1;
        Back(0,0);
        cout << "Case #"<<tst<<": "<< final1 << " "  << final2 << "\n";
        s1 = s2 = final1 = final2 = "";
        memset(r1,0,sizeof(r1));
        memset(r2,0,sizeof(r2));
    }
    return 0;
}
