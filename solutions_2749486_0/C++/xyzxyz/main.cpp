#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")


using namespace std;
typedef long long ll;
typedef double db;

int t,x,y;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++)
        {
            cin>>x>>y;
            cout<<"Case #"<<o<<": ";
            if(x<0)
                {
                    for(int i=1;i<=2*abs(x);i++)
                        if(i%2==1)
                            cout<<"E";
                        else
                            cout<<"W";
                }
            if(x>0)
                {
                    for(int i=1;i<=2*abs(x);i++)
                        if(i%2==1)
                            cout<<"W";
                        else
                            cout<<"E";
                }
            
            if(y<0)
                {
                    for(int i=1;i<=2*abs(y);i++)
                        if(i%2==1)
                            cout<<"N";
                        else
                            cout<<"S";
                }
            if(y>0)
                {
                    for(int i=1;i<=2*abs(y);i++)
                        if(i%2==1)
                            cout<<"S";
                        else
                            cout<<"N";
                }
            cout<<endl;
            
        }



  //  system("pause");
    return 0;
}
