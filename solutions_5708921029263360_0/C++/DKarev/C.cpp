//
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
#define lli long long

using namespace std;

struct Clothes
{
    int x,y,z;
};

Clothes A;
vector<Clothes>v,ans;
int cnt[12][12],cnt1[12][12],cnt2[12][12],J,P,S,m;

void rec(int a,int b, int c)
{
    if(ans.size()==J*P*S)return;
    if(c>S){b++;c=1;}
    if(b>P){a++;b=1;}
    if(a>J)
    {
        if(v.size()>ans.size())ans=v;
        return;
    }

    int a1,b1,c1;
    for(int i=a;i<=J;i++)
    {
        if(i==a)b1=b;
        else b1=1;

        for(int j=b1;j<=P;j++)
        {
            if(i==a && j==b)c1=c;
            else c1=1;

            for(int k=c1;k<=S;k++)
            {
                if(cnt[i][j]==m || cnt1[i][k]==m || cnt2[j][k]==m)continue;

                A.x=i; A.y=j; A.z=k;

                cnt[i][j]++;cnt1[i][k]++;cnt2[j][k]++;
                v.push_back(A);
                rec(i,j,k+1);


                cnt[i][j]--;cnt1[i][k]--;cnt2[j][k]--;
                v.pop_back();

            }
        }
    }

    if(v.size()>ans.size())ans=v;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("C.in");
    ofstream cout("C.txt");

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        //cout<<t<<endl;
        cout<<"Case #"<<t<<": ";
        cin>>J>>P>>S>>m;

        v.clear();
        ans.clear();
        memset(cnt,0,sizeof(cnt));
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));

        rec(1,1,1);

        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        {
            A=ans[i];
            cout<<A.x<<" "<<A.y<<" "<<A.z<<"\n";
        }



    }

    return 0;
}


