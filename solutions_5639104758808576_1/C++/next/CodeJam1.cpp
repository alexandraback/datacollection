#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
	int t, maxShy;
	string line;
	ifstream ifile ("A-large.in");
	ofstream ofile;
	ofile.open ("output.out");
	ifile>>t;
	//cin>>t;
	for(int i = 1; i <= t; ++i)
	{
		string shyness;
		int ans = 0;
		getline (ifile,line);
		ifile>>maxShy>>shyness;
		//cin>>maxShy;
		//cin>>shyness;
		maxShy = 0;
		char tmp;
		char *val;

		int len = shyness.length();
		int k, count = 0;
		for(k = 0; k < len; ++k)
		{
			if(shyness[k] != '0' && k > count)
			{
				ans += k - count;
				count += ans;
			}
			char tmp = shyness[k];
			char *val = &tmp;
			count += atoi(val) ;
		}
		//cout<<"case #"<<i<<": "<<ans<<endl;
		ofile<<"case #"<<i<<": "<<ans<<endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}