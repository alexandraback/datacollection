#include<iostream>
#include<string>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int T,N,S,p;
	int* scores;
	int max;
	cin>>T;
	REP(i,T)
	{
		cin>>N>>S>>p;
		scores=new int[N];
		max=0;
		REP(j,N) cin>>scores[j];
		REP(j,N)
		{
			if(scores[j]>3*p-3) max++;
			else if(p>1&&(scores[j]==3*p-3||scores[j]==3*p-4)) if(S>0)
			{
				max++;
				S--;
			}

		}
		printf("Case #%d: %d\n",i+1,max);
	}
	return 0;
}