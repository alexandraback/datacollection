#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<complex>
#include<set>
#include<map>
#include<sstream>
#include<string>
#include<deque>
#include<sys/time.h>
#include<fstream>
#include<bitset>
#include<cstring>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

timeval start,fin;

/*
 Functions used to measure times
*/
void init_time()
{
	gettimeofday(&start,NULL);
}

double get_time()
{
	gettimeofday(&fin,NULL);
	return (1000000*(fin.tv_sec-start.tv_sec)+(fin.tv_usec-start.tv_usec))/1000000.0;
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int t[22][22];
int v[22][22];
int N,M,K;
int mm;

bool check()
{
    forn(i,22)forn(j,22)v[i][j]=0;
    deque<pair<int,int> >cola;
    cola.pb(mp(0,0));
    v[0][0]=1;
    while(not cola.empty())
    {
        pair<int,int> p=cola.front();
        cola.pop_front();
        int x=p.first,y=p.second;
        forn(d,4)if(x+dx[d]>=0 and x+dx[d]<22 and y+dy[d]>=0 and y+dy[d]<22 and
                    t[x+dx[d]][y+dy[d]]==0 and v[x+dx[d]][y+dy[d]]==0)
        {
            v[x+dx[d]][y+dy[d]]=1;
            cola.pb(mp(x+dx[d],y+dy[d]));
        }
    }
    int c=0;
    forn(i,22)forn(j,22)if(v[i][j]==0)c++;
    return c>=K;
}

void bt(int u,int p)
{
    if(p>=mm)return;
    if(u==N*M)
    {
        if(check())
        {
            //cout<<"va "<<p<<endl;
            mm=min(mm,p);
        }
        return;
    }
    int x=u/M;
    int y=u%M;
    t[x+1][y+1]=0;
    bt(u+1,p);
    t[x+1][y+1]=1;
    bt(u+1,p+1);
}


int main()
{
    int T;
    cin>>T;
    forn(tt,T)
    {
        int n,m,k;
        cin>>n>>m>>k;
        mm=n*m;
        N=n;M=m;K=k;
        forn(i,22)forn(j,22)t[i][j]=0;
        bt(0,0);
        cout<<"Case #"<<tt+1<<": "<<mm<<endl;
    }
}
