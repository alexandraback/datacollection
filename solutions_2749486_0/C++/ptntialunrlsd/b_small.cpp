#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    ifstream cin("input");
    ofstream cout("output");
    
    int x,y,t,cx,cy;
    cin>>t;

    for(int k=1;k<=t;k++)
    {
        cin>>x>>y;

        cx=0;
        cy=0;
        string ans;

        while(x-cx>0)
        {
            ans+="WE";
            cx++;
        }
        while(cx-x>0)
        {
            ans+="EW";
            cx--;
        }

        while(y-cy>0)
        {
            ans+="SN";
            cy++;
        }
        while(cy-y>0)
        {
            ans+="NS";
            cy--;
        }

        cout<<"Case #"<<k<<": "<<ans<<"\n";
    }

    return 0;
}




