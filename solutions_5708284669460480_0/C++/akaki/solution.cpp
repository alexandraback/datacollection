#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

long long i,j,k,l,m,n, cur , r,c,w,test,t, mx, a[1005],d, ii,x;
double ans;
string alphabet, s;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    cin>>t;

    while(t--){
        cin>>k>>l>>n;
        test++;
        cin>>alphabet;
        cin>>s;
        for (i=1;i<l;i++){
            int d = 1;
            for (j=0;j<l-i;j++){
                if (s[j]!=s[i+j]){
                    d = 0;
                    break;
                }
            }
            if (d) break;
        }
        ans = ((n-l+i)/i);
        double pr = 1.0;
        for (i=0;i<l;i++){
            int occurences = 0;
            for (j=0;j<k;j++){
                if (alphabet[j]==s[i]){
                    occurences++;
                }
            }
            if (occurences==0) ans=0;
            pr *= 1.0*occurences/k;
        }
        ans = ans - (n-l+1)*pr;
        cout.precision(10);
        cout<<fixed<<"Case #"<<test<<": "<<ans<<"\n";
    } 
    return 0;
}
