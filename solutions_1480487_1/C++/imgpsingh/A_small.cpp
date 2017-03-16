#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
int ar[2010];
main(){
    int t,Kases=0;
    scanf("%d",&t);
    while(t--){
        int n,sum=0;
        double x[2010];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        int num=0;
        for(int i=1;i<n;i++)
            num+=(ar[0]-ar[i]);
        num=sum-num;
        cout<<"Case #"<<++Kases<<": ";
        x[0]=((double)num/(double)sum)/(double)n;
        printf("%0.7f ",x[0]*100.00);
        for(int i=1;i<n;i++){
            x[i]=(double)(ar[0]-ar[i])/(double)sum+x[0];
            printf("%0.7f ",x[i]*100.00);
        }
        cout<<"\n";
    }
    //system("pause");
    return 0;
}

