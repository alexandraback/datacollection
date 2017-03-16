/*
Google Code Jam 2016
Round 1A
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int bf[2016];
int ans = 2;

int go[2016];
int pts = 0;

bool judge()
{
    vector <int> run;
    for(int i=1;i<=n;i++) if(go[i]>0) run.push_back(i);
    //printf("Try: ");
    //for(int i=1;i<=n;i++) if(go[i]>0) printf("%d ",i); printf("\n");
    if(run.size()<=ans) return false;
    int dare = run.size();
    do
    {
        bool foul = false;
        for(int i=0;i<dare;i++)
        {
            int curid = run[i];
            int want = bf[curid];
            if(want==run[(i+1)%dare]||want==run[(i+dare-1)%dare]) continue; //Safe
            foul = true; break;
        }
        if(!foul)
        {
            //printf("AC: "); for(int i=0;i<dare;i++) printf("%d ",run[i]); printf("\n");
            return true;
        }
    }
    while(next_permutation(run.begin(),run.end()));
    return false;
}

void selection(int id)
{
    if(id>n)
    {
        if(judge()) ans = max(ans,pts); return;
    }
    //Not Selected
    go[id] = 0;
    selection(id+1);
    //Selected
    go[id] = 1; pts++;
    selection(id+1);
    go[id] = 0; pts--;
    return;
}

void each(int tc)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&bf[i]);
    for(int i=1;i<=n;i++) go[i] = 0;
    ans = 2;
    selection(1);
    printf("Case #%d: %d\n",tc,ans);
    return;
}

int main()
{
    freopen("BFFsmallIn.in","r",stdin);
    freopen("BFFsmallOut.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}


