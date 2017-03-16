#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>

using namespace std;

template<int N>
int FirstBit(const bitset<N> &s, bool value)
{
	for(int i = 0; i < N; ++i)
		if(s[i] == value)
			return i;

	return -1;
}

template<class T>
struct array2d
{
	vector<T> data;
	int rows, columns;

	array2d() {}

	array2d(int size):rows(size), columns(size)
	{
		data.resize(rows * columns);
	}

	array2d(int _rows, int _columns):rows(_rows), columns(_columns)
	{
		data.resize(rows * columns);
	}

	typename vector<T>::iterator operator[](int r)
	{
		return data.begin() + r * columns;
	}
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

struct Angle
{
	int xd, yd;

	bool operator ==(const Angle& a) const
	{
		if(sgn(xd) != sgn(a.xd) || sgn(yd) != sgn(a.yd))
			return false;

		return xd * a.yd == yd * a.xd;
	}

	bool operator<(const Angle& a) const
	{
		if(*this == a)
			return false;

		return atan2((double)a.yd, a.xd) - atan2((double)yd, xd) < 0;
	}

	int L2()
	{
		return xd * xd + yd * yd;
	}
};

struct Sector
{
	Angle a1, a2;

	bool Within(Angle &p)
	{
		return a1 < p && p < a2;
	}
};

struct Transform
{
	int xm, ym, xt, yt;
	bool rotate;

	int Get(array2d<int> &map, int mx, int my)
	{
		if(rotate)
			return map[yt + my * ym][xt + mx * xm];

		return map[mx * xm + xt][my * ym + yt];
	}

	void Reflect(int mx, int my, const int dir[2])
	{
		if(dir[0] != 0)
		{
			xt = xt + 2 * xm * mx + dir[0] * xm;
			xm = -xm;
		}
		else
		{
			yt = yt + 2 * ym * my + dir[1] * ym;
			ym = -ym;
		}
	}
};


struct Square
{
	Angle corners[4], center;
	Sector sides[3];

	Square(int mx, int my)
	{
		corners[0].xd = mx * 2 - 1; corners[0].yd = my * 2 - 1;
		corners[1].xd = mx * 2 - 1; corners[1].yd = my * 2 + 1;
		corners[2].xd = mx * 2 + 1; corners[2].yd = my * 2 + 1;
		corners[3].xd = mx * 2 + 1; corners[3].yd = my * 2 - 1;

		center.xd = mx * 2;
		center.yd = my * 2;

		for(int i = 0; i < 3; ++i)
		{
			sides[i].a1 = corners[i];
			sides[i].a2 = corners[i + 1];
		}
	}

