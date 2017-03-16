#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
vector<LL> a;
bool is_pan(LL val){
    LL sta[20],top=0;
    do{
        sta[top++]=val%10;
        val/=10;
    }while (val);
    for (int i=0;i<(top>>1);i++)
        if (sta[i]!=sta[top-i-1]){
            return false;
        }
    return true;
}
void init(){
    for (LL i=0;i<=10000000LL;i++)
        if (is_pan(i)&&is_pan(i*i)){
            a.push_back(i*i);
        }
    //cout<<a.size()<<endl;
}
LL find(LL val){
    for (int i=0;i<a.size();i++)
        if (a[i]>val)return i;
    return a.size();
}

int main(){
    freopen("C-large-1.in","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int total,tt=0;
    cin>>total;
    while (total--){
        LL a,b,x,y;
        while (cin>>a>>b){
            cout<<"Case #"<<++tt<<": ";
            cout<<find(b)-find(a-1)<<endl;
        }
    }
    return 0;
}