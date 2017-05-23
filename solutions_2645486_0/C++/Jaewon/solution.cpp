#include <iostream>
#include <algorithm>
using namespace std;

int maxEnergy;
int nRecover;
int nAct;
int val[10];

int memo[10][6];

int main()
{
	int nTests;
	cin>>nTests;
	for(int test=1; test<=nTests; test++) {

		cin>>maxEnergy>>nRecover>>nAct;
		for(int i=0; i<nAct; i++)
			cin>>val[i];

		for(int e=0; e<=maxEnergy; e++)
			memo[0][e] = val[0]*(maxEnergy-e);
		for(int a=1; a<nAct; a++)
			for(int e=0; e<=maxEnergy; e++)
				memo[a][e] = 0;
		for(int a=1; a<nAct; a++) {
			for(int e=0; e<=maxEnergy; e++) {
				for(int se=0; se<=maxEnergy-e; se++) {
					for(int r=0; r<=nRecover; r++) {
						if( e+se-r < 0 )
							continue;
						memo[a][e] = max( memo[a][e], memo[a-1][e+se-r] + val[a]*se );
					}
				}
			}
		}

		int answer = 0;
		for(int e=0; e<=maxEnergy; e++) {
			answer = max(answer, memo[nAct-1][e]);
		}

		cout<<"Case #"<<test<<": "<<answer<<endl;
	}
	return 0;
}