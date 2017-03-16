#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool flag[10000000];
long long save[10000000];
long long a,b;
int cnt=0;
int T;

void creatpalindromes(int a){
     int x[10],x1[10],x2[10];
     int tmp=a,p=0,ans1=0,ans2=0;
     while (tmp!=0){
           x[p++]=tmp%10;
           tmp/=10;
     }
     //even
     for (int i=0;i<p;i++){
         x1[i]=x[p-i-1];x1[2*p-i-1]=x[p-i-1];
     } 
     for (int i=0;i<2*p;i++) ans1=ans1*10+x1[i];
     if (ans1<10000000) flag[ans1]=1;
     //odd
     for (int i=0;i<p;i++){
         x2[i]=x[p-i-1];x2[2*p-i-2]=x[p-i-1];
     } 
     for (int i=0;i<2*p-1;i++) ans2=ans2*10+x2[i];
     flag[ans2]=1;
     //if (ans2==10) cout<<"~~~~~~ "<<x2[0]<<" ------"<<endl;
}

void checkpalindromes(long long a){
     int x[20],p=0;
     long long tmp=a;
     while (tmp!=0){
           x[p++]=tmp%10;
           tmp/=10;
     }
     for (int i=0;i<p/2;i++) if(x[i]!=x[p-1-i]) return;
     save[cnt++]=a;
}

int main()
{
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    for (int i=1;i<=9999;i++){
        creatpalindromes(i);
    } 
    //for (int i=1;i<=100000;i++) if (flag[i]) cout<<i<<endl; 
    long long tmp;
    for (int i=1;i<10000000;i++){
        if (flag[i]){
           tmp=i;
           tmp=tmp*tmp;
           //cout<<tmp<<endl;
           checkpalindromes(tmp);
        }
    } 
    
    cin>>T;
    for (int Case=1;Case<=T;Case++){
        cin>>a>>b;
        int st=cnt,ed=0;
        for (int i=0;i<cnt;i++) if (save[i]>=a){st=i;break;} 
        for (int i=cnt-1;i>=0;i--) if (save[i]<=b){ed=i;break;}
        int ans=ed-st+1;
        if (ans<=0) ans=0;
        cout<<"Case #"<<Case<<": "<<ans<<endl;
         
    }
    
    //for (int i=0;i<cnt;i++) cout<<save[i]<<endl;
}
