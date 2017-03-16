#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"

using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int a,b;
        bool now;
        
        scanf("%d%d",&a,&b);
        
        string ans="";
        
        if(a==0);
        else if(a<0)
        {
            now=false;
            ans+="W";
            a*=-1;
        }
        else
        {
            now=true;
            ans+="E";
        }
        
        for(int i=1;i<a;i++)
        {
            if(now)ans+="WE";
            else ans+="EW";
        }
        
        if(b==0);
        else if(b<0)
        {
            now=false;
            ans+="NS";
            b*=-1;
        }
        else
        {
            now=true;
            ans+="SN";
        }
        
        for(int i=1;i<b;i++)
        {
            if(now)ans+="SN";
            else ans+="NS";
        }
        
        cout << "Case #" << test << ": " << ans << endl;
    }
}
