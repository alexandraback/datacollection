#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[55][55];
int h,w,d,t,rrr[55555][2];

bool ok(int x,int y,int xx,int yy){
     if (d*d<(x-xx)*(x-xx)+(y-yy)*(y-yy))
        return false;
     
     
     return true;    
}


bool occu(int x,int y){
     if (rrr[x][0]*rrr[y][0]<0||rrr[x][1]*rrr[y][1]<0)
        return false;    
     if (rrr[x][0]*rrr[y][1]!=rrr[x][1]*rrr[y][0]) 
        return false;
     
     
     return true;
}

int main(){
    int i,j,k,x,y,xx,yy,ans,pp=0;
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    scanf("%d",&t);
    while (t--){
          scanf("%d%d%d",&h,&w,&d);
          for (i=0;i<h;i++)
              scanf("%s",s[i]);
          for (i=0;i<h;i++)
              for (j=0;j<w;j++)
                  if (s[i][j]=='X'){
                     x=i;y=j;break;                  
                  }
          h-=2;
          w-=2;
          ans=0;
          k=0;
          for (i=-d;i<=d;i++)
              for (j=-d;j<=d;j++)
                  if (!((i==0)&&(j==0))){
                     xx=x+(i*h);
                     if (i%2) xx+=h+1-2*x;
                     yy=y+(j*w);
                     if (j%2) yy+=w+1-2*y;
                     if (ok(x,y,xx,yy)) {
                           rrr[k][0]=xx-x;
                           rrr[k][1]=yy-y;   
                           k++;          
                     }  
                  }    
          for (i=0;i<k;i++){
              ans++;
              for (j=0;j<i;j++){        
                  if (occu(i,j)){
                     ans--;
                     break;               
                  }                  
              }
          }
          printf("Case #%d: %d\n",++pp,ans);
    }
    return 0;  
}
