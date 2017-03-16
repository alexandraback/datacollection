#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1005];
char c[1005];
int main()
{
    int i,N=0,n,t;
    cin>>t;
    while(t--){
        cin>>n;
        scanf("%s",c);
        for(i=0;i<=n;i++){
            a[i]=c[i]-'0';
        }
        int s=0;
        int j=a[0];
        for(i=1;i<=n;i++){
            if(j>=i){
                j+=a[i];
            }
            else{
                s+=i-j;
                j=i;
                j+=a[i];
            }
        }
        printf("Case #%d: ",++N);
        cout<<s<<endl;
    }
}