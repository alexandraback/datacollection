#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// OSMOS

int main(void)
{
	ifstream input_file;
	input_file.open("QuestionA/A-small-attempt3.in");
	//input_file.open("QuestionA/input.in");

	ofstream output_file;
	output_file.open("QuestionA/A-small-attempt3.out", std::ios_base::trunc);
	//output_file.open("QuestionA/output.out", std::ios_base::trunc);

	int game_count;
	input_file >> game_count;
	for(int iter = 1; iter <= game_count; iter++)
	{
		long partical_size;
		int count_of_parts;		
		input_file >> partical_size >> count_of_parts;
		long * other_particles = new long[count_of_parts];

		for(int i = 0; i < count_of_parts; i++)
		{
			input_file >> other_particles[i];
		}

		// sort
		std::sort(other_particles, other_particles + count_of_parts);

		// find result
		int number_of_moves = 0;
		bool in_order = true;
		int in_order_count = 0;
		for(int i = 0; i < count_of_parts; i++)
		{
			if(partical_size > other_particles[i])
			{
				partical_size += other_particles[i];
				if(in_order) in_order_count++;
			}
			else if(i == count_of_parts - 1)
			{
				number_of_moves++;
				in_order = false;
			}
			else
			{
				in_order = false;
				// check addition size
				int add_iter = i;
				long partical_size_temp = partical_size;
				while(add_iter < count_of_parts)
				{
					partical_size_temp *= 2;
					partical_size_temp--;
					add_iter++;
					if(partical_size_temp > other_particles[i]) break;
				}				
				number_of_moves += (add_iter - i);
				if(add_iter == count_of_parts) i = count_of_parts;
				else 
				{
					i = i - 1;
					partical_size = partical_size_temp;
				}
			}
		}

		output_file << "Case #" << iter << ": " << min(number_of_moves, count_of_parts - in_order_count) << std::endl;
		delete [] other_particles;
	}
	
	return 0;
}