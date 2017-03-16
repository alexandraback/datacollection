#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

long long v[20000];
pair<long long, long long> sortedv[20000];
set<long long> used2;

long long DP[100][100];

int used[20000];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int tc;
    cin >> tc;

    for(int nt=1; nt<=tc; nt++)
    {
        int E, R, N;
        cin >> E >> R >> N;
        for(int i=0; i<N; i++)
        {
            cin >> v[i];
            sortedv[i]=make_pair(v[i],i);
        }
        memset(used,0,sizeof(used));
        used2.clear();
        used2.insert(-100000000);
        used2.insert(200000000);
        sort(sortedv, sortedv+N);
        for(int i=0; 2*i<N; i++)
            swap(sortedv[i], sortedv[N-i-1]);
        long long ans=0;
        for(int i=0; i<N; i++)
        {
            long long p=E, r=sortedv[i].second, s=sortedv[i].first;
            set<long long>::iterator itlow,itup;
            itup=used2.upper_bound(r);
            itlow=itup;
            itlow--;
                if(*itlow>=0)
                    p=min(p,R*(r-*itlow));
            long long p2=E;
                if(*itup<N)
                    p2=min(p2,R*(*itup-r));
            //cout << r << " " << s << " ";
            //cout << p << " " << p2 << " ";
            p=max(0LL,p+p2-E);
            //cout << p << endl;
            ans+=s*p;
            used[r]=1;
            used2.insert(r);
        }

        cout << "Case #" << nt << ": " << ans << endl;

    }
}
