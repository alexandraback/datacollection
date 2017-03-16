#include<bits/stdc++.h>
using namespace std;
int ar[1005];
vector< vector<int> > gr;
int n;
int flag[1000];
int last,noef=-1;
int cou(int i)
{
flag[i]=1;
if(ar[ar[i]]==i)
{
    noef=ar[i];
    last = i;
    return 1;
}
if(flag[ar[i]])
{   last=ar[i];
return 0;
}
else
return 1+cou(ar[i]);

}
int main()
{
    int t,itr=1;
    cin>>t;
    while(t--)
    {
            cin>>n;
            gr.resize(n);
            for(int i=0;i<n;i++)
            {
            int a;
            cin>>a;
            ar[i]=a-1;
            gr[a-1].push_back(i);}
            int ans=0,curans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)    flag[j]=0;
            noef=-1;

            curans=cou(i);
            if(noef!=-1)
            {
            // cout<<"in no "<<noef<<endl;
            //         for(int j=0;j<gr[noef].size();j++)
            //         {
            //         cout<<" calling "<<gr[noef][j]<<" "<<endl;
            //             if(gr[noef][j]!=last)
            //             {
            //                 int tempans=cou(gr[noef][j]);
            //
            //                 if(last==i)
            //                 curans+=tempans+1;
            //
            //             }
            //         }
              int curlast=last,no=noef;
            for(int j=0;j<n;j++)
            if(ar[j]==no)
            if(j!=curlast)
            {
              //cout<<"calling "<<j;
              int tempans=cou(j);
              //cout<<" tempans "<<tempans<<endl;
              curans+=tempans-1;
          }
            }

          //cout<<curans<<endl;
          if(i==last||noef!=-1)
            ans = max(curans,ans);


        }
        cout<<"Case #"<<itr++<<": ";
        cout<<ans+1<<endl;

    }

    return 0;
}
