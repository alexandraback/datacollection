#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B_output_small.txt","w",stdout);
    int T;
    int X,Y;
    scanf("%d",&T);
    char dir;
    string res;
    int A,counter,sum;
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d%d",&X,&Y);
        res="";
        counter=0;
        if (X!=0)
        {
            if (X>0)
            {
                dir='E';
            }else if (X<0){
                dir='W';
            }
            A=abs(X);
            sum=0;
            while (sum<A)
            {
                counter++;
                sum+=counter;
                res+=dir;
            }
            int B=sum-A;
            if (B>0)
            {
                if (X>0)
                {
                    for (int i=0;i<B;i++)
                    {
                        res+="EW";
                        counter+=2;
                    }
                }else{
                    for (int i=0;i<B;i++)
                    {
                        res+="WE";
                        counter+=2;
                    }
                }
            }
        }
        if (Y!=0)
        {
            if (Y>0)
            {
                dir='N';
            }else if (Y<0){
                dir='S';
            }
            A=abs(Y);
            sum=0;
            while (sum<A)
            {
                counter++;
                //printf("sum=%d counter=%d\n",sum,counter);
                sum+=counter;
                res+=dir;
            }
            int B=sum-A;
            if (B>0)
            {
                if (Y>0)
                {
                    for (int i=0;i<B;i++)
                    {
                        res+="NS";
                    }
                }else{
                    for (int i=0;i<B;i++)
                    {
                        res+="SN";
                    }
                }
            }
        }
        printf("Case #%d: %s\n",cases,res.c_str());
    }
    return 0;
}
