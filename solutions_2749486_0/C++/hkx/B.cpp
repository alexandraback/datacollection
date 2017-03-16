#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
int X,Y;
int main()
{
	freopen("B.in","r",stdin);freopen("out.txt","w",stdout);
	int T,cas=0;
	cin>>T;
	while(T--)
	{
	    cas++;
	    printf("Case #%d: ",cas);
	    cin>>X>>Y;
	    int i,j;
	    if(X>0)
	    {
	        for(i=1;i<=X;i++) printf("WE");
	    }
	    else if(X<0)
	    {
	        for(i=1;i<=-X;i++) printf("EW");
	    }
	    if(Y>0)
	    {
	        for(i=1;i<=Y;i++) printf("SN");
	    }
	    else if(Y<0)
	    {
	        for(i=1;i<=-Y;i++) printf("NS");
	    }
	    printf("\n");
	}
    return 0;
}
