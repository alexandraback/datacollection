#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int tno=1;
    int t,done,todo;
    cin>>t;
    while(t--)
    {
		double ans=1e12;
        cin>>done>>todo;
        double probability[done],prob_product[done];
		cin>>probability[0];
		prob_product[0]=probability[0];
        for(int x=1;x<done;x++)
        {
            cin>>probability[x];
            prob_product[x]=prob_product[x-1]*probability[x];
        }
		ans=min(ans,prob_product[done-1]*(todo-done+1)+(1-prob_product[done-1])*(todo-done+1+todo+1));
        ans=min(ans,(double)done+todo+1);
        ans=min(ans,(double)1+todo+1);
        for(int x=1;x<done;x++)
        {
            ans=min(ans,prob_product[done-x-1]*(x+(todo-done+x)+1)+(1-prob_product[done-x-1])*(x+(todo-done+x)+1+todo+1));
        }
        printf("Case #%d: %.6f\n",tno,ans);
		tno++;
    }
    return 0;
}
