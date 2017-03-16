#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;
int T,n,s[1000],sum;
bool check(double p,int idx)
{
    double temp=s[idx]+p*sum,ct=0.0;
    
    //cout<<sum<<endl;
    for(int i=0;i<n;i++) {
        if(i!=idx) {
            if(s[i]<temp) ct+=(temp-s[i]);
        }
    }
  //  cout<<ct+p*sum<<" "<<sum<<endl;
    if(ct+p*sum>=sum) return true;
    return false;
}
double bs(double left,double right,int idx)
{
    if(right-left<0.000000005) return left;
    double mid=(left+right)/2;
    if(check(mid,idx)) return bs(left,mid-0.000000001,idx);
    return bs(mid+0.000000001,right,idx);
}
    
int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    
    int i,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        scanf("%d",&n);
        sum=0;
        for(j=0;j<n;j++) {
            scanf("%d",&s[j]);
            sum+=s[j];
        }
      //  if(check(0.5,0)) cout<<"hello"<<endl;
        printf("Case #%d:",i);
        
        for(j=0;j<n;j++) {
            double ans=bs(0,1.0,j);
           // double ans=(2.0*sum/n-s[j])/sum;
            //if(ans<0) printf(" %lf",0);
            //else 
            printf(" %lf",100*ans);
        }
        printf("\n");
    }
    
    return 0;
}
