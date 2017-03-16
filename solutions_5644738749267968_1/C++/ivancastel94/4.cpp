#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int war(vector<float> a, vector<float> b){
    int i,p=0,j=0;
    for(i=0;i<a.size();i++){
        while(j<b.size()&&b[j]<a[i])j++;
        if(j<b.size())p++;
        j++;
    }
    return a.size()-p;
}

int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int i,n,t,cases;
    float a;
    cin>>t;
    for(cases=1;cases<=t;cases++){
        cin>>n;
        vector<float> naomi,ken;
        for(i=0;i<n;i++){
            cin>>a;
            naomi.push_back(a);
        }
        for(i=0;i<n;i++){
            cin>>a;
            ken.push_back(a);
        }
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());
        int w = war(naomi,ken);
        int dw = n-war(ken,naomi);
        cout<<"Case #"<<cases<<": "<<dw<<" "<<w<<endl;
    }
}
