#include<iostream>
#include<set>
using namespace std;

int digc(int X)
{
int r = 0;
while(X) {
	X/=10;
	r++;
	}
return r;
}

int main()
{
int T, A, B;
cin>>T;

for(int i=1;i<=T;i++)
	{
		unsigned long long count=0;
		cin>>A>>B;
		for(int j=A;j<B;j++)
			{
			set<int> recycle;
			int dc = 0;
			int tmp = j;
			int div = 1; 
			while(tmp) { div*=10; tmp/=10; dc++;}
			tmp = j; div/=10;
				for(int k=0;k<dc;k++)
					{
						int tmp2 = tmp/div;
						tmp*=10;
						tmp+=tmp2;
						tmp%=(10*div);
						if(tmp > j && tmp <= B)
							{
							if(recycle.find(tmp) != recycle.end());
							else {
							recycle.insert(tmp);
							 count++;
								}
							}
					}
			}
	cout<<"Case #"<<i<<": "<<count<<endl;
	}	
return 0;
}
