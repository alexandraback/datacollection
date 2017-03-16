#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <cstdlib>
#include <ctime>

#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))


using namespace std;

int main()
{
    FILE* f = fopen("mots.in","r");
    FILE* fout = fopen("mots.out","w");
    int n,t;
    fscanf(f,"%d\n",&t);

    vector<int> mots;
    FOR(i,t)
    {
        mots.clear();
        fprintf(fout,"Case #%d: ",i+1);
        int a,n;
        fscanf(f,"%d %d\n",&a,&n);
        FOR(j,n)
        {
            int x;
            fscanf(f,"%d",&x);
            mots.PB(x);
        }
        sort(ALL(mots));

        int minOp=n;
        int crtOp=0;
        FOR(j,n)
        {
            if (a>mots[j])
            {
                a+=mots[j];
            }
            else
            {
                minOp = min(minOp,crtOp+n-j);
                if (a==1)
                {
                crtOp+=n-j;
                break;
                }
                while (a<=mots[j])
                {
                    a+=a-1;
                    crtOp++;
                }
                a+=mots[j];
            }

        }
        minOp = min(minOp,crtOp);

        fprintf(fout,"%d\n",minOp);
        printf("%d\n",minOp);
    }
    fclose(fout);
}
