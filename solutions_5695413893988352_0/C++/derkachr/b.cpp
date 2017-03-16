#include<bits/stdc++.h>
#define pb push_back
 using namespace std;

 int rz,mn,A,B,ans_A,ans_B,t,t_,n,m,i,k;
 string a,b;

 void ttt(int pos)
 {
    if(pos == m)
    {
        rz  = abs(A - B);
        if(rz < mn || rz == mn && ans_A>A || rz == mn && ans_A==A && ans_B>B)
        {
            mn = rz;
            ans_A=A;
            ans_B=B;
        }
        return;
    }
    if(b[pos]=='?')
    {
        for(int i=0;i<=9;++i)
        {
            B*=10;
            B+=i;
            ttt(pos+1);
            B-=i;
            B/=10;
        }
    } else
    {
        B*=10;
        B+=(b[pos]-'0');
        ttt(pos+1);
        B-=(b[pos]-'0');
        B/=10;
    }
 }

 void tt(int pos)
 {
    if(pos == n){
    ttt(0);
    return;
    }
    if(a[pos]=='?')
    {
        for(int i=0;i<=9;++i)
        {
            A*=10;
            A+=i;
            tt(pos+1);
            A-=i;
            A/=10;
        }
    } else
    {
        A*=10;
        A+=(a[pos]-'0');
        tt(pos+1);
        A-=(a[pos]-'0');
        A/=10;
    }
 }

  int main()
  {

//     freopen("output.txt","w",stdout);

    cin>>t;
     for(t_=1;t_<=t;++t_)
     {
       cin>>a>>b;
       n = (int)a.size();
       m = (int)b.size();
       mn = 100000;
       ans_A=1000000;
       ans_B=1000000;
        tt(0);
        cout<<"Case #"<<t_<<": ";
        k = ans_A;
         while(1)
         {
             --n;
             k/=10;
             if(k==0) break;
         }

         for(i=0;i<n;++i) cout<<'0';

        cout<<ans_A<<' ';

        k = ans_B;
         while(1)
         {
             --m;
             k/=10;
             if(k==0) break;
         }

         for(i=0;i<m;++i) cout<<'0';

        cout<<ans_B<<endl;
     }

  }
