#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std ;

bool isinlc(int lc, int x, int y)
{
    if(y+1<=lc)
    {
        int st = y-lc+1 ;
        if(st<=x&&x<=st+2*(lc-y-1))
        {
            return true ;
        }
    }
    
    return false ;
}

double dpt[2000][4000]; //dropped, has dropped

int main(void)
{
    int tc, cas ;

    scanf("%d",&tc) ;
    for(cas=1;cas<=tc;cas++)
    {
        int n, x, y ;
        
        scanf("%d%d%d",&n,&x,&y) ;
        
        int lc ;
        
        for(lc=1;;lc+=2)
        {
            if((lc+1)*lc/2>n)
            {
                lc -= 2 ;
                break ;
            }
        }
        
        //check if xy is in lc constructed
        if(isinlc(lc,x,y)==true)
        {
            printf("Case #%d: 1.0\n",cas) ;
        }
        else
        {
            //check if xy is in next level to construct
            if(isinlc(lc+2,x,y)==false)
            {
                printf("Case #%d: 0.0\n",cas) ;
            }
            else
            {
                if(x==0||n-(lc+1)*lc/2==0)
                {
                    printf("Case #%d: 0.0\n",cas) ;
                }
                else
                {
                    int tof = n-(lc+1)*lc/2 ;
                    int full = lc+1 ;
                    int level = y+1 ;
                    int d, dp ;
                    
                    memset(dpt,0,sizeof(dpt)) ;
                    dpt[0][0] = 1 ;
                    for(dp=0;dp<tof;dp++)
                    {
                        for(d=0;d<=dp&&d<=full;d++)
                        {
                            int pos = 0 ;
                            if(dp-d<full) pos++ ;
                            if(d<full) pos++ ;

                            if(dp-d<full) dpt[d][dp+1] += dpt[d][dp]/pos ;
                            if(d<full) dpt[d+1][dp+1] += dpt[d][dp]/pos ;
                        }
                    }
                    
                    double ans = 0 ;
                    for(d=level;d<=full;d++)
                    {
                        ans += dpt[d][tof] ;
                    }
                    
                    printf("Case #%d: %.9f\n",cas,ans) ;
                }
            }
        }
    }

    return 0;
}
