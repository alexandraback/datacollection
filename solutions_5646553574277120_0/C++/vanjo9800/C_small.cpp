#include<iostream>
#include<vector>
using namespace std;
vector<int> upd;
bool used[101];
int sums[101];
int br,d,v,ans;
void rek()
{
	for(int i=1;i<=v;i++)
	{
		if(!sums[i])
		{
			vector<int> pom;
			br++;
			for(int j=0;j<i;j++)
			{
				if(sums[j]&&!used[i-j])
				{
					used[i-j]=true;
					for(int p=0;p<=v;p++)
					{
						if(sums[p])
						{
							pom.push_back(p+i-j);
						}
					}
					for(int p=0;p<pom.size();p++)
					{
						sums[pom[p]]++;
					}
					rek();
					while(pom.size()!=0)
					{
						sums[pom.back()]--;
						pom.pop_back();
					}
				}
			}
			br--;
			return;
		}
	}
	ans=min(ans,br-d);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t,c;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>c>>d>>v;
		br=d;
		for(int j=0;j<=v;j++)
		{
			used[j]=false;
			sums[j]=0;
		}
		sums[0]=1;
		for(int j=0;j<br;j++)
		{
			cin>>c;
			used[c]=true;
			for(int p=0;p<=v;p++)
			{
				if(sums[p])
				{
					upd.push_back(p+c);
				}
			}
			while(upd.size()!=0)
			{
				sums[upd.back()]++;
				upd.pop_back();
			}
		}
		ans=1<<30;
		rek();
		cout<<"Case #"<<i+1<<": "<<ans<<"\n";
	}
	return 0;
}
