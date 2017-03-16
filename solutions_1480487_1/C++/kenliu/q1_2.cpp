#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI 3.141592653589793
#define DEBUG 0
#define INF 1000000007 

using namespace std;

int n,cases=1,sum,len;
vector<int>vc;
double bin(double a,double b,int w){
    int i,j=0,tot=0;
    double d=(a+b)/2, c=vc[w]+sum*d,e=(1-d)*sum,f;
    if(DEBUG)printf("w c e %d %f %f\n",w,c,e);
    for(i=0;i<len;i++)
        if(i!=w&&vc[i]<=c){j++;tot+=vc[i];}
    if(j==0)return bin(d,b,w);
    f=e+tot;
    if(fabs(f/j-c)<pow(10,-7))return d;
    else
        if(f/j>c)return bin(d,b,w);
        else return bin(a,d,w);
}
void getNum(){
    int i,tmp;
    len=vc.size();
    double a;
    sum=0;
    for(i=0;i<len;i++)sum+=vc[i];
    vector<double>res;
    for(i=0;i<len;i++){
        tmp = (2*sum-(len)*vc[i]);
        if(tmp>0){ 
            a = bin(0,1,i)*100;
            if(DEBUG)printf("i %d a %f\n",i,a);
            res.push_back(a);
        }
        else res.push_back(0);
    }
    printf("Case #%d: ",cases);
    for(i=0;i<len-1;i++)
        printf("%.8f ",res[i]);
    printf("%.8f\n",res[i]);
}
int main(){
    int i,j,a,b,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        for(j=0;j<a;j++){
            scanf("%d",&b);
            vc.push_back(b);
        }
        getNum();
        sum=0,cases++,vc.clear();
    }
            
    return 0;
}
