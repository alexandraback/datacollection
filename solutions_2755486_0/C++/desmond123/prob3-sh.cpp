#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
struct nomad
{
	int d,n,w,e,s,delE,delP,delS;
};
struct attack
{
	int d,w,e,s,t;
	bool operator < (const attack & c)
	{
		return (d<c.d) ;
	}
};
int main()
{
	vector<int> ans;
	int t;
	cin>>t;
	while(t--)
	{
		std::vector<int> h(4000,0);
		int n;
		cin>>n;
		std::vector<nomad> nom;
		for(int i=0;i<n;i++)
		{
			nomad temp;
			cin>>temp.d>>temp.n>>temp.w>>temp.e>>temp.s>>temp.delE>>temp.delP>>temp.delS;
			nom.push_back(temp);
		}
		std::vector<attack> v;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<nom[i].n;j++)
			{
				attack a;
				a.d = nom[i].d + j*nom[i].delE;
				a.w = nom[i].w + j*nom[i].delP;
				a.e = nom[i].e + j*nom[i].delP;
				a.s = nom[i].s + j*nom[i].delS;
				a.t = i+1;
				v.push_back(a); 
			}
		}
		// sort(v.begin(),v.end());
		int count = 0;
		for(int i=0;i<v.size();i++)
		{
			for(int j=i+1;j<v.size();j++)
			{
				if(v[i]<v[j])
				{

				}
				else
				{
					swap(v[i],v[j]);
				}
			}
		}
		for(int i=0;i<v.size();i++)
		{
			bool flag = 0;
			//cout<<v[i].d<<" "<<v[i].t<<" "<<v[i].w<<" "<<v[i].e<<" "<<v[i].s<<" ";
			for(int j = v[i].w; j< v[i].e;j++)
			{
				if(h[2*j+2000]<v[i].s||h[2*j+2000+1]<v[i].s)
				{
					flag = 1;
					if(h[2*j+2000]<v[i].s)
						h[2*j+2000] = v[i].s;
					if(h[2*j+2000+1]<v[i].s)
						h[2*j+2000+1] = v[i].s;
				}
			}
			if(h[2*v[i].e+2000]<v[i].s)
			{
				flag = 1;
				h[2*v[i].e+2000] = v[i].s;
			}
			count += flag;
			// if(flag)
			// 	cout<<"success";
			// cout<<endl;
		}
		//cout<<endl;
		ans.push_back(count);
	}
	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;

	}
}