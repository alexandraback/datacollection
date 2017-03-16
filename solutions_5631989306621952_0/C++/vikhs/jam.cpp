#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *in,*out;
    in=fopen("C:\\Users\\VED\\Desktop\\in.txt","r");
    out=fopen("C:\\Users\\VED\\Desktop\\out.txt","w");
    int t;
    fscanf(in,"%d",&t);
    for(int j=1;j<=t;j++)
    {
        char s[105],d[105];
     fscanf(in,"%s",s);
        int l=strlen(s);
        string p;
        p=s[0];
        for(int i=1;i<l;i++)
        {
            if(s[i]>=p[0])
                p=s[i]+p;
            else
                p+=s[i];
        }
        for(int i=0;i<l;i++)
           d[i]=p[i];
           d[l]='\0';
           fprintf(out,"Case #%d: %s\n",j,d);
    }
    fclose(out);
    fclose(in);
}
