#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.txt","w",stdout);
	int t,x,r,c,m;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> x >> r >> c;
		if(r<c) swap(r,c);
		// r>c
		if(x>=7)
		{
			cout << "Case #" << i+1 << ": RICHARD" << endl; 
						continue;
		}
		if(x==1)
		{
			cout << "Case #" << i+1 << ": GABRIEL" << endl; 
						continue;
		}
		if(x<=3)
		{
			if(r*c%x==0)
			{
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
							continue;
			}
			else
			{
				cout << "Case #" << i+1 << ": RICHARD" << endl; 
										continue;
			}
		}
		if(x==4)
		{
			if(c==1 or r*c%x !=0 )
			{
				cout << "Case #" << i+1 << ": RICHARD" << endl; 
				continue;
			}
			if(c==2)
			{
				if(r==2)
				{
					cout << "Case #" << i+1 << ": RICHARD" << endl; 
									continue;
				}
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
								continue;
			}
			if(c>=3)
			{
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
				continue;
			}
		}
		if(x==5)
		{
			if(c<=2 or r*c%x !=0 )
			{
				cout << "Case #" << i+1 << ": RICHARD" << endl; 
				continue;
			}
			if(c>3)
			{
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
								continue;
			}
			if(c==3)
			{
				if(r==5)
				{
					cout << "Case #" << i+1 << ": RICHARD" << endl; 
									continue;
				}
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
												continue;
			}
		}
		if(x==6)
		{
			if(c<=2 or r*c%x !=0 )
			{
				cout << "Case #" << i+1 << ": RICHARD" << endl; 
				continue;
			}
			if(c==3)
			{
				if(r==4)
				{
					cout << "Case #" << i+1 << ": RICHARD" << endl; 
									continue;
				}
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
				continue;
			}
			if(c>=4)
			{
				cout << "Case #" << i+1 << ": GABRIEL" << endl; 
								continue;
			}
		}
	}
}