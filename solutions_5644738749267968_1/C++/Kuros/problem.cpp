#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <fstream>
using namespace std;
#define mo 1000000007ll
#define eps 1e-8
#define inf 2147480000
ifstream in("D-large.in");
ofstream out("ans.txt");
int n,t;
double box[1001];
double aox[1001];
bool cox[1001];
int sgn(double a,double b)
{
    if(fabs(a-b)<eps) return 0;
    else if(a-b>eps) return 1;
    else return -1;
}
int main()
{
    in>>t;
    int cac=0;
    while(t--)
    {
       cac++;
       in>>n;
       for(int i=1;i<=n;i++)    in>>aox[i];
       for(int i=1;i<=n;i++)    in>>box[i];
       sort(aox+1,aox+1+n);
       sort(box+1,box+1+n);
       memset(cox,0,sizeof(cox));
       int start=1;
       int end=n;
       int sum=0;
       for(int i=1;i<=n;i++)
       {
            if(sgn(aox[i],box[start])==1)
            {
                sum++;
                start++;
            }
            else
                end--;
       }
       int su=0;
       for(int i=1;i<=n;i++)
       {
            bool con=0;
            for(int j=1;j<=n;j++)
            {
                if(!cox[j])
                {
                    if(sgn(box[j],aox[i])==1)
                    {
                        con=1;break;
                    }
                }
            }
            if(!con)
            {
                for(int j=1;j<=n;j++)
                {
                    if(!cox[j])
                    {
                        cox[j]=1;
                        su++;
                        break;
                    }
                }
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    if(!cox[j] && sgn(box[j],aox[i])==1)
                    {
                        cox[j]=1;
                        break;
                    }
                }
            }
       }
       out<<"Case #"<<cac<<": ";
       out<<sum<<" "<<su<<endl;
    }
    return 0;
}
