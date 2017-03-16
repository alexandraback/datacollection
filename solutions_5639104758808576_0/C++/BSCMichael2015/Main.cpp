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

int main()
{
	ifstream input("C:\\Test\\A-small-attempt0.in");
    ofstream output("C:\\Test\\A-small-attempt0.out",ios::trunc);
	int testN;
	input>>testN;
	for(int caseN=1;caseN<=testN;caseN++)
	{
		int N;string s;
		cin>>N>>s;
		int sum=s[0]-'0';
		int res=0;
		for(int i=1;i<=N;i++)
		{
			if(sum<i)
			{
				res+=i-sum;
				sum=i;
			}

			sum+=s[i]-'0';
		}

		output<<"Case #"<<caseN<<": "<<res<<endl;

		
	}
	return 0;
}
	


