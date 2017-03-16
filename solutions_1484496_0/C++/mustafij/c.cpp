#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;
vector<lli> v,tmp,rv1,rv2; lli N;
int vNum, marked[2000011];

bool canMake(vector<lli>& tmp,lli sum)
{
    vNum++;
    marked[0]=vNum;
    for(int i=0;i<sz(tmp);i++)
        for(int j=sum;j-tmp[i]>=0;j--) if(marked[j-tmp[i]]==vNum)
        {
            marked[j]=vNum;
            //aisi[j]=j-tmp[i];
        }
    return marked[sum]==vNum;
}

void printRes(int mask1,lli sum)
{
    rv1.clear();
    for(int i=0;i<N;i++) if(mask1&(1<<i)) rv1.push_back(v[i]);
    rv2.clear();
    int N=sz(tmp);
    for(int mask=1;mask<(1<<N);mask++)
    {
        lli cur=0; rv2.clear();
        for(int i=0;i<N;i++) if(mask&(1<<i)) cur+=tmp[i], rv2.push_back(tmp[i]);
        if(cur==sum) break;
    }
    sort(all(rv1)); sort(all(rv2));
}

int main()
{
    int t,cn=0; cin>>t; vNum=0;
    while(t--)
    {
        cin>>N; v.resize(N);
        for(int i=0;i<N;i++) cin>>v[i];
        bool ok=false;
        for(int mask=1;mask<(1<<N)&&!ok;mask++)
        {
            lli sum=0; tmp.clear();
            for(int i=0;i<N;i++) if(mask&(1<<i)) sum+=v[i]; else tmp.push_back(v[i]);
            if(canMake(tmp,sum)) printRes(mask,sum),ok=true;
        }
        printf("Case #%d:\n",++cn);
        if(!ok) printf("Impossible\n");
        else{
            for(int i=0;i<sz(rv1);i++)
            {
                if(i) printf(" ");
                cout<<rv1[i];
            }
            cout<<endl;
            for(int i=0;i<sz(rv2);i++)
            {
                if(i) printf(" ");
                cout<<rv2[i];
            }
            cout<<endl;
        }
    }

}
