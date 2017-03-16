#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_all_seen(bool seen[10])
{
	for(int i=0; i<10; i++) {
		if(!seen[i]) return false;
	}
	return true;
}

int run_test(int n)
{
	bool seen[10];
	fill_n(seen, 10, false);

	auto retval = 0;

	do {
		retval += n;

		for (int temp = retval; temp > 0; temp /= 10) {
		    seen[temp % 10] = true;
		}
	} while(!is_all_seen(seen));

	return retval;
}

int main()
{
	string line;
	cin>>line;

	auto n_tests = stoi(line);	

	for(int i = 0; i < n_tests; i++) {
		cin>>line;
		auto n = stoi(line);
		cout<<"Case #"<<i+1<<": ";

		if (n == 0) {
			cout<<"INSOMNIA\n";
			continue;
		}

		auto result = run_test(n);

		cout<<result<<"\n";	
	}
}
