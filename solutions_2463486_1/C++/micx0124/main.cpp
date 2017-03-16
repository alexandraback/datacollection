#include <iostream>
#include <math.h>

using namespace std;
long long a[10020];
bool pal(long long x){
 char c[20];
 int i=0,len;
 while(x){
     c[i++]=x%10;
     x/=10;
 }
 len=i;
 for(i=0;i<len/2;i++){
    if(c[i]!=c[len-i-1])return false;
 }
 return true;
}
bool check(int i){
    if(pal((long long)i)&&pal((long long)i*i))
    {
//        cout<<i<<"  "<<(long long)i*i<<endl;
        return true;
        }
    return false;
}

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    int c,t,i,j=1,k,ans,len=0;
    long long A,B;
    a[0]=0;
//    a[0]=0;
    for(i=1;i<10000002;i++){
        if(check(i))
        {
            a[j++] = (long long)i*i;
//            cout<<a[j-1]<<"  ";
        }

    }len=j-1;
//    cout<<len<<endl;

    cin>>t;
    for(c=1;c<=t;c++){
        cin>>A>>B;
//        cout<<A<<B;
        i=0;
        while(a[i]<A)i++;
        j=len;
        while(a[j]>B)j--;
//        cout<<i<<"  "<<j<<endl;
//     Binary_find(A);
     printf("Case #%d: ",c);
     printf("%d\n",j-i+1);

    }
    return 0;
}
