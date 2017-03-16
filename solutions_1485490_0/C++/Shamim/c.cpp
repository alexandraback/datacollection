#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

struct node
{
    long long amount;
    int id;
};
int n,m;
long long maxi;

void call(vector<node> box, vector<node> toys, long long packed)
{
    if ( packed > maxi)
        maxi = packed;
    if ( box.sz() == 0 || toys.sz() == 0 )
        return;
    if ( box[0].id == toys[0].id)
    {
        // same, take some
        long long mini = min(box[0].amount, toys[0].amount);
        box[0].amount -= mini;
        toys[0].amount -= mini;
        if ( box[0].amount == 0 )
            box.erase(box.begin());
        if ( toys[0].amount ==0 )
            toys.erase(toys.begin());
        call(box,toys,packed + mini);
    }
    else
    {
        vector<node> tempbox = box;
        vector<node> temptoy = toys;
        tempbox.erase(tempbox.begin());
        call(tempbox,toys,packed);
        temptoy.erase(temptoy.begin());
        call(box,temptoy, packed);
    }
}
int main()
{
    //freopen("sample.in","r",stdin);
    freopen("c.in","r",stdin);
    freopen("c.ans","w",stdout);

    int t;
    int kase=1;
    sf("%d",&t);
    while ( t--)
    {
        sf("%d %d",&n,&m);
        int i;
        vector<node> box;
        box.clear();
        for(i=0;i<n;i++)
        {
            node temp;
            cin>>temp.amount>>temp.id;
            box.pb(temp);
        }
        vector<node> toys;
        toys.clear();
        int j;
        for(j=0;j<m;j++)
        {
            node temp;
            cin>>temp.amount>>temp.id;
            toys.pb(temp);
        }
        maxi = 0;

        //cout<<toys.size()<< " "<<box.size()<<endl;

        call(box,toys,0);
        pf("Case #%d: ",kase++);
        cout<<maxi<<endl;

    }
    return 0;
}
