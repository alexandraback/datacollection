#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> input_to_array(string str)
{
	vector<bool> array;
	for(char& c : str) {
		array.push_back(c=='+');
	}
	reverse(array.begin(), array.end());
	return array;
}

int run_test(string line)
{	
	auto pancakes = input_to_array(line);

	auto retval = 0;
	auto was_flipped = false;

	for(unsigned int i=0; i<pancakes.size(); i++) {
		if (!(pancakes[i]^was_flipped)) {
			retval++;
			was_flipped = !was_flipped;
		}
	}

	return retval;
}

int main()
{
	string line;
	cin>>line;

	auto n_tests = stoi(line);	

	for(int i = 0; i < n_tests; i++) {
		cin>>line;

		cout<<"Case #"<<i+1<<": ";

		auto result = run_test(line);

		cout<<result<<"\n";	
	}
}
