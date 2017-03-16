#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int K,L,S,MX;
char kys[100];
char s[1000];
int w[100];
map<char, int> pr;

void pref_suf(const char *w, int n, int *p) {
    p[0] = 0;
    for(int i=1;i<n;i++) {
        p[i] = p[i-1];
        while(p[i] > 0 && w[i] != w[p[i]]) p[i] = p[p[i]-1];
        if (w[i] == w[p[i]]) p[i]++;
    }
}

double constr(int len, char* str)
{
    double res = 0;
    if (len == 0)
    {
        pref_suf(s,strlen(s),w);
        int cnt = 0;
        //printf("%s | ",s);
        //for(int i=L;i<=L+S+1;++i) printf("%d ",w[i]);puts("");
        for(int i=L; i<=L+S+1;++i)
            cnt += (w[i] == L);
        if (cnt!=0){
            MX = max(cnt, MX);
            //printf("cnt : %d | ",cnt);
            double pp = 1;
            for(int i=1;i<=S;++i)
            {
                pp *= ((double)pr[s[L+i]])/K;
            }
            //printf("prob : %lf\n",pp*cnt);
            res = pp*cnt;
        }
    }
    else
    {
        for(auto i : pr)
        {
            *str = i.first;
            res += constr(len-1, str+1);
        }
    }
    
    return res;
}

double generate()
{
    s[L] = '#';
    double res = constr(S,s+L+1);
    return res;
}

int main()
{
    int ts;
    scanf("%d", &ts);
    for(int tta=1; tta <= ts; ++tta)
    {
        scanf("%d %d %d",&K, &L, &S);
        MX = 0;
        char tmp[1000];
        scanf("%s",tmp);
        scanf("%s",s);
        for(int i=0;i<K; ++i)
        {
            if (pr.find(tmp[i]) == pr.end())
                pr[tmp[i]] = 0;
            pr[tmp[i]]++;
        }
        double Pr = generate();
        printf("Case #%d: %.9lf\n",tta,MX-Pr);        
        pr.clear();
    }
    return 0;
}
