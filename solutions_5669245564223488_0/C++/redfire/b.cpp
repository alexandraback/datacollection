/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(int i=s;i<=e;i++)
#define forj(s,e) for(int j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
using namespace std;
string a[102];
int brr[105];
int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y,b;
    freopen ( "B-small-attempt1.in","r",stdin );
    freopen ( "B2.txt","w",stdout );
    cin>>t;
    rep ( T,1,t )
    {
        cin>>n;
        fori ( 0,n-1 )
        {
            cin>>a[i];
        }
        printf ( "Case #%d: ",T );
        int f=1;
        mem ( brr,0 );
        //brr[i] is 0 if first and last can come together
        fori ( 0,n-1 )
        {
            int len=a[i].size();
            char first=a[i][0],last=a[i][len-1];
            /*int eq=1;
            forj ( 0,len-1 )
            {
                if ( a[i][j]!=first && a[i][j]!=last)
                {
                    eq=0;
                    break;
                }
            }
            if(eq==0)
            {
                brr[i]=1;
            }*/
            brr[i]=1;
            j=1;
            while ( j<len && a[i][j]==first )
            {
                j++;
            }
            k=len-2;
            while ( k>=0 && a[i][k]==last )
            {
                k--;
            }
            set<char> chars;
            rep ( it,j,k ) chars.insert ( a[i][it] );
            if ( chars.empty() )
            {
                brr[i]=0;
            }
            else
            {
                if(first==last) f=0;
                else brr[i]=0;
            }
            if ( chars.find ( first ) !=chars.end() )
            {
                f=0;
            }
            if ( chars.find ( last ) !=chars.end() )
            {
                f=0;
            }
            forj ( 0,n-1 )
            {
                if ( i==j )
                {
                    continue;
                }
                int len=a[j].size();
                fork ( 0,len-1 )
                {
                    char c=a[j][k];
                    if ( chars.find ( c ) !=chars.end() )
                    {
                        f=0;
                        break;
                    }
                }
                if ( f==0 )
                {
                    break;
                }
            }
            if ( f==0 )
            {
                break;
            }
        }
        if ( f==0 )
        {
            //printf("hey");
            printf ( "0\n" );
            continue;
        }
        int arr[n];
        fori ( 0,n-1 ) arr[i]=i;
        ll ans=0;
        do
        {
            int flag=1;
            int freq[26]= {0};
            int ind=arr[0];
            int len=a[ind].size();
            char prev=a[ind][len-1];
            freq[ a[ind][0]-'a']=1;
            freq[ a[ind][len-1]-'a']=1;
            fori ( 1,n-1 )
            {
                int ind=arr[i];
                int len=a[ind].size();
                char first=a[ind][0],last=a[ind][len-1];
                if ( freq[first-'a']==0 ) //ok
                {
                    freq[first-'a']=1;
                }
                else
                {
                    if ( first==prev ); //ok
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if ( freq[last-'a']==0 )
                {
                    freq[last-'a']=1;
                }
                else
                {
                    if ( last==first ); //ok
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                prev=last;
            }
            if ( flag==1 )
            {
                ans++;
            }
        }
        while ( next_permutation ( arr,arr+n ) );
        printf ( "%lld\n",ans );
    }
    return 0;
}

