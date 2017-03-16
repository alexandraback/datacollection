#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int lim,N;
bool compare(vector<int> A,vector<int> B)
{
  sort(A.begin(),A.end());
  return equal(A.begin(),A.end(),B.begin());
}
void print(vector<int> v)
{
    for(int i=0;i<N;i++)
        cout<<v[i]<<" ";
}
int BinInt(string X)
{
    int r=0;
    int  p=1;
    for(int i=X.length()-1;i>=0;i--,p*=2)
            r+=(X[i]-'0')*p;
        return r;
}
void tobin(int n)
{
    int x=0;
    while(n)
    {
        if(n%2==1)x++;
        n/=2;
    }
    cout<<x<<endl;
}
vector<int> Add(vector <int> A,int n)
{
    vector<int> r(N);
    for(int i=0;i<N;i++)
        if(A[i]+n<lim)
        r[i]=A[i]+n;
    else
        r[i]=A[i]+n-lim;
    return r;

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int L;
        cin>>N>>L;
        getchar();
        vector<int> A,B;
        for(int i=0;i<N;i++)
        {
            string tmp;cin>>tmp;
            B.push_back(BinInt(tmp));
        }
        for(int i=0;i<N;i++)
        {
            string tmp;cin>>tmp;
            A.push_back(BinInt(tmp));
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        bool ok=true;
        lim=pow(2,L);
        int count=abs(A[0]-B[0]);
             for(int i=1;i<N;i++)
             {
               if(abs(A[i]-B[i])!=count&&abs(A[i]-B[i])!=lim-count)
               {
                   //cout<<A[i]<<" "<<B[i]<<endl;
                   ok=false;
                   break;
               }

             }
             cout<<"Case #"<<t<<": ";
             if(ok==false)
             cout<<"NOT POSSIBLE"<<endl;
             else tobin(count);


    }
}
