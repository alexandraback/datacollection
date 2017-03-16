#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int t,i,j,n,s,p,ti,temp,count;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        count=0;
        cin>>n>>s>>p;
        for(j=0;j<n;j++)
        {
            cin>>ti;
            temp=ti/3;
            if(temp >= p)
                count++;
            else if((ti%3 >= 1) && (temp+1 >= p))
                count++;
            else if(s>0)
            {
                if(((ti%3 == 2) && (temp+2 >= p)) || ((ti%3 == 0) && (temp>0) && (temp+1 >= p)))
                {
                    s--;
                    count++;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;
    }
}
