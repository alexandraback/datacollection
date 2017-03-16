#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int t;
int r,n,m,k;
bool dp[5];
vector <int> a[127];

void cari()
{
     for (int i=2; i<=m; i++)
     {
         a[i].push_back(i);
         for (int j=2; j<=m; j++)
         {
             a[i*j].push_back(i);
             a[i*j].push_back(j);
                 
             for (int w=2; w<=m; w++)
             {
                 a[i*j*w].push_back(i);
                 a[i*j*w].push_back(j);
                 a[i*j*w].push_back(w);
             }
         }
     }
}

int main ()
{

    scanf("%d",&t);
    
    printf("Case #1:\n");
    
    scanf("%d%d%d%d",&r,&n,&m,&k);
    
    cari();
    for (int z=0; z<r; z++)
    {
        memset(dp,false,sizeof(dp));
        
        int p;
        int pk=0;
        
        vector <int> g;
        for (int i=0; i<k; i++)
        {
            scanf("%d",&p);
            g.push_back(p);
            
        }
        
        sort(g.begin(),g.end());
        
        vector<int> hasil;
        for (int i=k-1; i>=0; i--)
        {
            for (int j=0; j<a[g[i]].size(); j++)
            {
                hasil.push_back(a[g[i]][j]);
            }
            
            if (hasil.size() >n) break;
        }
        
        int w=2;
        
        if (hasil.size()<n)
        {
           for (int i=0; i<hasil.size(); i++) {
            printf("%d",hasil[i]);
//            if (i<n-1) printf(" ");
           }
           
           for (int i=0; i<n-hasil.size(); i++)
           {
               printf("%d",2);
//               if (i<n-hasil.size()) printf(" ");
           }   
           
        }
        else
        for (int i=0; i<n; i++)
        {
            printf("%d",hasil[i]);
//            if (i<hasil.size()) printf(" ");
        }
        
        
        printf("\n");
        
    }
    
    return 0;
}
