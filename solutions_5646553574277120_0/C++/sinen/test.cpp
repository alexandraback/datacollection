#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

void asd(){
    int c,d,v,x,t,max=0,count=0,n;
    vector<int> a;
    cin >> c >> d >> v;
    for(int i=0; i<d; i++){cin >> x; a.push_back(x);}
    sort(a.begin(),a.end());
    t=a.size();
    for(int i=0; i<a.size(); i++){
            if(a[i]!=i+1){t=i; break;}
    }
    if(t==0){a.push_back(1); t=1; sort(a.begin(),a.end());}
    max=(t*t+t)/2;//dari 1 sampe t(t-1)/2 uda keinclude
    n=a.size();
    for(int i=t; i<n; i++){
            if(max>=v){break;}
            if(a[i]<max){max+=a[i];}
            else{
                 //a[i]>max
                 for(int j=a[i]; j>=a[i-1]; j--){
                         if(j<=max){
                                   a.push_back(j);
                                   n++; sort(a.begin(),a.end());
                                   count++;
                                   max+=j;
                                   break;
                         }
                 }
            }
    }
    cout << count << endl;
}

int main(){
    freopen ("C-small-attempt1.in","r",stdin);
    freopen ("C-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
            cout << "Case #" << i << ": "; asd();
    }
    return 0;
}
