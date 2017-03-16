#include<iostream>
using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))

int main()
{
int T, N, S, P, tmp, best;

int rA, rB, rC; //rA + rB + rC = N
int thA, thB;

cin>>T;
for(int i=1;i<=T;i++)
	{
		cin>>N>>S>>P;
		rA = rB = rC =0;
		thB = 3*P - 2;
		thA = 3*P - 4;
		if(thA < 0) thA = 1;
		//cout<<thA<<" : "<<thB<<"  for "<<P<<" allowing "<<S<<"exceptions"<<endl;
		for(int j=0;j<N;j++)
			{
			cin>>tmp;
			if(tmp>=thB) rC++;
			else if(tmp>=thA) rB++;
			else rA++;
			//cout<<tmp<<" <"<<rA<<","<<rB<<","<<rC<<">"<<endl;
			}
	best = rC + MIN(rB, S);
	cout<<"Case #"<<i<<": "<<best<<endl;
	}
return 0;
}
