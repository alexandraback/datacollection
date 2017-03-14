#include <cstdio>
#include <vector>
using namespace std;

struct Point
{
	int x, y;
	
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	
	// printing for debug
	void print()
	{
		printf("(%d, %d)\n", x, y);
	}
};

inline bool operator== (Point a, Point b)
{
	if (a.x == b.x && a.y == b.y) return true;
	return false;
}

bool are_equal(Point a, Point b) // used for comparing directions
{
	if (a.x == 0 && b.x == 0 && a.y * b.y > 0) return true;
	if (a.x == 0 && b.x == 0) return false;
	if (a.x == 0 || b.x == 0) return false;
	// x != 0
	if ((a.y * b.x == b.y * a.x) && (a.x * b.x > 0)) return true;
	return false;
}

inline int sq(int a)
{
	return a*a;
}

int square_dist(Point a, Point b)
{
	return (sq(b.x-a.x) + sq(b.y-a.y));
}

Point get_direction(Point a, Point b)
{
	return Point(b.x-a.x, b.y-a.y);
}

char line[32];
vector<Point> points;
vector<Point> directions;

bool used(Point dir)
{
	int s = directions.size();
	for (int i = 0; i < s; i++)
		if (are_equal(directions[i], dir))
			return true;
	return false;
}

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		int h, w, d;
		scanf("%d%d%d", &h, &w, &d);
		getchar();
		for (int i = 0; i < h; i++)
		{
			scanf("%s", line);
			for (int j = 0; j < w; j++)
				if (line[j] == 'X')
				{
					// add myself into the plane
					points.push_back(Point(2*(j-1)+1, 2*(h-1-i)-1));
				}
		}
		// scale * 2
		w = 2*(w-2);
		h = 2*(h-2);
		d = 2*d;
		
		// make 3 adjacent halls of mirrors
		int add_x = 2*(w-points[0].x);
		int add_y = 2*(h-points[0].y);
		points.push_back(Point(points[0].x + add_x, points[0].y));
		points.push_back(Point(points[0].x, points[0].y + add_y));
		points.push_back(Point(points[0].x + add_x, points[0].y + add_y));
		
		w *= 2;
		h *= 2;
		
		// copy these 4 points to another halls of mirrors (up and down)
		for (int total_h = 0; total_h < d; total_h += h)
		{
			// copy down
			for (int i = 0; i < 4; i++)
				points.push_back(Point(points[i].x, points[i].y - total_h - h));
			// copy up
			for (int i = 0; i < 4; i++)
				points.push_back(Point(points[i].x, points[i].y + total_h + h));
		}

		// copy all points to another halls of mirrors (left and right)
		int how_many = points.size();
		for (int total_w = 0; total_w < d; total_w += w)
		{
			// copy left
			for (int i = 0; i < how_many; i++)
				points.push_back(Point(points[i].x - total_w - w, points[i].y));
			// copy right
			for (int i = 0; i < how_many; i++)
				points.push_back(Point(points[i].x + total_w + w, points[i].y));
		}
		
		int answer = 0;
		int total_size = points.size();
		
		// chech how many points P satisfy: dist(myself, P) <= d
		for (int i = 1; i < total_size; i++)
		{
			int sq_dist = square_dist(points[0], points[i]);
			Point dir = get_direction(points[0], points[i]);
			if ((sq_dist <= d*d) && (!used(dir)))
			{
				directions.push_back(dir);
				//printf("DIR "); dir.print();
				answer++;
			}
		}
		printf("Case #%d: %d\n", nr, answer);
		//for (int i = 0; i < total_size; i++)
		//	points[i].print();
		
		points.clear();
		directions.clear();
	}
	return 0;
}
