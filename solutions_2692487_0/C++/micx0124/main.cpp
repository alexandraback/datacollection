#include<iostream>
#include<cmath>
using namespace std;

int a[200];
int ans[200];
int add[200];
int del[200];

int step(int s,int i){
 int cnt=0;
 while(s<=a[i]){
     cnt++;
     s=s*2-1;
 }
    add[i]=add[i-1]+cnt;
//    cout<<"cnt="<<cnt<<endl;
    return s+a[i];
}
int main()
{
freopen("A-small-attempt2.in", "r", stdin);
freopen("2.txt", "w", stdout);
    int i,j,k,t,n,A,m,c,res;
    cin>>t;
    for(c=1;c<=t;++c){

        cin>>A>>n;
//        cout<<A<<endl;
        for(j=0;j<n;j++){
            cin>>a[j];
            ans[j]=0;
        }
        if(A==1){
            res=n;
        }
        else{
            sort(a,a+n);
//            for(i=0;i<n;i++){
//             cout<<a[i]<<" ";
//            }cout<<endl;
            int sum=0;
            for(i=0;i<n;i++)
            {

                if(a[i]<A)
                {
                    sum+=a[i];
                    add[i]=0;
                    del[i]=n-1-i;
                }
                else break;
            }
            sum+=A;
            for(;i<n;i++){
                if(sum>a[i])
                {
                    sum+=a[i];
                    add[i]=add[i-1];
                    del[i]=n-1-i;
                }else{
                    //
                    sum=step(sum,i);
                    del[i]=n-1-i;
                }
//                cout<<sum<<endl;
            }
            res = n;
//            for(i=0;i<n;i++)
//            {
//                cout<<add[i]<<" ";
//            }cout<<endl;
//            for(i=0;i<n;i++)
//            {
//                cout<<del[i]<<" ";
//            }cout<<endl;
            for(i=0;i<n;i++)
            {
                if(res>(add[i]+del[i]))
                    res=add[i]+del[i];
            }
        }
        printf("Case #%d: %d\n",c,res);
    }





return 0;
}
