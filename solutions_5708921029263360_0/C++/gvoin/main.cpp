#include <bits/stdc++.h>
using namespace std;

struct wear{
    int x,y,z;
    wear(int x,int y,int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
};
bool operator< (wear a,wear b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y) || (a.x==b.x && a.y==b.y && a.z<b.z);
}
bool cmp (wear a,wear b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y) || (a.x==b.x && a.y==b.y && a.z<b.z);
}

long long a,b,c;
int k;
int w[3];
int g[3];

set<pair<int,wear> > s;
int u[11][11][11][4];
int val[11][11][11];

inline int f(int n)
{
    if(n==1) return 1;
    return n*f(n-1);
}

vector<wear> v;/*
void check()
{
    for(int k=1;k<=3;++k)
    {
        v.clear();
        for(int s=1;s<=g[2];++s)
            for(int p=1;p<=g[1];++p)
                for(int j=1;j<=g[0];++j)
                    v.push_back(wear(j,p,s));
        cout << k << " " << v.size() << " size\n";
        int cnt = f(v.size());
        int mn=10000;
        int mx=-1;
        for(int c=0;c<cnt;++c)
        {
            //memset(u,0,sizeof(u));
            int ans=0;
            for(int i=0;i<v.size();++i)
            {
                int a = v[i].x;
                int b = v[i].y;
                int c = v[i].z;
                if(!u[a][b][c][3] && u[a][b][0][2]<k && u[a][0][c][1]<=k && u[0][b][c][0]<=k)
                {
                    u[a][b][c][3]++;
                    u[a][b][0][2]++;
                    u[a][0][c][1]++;
                    u[0][b][c][0]++;
                    ans++;
                }
            }
            for(int i=0;i<v.size();++i)
            {
                int a = v[i].x;
                int b = v[i].y;
                int c = v[i].z;
                u[a][b][c][3]=0;
                u[a][b][0][2]=0;
                u[a][0][c][1]=0;
                u[0][b][c][0]=0;
            }
            if(ans<mn) mn=ans;
            if(ans>mx) mx=ans;
            /*if(mx==10)
            {
                printf("\n");
                for(int i=0;i<v.size();++i)
                    printf("( %d %d %d )\n",v[i].x,v[i].y,v[i].z);
                printf("\n");
            }*/
           /* next_permutation(v.begin(),v.end());
        }
        cout << k << " " << mn << " " << mx << "\n";

    }
}*/

vector<wear> ans;

int main()
{
    srand(21);
    ios::sync_with_stdio(0);
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);

    //check();
    int T;
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d:",t);
        cin >> g[0] >> g[1] >> g[2] >> k;

        memset(u,0,sizeof(u));
        ans.clear();
        s.clear();
        for(w[0]=1;w[0]<=g[0];++w[0])
        for(w[1]=1;w[1]<=g[1];++w[1])
        for(w[2]=1;w[2]<=g[2];++w[2])
            s.insert(make_pair(3*k,wear(w[0],w[1],w[2]))),
            val[w[0]][w[1]][w[2]]=3*k;
        while(!s.empty())
        {
            pair<int,wear> p = *s.begin();
            s.erase(s.begin());
            int a = p.second.x;
            int b = p.second.y;
            int c = p.second.z;
            //if(!u[a][b][c][3] && u[a][b][0][2]<k && u[a][0][c][1]<k && u[0][b][c][0]<k)
            //    {
                    u[a][b][c][3]++;
                    u[a][b][0][2]++;
                    u[a][0][c][1]++;
                    u[0][b][c][0]++;
                    ans.push_back(wear(a,b,c));

                    for(int p=0;p<3;++p)
                        for(int d=1;d<=g[p];++d)
                    {
                        int a1 = a;
                        int b1 = b;
                        int c1 = c;
                        if(p==0) a1 = d; else if(p==1) b1=d; else c1=d;
                        s.erase(make_pair(val[a1][b1][c1],wear(a1,b1,c1)));
                        val[a1][b1][c1] = u[a1][b1][0][2]+u[a1][0][c1][1]+u[0][b1][c1][0];
                        if(!u[a1][b1][c1][3] && u[a1][b1][0][2]<k && u[a1][0][c1][1]<k && u[0][b1][c1][0]<k)
                            s.insert(make_pair(val[a1][b1][c1],wear(a1,b1,c1)));

                    }

             //   }


        }

        printf(" %d\n",ans.size());

        for(int i=0;i<ans.size();++i)
            printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);


    }

}
