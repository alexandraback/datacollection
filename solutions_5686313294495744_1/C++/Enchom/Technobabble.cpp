#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

string inp1,inp2;
int t;
int n;
pair<int,int> topics[2111];

map<string,int> mymap1;
map<string,int> mymap2;
map<string,int>::iterator myit;
int ctr1=0,ctr2=0;

int Cap[2111][2111];
int SOURCE,SINK;
vector<int> Graph[2111];
bool TFO[2111];

int maxflow=0;

void Add(int a,int b)
{
    Graph[a].push_back(b);
    Cap[a][b]=1;

    Graph[b].push_back(a);

    return;
}

void AddEdge(int a,int b)
{
    Add(SOURCE,a);
    Add(a,b);
    Add(b,SINK);

    return;
}

vector<int> Path;

bool DFS(int ver)
{
    if (TFO[ver])
    return false;

    Path.push_back(ver);

    if (ver==SINK)
    return true;

    TFO[ver]=true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Cap[ver][ Graph[ver][i] ]>0)
        {
            if (DFS(Graph[ver][i]))
            return true;
        }
    }

    Path.pop_back();

    return false;
}

void SendFlow()
{
    int i;
    int maxsend=999999;

    for (i=0;i<(int)Path.size()-1;i++)
    {
        if (Cap[ Path[i] ][ Path[i+1] ]<maxsend)
        maxsend=Cap[ Path[i] ][ Path[i+1] ];
    }

    maxflow+=maxsend;

    for (i=0;i<(int)Path.size()-1;i++)
    {
        Cap[ Path[i] ][ Path[i+1] ]-=maxsend;
        Cap[ Path[i+1] ][ Path[i] ]+=maxsend;
    }

    return;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    int test;
    int i;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        fprintf(stderr,"Solving #%d\n",test);

        mymap1.clear();
        mymap2.clear();
        ctr1=0;
        ctr2=0;
        maxflow=0;

        for (i=0;i<=2100;i++)
        {
            Graph[i].clear();
        }

        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            cin>>inp1>>inp2;

            myit=mymap1.find(inp1);

            if (myit==mymap1.end())
            {
                ctr1++;
                mymap1.insert(make_pair(inp1,ctr1));

                topics[i].first=ctr1;
            }
            else
            {
                topics[i].first=(*myit).second;
            }

            ///

            myit=mymap2.find(inp2);

            if (myit==mymap2.end())
            {
                ctr2++;
                mymap2.insert(make_pair(inp2,ctr2));

                topics[i].second=ctr2;
            }
            else
            {
                topics[i].second=(*myit).second;
            }
        }

        memset(Cap,0,sizeof(Cap));

        SOURCE=ctr1+ctr2+1;
        SINK=ctr1+ctr2+2;

        for (i=1;i<=n;i++)
        {
            AddEdge(topics[i].first,topics[i].second+ctr1);
        }

        memset(TFO,false,sizeof(TFO));
        Path.clear();
        while(DFS(SOURCE))
        {
            SendFlow();
            memset(TFO,false,sizeof(TFO));
            Path.clear();
        }

        printf("Case #%d: %d\n",test,n-(ctr1+ctr2-maxflow));
    }

    return 0;
}
