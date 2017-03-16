#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
int get(int a,int b){
    int t=0;
    while (a%b==0){
        t++;
        a/=b;
    }
    return t;
}
int main(){
    freopen("C-small-2-attempt6.in","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    cin>>T;
    cout<<"Case #1:"<<endl;
    int r,n,m,k;
    cin>>r>>n>>m>>k;

    for (int i=0;i<r;i++){
        int a[10];
        for (int j=0;j<k;j++) cin>>a[j];
        int t2,t3,t5,t7;
        t2=t3=t5=t7=0;
        for (int j=0;j<k;j++) {
            t2=max(t2,get(a[j],2));
            t3=max(t3,get(a[j],3));
            t5=max(t5,get(a[j],5));
            t7=max(t7,get(a[j],7));
        }
        vector<int> ans;
        for (;t7;t7--) ans.push_back(7);
        for (;t3;t3--) ans.push_back(3);
        for (;t5;t5--) ans.push_back(5);
        for (;ans.size()<n&&t2>0;t2--) ans.push_back(2);
        while (t2>0){
            int t=rand()%ans.size();
            if (ans[t]*2<=m) ans[t]*=2,t2--;

        }
        while (ans.size()<n) ans.push_back(2+rand()%7);
        for (int i=0;i<n;i++) cout<<ans[i];
        cout<<endl;
    }

}
