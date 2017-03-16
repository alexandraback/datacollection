#include<iostream>
#include<math.h>
#define REP(i,n) for(i=0;i<n;i++)

using namespace std;


int main()
{
	int T;
	cin>>T;
	int c,i,j,k;
	int N;
	char* C;
	int* S;
	int* P;
	float mintime,time;
	float st,et;
	REP(c,T)
	{
		cin>>N;
		mintime=-1;
		C=new char[N];
		S=new int[N];
		P=new int[N];
		REP(i,N)
			cin>>C[i]>>S[i]>>P[i];
		REP(i,N)
			REP(j,N)
			{
				if(S[i]>S[j]&&P[i]<=P[j])
				{
					if(P[i]+5<=P[j])
					{
						st=(P[j]-P[i]-5)/(S[i]-S[j]);
						et=10/(S[i]-S[j]);
					}
					else
					{
						st=0;
						et=(P[j]-P[i]+5)/(S[i]-S[j]);
					}
					REP(k,N)
						if(S[i]>S[k]&&P[i]<=P[k])
						{
							if((P[k]+st*S[k])>=(P[i]+st*S[i]+5)&&(P[k]+(st+et)*S[k])<(P[i]+(st+et)*S[i]+5))
							{
								time=((P[k]-P[i]-5)/(S[i]-S[k]));
								if(time<mintime||mintime==-1)
									mintime=time;
							}
						}
				}
				else if(S[i]==S[j]&&P[i]<=P[j]+5&&P[i]>=P[j]-5)
				{
					REP(k,N)
						if(S[i]>S[k]&&P[i]<=P[k])
						{
								time=((P[k]-P[i]-5)/(S[i]-S[k]));
								if(time<mintime||mintime==-1)
									mintime=time;
						}
				}
			}
		if(mintime==-1) printf("Case #%d: Possible\n",c+1);
		else printf("Case #%d: %.5f\n",c+1,mintime);
		//NOTE:consider equal cars going parallel also
	}
	return 0;
}