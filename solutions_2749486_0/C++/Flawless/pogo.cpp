// Shashank Jain
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define LL long long int
using namespace std;
int main()
{
    	int t=0,x,y,i=1;
    	cin>>t;
    	while(i<=t)
	{
        	cin>>x>>y;
		printf("Case #%d: ",i);
        	if(x<=0&&y>=0)
		{
            		x*=(-1);
            		while(x--)
                		cout<<"EW";
            		while(y--)
                		cout<<"SN";
            	}
        	else if(x<=0&&y<=0)
		{
            		x*=-1;
			y*=-1;
            		while(x--)
                		cout<<"EW";
            		while(y--)
                		cout<<"NS";
            	}
        	else if(x>=0&&y<=0)
		{
			y*=-1;            		
			while(x--)
                		cout<<"WE";
            		while(y--)
                		cout<<"NS";
        	}
        	else
		{
            		while(x--)
                		cout<<"WE";
            		while(y--)
                		cout<<"SN";
        	}
        	cout<<endl;
        	i++;
    	}
    return 0;
}
