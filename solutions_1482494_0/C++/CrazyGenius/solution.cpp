#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

bool mysort(pair< int,pair<int,int> >a , pair< int,pair<int,int> >b)
{
    if(a.second.first == b.second.first) return a.second.second <= b.second.second;
    return a.second.first <= b.second.first;
}

int main()
{
    FILE * pFile;
    pFile = fopen ("Bs.in","r");
    int cc,ans,n,po,pt,star;
    bool can;
    bool *visit;
    pair< int,pair<int,int> >* one;
    pair< int,pair<int,int> >* two;
    fscanf(pFile,"%d",&cc);
    for(int cas = 1 ; cas <= cc ; cas++)
    {
        ans = 0;
        po = 0;
        pt = 0;
        star = 0;
        can = true;
        fscanf(pFile,"%d",&n);
        visit = new bool[n];
        one = new pair< int,pair<int,int> >[n];
        two = new pair< int,pair<int,int> >[n];
        for(int i = 0 ; i < n ; i++)
        {
            fscanf(pFile,"%d %d",&one[i].second.first,&one[i].second.second);
            two[i].second.first = one[i].second.second;
            two[i].second.second = one[i].second.first;
            one[i].second.second *= -1;
            one[i].first = i;
            two[i].first = i;
            visit[i] = false;
        }
        sort(one,one+n,mysort);
        sort(two,two+n,mysort);

        /*printf("**********\n");

        for(int i = 0 ; i < n ; i++)
        {
            printf("%d %d %d *\n",one[i].first , one[i].second.first , one[i].second.second);
            printf("%d %d %d **\n",two[i].first , two[i].second.first , two[i].second.second);
        }

        printf("**********\n");*/

        while(pt < n)
        {
            while(two[pt].second.first > star)
            {
                //printf("want %d have%d\n",two[pt].second.first,star);
                if(one[po].second.first > star)
                {
                    can = false;
                    break;
                }
                else
                {
                    if(!visit[one[po].first])
                    {
                        star++;
                        ans++;
                        //printf("get one from po = %d now star = %d\n",po,star);
                    }
                    //else printf("po = %d visited before",po);
                    visit[one[po].first] = true;
                    po++;
                    //printf("po = %d visted\n",po);
                }
            }
            if(!can) break;
            if(visit[two[pt].first])
            {
                star++;
                ans++;
                //printf("get one from pt = %d now star = %d\n",pt,star);
            }
            else
            {
                star += 2;
                visit[two[pt].first] = true;
                ans++;
                //printf("get two from pt = %d now star = %d\n",pt,star);
                //printf("pt = %d visted\n",pt);
            }
            pt++;
        }
        if(pt != n) printf("Case #%d: Too Bad\n",cas);
        else printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
