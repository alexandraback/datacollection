#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t,i,j,k,n,c=1;
    ofstream out;
    out.open("small.out");
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool bo[2501]={0};
        for(i=0;i<n*(2*n-1);i++)
        {
            cin>>j;
            if(!bo[j])
            bo[j]=1;
            else
                bo[j]=0;
        }
        out<<"Case #"<<c<<":";
        for(i=1;i<=2500;i++)
        {
            if(bo[i])
                out<<" "<<i;
        }
        out<<endl;
        c++;
    }
    return 0;

}
