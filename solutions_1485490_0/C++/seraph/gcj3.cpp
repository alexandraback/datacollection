// Template By Fendy Kosnatha (Seraph)
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
long long b1[100], b2[100], t1[100], t2[100], _t1[100];
int main()
{
    long long tc;
    long long count=1;
    cin>>tc;
    while (tc--)
    {
        long long n,m;
        cin>>n>>m;
        for (long long i=0;i<n;i++)
            cin>>b1[i]>>b2[i];
        for (long long i=0;i<m;i++)
            cin>>_t1[i]>>t2[i];
        long long fans=0;
        if (n==1)
        {
            for (long long i=0;i<m;i++)
            {
                        long long a,b,c;
                        a = b1[0];
                        long long ans=0;
                        for (int j=0;j<m;j++) t1[j]=_t1[j];
                        for (long long l=0;l<m;l++)
                        {
                            if (t2[l]==b2[0])
                            {
                                long long ambil = (min(t1[l], a));
                                ans += ambil;
                                t1[l]-=ambil;
                                a-=ambil;
                                if (a<0) a=0;
                            }
                        }
                        fans = max(ans,fans);
            }
        }
        if (n==2)
        {
            for (long long i=0;i<m;i++)
            {
                for (long long j=i;j<m;j++)
                {
                    
                        long long a,b,c;
                        a = b1[0];
                        b = b1[1];
                        long long ans=0;
                        for (int  q=0;q<m;q++) t1[q]=_t1[q];
                        for (long long l=0;l<=j;l++)
                        {
                            if (t2[l]==b2[0])
                            {
                                long long ambil = (min(t1[l], a));
                                ans += ambil;
                                t1[l]-=ambil;
                                a-=ambil;
                                if (a<0) a=0;
                            }
                        }
                        for (long long l=j;l<m;l++)
                        {
                            if (t2[l]==b2[1])
                            {
                                long long ambil = (min(t1[l], b));
                                ans += ambil;
                                t1[l]-=ambil;
                                b-=ambil;
                                if (b<0) b=0;
                            }
                        }
                        fans = max(ans,fans);
                    
                }
            }
        }
        if (n==3)
        {
            for (long long i=0;i<m;i++)
            {
                for (long long j=i;j<m;j++)
                {
                    for (long long k=j;k<m;k++)
                    {
                        long long a,b,c;
                        a = b1[0];
                        b = b1[1];
                        c = b1[2];
                        long long ans=0;
                        for (int q=0;q<m;q++) t1[q]=_t1[q];
                        for (long long l=0;l<=j;l++)
                        {
                            if (t2[l]==b2[0])
                            {
                                long long ambil = (min(t1[l], a));
                                ans += ambil;
                                t1[l]-=ambil;
                                a-=ambil;
                                if (a<0) a=0;
                            }
                        }
                        for (long long l=j;l<=k;l++)
                        {
                            if (t2[l]==b2[1])
                            {
                                //cout<<"do ";
                                long long ambil = (min(t1[l], b));
                                ans += ambil;
                                t1[l]-=ambil;
                                b-=ambil;
                                if (b<0) b=0;
                            }
                        }
                        for (long long l=k;l<m;l++)
                        {
                            if (t2[l]==b2[2])
                            {
                                //cout<<"re "<<min(t1[l],c)<<" ";
                                long long ambil = (min(t1[l], c));
                                ans += ambil;
                                t1[l]-=ambil;
                                c-=ambil;
                                if (c<0) c=0;
                            }
                        }
                        
                        fans = max(ans,fans);
                    }
                }
            }
        }
        cout<<"Case #"<<count++<<": "<<fans<<endl;
    }
    return 0;
}
