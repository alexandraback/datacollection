#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define day 676060
#define f first
#define s second
using namespace std;


int num_attack[20],dis[20],ini[20][2],inist[20],fday[20];
int cur[20][2],curday[20],chday[20],chdis[20],chst[20],curst[20];
map<int,int>h;
vector< pair<int,int> >v;
vector<int>days[676065];
int check(int i,int j,int str)
{
    int a,b,c;
    b=0;
    for(a=i+1;a<=j;a++)
    {
        if(h[a]<str) b++;
    }
    return b;
}

void up(int i,int j,int str)
{
    for(int a=i+1;a<=j;a++) h[a]=max(h[a],str);
   // cout<<"updated "<<i+1<<" "<<j<<endl;
}

int main()
{
    freopen("00.in","r",stdin);
    freopen("0.out","w",stdout);

    int i,t,a,b,c,d,e,x,y;

    int z;

    cin>>t;
    pair<int,int>p;
    v.clear();
    for(i=1;i<=t;i++)
    {
        cin>>z;
        for(a=-2000;a<=2000;a++) h[a]=0;
        for(a=0;a<=day;a++) days[a].clear();
        for(a=0;a<z;a++)
        {
            cin>>fday[a]>>num_attack[a]>>ini[a][0]>>ini[a][1]>>inist[a]>>chday[a]>>chdis[a]>>chst[a];
        }
        for(a=0;a<z;a++)
        {
            p.s=a;
            p.f=fday[a];
            num_attack[a]--;
            v.push_back(p);
            days[p.f].push_back(a);
            cur[a][0]=ini[a][0];
            cur[a][1]=ini[a][1];
            curst[a]=inist[a];
            for(b=0;b<num_attack[a];b++)
            {
                p.f=fday[a]+(b+1)*chday[a];
                //v.push_back(p);
                days[p.f].push_back(a);
            }
        }
        //sort(v.begin(),v.end());
        int w;
        int ans=0;
        for(a=0;a<=day;a++)
        {
            if(days[a].size()==0) continue;
            for(b=0;b<days[a].size();b++)
            {
                c=days[a][b];
                if(check(cur[c][0],cur[c][1],curst[c]))
                {
                    //cout<<"Attack on "<<cur[c][0]<<" "<<cur[c][1]<<" success"<<endl;
                    ans++;
                }
            }
            for(b=0;b<days[a].size();b++)
            {
                c=days[a][b];
                up(cur[c][0],cur[c][1],curst[c]);
                cur[c][0]=cur[c][0]+chdis[c];
                cur[c][1]=cur[c][1]+chdis[c];
                curst[c]=curst[c]+chst[c];
            }
            //cout<<endl;
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
        //if(n!=x && y!=m) cout<<"ERROR"<<endl;
    }

    return 0;
}
