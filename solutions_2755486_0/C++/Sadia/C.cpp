#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
struct attack
{
    int start, end, strength, day;
};
bool cmp(attack x, attack y)
{
    return x.day < y.day;
}
vector < attack > V;
int wall[1000];
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("inputC.txt", "r", stdin);
    freopen("outputC.txt", "w", stdout);
    int t,T;
    int N,cnt,i,j;
    attack A;
    int d, n, start, end, strength, delta_day, delta_dist, delta_s;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        memset(wall, 0, sizeof(wall));
        scanf("%d", &N);
        V.clear();
        while(N--)
        {
            scanf("%d %d %d %d %d %d %d %d", &d, &n, &start, &end, &strength, &delta_day, &delta_dist, &delta_s);
            start += 500, end += 500-1;
            A.start = start, A.end = end;
            A.day = d;
            A.strength = strength;
            while(n--)
            {
                V.push_back(A);
                A.start += delta_dist, A.end += delta_dist;
                A.day += delta_day;
                A.strength += delta_s;
            }
        }
        sort(V.begin(), V.end(), cmp);
        A.day = -1;
        //for (i=0; i<V.size(); ++i) printf("%d %d %d %d\n", V[i].start, V[i].end, V[i].day, V[i].strength);
        V.push_back(A);
        start = end = cnt = 0;
        while(start<V.size())
        {
            if (V[start].day == -1) break;
            end = start;
            while(V[end].day == V[start].day) ++end;
            --end;
            //printf("\t\t\t%d %d\n", start, end);
            for (i=start; i<=end; ++i)
            {
                for (j=V[i].start; j<=V[i].end; ++j)
                {
                    if (wall[j] < V[i].strength)
                    {
                        ++cnt;
                        break;
                    }
                }
            }
            for (i=start; i<=end; ++i)
            {
                for (j=V[i].start; j<=V[i].end; ++j)
                {
                    if (wall[j] < V[i].strength) wall[j] = V[i].strength;
                }
            }
            start = end+1;
        }
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
