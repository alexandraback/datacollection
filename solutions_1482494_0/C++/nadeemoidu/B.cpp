
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstdio>

using namespace std;

typedef pair<int,int> pii;
int m, n;
int a[1234], b[1234];
pair<pii,int> p[1234];
int done[1234];
int main()
{
    int T, iT;
    scanf("%d", &T);
    for(iT = 1; iT <= T; iT++) {
        memset(done,0,sizeof(done));
        int i, n;
        scanf("%d",&n);
        priority_queue<pii> p1, p2;
        for(i = 0; i < n; i++) {
            scanf("%d%d", a+i, b+i);
            p[i] = make_pair(pii(a[i], b[i]),i);
            p1.push(pii(-a[i],i));
            p2.push(pii(-b[i],i));
        }
     //   sort(p,p+n);
        int stars = 0, levels = 0;
        i = 0;
        int best, besti;
        while(stars < 2 * n) {
            if(-p2.top().first <= stars) {
                stars += 2 - done[p2.top().second];
                done[p2.top().second] = 2;
                p2.pop();
                levels ++;
            }
            else {
                best = -1;
                besti = -1;
                for(i = 0; i < n; i++) {
                    if(done[i] == 0 && p[i].first.first <= stars && p[i].first.second > best) 
                    {
                        best = p[i].first.second;
                        besti = p[i].second;
                    }
                }
                if(best == -1) break;
                done[besti] = 1;
                stars ++;
                levels++;
            }
        }
        printf("Case #%d: ", iT );
        if(stars != 2 * n) {
            printf("Too Bad\n");
        }
        else {
            printf("%d\n", levels);
        }
    }
   return 0;
}
