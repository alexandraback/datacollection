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
	ifstream input("C:\\Test\\D-large.in");
    ofstream output("C:\\Test\\D-large.out",ios::trunc);
	int testN;
	input>>testN;
	for(int caseN=1;caseN<=testN;caseN++)
	{
		int X,R,C;

		cin>>X>>R>>C;

		if(X>=7)
		{
			cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
		else if(X==1) 
		{
			cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
		}
		else if(X==2)
		{
			if(R*C%2==0) cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
			else cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
		else if(X==3)
		{
			if(max(R,C)>=3&&min(R,C)>1&&R*C%3==0) cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
			else cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
		else if(X==4)
		{
			if(max(R,C)>=4&&min(R,C)>2&&R*C%4==0) cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
			else cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
		else if(X==5)
		{
			if(max(R,C)>=5&&min(R,C)>3&&R*C%5==0) cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
			else cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
		else if(X==6)
		{
			if(max(R,C)>=6&&min(R,C)>3&&R*C%6==0) cout<<"Case #"<<caseN<<": "<<"GABRIEL"<<endl;
			else cout<<"Case #"<<caseN<<": "<<"RICHARD"<<endl;
		}
	}
	
	return 0;
}
	


