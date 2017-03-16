#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int total = 1;
	while(T--)
	{
		string S;
		cin>>S;
		cout<<"Case #"<<total++<<": ";
		vector<int> V(26,0);
		for(int i=0;i<S.length();i++)
			V[S[i]-'A']++;
		vector<int> A(10,0);
		for(int i=0;i<S.length();i++)
		{
			switch(S[i])
			{
				case 'W': A[2]++;break;
				case 'Z': A[0]++;break;
				case 'G': A[8]++;break;
				case 'U': A[4]++;break;
				case 'X': A[6]++;break;
			}
		}
		A[3] = V['T'-'A'] - A[2]-A[8];
		A[7] = V['S'-'A'] - A[6];
		A[5] = V['V'-'A'] - A[7];
		A[9] = V['I'-'A'] - A[8]-A[6]-A[5];
		A[1] = V['O'-'A'] - A[2]-A[0]-A[4];
		for(int i=0;i<10;i++)
		{
			while(A[i])
			{
				cout<<i;
				A[i]--;
			}
		}
		cout<<endl;

	}
	return 0;
}