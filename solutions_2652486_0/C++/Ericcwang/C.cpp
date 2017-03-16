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
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    cin>>T;
    cout<<"Case #1:"<<endl;
    int r,n,m,k;
    cin>>r>>n>>m>>k;

    for (int i=0;i<r;i++){
        int a[10];
        for (int j=0;j<k;j++) cin>>a[j];
        int t2,t3,t5;
        t2=t3=t5=0;
        for (int j=0;j<k;j++) {
            t2=max(t2,get(a[j],2));
            t3=max(t3,get(a[j],3));
            t5=max(t5,get(a[j],5));
        }
        vector<int> ans;
        for (;t3;t3--) ans.push_back(3);
        for (;t5;t5--) ans.push_back(5);
        for (;ans.size()<n&&t2>0;t2--) ans.push_back(2);
        if (t2){
            for (int g=0;g<ans.size()&&t2>0;g++)
            if (ans[g]==2) ans[g]=4,t2--;

        }
        while (ans.size()<n) ans.push_back(2);
        for (int i=0;i<n;i++) cout<<ans[i];
        cout<<endl;
    }

}
