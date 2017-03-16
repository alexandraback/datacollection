#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char a[1000005];
int  b[1000005];
long long ans(int n,int len){
    long long i,j,k,pre=-1LL;
    long long rst=0LL;
    for(i=0;i<len;i++){

        if(b[i]>=n){
            rst+=(i-n+1-pre)*(len-i)*1LL;
            pre=i-n+1;
        }
    }
    return rst;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out2.txt","w",stdout);
    int i,j,k,m,n,t,c,len;
    cin>>t;
    for(c=1;c<=t;++c){
        cin>>a>>n;
//        cout<<a<<endl;
        len=strlen(a);
        int cnt=0;
        for(i=0;i<len;++i){
            if(a[i]=='a'|a[i]=='e'|a[i]=='i'|a[i]=='o'|a[i]=='u'){
                cnt=0;
                b[i]=0;
            }else{
                cnt++;
                b[i]=cnt;
            }
//            cout<<b[i]<<" ";
        }

        printf("Case #%d: ",c);cout<<ans(n,len)<<endl;
    }
    return 0;
}

