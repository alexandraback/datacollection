#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<random>
#include<fstream>
#include<cmath>
#include<cctype>
#include<functional>
#include<iomanip>
#include<bitset>

using namespace std;


#define input cin
#define output cout

int p[1000];
int main()
{
	ifstream input("C:\\Test\\B-large.in");
    ofstream output("C:\\Test\\B-large.out",ios::trunc);
	int testN;
	input>>testN;
	for(int caseN=1;caseN<=testN;caseN++)
	{
		int N;
		cin>>N;
		
		for(int i=0;i<N;i++)
		{
			cin>>p[i];
		}

		int res=INT_MAX,curr=0;
		for(int i=1;i<=1000;i++)
		{
			curr=i;
			for(int j=0;j<N;j++)
			{
				curr+=(p[j]-1)/i;
			}
			res=min(res,curr);
		}

		output<<"Case #"<<caseN<<": "<<res<<endl;

		
	}
	return 0;
}
	


