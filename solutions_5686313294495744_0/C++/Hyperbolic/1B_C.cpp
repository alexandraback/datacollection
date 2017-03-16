#include <iostream>
#include <string>
void solve(int);
int main()
{
	freopen("inputC1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	std::cin>>T;
	for(int i=1;i<=T;i++) solve(i);
}
std::string x[20],y[20];
int check[20],a;
int ans;
void func(int k)
{
	if(k>a)
	{
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1)
			{
				int control1 = 0, control2 = 0;
				for(int j=1;j<=a;j++)
				{
					if(check[j]==0)
					{
						if(x[i]==x[j])
						{
							control1 = 1;
							break;
						}
					}
				}
				for(int j=1;j<=a;j++)
				{
					if(check[j]==0)
					{
						if(y[i]==y[j])
						{
							control2 = 1;
							break;
						}
					}
				}
				if(control1==0||control2==0) return;
			}
		}
		int s=0;
		for(int i=1;i<=a;i++) s+=check[i];
		ans=ans>s?ans:s;
		return;
	}
	check[k] = 1;
	func(k+1);
	check[k] = 0;
	func(k+1);
}
void solve(int T)
{
	ans = 0;
	std::cin>>a;
	for(int i=1;i<=a;i++) std::cin>>x[i]>>y[i];
	func(1);
	std::cout<<"Case #"<<T<<": "<<ans<<"\n";
}
