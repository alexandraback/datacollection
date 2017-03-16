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
    freopen("A-small-attempt0.in","r+",stdin);
    freopen("output1.out","w+",stdout);
    ifstream fin("A-small-attempt0.in");
    char rep[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    int T,it=1;
    cin>>T;
    char G[1000]={'\0'};
    fin.getline(G,1000);
    while(it<=T)
    {
        fin.getline(G, 1000);
        int len=strlen(G);
        for(int i=0;i<len;i++)
        {
            if(G[i]>96&&G[i]<123)
            {
                G[i]=rep[G[i]-97];
            }
        }
        cout<<"Case #"<<it++<<": "<<G<<endl;
    }
}
