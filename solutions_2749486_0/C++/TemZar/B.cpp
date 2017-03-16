#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{int T,i,j; string D="aeiou";
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    cin>>T;
    for(i=1;i<=T;i++)
    {int x,y,j; string ans;
     cin>>x>>y;
     if(x<0)for(j=0;j<-x;j++)ans+="EW";
     else if(x>0)for(j=0;j<x;j++)ans+="WE";
     if(y<0)for(j=0;j<-y;j++)ans+="NS";
     else if(y>0)for(j=0;j<y;j++)ans+="SN";
     cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
