#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define INF 1<<23

#define I1(a) scanf("%d",&a)
#define I2(a,b) scanf("%d %d",&a,&b)
#define I3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rep(i,s,e) for(i=s;i<e;i++)
#define repr(i,s,e) for(i=s;i>e;i--)


#define in(a) freopen(a,"r",stdin)
#define out(a) freopen(a,"w",stdout)
#define ll long long
ll BigMod(ll B,ll P,ll M){  ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R%M;}
#define ull unsigned long long
int N;

int main()
{
    in("in.txt");
    out("out.txt");
    int t,n,caseno=1;
    scanf("%d",&t);
    while(t--){
        vector<int>nums;
        map<int,int>MP;
        int cnt[4000];
        cin>>N;
        MP.clear();
        nums.clear();
        for(int i=0;i<3000;i++)cnt[i]=0;


        for(int i=0;i<(2*N)-1;i++){
            for(int j=0;j<N;j++){
                int x;
                cin>>x;
                cnt[x]++;
                if(MP[x]==0){
                    MP[x]=1;
                    nums.push_back(x);
                }
            }
        }
        sort(nums.begin(),nums.end());
        printf("Case #%d:",caseno++);
        for(int i=0;i<nums.size();i++){
            if(cnt[nums[i]]%2==1){
                cout<<" "<<nums[i];
            }
        }
        cout<<endl;

    }
    return 0;
}
