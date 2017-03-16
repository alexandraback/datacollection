#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <set>
using namespace std;

#include <vector>
#include <set>
#include <map>

vector<set<int> > gyerekek;
vector<vector<int> > osok;

bool put_to(int gyerek,int os)
{//az i szamot az osszesi. elemnek az osebe beleteszi.
    vector<int> &os_akt=osok[os];
    if (gyerekek[os].find(gyerek) != gyerekek[os].end() )
    {

        return false;
    }
    gyerekek[os].insert(gyerek);
    for (int i=0;i<os_akt.size();i++)
    {
        if ( put_to(gyerek,os_akt[i]) == false) return false;
    }
    return true;

}

void solve()
{
    int num;
    scanf("%d",&num);
    gyerekek=vector<set<int> >(num);
    osok=vector<vector<int> >(num);
    for (int i=0;i<num;i++)
    {//vegigmegyek az elemeken es minden osebe beleteszem a gyerekekhez
        //put_to_gyerekek(i,gyerekek,osok);
        int o;
        scanf("%d",&o);
        for (int j=0;j<o;j++)
        {
            int r;
            scanf("%d",&r);
            osok[i].push_back(r-1);
        }
    }
    for (int i=0;i<num;i++)
    {
        if (put_to(i,i)==false) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");

}

int main()
{
    int casenum;
    scanf("%d",&casenum);
    for (int i=0;i<casenum;i++)
    {
        printf("Case #%d: ",i+1);
        solve();
    }

}
