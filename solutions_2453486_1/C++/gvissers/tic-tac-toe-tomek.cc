#include <fstream>
#include <iostream>
#include <stdexcept>

class Board
{
public:
	Board(): _cells() {}

	std::istream& scan(std::istream& is)
	{
		_cells.clear();
		std::string line;
		for (int i = 0; i < 4; ++i)
		{
			is >> line;
			if (line.size() != 4)
				throw std::runtime_error("Invalid board row");
			_cells += line;
		}
		return is;
	}

	std::string status() const
	{
		char winner = '\0';

		for (char player : "XO")
		{
			for (int i = 0; i < 4; ++i)
			{
				if ((_cells[i] == player || _cells[i] == 'T')
					&& (_cells[i+4] == player || _cells[i+4] == 'T')
					&& (_cells[i+8] == player || _cells[i+8] == 'T')
					&& (_cells[i+12] == player || _cells[i+12] == 'T'))
				{
					winner = player;
					goto done;
				}
				if ((_cells[4*i] == player || _cells[4*i] == 'T')
					&& (_cells[4*i+1] == player || _cells[4*i+1] == 'T')
					&& (_cells[4*i+2] == player || _cells[4*i+2] == 'T')
					&& (_cells[4*i+3] == player || _cells[4*i+3] == 'T'))
				{
					winner = player;
					goto done;
				}
			}
			if ((_cells[0] == player || _cells[0] == 'T')
				&& (_cells[5] == player || _cells[5] == 'T')
				&& (_cells[10] == player || _cells[10] == 'T')
				&& (_cells[15] == player || _cells[15] == 'T'))
			{
				winner = player;
				goto done;
			}
			if ((_cells[3] == player || _cells[3] == 'T')
				&& (_cells[6] == player || _cells[6] == 'T')
				&& (_cells[9] == player || _cells[9] == 'T')
				&& (_cells[12] == player || _cells[12] == 'T'))
			{
				winner = player;
				goto done;
			}
		}
done:
		if (winner)
			return winner == 'X' ? "X won" : "O won";
		if (_cells.find('.') != std::string::npos)
			return "Game has not completed";
		return "Draw";
	}

private:
	std::string _cells;
};

std::istream& operator>>(std::istream& is, Board& board)
{
	return board.scan(is);
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input-file>\n";
		return 1;
	}

	std::ifstream is(argv[1]);
	if (!is.good())
	{
		std::cerr << "Unable to open input file " << argv[1] << "\n";
		return 1;
	}

	int nr_cases;
	is >> nr_cases;
	if (!is.good())
	{
		std::cerr << "Failed to read number of test cases\n";
		return 1;
	}

	Board board;
	for (int icase = 1; icase <= nr_cases; ++icase)
	{
		is >> board;
		std::cout << "Case #" << icase << ": " << board.status() << '\n';
	}

	return 0;
}
