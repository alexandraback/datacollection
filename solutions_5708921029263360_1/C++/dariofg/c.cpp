#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int I=1;I<=T;I++)
	{
		int a,b,c,k;
		cin >> a >> b >> c >> k;
		cout << "Case #" << I << ": ";
		vector<int> v;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<c;k++)
					v.push_back(i*3600+j*60+k);
			}
		}
		vector<int> mej;
		int mx = 0;
		for(int ii=0;ii<500;ii++)	// MUAJAJAJAJA
		{
			random_shuffle(v.begin(),v.end());
			vector<int> act;
			vector<int> ab(6000,0),ac(5000,0),bc(5000,0);
			for(int i=0;i<v.size();i++)
			{
				int num = v[i];
				int cc = 1+num%60;num/=60;
				int bb = 1+num%60;num/=60;
				int aa = 1+num%60;
				if(ab[aa*60+bb]>=k)
					continue;
				if(ac[aa*60+cc]>=k)
					continue;
				if(bc[bb*60+cc]>=k)
					continue;
				
					ab[aa*60+bb]++;
					ac[aa*60+cc]++;
					bc[bb*60+cc]++;
					act.push_back(v[i]);
				
			}
			if(act.size()>mx)
			{
				mx=act.size();
				mej= vector<int>(mx);
				for(int i=0;i<mx;i++)
					mej[i]=act[i];
			}
		}
		cout << mx << endl;
		for(int i=0;i<mx;i++)
		{
			int num = mej[i];
			int cc = num%60;num/=60;
			int bb = num%60;num/=60;
			int aa = num%60;
			cout << aa+1 << " " << bb+1 << " " << cc+1 << endl;
		}
	}
}
