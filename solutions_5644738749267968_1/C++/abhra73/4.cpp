#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int t,n,i,j,w,dw,cas=0;
	double x;
	cin>>t;
	vector<double> ken,naomi,tk,tn;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		w=0;dw=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			naomi.push_back(x);
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
			ken.push_back(x);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		tn=naomi;
		tk=ken;
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<ken.size();j++)
			{
				if(naomi[i]<ken[j])
					break;
			}
			if(j==ken.size())
			{
				w++;
				ken.erase(ken.begin());
			}
			else
				ken.erase(ken.begin()+j);
			naomi.erase(naomi.begin()+i);
		}
		naomi=tn;
		ken=tk;
		
//		for(i=0;i<naomi.size();i++)
//			cout<<naomi[i]<<" ";
//		cout<<endl;
//		for(i=0;i<ken.size();i++)
//			cout<<ken[i]<<" ";
//		cout<<endl;
		int cnt=0;
		for(i=0;i<n;i++)
		{
//			cout<<"("<<naomi[0]<<","<<ken[0]<<") ";
			if(naomi[0]<ken[0])
			{
				cnt++;
				ken.erase(ken.begin()+ken.size()-1);
				naomi.erase(naomi.begin());
			}
			else
			{
				ken.erase(ken.begin());
				naomi.erase(naomi.begin());
			}
		}
//		cout<<endl<<n<<" "<<cnt<<endl;
		dw=n-cnt;
		cout<<dw<<" "<<w<<endl;
		ken.clear();
		naomi.clear();
	}
	return 0;
}