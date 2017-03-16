#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
char s[11000];

struct P{
    char c;
    int f;

    P(char a='1',int ff=1):c(a),f(ff){}

    P mult(P a){

      P b;
      b.f= f*a.f;
      if(c=='1') b.c=a.c;
      else if(c== a.c){
        b.c='1';
        b.f = b.f*(-1);
      }
      else if(a.c=='1') b.c=c;
      else if(c== 'i'){
        if(a.c=='j') b.c='k';
        else if(a.c=='k') b.c='j', b.f = b.f*(-1);
      }
      else if(c== 'j'){
        if(a.c=='k') b.c='i';
        else if(a.c=='i') b.c='k', b.f = b.f*(-1);
      }
       else if(c== 'k'){
        if(a.c=='i') b.c='j';
        else if(a.c=='j') b.c='i', b.f = b.f*(-1);
      }

      return b;
    }

    P exp(LL k)
    {
        P temp;
        temp.c=c;
        temp.f=f;

        P ret; ret.c='1';ret.f=1;

        while(k)
        {
            if(k&1) ret = ret.mult(temp);
            temp=temp.mult(temp);
            k=k>>1;
        }
        return ret;
    }

    bool operator ==(const P& a)const{
         return c==a.c && f==a.f;
    }
   void print()
   {
       printf("%c %d\n",c,f);
   }
};

P p[11000],q[11000];


int main()
{
    freopen("C-large.in","r",stdin);
    freopen("c.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n;
        LL m;
        scanf("%d%lld",&n,&m);
        gets(s);
        gets(s);
       // puts(s);

        p[0].c=s[0];
        p[0].f=1;
        q[n-1].c=s[n-1];
        q[n-1].f=1;
        for(int i=1;i<n;i++)
        {
            P b;
            b.c=s[i];b.f=1;
            p[i] = p[i-1].mult(b);
        }

        for(int i=n-2;i>=0;i--)
           {
            P b;
            b.c=s[i];b.f=1;
            q[i] = b.mult(q[i+1]);
        }

        if(n*m < 3){

            printf("Case #%d: NO\n",ca);
            continue;
        }

        P ret = p[n-1].exp(m);


        if(ret.f!=-1 || ret.c!='1') {
              printf("Case #%d: NO\n",ca);
              continue;
        }

        int x1= -1;

        for(int j=0;j<4 && x1==-1;j++)
        {
            P b= p[n-1].exp(j);
            for(int i=0;i<n && x1==-1;i++)
            {
               P a= b.mult(p[i]);
                if(a==P('i',1))
                      x1=j*n+i;
            }
        }


       int x2=-1;

        for(int j=0;j<4 && x2==-1;j++)
        {
            P b= q[0].exp(j);
            for(int i=n-1;i>=0 && x2==-1;i--)
            {
               P a= q[i].mult(b);

                if(a==P('k',1))
                      x2=j*n+(n-1-i);
            }
        }

//        printf("%d %d ----\n",x1,x2);

        if(x1!= -1  && x2!= -1 && (x1+x2+2)<= n*m )
        {
             printf("Case #%d: YES\n",ca);
        }
        else
                printf("Case #%d: NO\n",ca);




    }
    return 0;
}
