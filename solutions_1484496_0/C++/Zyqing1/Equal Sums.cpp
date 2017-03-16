#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=(1<<20)+10;
int s[25],n,m;
struct Data{
    int val;
    int sum;
}data[maxn];
int cmp(Data a, Data b){
    return a.sum<b.sum;
}
int calc(int p){
    int ret=0;
    for(int i=0;i<20;i++){
        if(p&(1<<i)){
            ret+=s[i];
        }
    }
    return ret;
}

void print(int p)
{
    for(int i=0;i<n;i++)
        if((1<<i) & p)
            printf("%d ",s[i]);
    puts("");
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        printf("Case #%d:\n",cas);
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=1;i<(1<<n);i++){
            data[i].val=i;
            data[i].sum=calc(i);
        }
        m=(1<<n);
        //cout<<m<<endl;
        sort(data,data+m,cmp);
        int a,b;
        for(a=0;a<m;a++){
            for(b=a+1;b<m && data[b].sum==data[a].sum;b++){
                if((data[a].val & data[b].val)==0)
                    break;
            }
            if(b<m && data[b].sum==data[a].sum)
                break;
        }
        if(a>=m)
            printf("Impossible\n");
        else{
            print(data[a].val);
            print(data[b].val);
            //puts("");
        }
    }
    return 0;
}
