#include<cstdio>
#include<algorithm>
using namespace std;

int p[105][105],maxV[105],maxH[105];

int main()
{
    int T,tc,m,n,c,d,cek;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%d%d",&m,&n);
        for(c=0;c<m;c++) for(d=0;d<n;d++) scanf("%d",&p[c][d]);
        for(c=0;c<m;c++)
        {
            maxV[c] = 0;
            for(d=0;d<n;d++) maxV[c] = max(maxV[c],p[c][d]);
        }
        for(d=0;d<n;d++)
        {
            maxH[d] = 0;
            for(c=0;c<m;c++) maxH[d] = max(maxH[d],p[c][d]);
        }
        cek = 1;
        for(c=0;c<m;c++) for(d=0;d<n;d++) if(!(p[c][d]>=maxV[c]||p[c][d]>=maxH[d])) cek = 0;
        if(cek) printf("Case #%d: YES\n",tc);
        else printf("Case #%d: NO\n",tc);
    }
    return 0;
}
