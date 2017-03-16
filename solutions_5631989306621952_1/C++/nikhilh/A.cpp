#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		string S;
		vector <char> A;

		cin>>S;

		A.push_back(S[0]);

		for(int i=1;i<S.size();i++)
		{
			if(S[i]<A[0])
				A.push_back(S[i]);
			else
				A.insert(A.begin(),S[i]);
		}

		printf("Case #%d: ",c);
		for(int i=0;i<A.size();i++)
			cout<<A[i];
		cout<<endl;
	}
}