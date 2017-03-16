#include<bits/stdc++.h>

using namespace std;

bool b(int a,int c)
{
	return a>c;
}

int main()
{
	//freopen("i.txt","r",stdin);
	freopen("k.txt","w",stdout);
	fstream fin("i.txt");
	int t,u=1;
	clock_t tr=clock();
	fin>>t;
	//t=1;
	while(t--)
	{
		int d;
		fin>>d;
		vector <int> p(d);
		for(int i=0;i<d;i++)
			fin>>p[i];
		int ans=*max_element(p.begin(),p.end());
		//cout<<ans<<" ";
		int k=2;
		while(k<ans)
		{
			int y=0;
			for(int i=0;i<p.size();i++)
				y+=(p[i]-1)/k;
			ans=min(ans,k+y);
			//cout<<ans<<" ";
			k++;
		}
		cout<<"Case #"<<u++<<": "<<ans<<endl;
	}
	//cout<<"Time spent is "<<(long double)(clock()-tr)/(long double)(CLOCKS_PER_SEC)<<endl;
	return 0;
}