#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string run_test(string line)
{	
	int k, c, s;
	istringstream iss(line);
	iss>>k>>c>>s;

	string retval;
	ostringstream oss(retval);

	long long positions[s];
	for (int i=0; i<s; i++)
	{
		positions[s] = i*pow(k,c-1)+1;
		oss <<i+1<<" ";
	}


	return oss.str();
}

int main()
{
	string line;
	getline(cin,line);

	auto n_tests = stoi(line);	

	for(int i = 0; i < n_tests; i++) {		
		getline(cin,line);

		cout<<"Case #"<<i+1<<": ";

		auto result = run_test(line);

		cout<<result<<"\n";	
	}
}
