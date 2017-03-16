#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int c,i,t,cases,size,n,aux,s,min;
    cin>>t;
    for(cases=1;cases<=t;cases++){
        cin>>size>>n;
        vector<int> a,m;
        for(i=0;i<n;i++){
            cin>>aux;
            a.push_back(aux);
            }
        sort(a.begin(),a.end());
        s=size;
        if(s==1){
            cout<<"Case #"<<cases<<": "<<n<<endl;
            continue;
            }
        for(i=0;i<a.size();i++){
            c=0;
            while(s<=a[i]){
                c++;
                s=2*s-1;
                }
            s=s+a[i];
            m.push_back(c);
            }
        for(i=1;i<m.size();i++){
            m[i]=m[i]+m[i-1];
            }
        min=n;
        for(i=0;i<m.size();i++){
            if(min>m[i]+n-i-1){
                min=m[i]+n-i-1;
                }
            }
        cout<<"Case #"<<cases<<": "<<min<<endl;
        }
    }
