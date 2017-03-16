#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r+",stdin);
    freopen("output2.out","w+",stdout);
    int T,it=1;
    cin>>T;
    while(it<=T)
    {
        int S,p,N,scr[101],ans=0,t1=0,t2=0;
        cin>>N>>S>>p;
        for(int i=0;i<N;i++)
        {
            cin>>scr[i];
            if(scr[i]>(3*(p-1)))
            {
                if(scr[i]>=p)
                t1++;
            }
            else if(scr[i]>(3*(p-2)+1))
            {
                if(scr[i]>=p)
                t2++;
            }
        }
        if(t2>S)
        {
            t2=S;
        }
        if((t1+t2)>=N)
        {
            ans=N;
        }
        else
        {
            ans=t1+t2;
        }

        cout<<"Case #"<<it++<<": "<<ans<<endl;
    }

}
