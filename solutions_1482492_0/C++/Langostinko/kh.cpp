#include <stdio.h>
#include <iostream>
using namespace std;
int n,l,i=1,j;
char a[1<<27];
int main(){
//freopen("a.in","r",stdin);
//freopen("a.out","w",stdout);
scanf("%d",&n);
a[0]=a[l=n*2-2]=49;
for(;i<n;i++){
a[i]=(a[i-1]-47)%10+48;
a[l-i]=(a[l+1-i]-47)%10+48;
n>9?a[i]==56?a[i]++:0,a[l-i]==49?a[l-i]++:0:0;
}

cout << endl;
int r[10]={1,2,3,4,5,6,7,8,9};
for (int i=0; i<n-1; i++)
    cout << (r[i%9]+(i%9>6))%10;
for (int i=n-1; i>=1; i--)
    cout << (r[i%9]-(i%9==0))%10;

cout << 1;
cout << endl;

for (int i=0; i<2*n-2; i++){
    if (i<n-1)
        cout << (r[i%9]+(i%9>6))%10;
    else{
        j = 2*n-i-2;
        cout << (r[j%9]-(j%9==0))%10;
    }
}
cout << 1;
cout << endl;

for (int i=0; i<2*n-2; i++)
    i<n-1?
        printf("%d",(r[i%9]+(i%9>6))%10):
        (j=2*n-i-2,printf("%d",(r[j%9]-(j%9==0))%10));
cout << 1;
cout << endl;

puts(a);
}
