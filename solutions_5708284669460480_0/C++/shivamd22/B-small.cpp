#include<bits/stdc++.h>
using namespace std;
int strmatch(char *a,int n,string b){//a is text, b is keyword
    //int n=a.length();
    int m=b.length();
    int cnt=0;
    bool flag;
    for(int i=0;i<=(n-m);i++){
        flag=true;
        for(int j=0;j<m;j++){
            if(a[i+j]!=b[j]){flag=false;
                break;
            }
        }
        if(flag)cnt++;
    }
    return cnt;
}
int cont[300];
vector<char> alpha;

void assgn(char *tmp, int sz, int val, int v){
    int d;
    for(int i=sz-1;i>=0;i--){
        d=val%v;
        tmp[i]=alpha[d];
        val=val/v;
    }

}
int pwr(int x,int n){
    int ans=1;
    for(int i=0;i<n;i++)
        ans*=x;
    return ans;
}

int main(){
    int t,k,l,s;
    double ans;
    string keys,trgt;
    cin>>t;
    for(int x=1;x<=t;x++){
        ans=0;
        cin>>k>>l>>s;
        cin>>keys;
        cin>>trgt;
        alpha.clear();
        memset(cont,0,sizeof(cont));

        char *tmp=new char[s+2];
        for(int i=0;i<k;i++){
            if(cont[keys[i]]==0){
                alpha.push_back(keys[i]);
            }
            cont[keys[i]]++;
        }
        int v=alpha.size();
        int mx=pwr(v,s);
        int mxmatch=0;
        for(int i=0;i<mx;i++){
            assgn(tmp,s,i,v);
            for(int i=0;i<s;i++){
                //cout<<tmp[i];
            }
            //cout<<" "<<i<<endl;
            double temp=0;
            double prob=1;
            for(int i=0;i<s;i++){
                prob=prob*((double)cont[tmp[i]]/(double)k);
            }
            int num=(strmatch(tmp,s,trgt));
            mxmatch=max(mxmatch,num);
            temp=prob*num;
            ans+=temp;
            //cout<<prob<<" "<<num<<" "<<ans<<endl;
        }
        cout<<"Case #"<<x<<": "<<double(mxmatch-ans)<<endl;
    }
}
