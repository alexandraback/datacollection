#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ifstream cin;
	cin.open("B-small-attempt0.in");
	ofstream cout;
	cout.open("dancer_small.out");

	int T, N, S, p;
	int totals[105];

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>N>>S>>p;

		for (int i=0 ; i<N; i++)
			cin>>totals[i];

		int S_rem=S;
		int count=0;
		for (int dancer=0; dancer<N ; dancer++)
		{
			bool found=false,maxfound=false;
			for (int i=10;i>=0 && !maxfound;i--){
				for (int j=min(i+1,10);j>=max(i-1,0) && !found;j--){
					for (int k=min(min(j+1,10),min(i+1,10)); k>=max(0,max(i-1,j-1)) && !found;k--){
						if ( (i+j+k)==totals[dancer]){
							found=true;
							if ( max(i,max(j,k)) >= p){
								count++;
								maxfound=true;
							}
						}
					}
				}
			}
			bool found2;
			bool maxfound2;
			if ((!found || !maxfound) && S_rem>0){
				found2=false;
				maxfound2=false;
				for (int i=10;i>=0 && !maxfound2;i--){
					for (int j=min(i+2,10);j>=max(i-2,0) && !maxfound2;j--){
						for (int k=min(min(j+2,10),min(i+2,10)); k>=max(0,max(i-2,j-2)) && !maxfound2;k--){
							if ( (i+j+k)==totals[dancer] ){
								found2=true;
								if ( max(i,max(j,k)) >= p){
									count++;
									maxfound2=true;
								}
							}
						}
					}
				}
				if ((!found && found2) || maxfound2)
					S_rem--;
			}
		}
		
		cout<<"Case #"<<t<<": "<<count<<endl;
	}
	

	return 0;
}