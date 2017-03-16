#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int t,k,l,s;
double p[30];
double Max,sum;
string a,b;

int get(string a, string b){
    int l1=a.size(),l2=b.size(),ans=0;
    for(int i=0;i<l1;i++){
        int j=0;
        int ii=i;
        while(ii<l1 && j<l2 && a[ii]==b[j]){
            ii++,j++;
        }
        if(j==l2){
            ans++;
        }
    }
    return ans;
}

void dfs(int now,double pp,string X){
    if(now==s){
        int v=get(X,b);
        //cout<<X<<" "<<v<<endl;
        if(v>Max)   Max=v;
        sum += v*pp;
    }
    else{
        for(int i=0;i<26;i++) if(p[i]!=0.0){
            string Y=X+(char)(i+'A');
            dfs(now+1,pp*p[i],Y);
        }
    }

}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        cin>>k>>l>>s>>a>>b;
        for(int i=0;i<26;i++) p[i]=0.0;
        int len=a.size();
        for(int i=0;i<len;i++) p[a[i]-'A']+=1.0;
        for(int i=0;i<26;i++) p[i]/=len;
        Max=0,sum=0;
        dfs(0,1,"");
        printf("Case #%d: %lf\n",ca,Max-sum);
    }
    return 0;
}
