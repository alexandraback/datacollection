#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0),eps=1e-9;
LL R;
LL ink;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int total,tt=0;
    cin>>total;
    while (total--){
        cin>>R>>ink;
        LL l=0,r=ink,mid;
        R=(R<<1)|1;
        while (l<r){
            mid=(l+r+1)>>1;
            LL tot=(R+2*(mid-1));
            if (tot<=ink/mid)
                l=mid;
            else
                r=mid-1;
        }
        cout<<"Case #"<<++tt<<": "<<l<<endl;
    }
    return 0;
}