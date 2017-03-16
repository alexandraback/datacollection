#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
int T,t;
long long num[39]=
{
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004
};
bool checkhw(long long a)
{
    int t[20];
    int f=0;
    while(a!=0)
    {
        t[f]=a%10;
        a/=10;
        f++;
    }
    int i;
    int w=f/2;
    for(i=0;i<w;i++)
    {
        if(t[i]!=t[f-1-i])
            return false;
    }
    return true;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("C-large-1.in","r");
    fout=fopen("out.txt","w");
    fscanf(fin,"%d",&T);
    int i,j;
    long long A,B;
    for(t=1;t<=T;t++)
    {
        fscanf(fin,"%lld%lld",&A,&B);
        int c=0;
        for(i=0;i<39;i++)
        {
            if(num[i]>=A&&num[i]<=B)
                c++;
        }


        fprintf(fout,"Case #%d: %d\n",t,c);
    }
/*
    long long s;
    for(s=1;s<=10000000;s++)
    {
        long long ss=s*s;
        if(checkhw(s))
        {
            if(checkhw(ss))
                fprintf(fout,"%lld\n",ss);
        }

    }
    printf("Success!!!\n");
*/
    fclose(fin);
    fclose(fout);
    return 0;
}
