#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mult(int a, int b){
    int s=(a%2)+(b%2);
    a/=2;
    b/=2;
    int r=0;
    if (a==0){
        r=b;
    }
    else if(b==0){
        r=a;
    }
    else if(a==b){
        r=0;
        s++;
    }
    else if(a==1){
        if (b==2){
            r=3;
        }
        if (b==3){
            r=2;
            s++;
        }
    }
    else if(a==2){
        if (b==1){
            r=3;
            s++;
        }
        if (b==3){
            r=1;
        }
    }
    else if(a==3){
        if (b==1){
            r=2;
        }
        if (b==2){
            r=1;
            s++;
        }
    }
    return r*2+(s%2);
}

int divs(int a, int b){//a:n alusta otetaan b pois
    for (int i=0;i<8;i++){
        if (mult(b, i)==a) return i;
    }
    return -1;
}

int is[3][8];

int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        int l;
        ll x;
        cin>>l>>x;
        if (x>14ll){
            x%=12ll;
            while (x<14){
                x+=12;
            }
        }
        string s;
        cin>>s;
        int n=l*x;
        int su=0;
        for (int i=0;i<3;i++){
            for (int ii=0;ii<8;ii++){
                is[i][ii]=0;
            }
        }
        is[0][0]=1;
        int f=0;
        for (int i=0;i<n;i++){
            int t=0;
            if (s[i%l]=='i') t=2;
            if (s[i%l]=='j') t=4;
            if (s[i%l]=='k') t=6;
            su=mult(su, t);
            if (i==n-1){
                for (int ii=0;ii<8;ii++){
                    if (is[2][ii]&&divs(su, ii)==6){
                        f=1;
                    }
                }
            }
            for (int ii=0;ii<8;ii++){
                if (is[1][ii]&&divs(su, ii)==4){
                    is[2][su]=1;
                }
            }
            for (int ii=0;ii<8;ii++){
                if (is[0][ii]&&divs(su, ii)==2){
                    is[1][su]=1;
                }
            }
        }
        if (f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
