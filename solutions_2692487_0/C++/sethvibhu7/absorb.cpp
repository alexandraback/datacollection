#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#define ss(x) fscanf(in,"%d",&x)
//scanf("%d",&x) 
//
using namespace std;
int minn,c;

int ab(int a,int b)
{                                   //cout<<endl<<"call:"<<a<<" "<<b<<" ";
   if(a<2)
   {c= minn; return 0;}
   
    while(a<=b)
   {  a+=a-1;
      c++;
   }
                       //cout<<a+b;
   return a+b;
   
}

int main()
{   int A,t,f,i,j,k,n;
    //int L[101][101];
    vector<int> a(101),m(100);
    FILE *in,*out;
    
    in = fopen("in.in","r");
    out = fopen("out.out","w");
    
    ss(t);
    k=0;
    while(k<t)
   {                                   //     cout<<"start";cin>>i;
         ss(A);ss(n);
                for(i=0;i<n;i++)
                {ss(m[i]);}
                sort(m.begin(),m.begin()+n);
                                            //cout<<"m[0]"<<m[0];
                c=0;minn=n;
                i=0;
             while(i<n)
             {   A=ab(A,m[i]);
                if(A==0) break;
                 i++;
                 minn=min(minn,c+n-i);
                 if(minn<c)
                 break;
             }            
        minn=min(minn,c);
   k++;   //    cout<< "Case #%d: %d\n" <<k<<minn;
   
   fprintf(out,"Case #%d: %d\n",k,minn); 
   }
    
    //cin>>n; 
return 0;}
