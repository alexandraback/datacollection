#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#define ss(x) fscanf(in,"%d",&x)
//scanf("%d",&x) 
//
#define base 50
using namespace std;
int tot,con;
int x,y;

int fall(int a[100][100],int n)
{   int i,j;
   //cout<<"call" <<n;
    if(n<1)
    {  //for( j=30;j>-1;j--){for( i=30;i<70;i++){cout<<a[i][j];}cout<<endl;}
        //cin>>i;   
      tot++; 
      if(a[base+x][y]==1)
      {   con++;
      }
    return 0;
    }
    
    i=base; j=a[i][99]*2+(i%2);   
    if(j==0){a[i][j]=1; a[i][99]++; fall(a,n-1);a[i][99]--;a[i][j]=0;return 0;}
    if(a[i-1][j-1]==1 && a[i+1][j-1]==1)
    {a[i][j]=1;a[i][99]++; fall(a,n-1);
                a[i][j]=0;a[i][99]--;
                return 0; 
    }
    
    i=base; j=a[i][99]*2+(i%2); 
    if(a[i-1][j-1]!=1){           //left
    while(a[i-1][j-1]!=1 && j>0)  
    {    i--;j--;
    }
         a[i][j]=1;a[i][99]++;
         fall(a,n-1);
         a[i][j]=0;a[i][99]--;
    }
    
    i=base; j=a[i][99]*2+(i%2); 
    if(a[i+1][j-1]!=1){           //right
    while(a[i+1][j-1]!=1 && j>0){
                         i++;j--;
                         }
                          a[i][j]=1;a[i][99]++;
                          fall(a,n-1);a[i][j]=0;a[i][99]--;
}

}
int main()
{   int A,t,f,i,j,k,n;
    //int L[101][101];
     int pla[100][100];
    FILE *in,*out;
    
    in = fopen("in.in","r");
    out = fopen("out.out","w");
   float p;
   
   
   
   
    ss(t);
  // cin>>t;
    k=0;
    while(k<t)
   {    //cin>>x>>y>>n;
   ss(n);ss(x);ss(y);
   if(x<-50 || x>50  || y>50 ){p=0;}
   else{
   //cout<<n<<endl;//cin>>i;
   for(i=0;i<100;i++)for(j=0;j<100;j++)pla[i][j]=0; 
   tot=0;con=0;
    fall(pla,n);                    
               p=(float)con/tot;
  }             //cout<<p<<endl;
   k++;            fprintf(out,"Case #%d: %.9f\n",k,p);      
   }
   //cout<<"done";//cin>>i;
return 0;
}
