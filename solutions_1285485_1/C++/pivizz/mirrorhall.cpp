#include <cmath>
#include <cstdio>

const int MAXROOM = 30;

int GCD(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    a = (a > 0 ? a : -a);
    b = (b > 0 ? b : -b);
	if (a == 0)
		return b;
	if (b == 0)
		return a;
    int c;
    if (a > b)
    {
        c = a;
        a = b;
        b = c;
    }
    while (a != 0)
    {
        c = b % a;
        b = a;
        a = c;
    }
    return b;
}

int NOC(int a, int b)
{
    return (a/GCD(a,b))*b;
}

struct Fraction
{
    Fraction()
    {
        x = 0;
        y = 1;
    }
    Fraction(int _x)
    {
        x = _x;
        y = 1;
    }
    Fraction(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool Positive() const
    {
        return x > 0;
    }
    bool Negative() const
    {
        return x < 0;
    }
    Fraction Abs() const
    {
        return Fraction(x > 0 ? x : -x, y);
    }
    Fraction Inverse() const
    {
        if (x > 0)
            return Fraction(y, x);
        else if (x < 0)
            return Fraction(-y, -x);
        throw;
    }
    operator double() const
    {
        return double(x)/y;
    }
    operator int() const
    {
        if (x > 0)
            return x / y;
        else if (x < 0)
            return (x - y + 1) / y;
        else
            return 0;
    }
    operator bool() const
    {
        return x != 0;
    }
	bool operator==(const int& i)
	{
		return y * i == x;
	}
	bool Equals(const Fraction& g) const
	{
	    return x * g.y == g.x * y;
	}
	bool Greater(const Fraction& g) const
	{
	    return x * g.y > g.x * y;
	}
	bool Less(const Fraction& g) const
	{
	    return x * g.y < g.x * y;
	}
    int x, y;
};

Fraction operator+(const Fraction& f, const Fraction& g)
{
    int noc = NOC(f.y, g.y);
    int cf = noc / f.y;
    int cg = noc / g.y;
    return Fraction(f.x * cf + g.x * cg, noc);
}
Fraction operator-(const Fraction& f, const Fraction& g)
{
    int noc = NOC(f.y, g.y);
    int cf = noc / f.y;
    int cg = noc / g.y;
    return Fraction(f.x * cf - g.x * cg, noc);
}
Fraction operator-(const Fraction& f)
{
    return Fraction(-f.x, f.y);
}
Fraction operator*(const Fraction& f, const Fraction& g)
{
	if (f.x == 0 || g.x == 0)
		return Fraction(0, 1);
    int y = f.y * g.y;
    int x = f.x * g.x;
    int gcd = GCD(x, y);
    return Fraction(x/gcd, y/gcd);
}
Fraction operator/(const Fraction& f, const Fraction& g)
{
    return f * g.Inverse();
}

Fraction Min(const Fraction& f, const Fraction& g)
{
    return f.Greater(g) ? g : f;
}


Fraction INF(10000000);
Fraction F1(1);

bool trace(bool room[MAXROOM][MAXROOM], Fraction you_x, Fraction you_y, Fraction dir_x, Fraction dir_y, int D)
{
    Fraction x = you_x;
    Fraction y = you_y;
    Fraction dx = dir_x;
    Fraction dy = dir_y;
    Fraction dist(0);
    double velocity = sqrt(double(dx*dx + dy*dy));
    while (double(dist) * velocity < D)
    {
        Fraction x_d = x - Fraction(int(x));
        Fraction y_d = y - Fraction(int(y));
        Fraction x_t = INF;
        Fraction y_t = INF;
        Fraction you_t = INF;
        if (dx.Positive())
            x_d = F1 - x_d;
        if (dy.Positive())
            y_d = F1 - y_d;
        if (x_d == 0)
            x_d = 1;
        if (y_d == 0)
            y_d = 1;
        if (dx)
            x_t = x_d / dx.Abs();
        if (dy)
            y_t = y_d / dy.Abs();
        Fraction t = Min(x_t, y_t);
        Fraction dir_you_x = you_x - x;
        Fraction dir_you_y = you_y - y;
        
        if ((dir_you_y * dx).Equals(dir_you_x * dy))
        {
            you_t = bool(dx) ? dir_you_x / dx : dir_you_y / dy;
            if (you_t.Positive() && you_t.Less(t))
                return double(dist + you_t) * velocity <= D;
        }
        x = x + dx*t;
        y = y + dy*t;
        dist = dist + t;
		if (x_t.Equals(y_t))
        {
            int xi = int(x);
            int yi = int(y);
            bool m22 = room[xi][yi];
            bool m11 = room[xi-1][yi-1];
            bool m12 = room[xi][yi-1];
            bool m21 = room[xi-1][yi];
            int msum = m11 + m12 + m21 + m22;
            if (msum >= 3)
            {
                //# corner mirror
                dx = -dx;
                dy = -dy;
            }
            else if (msum == 2)
            {
                if (m11 ^ m22)
                {
                    //#mirror wall
                    if ((m11 && m12) || (m21 && m22))
                        //#horizontal mirror
                        dy = -dy;
                    else
                        //#vertical mirror
                        dx = -dx;
                }
                //else
                //    //# edge passing - no direction change
                //   ;
            }
            else if (msum == 1)
            {
                if ((dx.Positive() && dy.Positive() && m22) ||
                    (dx.Negative() && dy.Positive() && m21) ||
                    (dx.Positive() && dy.Negative() && m12) ||
                    (dx.Negative() && dy.Negative() && m11))
                    //# dead end
                    return false;
            }
        }
        else if (x_t.Less(y_t))
        {
            int xi = int(x);
            int yi = int(y);
            bool mL = room[xi-1][yi];
            bool mR = room[xi][yi];
            if (mL || mR)
                dx = -dx;
        }
        else
        {
            int xi = int(x);
            int yi = int(y);
            bool mU = room[xi][yi];
            bool mD = room[xi][yi-1];
            if (mU || mD)
                dy = -dy;
        }
    }
    return false;
}

int solve(bool room[MAXROOM][MAXROOM], int you_i, int you_j, int D)
{
    Fraction you_x(2*you_i+1,2);
    Fraction you_y(2*you_j+1,2);
    int res = 0;
    for (int x = -D; x <= D; x++)
        for (int y = -D; y <= D; y++)
        {
            if (GCD(x, y) == 1 && trace(room, you_x, you_y, Fraction(x), Fraction(y), D))
                res += 1;
        }
    return res;
}

int main()
{
    bool room[MAXROOM][MAXROOM];
	char buf[1024];
    FILE* f = fopen("inLA.txt", "r");
	FILE* g = fopen("outLA.txt", "w");
	int T = 0;
	fgets(buf, 1024, f);
	sscanf(buf, "%i", &T);

    for (int i = 1; i <= T; i++)
	{
		fgets(buf, 1024, f);
        int H, W, D;
		sscanf(buf, "%i %i %i", &H, &W, &D);
		int you_i = 0, you_j = 0;
        for (int j = 0; j < H; j++)
		{
			fgets(buf, 1024, f);
			for (int k = 0; k < W; k++)
			{
				room[j][k] = (buf[k] == '#');
				if (buf[k] == 'X')
				{
					you_i = j;
					you_j = k;
				}
			}
		}
        int res = solve(room, you_i, you_j, D);
		fprintf(g, "Case #%i: %i\n", i, res);
	}

	fclose(f);
	fclose(g);
}