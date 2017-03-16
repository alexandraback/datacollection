#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T, L, X, a[100000], fir, sec, last;
    char str[100000];
    cin>>T;
    int mul[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
    for(int i=1;i<=T;i++)
    {
        cin>>L>>X;
        cin>>str;
        for(int j=0;j<L;j++)
            if(str[j]=='i')
                a[j]=2;
            else if(str[j]=='j')
                a[j]=3;
            else if(str[j]=='k')
                a[j]=4;
        for(int k=1;k<X;k++)
            for(int j=0;j<L;j++)
                a[k*L+j]=a[j];
        int j=0;
        fir=a[j++];
        int t=L*X, neg=1;
        //cout<<"fir\n";
        while(neg*fir!=2 && j<t)
        {
            fir=mul[fir][a[j++]];
            if(fir<0)
                neg*=-1, fir*=-1;
            //cout<<fir<<endl;
        }
        if(j<t)
        {
            //cout<<"sec\n";
            sec=a[j++];
            neg=1;
            while(neg*sec!=3 && j<t)
            {
                sec=mul[sec][a[j++]];
                if(sec<0)
                    neg*=-1, sec*=-1;
                //cout<<sec<<endl;
            }
            if(j<t)
            {
                //cout<<"last\n";
                last=a[j++];
                neg=1;
                while(j<t)
                {
                    last=mul[last][a[j++]];
                    if(last<0)
                        neg*=-1, last*=-1;
                    //cout<<last<<endl;
                }
                if(last*neg==4)
                    cout<<"Case #"<<i<<": YES\n";
                else
                    cout<<"Case #"<<i<<": NO\n";
            }
            else
                    cout<<"Case #"<<i<<": NO\n";
        }
        else
                    cout<<"Case #"<<i<<": NO\n";
    }
    return 0;
}
