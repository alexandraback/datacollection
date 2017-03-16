#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std;
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ppii pair< pii,int >
#define big 2000000000
#define N 1005

int kasus,r,c,jml,jawab,p,a,b;
bool cek[N][N],hit[N][N];
vector < pii > q[2];
const int dr[4] = {0,1,0,-1};
const int dc[4] = {1,0,-1,0};

int main()
{
//    freopen("C-small-attempt0.in","r",stdin);
//    freopen("c.out","w",stdout);
    
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        scanf("%d %d %d",&r,&c,&jml);
        printf("Case #%d: ",z);
        if (r<=2 || c<=2) printf("%d\n",jml);
        else
        {
            memset(cek,0,sizeof(cek));
            memset(hit,0,sizeof(hit));
            
            p = 1;
            for (int i=0;i<2;i++) q[i].clear();
            q[1].PB(MP(2,2));
            cek[2][2] = true;
            jml--;
            
            while (jml>0 && q[p].size())
            {
                q[1-p].clear();
                for (int i=0;i<q[p].size() && jml;i++)
                {
                    a = q[p][i].fs;
                    b = q[p][i].sc;
                    for (int m=0;m<4 && jml;m++)
                    {
                        if ((a+dr[m]<1)||(b+dc[m]<1)||(a+dr[m]>r)||(b+dc[m]>c)) continue;
                        if ((a+dr[m]==1&&b+dc[m]==1)||(a+dr[m]==1&&b+dc[m]==c)||(a+dr[m]==r&&b+dc[m]==c)||(a+dr[m]==r&&b+dc[m]==1)) continue;
                        if (cek[a+dr[m]][b+dc[m]]) continue;
                        q[1-p].PB(MP(a+dr[m],b+dc[m]));
                        cek[a+dr[m]][b+dc[m]] = true;
                        jml--;
                    }
                }
                p = 1-p;
            }
            jawab = 0;
            for (int i=1;i<=r;i++)
            {
                for (int j=1;j<=c;j++)
                    if (cek[i][j]) {hit[i][j] = true; jawab++; break;}
                for (int j=c;j>=1;j--)
                {
                    if (hit[i][j]) break;
                    if (cek[i][j]) {hit[i][j]=true; jawab++; break;}
                }
            }
            for (int j=1;j<=c;j++)
            {
                for (int i=1;i<=r;i++)
                {
                    if (hit[i][j]) break;
                    if (cek[i][j]) {hit[i][j] = true; jawab++; break;}
                }
                for (int i=r;i>=1;i--)
                {
                    if (hit[i][j]) break;
                    if (cek[i][j]) {hit[i][j] = true; jawab++; break;}
                }
            }
            jawab += jml;
            printf("%d\n",jawab);
            /*for (int i=1;i<=r;i++)
            {
                for (int j=1;j<=c;j++)
                {
                    if (hit[i][j]) cout << "1 ";
                    else cout << "- ";
                }
                cout << endl;
            }*/
        }
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
