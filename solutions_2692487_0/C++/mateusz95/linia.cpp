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


int t;
LL size,tab[1000005];
int n;

int main()
{
  scanf("%d",&t);
  for(int z=1;z<=t;z++)
  {
    printf("Case #%d: ",z);
    scanf("%lld%d",&size,&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%lld",&tab[i]);
           
    }
    sort(tab+1,tab+1+n);
    int wyn=1000000000;
    int ile=0;
    
    if(size==1)
    {
      printf("%d\n",n);
      continue;
    }
    for(int i=1;i<=n;i++)
    {
      wyn=min(wyn,ile+n-i+1);
      //cout<<wyn<<" ";
      while(size<=tab[i]){
	
	  
	size+=(size-1);	
	ile++;}
	size+=tab[i];
        
      
    }
        wyn=min(wyn,ile);
      
      printf("%d\n",wyn);
    
    
  }
  
  

  return 0;
}