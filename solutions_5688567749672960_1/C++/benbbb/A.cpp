#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    long long N;
    cin>>T;
    int ca;
    int ee[16];
    ee[0]=1;
    for (int i=1;i<=15;i++) ee[i]=ee[i-1]*10;
    int ww[16];
    ww[0]=0;
    for (int i=1;i<=15;i++) ww[i]=ee[i/2]+ee[(i+1)/2]-1;
    for (ca=1;ca<=T;ca++)
    {

       cin>>N;
       int ff;
       long long t;
       t=N;
       ff=0;
       if (N%10==0) {ff=1;t--;}
       int ll;
       ll=0;

       while (t>0) {ll++;t=t/10;}
       t=N-ff;
       long long cnt;
       cnt=0;
       for (int i=1;i<=ll;i++) cnt+=ww[i-1];
       //cout<<cnt<<' '<<ll<<endl;

       int xx,yy,kk;
       xx=t/ee[(ll+1)/2];
      kk=0;
      while (xx>0) {kk*=10;kk+=xx%10;xx/=10;}

      if (kk>1)
      cnt+=kk+1;

       yy=t%ee[(ll+1)/2];
       if (kk<=1) cnt+=yy;
       else cnt+=yy-1;


      //cout<<kk<<yy<<endl;

        if (ff) cnt++;

        printf("Case #%d: %d\n",ca,cnt);
       //cout<<cnt<<endl;

    }

}
