#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair


using namespace std;
int x,y;
int poziom;
int t;
LL size,tab[1000005];
LL stan[10005][10005];
int n;





int main()
{
  
  stan[0][0]=1;
  for(int i=0;i<=10000;i++)
  {
    
    for(int j=0;j<=10000;j++)
    {
    //  if(stan[i][j]>100000000000000000LL)
	stan[i][j]/=10;
      stan[i+1][j]+=stan[i][j];
      stan[i][j+1]+=stan[i][j];
      
    }
  }
  
 
  
  
  scanf("%d",&t);
  for(int z=1;z<=t;z++)
  {
    printf("Case #%d: ",z);
    
    scanf("%d%d%d",&n,&x,&y);
    if(x<0)x=-x;
    if(x+y%2==1){printf("0.0\n");continue;}
    
    else
    {
      poziom=(x+y)/2+1;
      int cos=1;
      
      for(int i=1;i<poziom;i++)
      {
	n-=(2*cos-1);
	cos+=2;
      }
      if(n<0){printf("0.0\n");continue;}
      if(n>=cos+cos-1)
      {
	printf("1.0\n");
	continue;
      }
      
      if(x==0)
      {
	if(n==cos+cos-1)
	  printf("1.0\n");
	else printf("0.0\n");
	continue;
      }
      
      
      
      
     
      //wrzucaj(0,0,n,poziom,y+1);
      //printf("%lf\n",double(ile)/double(suma));
      int lewo=min(n,poziom);
      int prawo=n-lewo;
      int wys=y+1;
      LL suma=0;
      LL ile=0;
      while(prawo<=poziom)
      {
	//cout<<lewo<<" "<<prawo<<endl;
	//break;
	suma+=stan[lewo][prawo];
	if(prawo>=wys)
	  ile+=stan[lewo][prawo];
	prawo++;
	lewo--;
      }
      
      
      printf("%lf\n",double(ile)/double(suma));
      
      
      
      
    }
    
    
  }
  
  

  return 0;
}