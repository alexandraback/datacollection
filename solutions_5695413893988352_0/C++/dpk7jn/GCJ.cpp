#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define fora(x,y,z) for(int x=y;x<=(z);x++)
#define PNL printf("\n")
#define FL(a,n,x) fill(a,a+n,x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define debug(x) cout<<"here"<<x<<endl;

char s1[10];
char s2[10];
int str1[10];
int str2[10];

void gen(int in,int arr[],int n,vector<int> &v){
if(in==n){
int x=arr[0];
for(int i=1;i<n;i++)
        x=x*10+arr[i];
v.pb(x);
return;
}

if(arr[in]!=-1)
    gen(in+1,arr,n,v);
else{
    for(int d=0;d<=9;d++){
    arr[in]=d;
    gen(in+1,arr,n,v);
    }
    arr[in]=-1;
}

}

void print(int x,int n){
int temp=x;
int cnt=0;
while(temp!=0)
    temp=temp/10 , cnt++;
fora(i,1,n-cnt)
cout<<"0";
if(x!=0)
cout<<x;
}

int main(){
   freopen("Input.in","r",stdin);
   freopen("Output.txt","w",stdout);
   int te;
   si(te);
   int ts=0;
   while(te--){
        ts++;
     scanf(" %s",s1);
     scanf(" %s",s2);
     int n=strlen(s1);
     fora(i,0,n-1){
     if(s1[i]!='?')
     str1[i]=s1[i]-'0';
     else
        str1[i]=-1;
     if(s2[i]!='?')
     str2[i]=s2[i]-'0';
     else
        str2[i]=-1;
     }
     vector<int> v1,v2;
     gen(0,str1,n,v1);
     gen(0,str2,n,v2);
     sort(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());

     int l1=v1.size(),l2=v2.size();

     /*fora(i,0,l1-1)
     cout<<v1[i]<<" ";
     cout<<endl;
     fora(i,0,l2-1)
     cout<<v2[i]<<" ";
     cout<<endl;
*/
     int d=abs(v1[0]-v2[0]),a1=v1[0],a2=v2[0];
     fora(i,0,l1-1)
     fora(j,0,l2-1){
     int t=abs(v1[i]-v2[j]);
     if(t<d){
        d=t;
        a1=v1[i];
        a2=v2[j];
     }
     }
     cout<<"Case #"<<ts<<": ";
     print(a1,n);
     cout<<" ";
     print(a2,n);
     cout<<endl;
   }
   return 0;
}
