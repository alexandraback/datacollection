#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int mote[1000000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int nc;
	cin>>nc;

	int A,N;
	int count,op,minc;
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>A>>N;
		for(int i=0;i<N;i++)
		{
			cin>>mote[i];
		}
		sort(mote,mote+N);
		count=0;
		minc=N;
		for(int i=0;A>1&&i<N;i++)
		{
			op=0;
			while(A<=mote[i])
			{
				A+=A-1;
				op++;
			}
			A+=mote[i];
			count+=op;
			if(count+N-i-1<minc)
				minc=count+N-i-1;
		}
		cout<<"Case #"<<tc<<": "<<minc<<endl;
	}	
	return 0;
}