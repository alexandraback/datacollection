#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int T,iA,iB,res;
	string A,B;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		res=0;
		cin>>iA>>iB;
		for (int n=iA;n<=iB;n++)
		{
			int d[10],nd=0,tmp=n;
			while(tmp>0)
			{
				d[nd++]=tmp%10;
				tmp/=10;
			}
			for (int i=0,j=nd-1;i<j;i++,j--)
			{
				tmp=d[i];d[i]=d[j];d[j]=tmp;
			}
			map<int,bool> M;
			for (int s=1;s<nd;s++)
			{
				int n2=0;
				for (int i=0;i<nd;i++)
					n2 = n2*10 + d[(i+s)%nd];
				if (n2>n && n2 >= iA && n2 <= iB && M.find(n2)==M.end())
				{
					res++;
					//cout<<n<<" "<<n2<<"\n";
					M[n2]=1;
				}
			}
		}
		cout<<"Case #"<<t<<": "<<res<<"\n";
	}
	return 0;
}