#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<cstring>
#include <cmath>
#include<algorithm>
#include<stack>
using namespace std;

int T;
int den;
int num;
int n;
void get()
{
    if(den%2==0)
    {
        den/=2;
    }
    else
    {
        num*=2;
    }
    n++;
  //  cout<<num<<" "<<den<<endl;

}
bool solve()
{
    while(true)
    {
        get();
        if(num==den) return true;
        if(num>den)
        {
           // n++;
            num-=den;
            double den2=log(den)/log(2);
            //cout<<den2-int(den2)<<endl;
           // cout<<<<endl;
            if((den2-int(den2))!=0)
            {
              //  cout<<"ff";
                return false;
                //printf("impossible/n");
            }
            else
            {
             //   cout<<num%2<<endl;
                if(num%2==1&&num<den)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

        }
    }
}

int main()
{
 //freopen("input.txt","r",stdin);
 freopen("A-small-attempt1.in","r",stdin);
 freopen("a.out","w",stdout);

    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d/%d",&num,&den);
        n=0;
        if(solve())
        {
            printf("Case #%d: %d\n",i,n);
        }
        else
        {
            printf("Case #%d: impossible\n",i);
        }
    }
    return 0;
}
