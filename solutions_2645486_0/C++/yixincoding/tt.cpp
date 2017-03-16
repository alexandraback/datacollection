
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;




int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int T;cin>>T;
	for (int qq=1;qq<=T;qq++)
	{
		int e,r,n;
		cin >> e>>r>>n;
		int v[100];
		int t[100];
		int max=0;
		int value=0;
		for (int i = 0; i < 100; ++i)
		{
			v[i]=0;t[i]=0;
			/* code */
		}
		
		for (int i = 0; i < n; ++i)
		{
			cin>> v[i];
			/* code */
		}
		while (t[n]!=1)
		{
			int vv=0;
			while(t[vv]==e) vv++;
			t[vv]++;
			for (int i=0;i<vv;i++)
			{
				t[i]=0;
			}
			int ene=e;
			bool flag=true;
			value=0;
			for (int i = 0; i < n; ++i)
			{
				ene-=t[i];
				if (ene<0) {flag=false;break;}
				value+=v[i]*t[i];
				ene+=r;
				if (ene>e) ene=e;
				/* code */
			}
			if (flag) 
			{
				if (max<value) max=value;
			}
		}
		cout << "Case #"<< qq<<": " << max<<endl;

	}



	
	return 0;
}