#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;


int main()
{
    int T,cased=0,count;
    int r,c,m,blank;
    char arr[60][60];
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>T;
    while(T--)
    {

        cin>>r>>c>>m;
        blank=r*c-m;
        count=0;
        memset(arr,'s',sizeof(arr));
        printf("Case #%d:\n",++cased);
        if((r==1 or c==1 or blank==1) and blank)
        {
            for(int i=1; i<=r; i++)
            {
                for(int j=1; j<=c; j++)
                    if(i==r and j==c)cout<<"c";
                    else if(count++<m)cout<<"*";
                    else cout<<".";
                cout<<endl;


            }
            continue;

        }
        if( blank==5 or blank==7 or blank<4 or((r==2 or c==2) and blank%2==1 ))
        {
            printf("Impossible\n");
            continue;
        }
        if(blank>=4)
        {
           arr[r-1][c]=arr[r][c-1]=arr[r-1][c-1]='.';
           blank-=4;
           arr[r][c]='c';
           if(blank%2==1){arr[r-2][c-2]='.'; blank--;}
           bool pos=true;
           int i=r-2,j=c-2;
           while(blank>0 && (i>0 || j>0))
           {
               if((pos or j<=0) and i>0)
               {arr[i][c]=arr[i][c-1]='.';  i--;}
               else if(j>0){arr[r][j]=arr[r-1][j]='.'; j--;}
               blank-=2;
               pos=!pos;
           }
           for(int i=1;i<=r;i++)
           {
                for(int j=1;j<=c;j++)
                if(i==r and j==c )cout<<"c";
                else if((arr[i][j]!='.')and count++<m)cout<<"*";
                else cout<<'.';
                cout<<endl;
           }

            continue;

        }
    }

}

