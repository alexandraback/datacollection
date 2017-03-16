#include<iostream>
#include<fstream>

using namespace std;

long long int calc(long long int n, long long int k)
{
	if(k>n) return 0;
	return ((n-k+1)*(n-k+2))/2;
}

int main()
{
	int t,tc;
	char a[1000005];
	long long int px,x,k,n,s,ans;
	ifstream ifile("D:/in3.in");
	ofstream ofile("D:/out.txt");
	ifile>>tc;
	for(t=0;t<tc;++t)
	{
		ifile>>a;
		ifile>>n;
		px=-1;
		k=0;
		s=0;
		for(x=0;a[x]!=0;++x)
		{
			switch(a[x])
			{
				case 'a': case 'e': case 'i': case 'o': case 'u':
				if(x-px<=n) k+=x-px;
				else
				{
					if(k!=0)
					s+=calc(k+n-1,n);
					//cout<<k+n-1<<" "<<n<<endl;
					k=n;
				}
				px=x;
				break;
			}
		}
		if(k!=0)
		{if(x-px<=n) s+=calc(k+x-px-1,n);
		else s+=calc(k+n-1,n);
		}
		ans=calc(x,n)-s;
		//cout<<x-px<<endl;
		ofile<<"Case #"<<t+1<<": "<<ans<<endl;
	}
	return 0;
}
