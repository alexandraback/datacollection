#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    FILE *ptrin,*ptrout;
    ptrin=fopen("C:\\Users\\DELL\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\DELL\\Desktop\\out.txt","w");
    int t,T,i,n,tmp;
    char s[2005];
    fscanf(ptrin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(ptrin,"%s",s);
        int l=strlen(s);
        int x=0,w=0,z=0,g=0,r=0,f=0,v=0,h=0,i=0,n=0,u=0;
        for(int j=0;j<l;j++)
        {
        	if(s[j]=='X')
        	x++;
        	if(s[j]=='W')
        	w++;
        	if(s[j]=='Z')
        	z++;
        	if(s[j]=='G')
        	g++;
        	if(s[j]=='R')
        	r++;
        	if(s[j]=='F')
        	f++;
        	if(s[j]=='V')
        	v++;
        	if(s[j]=='H')
        	h++;
        	if(s[j]=='I')
        	i++;
        	if(s[j]=='N')
        	n++;
        	if(s[j]=='U')
        	u++;
        }
        int ans[10];
        ans[6]=x,ans[2]=w,ans[0]=z,ans[8]=g;
        ans[4]=u;
        ans[5]=f-ans[4];
        ans[7]=v-ans[5];
        ans[3]=h-ans[8];
        ans[9]=i-ans[8]-ans[6]-ans[5];
        ans[1]=n-2*ans[9]-ans[7];
        fprintf(ptrout,"Case #%d: ",t);
        for(int l=0;l<=9;l++)
        {
        	for(int j=1;j<=ans[l];j++)
        	fprintf(ptrout,"%d",l);
        }
        fprintf(ptrout,"\n");
    }
    fclose(ptrin);
    fclose(ptrout);
    return 0;
}
