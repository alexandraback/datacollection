#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define maxi 1000006
vector<int> vc;
int arr[maxi];
int main()
{
    freopen("inc.txt","r",stdin);
    freopen("outc.txt","w",stdout);
    int t;
    cin>>t;

    for(int ii=1;ii<=t;ii++)
    {
        cerr<<ii<<endl;
        int ans=0;
        int n;
        cin>>n;
        vc.clear();
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]--;
        }
        for(int i=1;i<(1<<n);i++){
            vc.clear();
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                    vc.push_back(j);
            int l=vc.size();
            do {
                int cnt=0;
                int ai;
                for( ai=0;ai<l;ai++)
                {
                    int tt=arr[vc[ai]];
                    if(vc[(ai-1+l)%l]==tt||vc[(ai+1)%l]==tt)
                    {

                    }
                    else
                        break;
                }
                if(ai==l)
                ans=max(ans,l);
            } while ( std::next_permutation(vc.begin(),vc.end()) );
        }
        cout<<"Case #"<<ii<<": "<<ans<<endl;
    }
}
