#include<bits/stdc++.h>
#include<cmath>
#define M_PI  3.14159265358979323846
using namespace std;
void equate(int m1,int m2,int m3,int m4)
{
    for(int i=0;i<m3-m4;i++)
            cout<<char('A'+m1)<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        int p,s,x,y,z;
        int i,j,k,n;
        cin>>j>>p>>s>>k;
        int a[11][11]={0},b[11][11]={0},c[11][11]={0};
        vector< string > v;
        for(i=0;i<j;i++)
            for(x=0;x<p;x++)
                for(y=0;y<s;y++)
                {
                    if(a[i+1][x+1]<k&&b[x+1][y+1]<k&&c[i+1][y+1]<k)
                    {
                        a[i+1][x+1]++;
                       b[x+1][y+1]++;
                        c[i+1][y+1]++;
                        v.push_back(to_string(i+1)+" "+to_string(x+1)+" "+to_string(y+1));
                    }    
                }
        cout<<"Case #"<<tt<<": "<<v.size()<<"\n";
        for(i=0;i<v.size();i++)
            cout<<v[i]<<"\n";
   }
    return 0;
}

