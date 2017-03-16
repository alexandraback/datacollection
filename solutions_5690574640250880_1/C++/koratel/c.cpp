#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-12;

void solve(int num)
{
    int r, c, m;
    cin>>r>>c>>m;
    int fail=0, transpose=0;
    if(r<c)
    {
        swap(r, c);
        transpose=1;
    }
    vector<vector<char> > v(r, vector<char>(c, '*'));
    if(c==1)
    {
        for(int i=1; i+m<r; i++) v[i][0]='.';
    }
    else if(c==2)
    {
        if((m%2) && m!=r*c-1) fail=1;
        if(m==r*c-2) fail=1;
        for(int i=0; 2*(i+1)+m<=r*c; i++)
        {
            v[i][0]=v[i][1]='.';
        }
    }
    else
    {
        int notm=r*c-m, cnt=0;;
        if(notm==2 || notm==3 || notm==5 || notm==7) fail=1;
        else if(notm > 2*c+1)
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c && cnt<notm; j++)
                {
                    v[i][j]='.';
                    cnt++;
                }
            }
            if((notm%c) == 1)
            {
                int i=notm/c;
                v[i][1]='.';
                v[i-1][c-1]='*';
            }
        }
        else if(notm>1)
        {
            if(notm%2)
            {
                cnt=3;
                v[2][0]=v[2][1]=v[2][2]='.';
            }
            for(int j=0; cnt<notm; j++)
            {
                v[0][j]=v[1][j]='.';
                cnt+=2;
            }
        }
    }
    v[0][0]='c';
    cout<<"Case #"<<num<<":\n";
    if(fail) cout<<"Impossible\n";
    else if(transpose)
    {
        for(int j=0; j<c; j++)
        {
            for(int i=0; i<r; i++) cout<<v[i][j];
            cout<<"\n";
        }
    }
    else
    {
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++) cout<<v[i][j];
            cout<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
