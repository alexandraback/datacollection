#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>

using namespace std;

vector <int> tmp[20],st_tmp,c[20],st;
int n,box[25],mymap[205],m;

vector<int> dph[1<<20];
int dp[1<<20];

vector<int> h(int mask)
{
    if(mask==0) return st;

    if(dph[mask].size()) return dph[mask];

    int i,j,k;
    vector<int> q,r;

    for(i=0;i<n;i++)
    {
        if(mask & (1<<i))
        {
            q=h(mask^(1<<i));
            j=i;
            break;
        }
    }

    for(i=0;i<m;i++) r.push_back(c[j][i]+q[i]);

    r[box[j]]--;

    return dph[mask]=r;
}

int f(int mask)
{
    if(mask==(1<<n)-1 ) return 100;

    if(dp[mask]!=-2) return dp[mask];

    int i,j,k,r=-1;
    vector<int> q;

    q=h(mask);

    for(i=0;i<n;i++)
    {
        if( (mask & (1<<i))==0 && q[box[i]] && f(mask^(1<<i))>-1 ) { r=i;break;}
    }

    return dp[mask]=r;
}

int main()
{
    int i,j,k,t,T;

    freopen("D-small-attempt1.in","r",stdin);
    freopen("treasure-out-small.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&k,&n);

        st.clear();
        st_tmp.clear();

        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            mymap[j]=-1;
            st_tmp.push_back(j);
        }

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&box[i],&j);
            tmp[i].clear();

            mymap[box[i]]=-1;

            for(int ii=0;ii<j;ii++)
            {
                scanf("%d",&k);
                mymap[k]=-1;
                tmp[i].push_back(k);
            }
        }

        m=0;

        for(i=0;i<n;i++)
        {
            if(mymap[box[i]]==-1)
            {
                mymap[box[i]]=m;
                m++;
            }
        }

        for(i=0;i<n;i++)
        {
            c[i].clear();

            for(j=0;j<m;j++) c[i].push_back(0);

            for(j=0;j<tmp[i].size();j++)
            {
                int kk=tmp[i][j];
                if(mymap[kk]!=-1) c[i][mymap[kk]]++;
            }
        }

        st.clear();

        for(i=0;i<m;i++) st.push_back(0);

        for(i=0;i<st_tmp.size();i++)
        {
            j=st_tmp[i];

           // printf("%d , %d\n",j,mymap[j]);

            if(mymap[j]!=-1) st[mymap[j]]++;
        }

        //cout<<m<<endl;

        //for(i=0;i<m;i++) cout<<st[i]<<" ";

        //cout<<endl;

        for(i=0;i<n;i++) box[i]=mymap[box[i]];

        for(i=0;i<(1<<n);i++) dph[i].clear();

        for(i=0;i<(1<<n);i++) dp[i]=-2;

        k=f(0);

        printf("Case #%d:",t);

        if(k==-1) printf(" IMPOSSIBLE\n");

        else
        {
            int mask=0;

            while(mask!=(1<<n)-1)
            {
                k=f(mask);
                printf(" %d",k+1);
                mask^=(1<<k);
            }

            printf("\n");
        }

    }

    return 0;
}


