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
	    int X0=X,Y0=Y;
	    if(X0<0) X0=-X0;
	    if(Y0<0) Y0=-Y0;
	    int delta_x=X0;
	    int delta_y=Y0;
	    char path[1000000];
	    int i,j,k=0;
	    while(delta_x>=k+1)
	    {
	        k++;
	        path[k]='E';
	        delta_x-=(k+1);
	    }

	    while(delta_y>=k+1)
	    {
	        k++;
	        path[k]='N';
	        delta_y-=(k+1);
	    }
/*
	    for(i=1;i<=delta_x;i++)
	    {
	        k++;path[k]='W';
	        k++;path[k]='E';
	    }
	    for(i=1;i<=delta_y;i++)
	    {
	        k++;path[k]='S';
	        k++;path[k]='N';
	    }*/
	    if(X<0)
	    {
	        for(i=1;i<=k;i++)
	        {
	            if(path[i]=='E') path[i]='W';
	            if(path[i]=='W') path[i]='E';
	        }
	    }
	    if(Y<0)
	    {
	        for(i=1;i<=k;i++)
	        {
	            if(path[i]=='N') path[i]='S';
	            if(path[i]=='S') path[i]='N';
	        }
	    }
	    for(i=1;i<=k;i++) cout<<path[i];
	    cout<<endl;
	}
    return 0;
}
