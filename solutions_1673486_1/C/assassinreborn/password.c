#include<stdio.h>


int main()
{
FILE *in;
FILE *out;
in=fopen("input.in","r");
out=fopen("output.in","w");
int curcase=0,cases,a,b,i=0,j=0,k=0,l=0,m=0;
fscanf(in,"%d",&cases);
for(;curcase<cases;curcase++)
{
fscanf(in,"%d %d\n",&a,&b);
double probs[100000],probs1[100000],exps,temp,temp2,temp3,temp4;
for(i=0;i<a;i++)
{
fscanf(in,"%lf",&probs[i]);
}
probs1[0]=(1-probs[0]);
for(i=1;i<a;i++)
{
probs1[i]=1-probs[i];
//if(probs1[a-i]==0)probs1[(a-1)-i]=0;else probs1[(a-1)-i]=(probs1[(a)-i]*probs[(a)-i]*(1-probs[(a-1)-i]))/(1-probs[(a)-i]);

for(j=0;j<i;j++){probs1[i]*=probs[j];}
//printf("%lf\t",probs1[i]);
}
//if(probs[0]==1)temp2=1;
//else temp2=(probs1[0]*probs[0])/(1-probs[0]);
temp2=1;
for(j=0;j<a;j++){temp2*=probs[j];}
exps=(b+1-a)+(1-temp2)*(b+1);
temp=b+2;
if(exps>temp)exps=temp;
for(j=0;j<a;j++)
{
temp4=temp2;
for(k=(a-1);k>=(a-(1+j));k--)temp4=temp4+probs1[k];
temp3=(2*(j+1)+1+b-a)+(1-temp4)*(b+1);
if(exps>temp3)exps=temp3;
//printf("%lf\n",temp3);

}

fprintf(out,"Case #%d: %lf\n",curcase+1,exps);

}



fclose(in);
fclose(out);

return 0;

}
