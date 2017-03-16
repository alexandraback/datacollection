#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
unsigned long long bs(unsigned long long t,unsigned long long r,unsigned long long limit)
{
	
    unsigned long long p,mid,beg,end;
        beg=0;end=limit;
        while(beg<=end)
        {
                mid=(beg+end)/2;
                //printf("beg=%llu mid=%llu end=%llu\n",beg,mid,end);
                if(mid==beg)
                {
                        mid=end;
                        p=2*mid*mid+mid*(r+r-1);
                        if(p<=t)
                        return end;
                return beg;
                }
                p=2*mid*mid+mid*(r+r-1);
                if(p>t)
                end=mid-1;
                else
                beg=mid;
                
        }
        return 0;
}
int main()
{
	FILE *fout=fopen("outputt.txt","w");
    int k;
        unsigned long long r,t,p,cnt,c=0;
        //freopen("A-small-attempt1.in","r",stdin);
        //freopen("b.txt","w",stdout);
        scanf("%d",&k);
        while(k--)
        {
                cnt=0;c++;
                scanf("%llu%llu",&r,&t);
                /*for(unsigned long long i=1;;i++)
                {
                        
                        if(p<=t)
                        continue;
                        else 
                        {
                                cnt=i-1;
                                break;
                        }
                        
                }*/
                long long ll=1000000000000000000LL,l=1000000000,m=ll/r;
                printf("%d",c);
                fprintf(fout,"Case #%llu: %llu\n",c,bs(t,r,(m<=l?m:l)));
                
        }
}
