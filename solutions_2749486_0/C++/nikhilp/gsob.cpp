#include<iostream>

using namespace std;

int main()
{
	int T,i,xt,yt,x,y,step;
	bool xneg,yneg;
	
	cin >> T;
	
	for(i=1;i<=T;i++)
	{
		cin >> xt >> yt;
		
		
		x=y=0;
		step = 1;
		xneg = yneg =false;
		
		if(xt<0)
		{
			xt *= -1;
			xneg = true;
		}
		
		if(yt<0)	
		{
			yt *= -1;
			yneg = true;
		}
		
		
		cout << "Case #"<<i<<": ";
		
		while((x+step )<=xt)
		{
			x += step;
			step++;
			if(xneg)
			cout<<"W";
			else
			cout<<"E";
		}
			
		while(xt>x)
		{
			step++;
			if(xneg)
			cout<<"E";
			else
			cout<<"W";
			step++;
			if(xneg)
			cout<<"W";
			else
			cout<<"E";
			x++;
		}
		
		while((y+step)<=yt)
		{	
			y += step;
			step++;
			if(yneg)
				cout<<"S";
			else
				cout<<"N";
		}	
		
		while(yt>y)
		{
			step++;
			if(yneg)
			cout<<"N";
			else
			cout<<"S";
			step++;
			if(yneg)
			cout<<"S";
			else
			cout<<"N";
			y++;
		}
		cout<<endl;
	}
	return 0;
}

