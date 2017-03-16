// a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back


int rs[1000];
int sn[1000];

vector<int> ns[1000];

bool walk(int r, int n)
{
	fore(i,ns[n])
	{
		int q=*i;
		if (rs[q]==r)
			return true;
		rs[q]=r;
		if (walk(r,q))
			return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		fori(i,0,1000) sn[i]=0;
		int N;
		cin>>N;
	
		fori(n,0,N)
		{
			rs[n]=-1;
			int M;
			cin>>M;
			vector<int> ms(M);
			fori(m,0,M)
			{
				int a;
				cin>>a;
				ms[m]=a-1;
				sn[ms[m]]+=1;
			}
			ns[n]=ms;
		}

		bool d=false;
		fori(n,0,N)
		{
			if (sn[n]==0)
			{	
				if (walk(n,n))
				{	
					d=true;
					break;
				}
			}
		}

		cout<<"Case #"<<t+1<<": ";
		if (d) cout<<"Yes"; else cout<<"No";
		cout<<std::endl;
	}

	return 0;
}