	int L2()
	{
		return min(corners[0].L2(), corners[1].L2());
	}
};

const	int castDirs[][2] = {{-1, 0}, {0, 1}, {1, 0}};

void RayCast(array2d<int> &map, int D2, Angle ray, int mx, int my, Transform tr, vector<Angle> &reflections)
{
	Square s(mx, my);

	if(s.L2() > D2)
		return;

	if(s.center == ray && tr.Get(map, mx, my) == 2 && s.center.L2() > 0 && s.center.L2() <= D2)
		reflections.push_back(s.center);

	if(s.corners[1] == ray)
	{
		bool top = tr.Get(map, mx, my + 1) == 1, topLeft = tr.Get(map, mx - 1, my + 1) == 1, left = tr.Get(map, mx - 1, my) == 1;
		int cmx = mx - 1, cmy = my + 1;
		Transform ctr = tr;
		if(top && topLeft && left)
		{
			if(s.corners[1].L2() * 4 <= D2)
				reflections.push_back(s.corners[1]);
		}
		else if(top && topLeft && !left)
		{
			ctr.Reflect(mx, my, castDirs[1]);
			RayCast(map, D2, ray, cmx, cmy, ctr, reflections);
		}
		else if(!topLeft)
			RayCast(map, D2, ray, cmx, cmy, tr, reflections);
		else if(left && topLeft && !top)
		{
			ctr.Reflect(mx, my, castDirs[0]);
			RayCast(map, D2, ray, cmx, cmy, ctr, reflections);
		}
	}

	if(s.corners[2] == ray)
	{
		bool top = tr.Get(map, mx, my + 1) == 1, topRight = tr.Get(map, mx + 1, my + 1) == 1, right = tr.Get(map, mx + 1, my) == 1;
		int cmx = mx + 1, cmy = my + 1;
		Transform ctr = tr;
		if(top && topRight && right)
		{
			if(s.corners[2].L2() * 4 <= D2)
				reflections.push_back(s.corners[2]);
		}
		else if(top && topRight && !right)
		{
			ctr.Reflect(mx, my, castDirs[1]);
			RayCast(map, D2, ray, cmx, cmy, ctr, reflections);
		}
		else if(!topRight)
			RayCast(map, D2, ray, cmx, cmy, tr, reflections);
		else if(right && topRight && !top)
		{
			ctr.Reflect(mx, my, castDirs[2]);
			RayCast(map, D2, ray, cmx, cmy, ctr, reflections);
		}
	}

	for(int i = 0; i < 3; ++i)
		if(s.sides[i].Within(ray))
		{
			int cmx = mx + castDirs[i][0], cmy = my + castDirs[i][1];
			Transform ctr = tr;
			if(tr.Get(map, cmx, cmy) == 1)
				ctr.Reflect(mx, my, castDirs[i]);

			RayCast(map, D2, ray, cmx, cmy, ctr, reflections);
		}
}

void SectorCast(array2d<int> &map, int D2, Sector sec, int mx, int my, Transform tr, vector<Angle> &reflections)
{
	Square s(mx, my);

	if(s.L2() >= D2)
		return;

	if(tr.Get(map, mx, my) == 2 && s.center.L2() > 0 && s.center.L2() <= D2 && sec.Within(s.center))
		reflections.push_back(s.center);


	for(int i = 0; i < 3; ++i)
	{
		Sector cast;
		cast.a1 = s.sides[i].a1 < sec.a1 ? sec.a1 : s.sides[i].a1;
		cast.a2 = s.sides[i].a2 < sec.a2 ? s.sides[i].a2 : sec.a2;

		if(!(cast.a1 < cast.a2))
			continue;

		int cmx = mx + castDirs[i][0], cmy = my + castDirs[i][1];
		Transform ctr = tr;
		if(tr.Get(map, cmx, cmy) == 1)
			ctr.Reflect(mx, my, castDirs[i]);

		SectorCast(map, D2, cast, cmx, cmy, ctr, reflections);
	}

	if(sec.Within(s.corners[1]))
		RayCast(map, D2, s.corners[1], mx, my, tr, reflections);

	if(sec.Within(s.corners[2]))
		RayCast(map, D2, s.corners[2], mx, my, tr, reflections);
}

void SolveCase()
{
	int H, W, D;
	cin >> H >> W >> D >> ws;
	array2d<int> map(W, H);
	int charX, charY;
	for(int y = 0; y < H; ++y)
		for(int x = 0; x < W; ++x)
		{
			char c;
			cin >> c;
			map[x][y] = c == '.' ? 0 : c == '#' ? 1 : 2;
			if(map[x][y] == 2)
			{
				charX = x;
				charY = y;
			}
		}

	Sector initial;
	initial.a1.xd = -1; initial.a1.yd = 1;
	initial.a2.xd = 1; initial.a2.yd = 1;
	Transform tr;
	set<Angle> reflections;
	for(int i = 0; i < 4; ++i)
	{
		switch(i)
		{
		case 0:
			tr.xt = charX; tr.yt = charY;
			tr.rotate = false;
			tr.xm = 1;
			tr.ym = 1;
			break;
		case 1:
			tr.yt = charX; tr.xt = charY;
			tr.rotate = true;
			tr.xm = -1;
			tr.ym = 1;
			break;
		case 2:
			tr.xt = charX; tr.yt = charY;
			tr.rotate = false;
			tr.xm = -1;
			tr.ym = -1;
			break;
		case 3:
			tr.yt = charX; tr.xt = charY;
			tr.rotate = true;
			tr.xm = 1;
			tr.ym = -1;
			break;
		}

		vector<Angle> castRefs;
		int D2 = D * D * 4;
		SectorCast(map, D2, initial, 0, 0, tr, castRefs);
		RayCast(map, D2, initial.a1, 0, 0, tr, castRefs);
		if(i == 1)
			RayCast(map, D2, initial.a2, 0, 0, tr, castRefs);
		for(int j = 0; j < castRefs.size(); ++j)
		{
			if(i == 2)
			{
				castRefs[j].yd *= -1;
				castRefs[j].xd *= -1;
			}
			else if(i == 1)
			{
				int x = castRefs[j].xd;
				castRefs[j].xd = castRefs[j].yd;
				castRefs[j].yd = -x;
			}
			else if(i == 3)
			{
				int x = castRefs[j].xd;
				castRefs[j].xd = -castRefs[j].yd;
				castRefs[j].yd = x;
			}
		}

		reflections.insert(castRefs.begin(), castRefs.end());
	}

	cout << reflections.size();
}

void main()
{
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		SolveCase();
		cout << endl;
	}
}