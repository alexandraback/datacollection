#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define M(x,y) memset(x,y,sizeof(x))
using namespace std;
//bool cmp(int * a,int *b,int l)
//{
//    int i=0;
//    cout << "cmp " ;
//    for(i=l-1; i>=0; i--) cout << a[i];
//    cout << ' ' ;
//    for(i=l-1; i>=0; i--) cout << b[i] ;
//    cout << endl;
//    for(i=l-1; i>=0; i--)
//    {
//        if(a[i]==b[i]) continue;
//        return a[i]<b[i];
//    }
//}
//int cal[3000000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a,b;
//    int sa[10];
//    int sb[10];
    int s[30];
    int cas;
    scanf("%d",&cas);
    int ci;
    int i,j,k;
    int ans;
    int l;
    int x,t,w;
    int ta,tb;
    int temp[10];
    int ti;
    for(ci=1; ci<=cas; ci++)
    {
//        M(cal,0);
        ans=0;
        l=0;
        scanf("%d%d",&a,&b);
        ta=a;
        tb=b;
        x=1;
        while(a)
        {
//            sa[l++]=a%10;
            l++;
            a/=10;
            x*=10;
        }
//        l=0;
//        while(b)
//        {
//            sb[l++]=b%10;
//            b/=10;
//        }
        ans=0;
//        cout << x << endl;
        if(l>1)
        {
            for(i=ta; i<tb; i++)
            {
//                cout << "i" << i << endl;
                j=i;
                t=0;
                while(j)
                {
                    s[t++]=j%10;
                    j/=10;
                }
                t=i;
                ti=0;
                for(j=l-1; j>0; j--)
                {
                    t=t*10%x+s[j];
//                    cout << "t" << t << endl;
                    if(t>i && t<=tb)
                    {
                        for(k=0; k<ti; k++)
                        {
                            if(temp[k]==t)break;
                        }
                        if(k==ti)
                        {
//                            cout << t << endl;
                            temp[ti++]=t;
                            ans++;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ci,ans);
    }
    return 0;
}
