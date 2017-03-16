#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
FILE *fin = fopen("input.in","r");
FILE *fout = fopen("output.out","w");
using namespace std;
void pro()
{
    char name[1000001],n;
    int sum=0,len;
    fscanf(fin,"%s",&name);
    fscanf(fin,"%d",&n);
    len=strlen(name);
    int cnt=0;
    int check[len];
    check[0]=0;
    for(int i=0;i<len;i++)
    {
        if(i!=0)
            check[i]=check[i-1];
        if(name[i]!='a'&&name[i]!='e'&&name[i]!='i'&&name[i]!='o'&&name[i]!='u')
        {
            cnt++;
        }
        else
            cnt=0;
        if(cnt==n)
        {
            check[i]=1+i-n+1;
            cnt--;
        }
    }
    for(int i=0;i<len;i++)
        sum+=check[i];
    fprintf(fout,"%d\n",sum);
}
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fprintf(fout,"Case #%d: ",i+1);
        pro();
    }
    return 0;
}
