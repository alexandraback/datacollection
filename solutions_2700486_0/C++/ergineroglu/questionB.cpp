#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// FALLING DIAMONDS

int main(void)
{
	ifstream input_file;
	input_file.open("QuestionB/B-small-attempt0.in");
	//input_file.open("QuestionB/input.in");

	ofstream output_file;
	output_file.open("QuestionB/B-small-attempt0.out", std::ios_base::trunc);
	//output_file.open("QuestionB/output.out", std::ios_base::trunc);

	int game_count;
	input_file >> game_count;
	for(int iter = 1; iter <= game_count; iter++)
	{
		int diamonds;
		int pos_x;
		int pos_y;

		input_file >> diamonds >> pos_x >> pos_y;

		// left outer
		int left_outer_x = 0;
		int left_outer_y = 0;

		// right outer
		int right_outer_x = 0;
		int right_outer_y = 0;

		float probability = 0;
		if(pos_x == 0 && pos_y == 0)
		{
			probability = 1.0;
		}
		else if((pos_x == 2 && pos_y == 0) || (pos_x == -2 && pos_y == 0))
		{
			if(diamonds == 2) probability = 0.5;
			if(diamonds == 3) probability = 0.75;
			else if(diamonds > 3) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 1 && pos_y == 1) || (pos_x == -1 && pos_y == 1))
		{
			if(diamonds == 3) probability = 0.25;
			else if(diamonds == 4) probability = 0.5;
			else if(diamonds > 4) probability = 1.0;
			else probability = 0;
		}
		else if(pos_x == 0 && pos_y == 2)
		{
			if(diamonds >= 5) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 4 && pos_y == 0) || (pos_x == -4 && pos_y == 0))
		{
			if(diamonds == 7) probability = 0.5;
			else if(diamonds == 8) probability = 0.75;
			else if(diamonds == 9) probability = 0.875;
			else if(diamonds == 10) probability = (15.0 / 16.0);
			else if(diamonds > 10) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 3 && pos_y == 1) || (pos_x == -3 && pos_y == 1))
		{
			if(diamonds == 8) probability = 0.25;
			else if(diamonds == 9) probability = (4.0 / 8.0);
			else if(diamonds == 10) probability = (11.0 / 16.0);
			else if(diamonds == 11) probability = (7.0 / 8.0);
			else if(diamonds > 11) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 2 && pos_y == 2) || (pos_x == -2 && pos_y == 2))
		{
			if(diamonds == 9) probability = 0.125;
			else if(diamonds == 10) probability = (5.0 / 16.0);
			else if(diamonds == 11) probability = 0.5;
			else if(diamonds == 12) probability = 0.75;			
			else if(diamonds > 12) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 1 && pos_y == 3) || (pos_x == -1 && pos_y == 3))
		{
			if(diamonds == 10) probability = (1.0 / 16.0);
			else if(diamonds == 11) probability = (1.0 / 8.0);
			else if(diamonds == 12) probability = 0.25;
			else if(diamonds == 13) probability = 0.5;			
			else if(diamonds > 13) probability = 1.0;
			else probability = 0;
		}
		else if(pos_x == 0 && pos_y == 4)
		{
			if(diamonds >= 15) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 6 && pos_y == 0) || (pos_x == -6 && pos_y == 0))
		{
			if(diamonds == 16) probability = 0.5;
			else if(diamonds == 17) probability = 0.75;
			else if(diamonds == 18) probability = 0.875;
			else if(diamonds == 19) probability = (15.0 / 16.0);
			else if(diamonds == 20) probability = (31.0 / 32.0);
			else if(diamonds > 10) probability = 1.0;
			else probability = 0;
		}
		else if((pos_x == 5 && pos_y == 1) || (pos_x == -5 && pos_y == 1))
		{
			if(diamonds == 17) probability = 0.25;
			else if(diamonds == 18) probability = (4.0 / 8.0);
			else if(diamonds == 19) probability = (11.0 / 16.0);
			else if(diamonds == 20) probability = (7.0 / 8.0);
			else probability = 0;
		}
		else if((pos_x == 4 && pos_y == 2) || (pos_x == -4 && pos_y == 2))
		{
			if(diamonds == 18) probability = 0.125;
			else if(diamonds == 19) probability = (5.0 / 16.0);
			else if(diamonds == 20) probability = 0.5;
			else probability = 0;
		}
		else if((pos_x == 3 && pos_y == 3) || (pos_x == -3 && pos_y == 3))
		{
			if(diamonds == 19) probability = (1.0 / 16.0);
			else if(diamonds == 20) probability = (6.0 / 32.0);
			else probability = 0;
		}
		else if((pos_x == 2 && pos_y == 4) || (pos_x == -2 && pos_y == 4))
		{
			if(diamonds == 20) probability = (1.0 / 32.0);			
			else probability = 0;
		}
		
		output_file << "Case #" << iter << ": " << probability << std::endl;
	}
	
	return 0;
}