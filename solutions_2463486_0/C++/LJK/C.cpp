#include<iostream>
#include<algorithm>
using namespace std;

int tab[1001];


long long res[1000001];


int main()
{
    int z;
    cin >> z;
    
    long long M=(long long)10000000*10000000;
    int I=0;
    //cout << M << endl;
    
    for(long long i=1; i*i<=M; i++)
    {
             //cout << i << endl;
             
             long long temp=i;
             int it=0;
             
             while(temp)
             {
                        tab[it++]=temp%10;
                        temp/=10;
             }
             
             int a=0;
             int b=it-1;
             
             bool flag=true;
             
             while(a<b)
             {
                       if(tab[a]!=tab[b])
                       {
                                         flag=false;
                                         break;
                       }
                       a++;
                       b--;
             }
             
             if(!flag)
              continue;
             
             
             
             
             temp=i*i;
             it=0;
             
             while(temp)
             {
                        tab[it++]=temp%10;
                        temp/=10;
             }
             
             a=0;
             b=it-1;
             
             while(a<b)
             {
                       if(tab[a]!=tab[b])
                       {
                                         flag=false;
                                         break;
                       }
                       a++;
                       b--;
             }
             
             if(flag)
                     res[I++]=i*i;
             
            
    }
    
    //cout << I << endl;
    
    for(int x=1; x<=z; x++)
    {
            long long a;
            cin >> a;
            long long b;
            cin >> b;
            
            int i=0;
            while(res[i]<a)
            i++;
            
            int j=I-1;
            while(res[j]>b)
            j--;
            
            cout <<"Case #" << x << ": " << j-i+1 << endl;
    }
return 0;
}
