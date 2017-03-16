#include<bits/stdc++.h>
using namespace std;
int a,s,d,f,g,h,j,k,l,i,n,m;
string x,z;
char c;
main(){
    freopen("out.txt","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        cout<<"Case #"<<i+1<<": ";
        z="";
        c='A';
        for(a=0;a<x.size();a++){
            if(x[a]>=c) {z+=x[a];c=x[a];x[a]='2';}
        }
        reverse(z.begin(),z.end());
        cout<<z;
        for(a=0;a<x.size();a++){
            if(x[a]!='2') cout<<x[a];
        }
        cout<<endl;

    }
}
