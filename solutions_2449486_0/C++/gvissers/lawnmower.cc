#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

class Lawn
{
public:
	Lawn(): _width(0), _height(0), _lens() {}

	int width() const { return _width; }
	int height() const { return _height; }
	int length(int i, int j) const { return _lens[i*width()+j]; }

	std::istream& scan(std::istream& is)
	{
		is >> _height >> _width;
		_lens.clear();
		std::copy_n(std::istream_iterator<int>(is), width()*height(),
			std::back_inserter(_lens));
		return is;
	}

	bool possible()
	{
		if (*std::max_element(_lens.begin(), _lens.end()) > 100)
			return false;
		if (*std::min_element(_lens.begin(), _lens.end()) < 1)
			return false;

		std::vector<int> row_lens(height(), 0), col_lens(width(), 0);
		for (int i = 0; i < height(); ++i)
		{
			for (int j = 0; j < width(); ++j)
			{
				int l = length(i, j);
				if (l > row_lens[i])
					row_lens[i] = l;
				if (l > col_lens[j])
					col_lens[j] = l;
			}
		}

		std::vector<int> lens2(width()*height(), 100);
		for (int i = 0; i < height(); ++i)
		{
			for (int j = 0; j < width(); ++j)
			{
				if (length(i, j) != std::min(row_lens[i], col_lens[j]))
					return false;
			}
		}

		return true;
	}

private:
	int _width;
	int _height;
	std::vector<int> _lens;
};

std::istream& operator>>(std::istream& is, Lawn &lawn)
{
	return lawn.scan(is);
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

	Lawn lawn;
	for (int icase = 1; icase <= nr_cases; ++icase)
	{
		is >> lawn;
		std::cout << "Case #" << icase << ": "
			<< (lawn.possible() ? "YES" : "NO") << '\n';
	}

	return 0;
}
