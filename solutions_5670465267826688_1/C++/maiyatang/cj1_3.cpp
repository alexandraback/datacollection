#include<fstream>
#include<string>
using namespace std;
ifstream cin ("temp.in");
ofstream cout ("temp.out");
int mark[4][4]={
    {1,2,3,4},
    {2,-1,4,-3},
    {3,-4,-1,2},
    {4,3,-2,-1}
};
int main ()
{
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        int l;
        long long x;
        string save;
        cin>>l>>x>>save;
        int find=2;
        int now=1;
        int need=1;
        for (int j=0;j<l;j++)
        {
            int temp;
            if (save[j]=='i') temp=2;
            else if (save[j]=='j') temp=3;
            else temp=4;
            if (now<0) now=-mark[-now-1][temp-1];
            else now=mark[now-1][temp-1];
        }
        if ((now==-1&&x%2==1)||((now==2||now==3||now==4||now==-2||now==-3||now==-4)&&x%4==2))
        {
            for (int q=0;q<12&&q<x;q++)
                for (int j=0;j<l;j++)
                {
                    int temp;
                    if (save[j]=='i') temp=2;
                    else if (save[j]=='j') temp=3;
                    else temp=4;
                    if (need<0) need=-mark[-need-1][temp-1];
                    else need=mark[need-1][temp-1];
                    if (need==find)
                    {
                        need=1;
                        find++;
                    }
                }
            if (find>4) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
