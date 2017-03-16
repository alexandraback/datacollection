#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int fact(int n)
    {
    int pro=1,i;
    for(i=1;i<=n;i++)
        pro=pro*i;
    return pro;
}
int perm(int n,int r)
    {
    int nu=fact(n);
    int d=fact(n-r);
    return(nu/d);
}

int main() {
  int t,n,q,w,e,r,y,u,i,o,p,s,d,f,g,h,j,k,l,z,x,v,m;
    cin>>t;
    int a[10][10];
     int b[10][10];
     int c[10][10];
    int tx[10];
     int tz[10];
     int ty[10];
    for(u=0;u<t;u++)
        {
         int count=0;
        f=0;
        cin>>j>>p>>s>>k;
        
        for(i=0;i<s;i++)
            for(o=0;o<s;o++)
            {
            a[i][o]=0;
             b[i][o]=0;
             c[i][o]=0;
        }
      
        for(x=0;x<j;x++)
               for(y=x;y<p;y++)
            for(z=y;z<s;z++)
           
            {
           
            v=0;
                if(a[x][y]<k)v++;
                if(b[x][z]<k)v++;
                if(c[y][z]<k)v++;
                if(v==3)
                {
              tx[count]=x+1;
                  ty[count]=   y+1;
                    tz[count]=z+1;
                a[x][y]++;
                 b[x][z]++;
                 c[y][z]++;
                    count++;
            }
          
        }
         for(x=0;x<j;x++)
               for(y=p-1;y>=p-x;y--)
            for(z=s-1;z>=s-y;z--)
           
            {
           
            v=0;
                if(a[x][y]<k)v++;
                if(b[x][z]<k)v++;
                if(c[y][z]<k)v++;
                if(v==3)
                {
              tx[count]=x+1;
                  ty[count]=   y+1;
                    tz[count]=z+1;
                a[x][y]++;
                 b[x][z]++;
                 c[y][z]++;
                    count++;
            }
          
        }
         
        cout<<"Case #"<<u+1<<": "<<count<<endl;  
        for(w=0;w<count;w++)
           cout<<tx[w]<<" "<<ty[w]<<" "<<tz[w]<<endl;
}
   
  return 0;
}

