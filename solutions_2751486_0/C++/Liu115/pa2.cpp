#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> ii;
int t,n;
char name[1000005];
map<char,int>m;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(char i='a';i<='z';i++)m[i]=0;
    m['a']=m['e']=m['i']=m['o']=m['u']=1;
    for(int amm=1;amm<=t;amm++)
    {
        scanf("%s %d",name,&n);
        priority_queue<ii> pq;
        int l=strlen(name),cnt=0,ans=0;
        for(int i=0;i<l;i++)
        {
            if(!m[name[i]])cnt++;
            else cnt=0;
            if(cnt>=n)pq.push(ii(n,i));
            else pq.push(ii(0,i));
            ii tmp=pq.top();
            if(tmp.first>=n)
            {
                ans+=(tmp.second-n+1)+1;
            }
        }
        printf("Case #%d: %d\n",amm,ans);
    }
    return 0;
}
