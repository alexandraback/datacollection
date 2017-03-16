#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        string i,j="",k;
        cin>>i;
        j=i[0];
        long long a,b,c;
        for(a=1;a<i.size();a++)
        {
            if(i[a]>=j[0])
                {
                    k=i[a]+j;
                    j=k;
                }
            else
            {
                    k=j+i[a];
                    j=k;
            }    
        }
        cout<<"Case #"<<tt<<": "<<j<<"\n";
    }
    return 0;
}
