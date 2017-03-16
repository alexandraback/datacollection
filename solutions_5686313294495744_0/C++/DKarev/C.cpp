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

string s[1040],s1[1040];
bool use[100];
int n,mx=0;
vector<int>v,v1;

bool Check()
{
    bool l,l1;
    for(int i=0;i<v1.size();i++)
    {
        l=0; l1=0;
        for(int j=0;j<v.size();j++)
        {
            if(s[v1[i]]==s[v[j]])l=1;
            if(s1[v1[i]]==s1[v[j]])l1=1;
        }
        if(l==0 || l1==0)return 0;
    }
    return 1;
}

void rec(int k)
{

    if(k==n+1)
    {
        int br=0;
        v.clear(); v1.clear();
        for(int i=1;i<=n;i++)
        {
            if(use[i]==0)v.push_back(i);
            else {br++;v1.push_back(i);}
        }

        if(br>mx && Check())mx=br;
        return;

    }
    use[k]=0;
    rec(k+1);
    use[k]=1;
    rec(k+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("C.in");
    ofstream cout("C.out");

    int T;
    cin>>T;

    for(int t1=1;t1<=T;t1++)
    {
        cout<<"Case #"<<t1<<": ";

        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i]>>s1[i];
        }

        mx=0;
        rec(0);
        cout<<mx<<"\n";


    }

    return 0;
}


