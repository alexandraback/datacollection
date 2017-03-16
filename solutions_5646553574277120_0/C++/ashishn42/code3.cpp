#include <bits/stdc++.h>
using namespace std;

bool chk(vector <int> &v,int y,int i)
{
	if(y==0)
		return true;
	if(i==v.size()||y<0)
		return false;
	return (chk(v,y-v[i],i+1)||chk(v,y,i+1));
}

int main() 
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		int c,d,d2,v;
		cin>>c>>d>>v;
		vector <bool> w(v+1,false);
		w[0]=true;
		vector <int> u(d);
		vector <bool> b(d,false);
		for(int i=0;i<d;i++)
			cin>>u[i];
		do
		{
			d2=u.size();
			for(int i=1;i<w.size();i++)
			{
				if(chk(u,i,0))
					w[i]=true;
			}
			for(int i=1;i<w.size();i++)
			{
				if(!w[i])
				{
					u.push_back(pow(2,log2(i)));
					break;
				}
			}
		}while(d2!=u.size());
		cout<<"Case #"<<j++<<": "<<u.size()-d<<endl;
	}
	return 0;
}