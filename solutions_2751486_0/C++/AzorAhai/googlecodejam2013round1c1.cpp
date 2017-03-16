#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

/*long long int input()
{
long long int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}*/
string s1;
int calculate(string s1, int n)
{
    int i,length = s1.length(),a[length];
    int count=0,sum=0,j,max=0;
    for(i=0;i<length;i++)
    {
        if(s1[i]!='a' && s1[i]!= 'e' && s1[i] !='i' && s1[i]!='o' && s1[i]!='u')
        {
            a[i] = 1;
        }
        else
        {
            a[i]  = 0;
        }
    }
    for(i=0;i<length;i++)
    {
        max = count = 0;
        for(j=i;j<length;j++)
        {
            if(a[j] == 1)
            count++;
            else
            count =0;
            if(count>max)
            max = count;
            if(max>=n)
            sum++;
        }
    }
    return sum;
}
int main(){
   //freopen("input224.txt","r",stdin);
   //freopen("b1.txt","w",stdout);
int t,n,i,j,a,k,l,m,p,ans;
scanf("%d",&t);
for(i=1;i<=t;++i){
    cin>>s1;
    cin>>n;
   ans=calculate(s1,n);

printf("Case #%d: %d\n",i,ans);
}
return 0;
}
