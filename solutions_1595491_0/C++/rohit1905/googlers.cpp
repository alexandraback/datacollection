#include<iostream>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,s,p,q,score[100],x,y,count,i;
    cin>>t;
    for(q=1;q<=t;q++)
    {
        count=0;
        cin>>n>>s>>p;
        for(i=0;i<n;i++)
            cin>>score[i];
        x=p*3-2;
        if(p==1)
           y=1;
        else
           y=p*3-4;
        for(i=0;i<n;i++)
        {
            if(score[i]>=x)
                count++;
            else if(score[i]>=y && s>0)
            {
                count++;
                s--;
            }  
        }
        cout<<"Case #"<<q<<": "<<count<<endl;
    }
}              
                
