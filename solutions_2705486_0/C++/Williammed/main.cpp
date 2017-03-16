#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INF 1000000000
using namespace std;

struct Q
{
    int next[26];
    bool flag;
}trie[4000005];
int tot;

void insert(char str[])
{
    int cur=0,len;

    len=strlen(str);
    for (int i=0;i<len;i++)
    {
        char ch=str[i];
        int ne=ch-'a';
        if (trie[cur].next[ne]!=-1)
        {
            cur=trie[cur].next[ne];
        }
        else
        {
            trie[cur].next[ne]=tot;
            memset(trie[tot].next,-1,sizeof(trie[tot].next));
            trie[tot].flag=false;
            cur=tot++;
        }
    }
    trie[cur].flag=true;
}
char s[50];
int ans;
int heap_size;
int cost[51][1200005]; //在cost[i][j]在i城市，剩余的油量是j
struct P
{
    int pos;
    int state;
    int t;
}heap[10000000];
void heap_keep(int i)
{
    int child;
    P temp;

    temp=heap[i];
    while (2*i<=heap_size)
    {
        child=2*i;
        if (child<heap_size&&heap[child].t>heap[child+1].t)
            child+=1;
        if (temp.t>heap[child].t)
        {
            heap[i]=heap[child];
            i=child;
        }
        else
            break;
    }
    heap[i]=temp;
}
void push(P val)
{
    P temp;
    int i;

    heap_size++;
    i=heap_size;
    heap[heap_size]=val;
    temp=val;
    while (i>1)
    {
        if (temp.t<heap[i/2].t)
        {
            heap[i]=heap[i/2];
            i/=2;
        }
        else
            break;
    }
    heap[i]=temp;
}
void pop()
{
    heap[1]=heap[heap_size];
    heap_size--;
    heap_keep(1);
}
int n;
void BFS()
{
    P tmp,cur;

    heap_size=0;
    tmp.pos=0;
    tmp.state=0;
    tmp.t=0;
    cost[0][0]=0;
    push(tmp);
    while (heap_size>0)
    {
        cur.pos=heap[1].pos;
        cur.t=heap[1].t;
        cur.state=heap[1].state;
        if (cur.pos==n&&trie[cur.state].flag==true)
        {
            if (cur.t<ans)
                ans=cur.t;
            pop();
            return;
        }
        else if(cur.pos==n)
        {
            pop();
            continue;
        }
        pop();
        char ch=s[cur.pos];
        int ne=ch-'a';
        if (trie[cur.state].next[ne]!=-1)
        {
            tmp.state=trie[cur.state].next[ne];
            tmp.pos=cur.pos+1;
            tmp.t=cur.t;
            if (tmp.t<cost[tmp.pos][tmp.state]||cost[tmp.pos][tmp.state]==-1)
            {
                cost[tmp.pos][tmp.state]=tmp.t;
                push(tmp);
            }
        }
        for (int i=0;i<26;i++)
        {
            if (i!=ne&&trie[cur.state].next[i]!=-1)
            {
                tmp.state=trie[cur.state].next[i];
                tmp.pos=cur.pos+1;
                tmp.t=cur.t+1;
                int cnt=0;
                while(cnt<4&&tmp.pos<n)
                {
                    char ch=s[tmp.pos];
                    int ne=ch-'a';
                    if(trie[tmp.state].next[ne]!=-1)
                    {
                        tmp.state=trie[tmp.state].next[ne];
                        tmp.pos+=1;
                    }
                    else
                       break;
                    cnt++;
                }
                if(cnt<4&&tmp.pos!=n)
                   continue;
                else if (tmp.t<cost[tmp.pos][tmp.state]||cost[tmp.pos][tmp.state]==-1)
                {
                    cost[tmp.pos][tmp.state]=tmp.t;
                    push(tmp);
                }
            }
        }
        //add in kongge
        if (trie[cur.state].flag==true)
        {
            tmp.state=0;
            tmp.pos=cur.pos;
            tmp.t=cur.t;
            if (tmp.t<cost[tmp.pos][tmp.state]||cost[tmp.pos][tmp.state]==-1)
            {
                cost[tmp.pos][tmp.state]=tmp.t;
                push(tmp);
            }
        }
    }
}

int main()
{
    int cas,t=1;
    FILE* fp=NULL;
    char str[1000];

    fp=fopen("dic.txt","r");
    tot=0;
    memset(trie[0].next,-1,sizeof(trie[0].next));
    trie[0].flag=false;
    while(fscanf(fp,"%s",str)!=EOF)
    {
        insert(str);
    }
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    //printf("%d\n",tot);
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%s",s);
        ans=INF;
        n=strlen(s);
        for(int i=0;i<=n;i++)
           for(int j=0;j<=tot;j++)
              cost[i][j]=-1;
        BFS();
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}
