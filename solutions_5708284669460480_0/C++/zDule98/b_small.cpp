#include <cstdio>
double prob[30];
int k,l,s;
char tst[110];
int num;
char chars[30];
double sol;
int mx;

char tren[210];
void solve(double tprob, int pos)
{
   // printf("%d %d\n",pos,s);
    if (pos >= s)
    {
        int nadj = 0;
        for(int i = 0; i < s; i++)
        {
            bool ok = true;
            for(int j = 0; j < l && ok; j++)
                if (tren[i+j] != tst[j])
                    ok = false;
            if (ok) nadj++;
        }
        if (nadj > mx)
            mx = nadj;
        //printf("%lf %d %lf\n",sol,nadj,tprob);
        sol += tprob*nadj;
        return;
    }
    for(int i = 0; i < num; i++)
    {
        tren[pos] = chars[i];
        solve(tprob*prob[chars[i]-'A'],pos+1);
    }
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int wt = 1; wt <= t; wt++)
    {
        for(int i= 0 ; i < 210; i++)
            tren[i] = 'a';
        num = 0;
        sol = 0;
        mx = 0;
        scanf("%d %d %d",&k,&l,&s);
        for (int i = 0; i < 30; i ++)
            prob[i] =0;
        char str[110];
        scanf("%s",str);
        scanf("%s",tst);
        for(int i =0 ; i< k; i++)
            prob[str[i]-'A']++;
        for(int i = 0; i< 30; i++)
            prob[i] = prob[i]/k;
        for(int i = 0; i< 30; i++)
            if (prob[i]>0)
                chars[num++] = i+'A';
        solve(1,0);
        printf("Case #%d: %lf\n",wt,mx-sol);
    }
    return 0;
}
