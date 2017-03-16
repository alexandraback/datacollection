#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);




vector<int> motes;
int main()
{

    int T,i,j,k,cs,n,val,A;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);


    for(cs=1; cs<=T; cs++)
    {
        printf("Case #%d: ",cs);
        scanf("%d %d",&A,&n);


        motes.clear();

        for(i=0; i<n; i++)
        {
            scanf("%d",&val);
            motes.push_back(val);
        }
        sort(motes.begin(),motes.end());



        int ans=n;


        int l=0,r;


        // cout<<A;
        // asdf

        if(A==1)
            ans=n;
        else
        {
            for(i=0; i<n; i++)
            {
             //   cout<<i<<" "<<A<<" "<<motes[i]<<endl;
                if(motes[i]<A)
                {
                    //  cout<<l<<enl
                    A+=motes[i];
                    r=n-i-1;
                    ans=min(ans,l+r);
                }
                else
                {
                    A+=(A-1);
                    l++;
                    i--;
                }
            }
        }
        //  asdf

        printf("%d\n",ans);







    }

    return 0;
}
