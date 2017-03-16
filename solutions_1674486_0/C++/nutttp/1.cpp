#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> Vertex[10000];
int visit[10000];
int deg[10000];

void search(int curr)
{
    visit[curr]++;
    vector<int>::iterator p;
    p = Vertex[curr].begin();
    for(;p!=Vertex[curr].end();p++)
    {
        if(*p  != 0)
        search(*p);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int curr,caseNum;
    cin >> caseNum;
    int i,j,Vnum,tmp,x;
    int isValid;
    int deg0;
    for(curr=1;curr<=caseNum;curr++)
    {
        memset(visit,0,sizeof(visit));
        memset(deg,0,sizeof(deg));
        cin >> Vnum;
        for(int i = 1;i<=Vnum;i++)
        {
            cin >> tmp;
            Vertex[i].clear();
            for(j=1;j<=tmp;j++)
            {
                cin >> x;
                Vertex[i].push_back(x);
                deg[x] ++;
            }
        }
        // find deg 0
        isValid = 0;
        for(i=1;i<=Vnum;i++)
        {
            memset(visit,0,sizeof(visit));
            search(i);
            for(j=1;j<=Vnum;j++)
            {
                if(visit[j] > 1)
                isValid = 1;
            }
        }
        printf("Case #%d: ",curr);
        if(isValid == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
