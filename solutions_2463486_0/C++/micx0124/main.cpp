#include <iostream>
#include <math.h>

using namespace std;
int a[1002];
bool check(int i){
    int k=sqrt(i*1.0),j=i/100,l=i%10;
    if(k*k != i )return false;
    if(i<10)return true;
    if(i<100)return false;

    if( j == l &&k/10==k%10)return true;
    return false;
}
int main()
{
//    freopen("C-small-attempt0.in","r",stdin);
//    freopen("C-small-attempt0.out","w",stdout);
    int c,t,i,j,k,A,B,ans;
    a[0]=0;
    for(i=1;i<1001;i++){
        if(check(i))
        {
            a[i]=a[i-1]+1;
//            cout<<i<<"  ";
        }
        else a[i]=a[i-1];

    }

    for(i=0;i<1001;i++){

    }

    cin>>t;
    for(c=1;c<=t;c++){
        cin>>A>>B;


     printf("Case #%d: ",c);
     printf("%d\n",a[B]-a[A-1]);

    }
    return 0;
}
