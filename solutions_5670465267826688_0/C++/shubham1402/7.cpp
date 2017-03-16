#include<bits/stdc++.h>
#define SWAP(x,y,t) t=x,x=y,y=t
using namespace std;

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    int t;
    cin>>t;
    int k = 1;
    while(t--)
    {
        int flag = 0;
        cout<<"Case #"<<k<<": ";
        k++;
        int x,r,c;
        cin>>x>>r>>c;
        if(x == 1)
        {
            flag = 1;
        }
        else if(x == 2)
        {
            if((r*c)%2 == 0)
            flag = 1;
        }
        else if(x < 7)
        {
            if((r*c)%x == 0)
            {
                if(x == 3)
                {
                    int t;
                    if(r >= c)
                    SWAP(r,c,t);
                    if(c >= 3 && r >= 2)
                    flag = 1;
                }
                else if(x == 4)
                {
                    int t;
                    if(r >= c)
                    SWAP(r,c,t);
                    if(c >= 4 && r >= 3)
                    flag = 1;
                }
                else
                {
                    int t;
                    if(r >= c)
                    SWAP(r,c,t);
                    if(c >= x && r >= 4)
                    flag = 1;
                }
            }
            else
            {
                flag = 0;
            }
        }
        else
        {
            flag = 0;
        }
        if(flag)
        cout<<"GABRIEL"<<endl;
        else
        cout<<"RICHARD"<<endl;
    }
    return 0;
}
