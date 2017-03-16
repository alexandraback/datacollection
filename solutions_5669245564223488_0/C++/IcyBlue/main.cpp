#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int codebook[26][26];
long long ans;
long long calc(int n)
{
    long long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = ans * i;
        ans = ans % 1000000007;
    }
    return ans;
}
bool flag;
int expand(int a, int b)
{
    if (a == b)
    {
        ans = ans * calc(codebook[a][b]);
        ans = ans % 1000000007;
        codebook[a][b] = 0;
        return 0;
    }
    if (codebook[a][a] != 0){
            ans = ans * calc(codebook[a][a]);
            ans = ans % 1000000007;
            codebook[a][a] = 0;
    }
    if (codebook[b][b] != 0){
        ans = ans * calc(codebook[b][b]);
        ans = ans % 1000000007;
        codebook[b][b] = 0;
    }
    codebook[a][b] = -1;
    for (int i = 0; i < 26; i++)
    {
        if (codebook[i][a] != 0 && codebook[i][a] != -2)
        {
            if (codebook[i][a] == -1){
                flag = false;
                return 0;
            }
            expand(i,a);
            if (!flag) return 0;
        }
    }
    codebook[a][b] = -2;
    for (int i = 0; i < 26; i++)
    {
        if (codebook[b][i] != 0 && codebook[b][i] != -1)
        {
            if (codebook[b][i] == -2){
                flag = false;
                return 0;
            }
            expand(b,i);
            if (!flag) return 0;
        }
    }
    if (!flag) return 0;
    codebook[a][b] = 0;
}
int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B-small.txt","w",stdout);
    int times;

    scanf("%d",&times);
    for (int t = 0; t < times; t++)
    {
        int n;
        scanf("%d\n",&n);
        char dic[110][110];
        flag = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%s",dic[i]);
        }
        /*for (int i = 0; i < n; i++)
        {
            printf("%s\n",dic[i]);
        }*/
        memset(codebook,0,sizeof(codebook));
        bool appear[26];
        memset(appear,false,sizeof(appear));
        for (int i = 0; i < n; i++)
        {
            char st = dic[i][0];
            char ed = dic[i][strlen(dic[i])-1];
            appear[st-'a'] = true;
            appear[ed-'a'] = true;
            int ps = 0;
            while (dic[i][ps] == st) ps ++;
            ps --;
            int pe = strlen(dic[i]) - 1;
            while (pe != 0 && dic[i][pe] == ed) pe--;

            if (dic[i][pe] != ed) pe++;
            if (ps == strlen(dic[i]) - 1) {codebook[st-'a'][ed-'a'] ++; continue;}
            if (pe == ps + 1) {codebook[st-'a'][ed-'a'] ++; continue;}
            if (st == ed) {flag = false;break;}
            for (int j = ps+1; j < pe; j++)
            {
                if (appear[dic[i][j] - 'a'] && dic[i][j] != dic[i][j-1]) {flag = false; break;}
                appear[dic[i][j]-'a'] = true;
            }
            if (!flag) break;
            codebook[st-'a'][ed-'a'] ++;
        }
        if (!flag)
        {
             printf("Case #%d: 0\n",t+1);
             continue;
        }
        for (int i = 0 ; i < 26; i++)
        {
            int sumi = 0;
            int sumj = 0;
            for (int j = 0; j < 26; j++)
            {
                if (i != j)
                { sumi = sumi + codebook[j][i];
                  sumj = sumj + codebook[i][j];
                }
            }
            if (sumi > 1 || sumj > 1)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
             printf("Case #%d: 0\n",t+1);
             continue;
        }
        ans = 1;
        int cc = 0;

        for (int i = 0 ; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i != j && codebook[i][j] != 0){
                    expand(i,j);
                    cc++;
                }
            }
        }
        if (!flag)
        {
             printf("Case #%d: 0\n",t+1);
             continue;
        }
        for (int i = 0; i < 26; i++)
        {
            if (codebook[i][i]) {expand(i,i);cc++;}
        }
        if (!flag)
        {
             printf("Case #%d: 0\n",t+1);
             continue;
        }
        ans = ans * calc(cc);
        ans = ans % 1000000007;
        printf("Case #%d: %lld\n", t+1, ans);
    }
}
