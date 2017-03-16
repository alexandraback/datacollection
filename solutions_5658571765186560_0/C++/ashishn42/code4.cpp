#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("i.txt","r",stdin);
	freopen("l.txt","w",stdout);
	int t,u=1;
	cin>>t;
	while(t--)
	{
		int x,r,c;
		cin>>x>>r>>c;
		if((r*c)%x!=0)
			cout<<"Case #"<<u++<<": RICHARD\n";
		else if(x>6)
			cout<<"Case #"<<u++<<": RICHARD\n";
		else if(x>max(r,c))
			cout<<"Case #"<<u++<<": RICHARD\n";
		else if((x+1)/2>min(r,c))
			cout<<"Case #"<<u++<<": RICHARD\n";
		else if(x==1)
			cout<<"Case #"<<u++<<": GABRIEL\n";
		else if(x==2)
			cout<<"Case #"<<u++<<": GABRIEL\n";
		else if(x==3)
			cout<<"Case #"<<u++<<": GABRIEL\n";
		else if(x==4)
		{
			if(min(r,c)>2)
				cout<<"Case #"<<u++<<": GABRIEL\n";
			else
				cout<<"Case #"<<u++<<": RICHARD\n";
		}
		else if(x==5)
		{
			if(r==3&&c==5||c==5&&r==3)
				cout<<"Case #"<<u++<<": RICHARD\n";
			else
				cout<<"Case #"<<u++<<": GABRIEL\n";
		}
		else if(x==6)
		{
			if(min(r,c)>3)
				cout<<"Case #"<<u++<<": GABRIEL\n";
			else
				cout<<"Case #"<<u++<<": RICHARD\n";
		}
	}
	return 0;
}