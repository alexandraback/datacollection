#include<stdio.h>
#include<math.h>
int n,ans=0,count,max=0,k,l,s;
char temp[1000],a[1000],b[1000];
void recur(int i)
{
	int j,s1,count=0;
	if(i==s)
	{
	//	for(j=0;j<s;j++)
	//	printf("%s\n",temp);
		for(s1=0;s1<=s-l;s1++)
		{
			for(j=0;j<l;j++)
			{
				if(b[j]!=temp[j+s1])
				break;
			}
			if(j==l)
			{
				count++;
			}
		}
		if(count>max)
		max=count;
		ans+=count;
		n++;
	}
	else
	{
		for(j=0;j<k;j++)
		{
			temp[i]=a[j];
			recur(i+1);
		}
	}
}
int main()
{
    //char a[1000],b[1000];
    int c[1000]={0},t,x,i,co=1,p;
    double ans1;
    FILE *fp,*fo;
    fp=fopen("B-small-attempt0.in","r");
    fo=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    while(t--)
    {
    	ans=0;
    	n=0;
    	max=0;
        fscanf(fp,"%d%d%d",&k,&l,&s);
        fscanf(fp,"%s",&a);
        fscanf(fp,"%s",&b);
        for(i=0;i<200;i++)
        c[i]=0;
        for(i=0;i<k;i++)
        {
        	c[a[i]]++;
        	//printf("%d ",a[i]);
        }
        x=c[b[0]];
        //printf("x %d ",x);
        for(i=1;i<l;i++)
        {
            x=x*c[b[i]];
            //printf("%d ",b[i]);
        }
        //printf("x %d\n",x);
        //max=s-l+1;
        if(x==0 || max<0)
        {
            fprintf(fo,"Case #%d: %lf\n",co++,0);
            continue;
        }
        p=pow(k,s);
        recur(0);
        //printf("%d %d %d %d\n",max,ans,p,n);
        ans1=(double)max-(double)ans/n;
        /*ans=(double)x/p;
        ans=max-ans;*/
        fprintf(fo,"Case #%d: %lf\n",co++,ans1);



    }
    return 0;
}
