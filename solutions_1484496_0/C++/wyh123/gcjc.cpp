#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

struct Node {
    int sum,mask;
}ans[1<<22];

int a[50],n;

bool cmp(const Node &a,const Node &b) {
    return a.sum<b.sum;
}
  
int main() {
    int T;    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    cin >> T;
    for (int cas=1; cas<=T; cas++){
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        cout << "Case #" << cas << ":" << endl;    
        int summ;
        for (int i=0; i<(1<<n); i++) {
            summ=0;
            ans[i].sum=0;
            for (int j=0; j<n; j++) {
                if ((1<<j)&i) summ+=a[j];
            }
           // cout << summ << " " << i << endl;
            ans[i].sum=summ;  
            ans[i].mask=i;
        }
        sort(ans,ans+(1<<n),cmp);
        bool flag1=false;
        Node tmp=ans[0];
        for (int i=1; i<(1<<n); i++) {
            if (tmp.sum==ans[i].sum) {
                bool flag=true;
                for (int j=0; j<n; j++) {                    
                    if ((1<<j)&tmp.mask) {
                        if (flag) flag=false;
                        else cout << " ";
                        cout << a[j];
                    }
                }
                cout << endl;
                flag=true;
                for (int j=0; j<n; j++) {
                     if ((1<<j)&ans[i].mask){
                        if (flag) flag=false;
                        else cout << " ";
                        cout << a[j];
                    }
                }  
                cout << endl;
                flag1=true;
                break;
            }
            else tmp=ans[i];
        }
        if (!flag1) cout << "Impossible" << endl;
    }  
    return 0;  
}     

