#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

FILE *output = 0;

typedef struct tag_TestCase
{
	int id;
	int height;
	int width;
	int mines;
	int cells_to_be_free;
} TestCase;

typedef struct tag_Point
{
	int y;
	int x;

	tag_Point();

	tag_Point(int y_value, int x_value) :
		y(y_value),
		x(x_value)
	{
	}

	tag_Point(const tag_Point &source) :
		y(source.y),
		x(source.x)
	{
	}
} Point;

typedef struct tag_Map
{
	int height;
	int width;
	int free_cells;
	std::vector<char> map;
	std::vector<Point> perimeter;

	tag_Map();
	tag_Map(int h, int w):
		height(h),
		width(w),
		free_cells(0),
		map(h * w, false),
		perimeter()
	{
	}

	tag_Map(const tag_Map &source):
		height(source.height),
		width(source.width),
		free_cells(source.free_cells),
		map(source.map),
		perimeter(source.perimeter)
	{
	}

	bool inline get_cell_is_free(int y, int x)
	{
		return *(map.begin() + (y * width + x));
	}

	void inline set_cell_is_free(int y, int x)
	{
		if (!get_cell_is_free(y, x))
			++free_cells;
		*(map.begin() + (y * width + x)) = true;
	}

	void grow(int perimeter_cell)
	{
		Point perimeter_point = perimeter.at(perimeter_cell);
		perimeter.erase(perimeter.begin() + perimeter_cell);
		for (int dy = -1; dy <= 1; ++dy)
		{
			int y = perimeter_point.y + dy;
			if (y < 0 || y >= height)
				continue;
			for (int dx = -1; dx <= 1; ++dx)
			{
				if (dy == 0 && dx == 0)
					continue;
				int x = perimeter_point.x + dx;
				if (x < 0 || x >= width)
					continue;
				if (get_cell_is_free(y, x))
					continue;
				set_cell_is_free(y, x);
				perimeter.push_back(Point(y, x));
			}
		}
	}
} Map;

void output_map(Map &map)
{
	for (int y = 0; y < map.height; ++y)
	{
		for (int x = 0; x < map.width; ++x)
		{
			if (y == 0 && x == 0)
				fprintf(output, "c");
			else if (map.get_cell_is_free(y, x))
				fprintf(output, ".");
			else
				fprintf(output, "*");
		}
		fprintf(output, "\n");
	}
}

bool grow(TestCase test_case, Map map)
{
	if (map.free_cells == test_case.cells_to_be_free)
	{
		output_map(map);
		return true;
	}
	if (map.free_cells > test_case.cells_to_be_free)
		return false;
	for (int i = 0; i < map.perimeter.size(); ++i)
	{
		Map new_map(map);
		new_map.grow(i);
		if (grow(test_case, new_map))
			return true;
	}
	return false;
}

void solve_test_case(TestCase test_case, FILE *output)
{
	test_case.cells_to_be_free = test_case.height * test_case.width - test_case.mines;
	Map map(test_case.height, test_case.width);
	int side = std::max(0, std::min(std::min(test_case.height, test_case.width), (int)std::sqrt(test_case.cells_to_be_free)) - 2);
	if (side > 1)
	{
		for (int y = 0; y < side; ++y)
			for (int x = 0; x < side; ++x)
				map.set_cell_is_free(y, x);
		for (int i = 0; i < side - 1; ++i)
		{
			map.perimeter.push_back(Point(side - 1, i));
			map.perimeter.push_back(Point(i, side - 1));
		}
		map.perimeter.push_back(Point(side - 1, side - 1));
	}
	else
	{
		map.set_cell_is_free(0, 0);
		map.perimeter.push_back(Point(0, 0));
	}
	fprintf(output, "Case #%d:\n", test_case.id);
	if (!grow(test_case, map))
		fprintf(output, "Impossible\n");
}

void main()
{
	FILE *input = fopen("IO/input.txt", "rt");
	output = fopen("IO/output.txt", "wt");
	int t = 0;
	fscanf(input, "%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		TestCase test_case;
		test_case.id = i;
		fscanf(input, "%d %d %d", &test_case.height, &test_case.width, &test_case.mines);
		solve_test_case(test_case, output);
	}
	fclose(output);
	fclose(input);
}