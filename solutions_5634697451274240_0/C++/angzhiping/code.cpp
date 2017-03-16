#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Compresses pancake by eliminating contiguous pancakes of the same side
string compress_pancake
	(const string& pancake)
{
	string compressed_pancake;
	
	if(!pancake.empty())
	{
		compressed_pancake.push_back(pancake[0]);
		
		for(int pancake_index = 1; pancake_index < pancake.size(); pancake_index++)
		{
			if(pancake[pancake_index] != compressed_pancake.back())
				compressed_pancake.push_back(pancake[pancake_index]);
		}
	}
	
	return compressed_pancake;
}

string flip_pancake
	(const string& pancake,
	 int num_pancakes_to_flip)
{
	string flipped_pancake = pancake;
	
	for(int i = 0; i < num_pancakes_to_flip; i++)
		flipped_pancake[num_pancakes_to_flip - i - 1] = (pancake[i] == '+') ? '-' : '+';
	
	return flipped_pancake;
}

int main()
{
	// Precompute pancake solution using dynamic programming
	
	const int max_pancake_size = 150;
	
	unordered_map<string,int> shortest_pancake_flips;
	
	string good_pancake = string("+");
	string anti_pancake = string("-"); // Nothing against pancakes on the wrong side...
	
	// We can insert some trivial solutions
	shortest_pancake_flips[good_pancake] = 0;
	shortest_pancake_flips[anti_pancake] = 1;
	
	for(int i = 1; i < max_pancake_size; i++)
	{
		good_pancake.push_back((good_pancake.back() == '-') ? '+' : '-');
		anti_pancake.push_back((good_pancake.back() == '-') ? '+' : '-');
		
		// Good pancake
		int optimal_good_pancake = INT_MAX;
		
		for(int j = 1; j < good_pancake.size(); j++)
		{
			string good_pancake_flipped = flip_pancake(good_pancake,j);
			good_pancake_flipped = compress_pancake(good_pancake_flipped);
			
			if(good_pancake_flipped.size() < good_pancake.size() && (1 + shortest_pancake_flips[good_pancake_flipped]) < optimal_good_pancake)
				optimal_good_pancake = 1 + shortest_pancake_flips[good_pancake_flipped];
		}
		
		// Anti pancake
		int optimal_anti_pancake = INT_MAX;
		
		for(int j = 1; j < anti_pancake.size(); j++)
		{
			string anti_pancake_flipped = flip_pancake(anti_pancake,j);
			anti_pancake_flipped = compress_pancake(anti_pancake_flipped);
			
			if(anti_pancake_flipped.size() < anti_pancake.size() && (1 + shortest_pancake_flips[anti_pancake_flipped]) < optimal_anti_pancake)
				optimal_anti_pancake = 1 + shortest_pancake_flips[anti_pancake_flipped];
		}
		
		if(1 + optimal_good_pancake < optimal_anti_pancake)
			optimal_anti_pancake = 1 + optimal_good_pancake;
			
		if(1 + optimal_anti_pancake < optimal_good_pancake)
			optimal_good_pancake = 1 + optimal_anti_pancake;
			
		shortest_pancake_flips[good_pancake] = optimal_good_pancake;
		shortest_pancake_flips[anti_pancake] = optimal_anti_pancake;
	}
	
	int num_cases;
	string pancake;
	
	cin >> num_cases;
	
	for(int case_index = 1; case_index <= num_cases; case_index++)
	{
		int flips_required = 0;
		
		cin >> pancake;
		
		pancake = compress_pancake(pancake);
		
		// Use hash table for lookup
		cout << "Case #" << case_index << ": " << shortest_pancake_flips[pancake] << endl;
	}
	
	return 0;
}
