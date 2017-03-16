#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
char mul(char x,char y)
{
    if(x=='i'&&y=='i')return 'b';
    if(x=='i'&&y=='j')return 'k';
    if(x=='i'&&y=='k')return 'y';

    if(x=='j'&&y=='i')return 'z';
    if(x=='j'&&y=='j')return 'b';
    if(x=='j'&&y=='k')return 'i';

    if(x=='k'&&y=='i')return 'j';
    if(x=='k'&&y=='j')return 'x';
    if(x=='k'&&y=='k')return 'b';

    if(x=='x'&&y=='i')return 'a';
    if(x=='x'&&y=='j')return 'z';
    if(x=='x'&&y=='k')return 'j';

    if(x=='y'&&y=='i')return 'k';
    if(x=='y'&&y=='j')return 'a';
    if(x=='y'&&y=='k')return 'x';

    if(x=='z'&&y=='i')return 'y';
    if(x=='z'&&y=='j')return 'i';
    if(x=='z'&&y=='k')return 'a';

    if(x=='a'&&y=='i')return 'i';
    if(x=='a'&&y=='j')return 'j';
    if(x=='a'&&y=='k')return 'k';

    if(x=='b'&&y=='i')return 'x';
    if(x=='b'&&y=='j')return 'y';
    if(x=='b'&&y=='k')return 'z';
}
int main()
{
    FILE* f;
    FILE* fo;
    f=fopen("A.txt","r");
    fo=fopen("AO.txt","w");
    int n;
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        int len;
        long long int sn;
        fscanf(f,"%d%lld",&len,&sn);
        char a1[10001];
        string a;
        fscanf(f,"%s",a1);
        a=a1;
        a+=a;
        a+=a;
        if(len*sn<3)
        {
            fprintf(fo,"Case #%d: NO\n",i+1);
            continue;
        }
        char first,sum=a[0];
        int c1=0,c2=0,c3;
        if(sn>=4)c3=4;
        else c3=sn;
        for(int j=1;j<len*c3;j++)
        {
            if(sum=='i')c1=1;
            if(c1==1&&sum=='k')c2=1;

            sum=mul(sum,a[j]);
            //cout<<sum<<' ';
            if(sum=='i')c1=1;
            if(c1==1&&sum=='k')c2=1;
            if(j==len-1)
            {
                first=sum;
            }


        }
       // cout<<endl;
        sn=sn%4;
       // cout<<sn<<endl;
        if(c1==1&&c2==1){
            if(sn==0)fprintf(fo,"Case #%d: NO\n",i+1);
            if(sn==1&&first=='b')fprintf(fo,"Case #%d: YES\n",i+1);
            else if(sn==1) fprintf(fo,"Case #%d: NO\n",i+1);
            if(sn==2&&(first=='i'||first=='j'||first=='k'
                       ||first=='x'||first=='y'||first=='z'))fprintf(fo,"Case #%d: YES\n",i+1);
            else if(sn==2)fprintf(fo,"Case #%d: NO\n",i+1);
            if(sn==3)fprintf(fo,"Case #%d: NO\n",i+1);
        }
        else fprintf(fo,"Case #%d: NO\n",i+1);

    }
    return 0;
}
//ik-1
