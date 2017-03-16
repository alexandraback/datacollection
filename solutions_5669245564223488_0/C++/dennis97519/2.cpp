#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int MOD=1000000007;
struct shit
{
	string s;
	long long n;
};
vector<shit> f;
void print()
{
	for (int i=0;i<f.size();++i)
		cout<<f[i].s<<" "<<f[i].n<<endl;
	cout<<endl;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T;
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		int n;
		cin>>n;
		f.clear();
		bool flag=1;
		for (int i=0;i<n;++i)
		{
			string s;
			cin>>s;
			int t=1;
			while (s.size()>t)
			{
				while (s[t]==s[t-1]) s.erase(t,1);
				if (s.find(s[t])>=0&&s.find(s[t])<t) flag=0;
				++t;
			}
			shit temp;
			temp.s=s;temp.n=1;
			f.push_back(temp);
		}
		if (!flag) {cout<<"Case #"<<TT<<": "<<0<<endl;continue;}
		

		
		for (int i=0;i<f.size();++i)
			if (f[i].s.size()==1)
				for (int j=i+1;j<f.size();++j)
					if (f[j].s==f[i].s)
					{
						++f[i].n;
						f.erase(f.begin()+j);
						--j;
					}
		
		
		
		for (int i=0;i<f.size();++i)
		{
			long long temp=1;
			for (int j=1;j<=f[i].n;++j)
				temp=temp*j%MOD;
			f[i].n=temp;
		}
		

		
		
		for (int i=0;i<f.size();++i)
			if (f[i].s.size()!=1)
				for (int j=0;j<f.size();++j)
					if (f[j].s.size()==1&&(f[j].s[0]==f[i].s[0]||f[j].s[0]==f[i].s[f[i].s.size()-1]))
					{
						f[i].n=f[i].n*f[j].n%MOD;
						f.erase(f.begin()+j);
						if (j<i) --i;
						--j;
					}
			
	
bool fuck=1;
while (fuck)
{					
fuck=0;
		for (int i=0;i<f.size();++i)
				for (int j=0;j<f.size();++j)
					if (i!=j&&(f[i].s[0]==f[j].s[f[j].s.size()-1]||f[j].s[0]==f[i].s[f[i].s.size()-1]))
					{
						f[i].n=f[i].n*f[j].n%MOD;
						if (f[i].s[0]==f[j].s[f[j].s.size()-1]) f[i].s=f[j].s+f[i].s;
						else f[i].s+=f[j].s;
						f.erase(f.begin()+j);
						if (j<i) --i;
						--j;
						fuck=1;
					}
}
					
					
					



		
		flag=1;long long ans=1;
		for (int i=1;i<=f.size();++i)
			ans=ans*i%MOD;
		for (int i=0;flag&&i<f.size();++i)
		{
			ans=ans*f[i].n%MOD;
			for (int j=0;flag&&j<i;++j)
				for (int k=0;flag&&k<f[j].s.size();++k)
					if (f[i].s.find(f[j].s[k])<f[j].s.size()) {ans=0;flag=0;}
		}
		cout<<"Case #"<<TT<<": "<<ans<<endl;
	}
}
