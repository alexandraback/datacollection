#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

string s="";

void work (int i,int x,int y) {
    if (i==0) return;
    int a=abs(x),b=abs(y);
    int p = i*(i-1)/2;
    if (i%2==0) {
        if (abs(x+i)+b<=p && (abs(x+i)+b)%2==(i/2)%2) s+='W',work(i-1,x+i,y);
        else if (abs(x-i)+b<=p && (abs(x-i)+b)%2==(i/2)%2) s+='E',work(i-1,x-i,y);
        else if (abs(y+i)+a<=p && (abs(y+i)+a)%2==(i/2)%2) s+='S',work(i-1,x,y+i);
        else s+='N',work(i-1,x,y-i);
    }
    else {
        if (abs(x+i)+b<=p && (abs(x+i)+b)%2==(i/2)%2) s+='W',work(i-1,x+i,y);
        else if (abs(x-i)+b<=p && (abs(x-i)+b)%2==(i/2)%2) s+='E',work(i-1,x-i,y);
        else if (abs(y+i)+a<=p && (abs(y+i)+a)%2==(i/2)%2) s+='S',work(i-1,x,y+i);
        else s+='N',work(i-1,x,y-i);
    }
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    int X,Y;
    s="";
    scanf("%d %d",&X,&Y);
    int l=1,r=2000;
    while (l<r) {
        int m=(l+r)/2;
        int val = m*(m+1)/2;
        if (val<abs(X)+abs(Y)) l=m+1;
        else r=m;
    }
    while ((l+1)/2%2!=(abs(X)+abs(Y))%2) ++l;
    work(l,X,Y);
    printf("Case #%d: ",z);
    for (int i=s.size()-1;i>=0;--i) printf("%c",s[i]);
    printf("\n");
    }
    return 0;
}
