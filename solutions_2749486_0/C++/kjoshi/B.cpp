#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main()
{
    int i,j,k,l;
    int T,t;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("output-B.txt","w",stdout);

    cin>>T;
    for(t=1;t<=T;++t)
    {
        int X,Y,posx=0,posy=0,steps=1;
        string ans="";
        cin>>X>>Y;
        if(X>0)
        {
            while(posx!=X&&steps<501)
            {
                if((posx+steps)<=X)
                {
                    posx+=steps;
                    ans+="E";
                }
                else
                {
                    posx-=steps;
                    ans+="W";
                }
                ++steps;
                //cout<<posx<<" : "<<posy<<endl;
            }
        }
        else
        {
            while(posx!=X&&steps<501)
            {
                if((posx-steps)>=X)
                {
                    posx-=steps;
                    ans+="W";
                }
                else
                {
                    posx+=steps;
                    ans+="E";
                }
                ++steps;
                //cout<<posx<<" : "<<posy<<endl;
            }
        }
        if(Y>0)
        {
            while(posy!=Y&&steps<501)
            {
                if((posy+steps)<=Y)
                {
                    posy+=steps;
                     ans+="N";
                }
                else
                {
                    posy-=steps;
                     ans+="S";
                }
                 ++steps;
                // cout<<posx<<" : "<<posy<<endl;
            }
        }
        else
        {
            while(posy!=Y&&steps<501)
            {
                if((posy-steps)>=Y)
                {
                    posy-=steps;
                   ans+="S";
                }
                else
                {
                    posy+=steps;
                    ans+="N";
                }
                ++steps;
                //cout<<posx<<" : "<<posy<<endl;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }


    return 0;
}
