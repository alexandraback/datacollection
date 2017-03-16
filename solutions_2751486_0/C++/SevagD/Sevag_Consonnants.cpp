#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;





int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("sevag_cons_small.out");

	int T, n;
	string str;

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>str>>n;

		int n_value=0;
		for (int i=0; i<str.size(); i++)
		{
			int consec=0;
			bool found=false;
			for (int j=i; j<str.size(); j++)
			{
				if (str[j]!='a' && str[j]!='e' && str[j]!='i' && str[j]!='o' && str[j]!='u')
					consec++;
				else
					 consec=0;
				if (consec>=n)
					found=true;
				if (found)
					n_value++;
			}
		}

		cout<<"Case #"<<t<<": "<<n_value<<endl;

	}


	return 0;
}