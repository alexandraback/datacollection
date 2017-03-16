#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

# define PB push_back  
# define MP make_pair  
# define SZ(v) ((int)(v).size())  
# define FOR(i,a,b) for(i=(a);i<(b);++i)  
# define REP(i,n) FOR(i,0,n)  
# define FORE(i,a,b) for(i=(a);i<=(b);++i)  
# define REPE(i,n) FORE(i,0,n)  
# define FORSZ(i,a,v) FOR(i,a,SZ(v))  
# define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

int a[1000][1000];
int marked[1000];
int n;
int first = 0;
int tree(int l)
{
    int i,j;
    
    int r;
    if(marked[l] ==1)
        return 1;
    marked[l] = 1;

    for(j=0;j<n;j++)
    {
        if(a[l][j]==1 && j!= first)
        {

            //marked[j] = 1;
            r=0;
            r = tree(j);
            if(r == 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i,j,k=0,t,r,m,c;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    cin>>t;

    while(t--)
    {
        cin>>n;
        
        memset(a,0,sizeof(int)*1000*1000);

        for(i=0;i<n;i++)
        {
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>c;
                a[i][c-1] = 1;
            }
        }
        
        
        
        int flag = 0;
        for(i=0;i<n;i++)
        {
            memset(marked,0,sizeof(int)*1000);
            first =i ;
            if(tree(i))
            {cout<<"Case #"<<++k<<": Yes"<<"\n";
            flag =1;
            break;
            }
        } 
        if(flag ==0)
            cout<<"Case #"<<++k<<": No"<<"\n";
        
         
        }
        
        
    
    return 0;
}
