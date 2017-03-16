#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int,int> > v;
vector<pair<int,int> > v2;
int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int q = 1; q <= t; q++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int tmp = 1000000;  
        int l = 7;
        long long ans = 0;
        for (int i = a; i <= b; i++)
        {
            int qwe = tmp;
            l = 7;
            while ((i / qwe) == 0)
            {
                qwe /= 10;
                l--;
            }
            int asd = i;
            for (int j = 0 ; j < l; j++)
            {
                asd = asd % qwe * 10 + asd / qwe;
                if ((asd >= a) && (asd <= b) && (asd != i))
                {
                   /* pair<int,int> p = make_pair(min(i,asd), max(i,asd));
                    int ok = 1;
                    for (int k = 0; k < v.size(); k++)
                        if (v[k] == p)
                        {
                            ok = 0;
                            break;
                        }
                    if (ok)
                        v.push_back(p);*/
                    if (i < asd)
                    {
                       /* for (int k = 0 ; k < v2.size(); k++)
                            if (v2[k] == p)
                            {
                                printf("%d %d\n", i, asd);
                            }
                        v2.push_back(p);*/
                        ans++;
                      //  printf("%d %d\n", i, asd);
                    }
                }
                if (i == asd)
                    break;
            }
        }
       /* printf("??????????????\n");
        printf("%d\n",v.size());*/
        //for (int i = 0 ; i < v.size(); i++)
           // printf("%d %d\n",v[i].first, v[i].second);
        //printf("************\n");
        /*for (int i = 0 ; i < v2.size(); i++)
        {
            int ok = 1;
            for (int j = 0 ;j < v.size(); j++)
                if (v2[i] == v[j])
                {
                    ok = 0;
                    break;
                }
            if (ok)
                printf("%d %d\n", v2[i].first, v2[i].second);
        }*/
        printf("Case #%d: %lld\n", q, ans);
    }
    return 0;
}