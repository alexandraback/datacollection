#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int T,R,C,W;
    cin>>T;
    for (int i=0;i<T;i++)
    {
	cin>>R>>C>>W;
	int x=W-1;
	int xc=0;
	while(x<=C-1)
	{
	    x=x+W;
	    xc++;
	}
	xc=xc*R;
	if (x-W != C-1)
	{
	    xc=xc+1;
	}
	xc=xc+W-1;
	printf("Case #%d: %d\n",i+1,xc);
    }
    return 0;
}
