#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-7;


struct sVector2n
{
	long long x, y;
	sVector2n() {};
	sVector2n(const long long _x, const long long _y)  { x = _x;  y = _y; }; 
	sVector2n operator+(const sVector2n b)  { return sVector2n(x + b.x, y + b.y); };
	sVector2n operator-(const sVector2n b)  { return sVector2n(x - b.x, y - b.y); };
	sVector2n operator*(const int k)  { return sVector2n(x * k, y * k); };
};

long long gcd(long long a, long long b)
{
	return (b == 0)? a: gcd(b, a % b);	
}

inline long long Vec2Length2(const sVector2n &a)
{
	return a.x * a.x + a.y * a.y;
}


int H, W;
int D;

string g[32];
int ans;

vector <long long> sb;

int Work()
{
	cin >> H >> W >> D;

	D = D * D * 4;

	for (int i = 0; i < H; i ++)
		cin >> g[i];

	int xx = 0, yy = 0;

	for (int i = 0; i < H; i ++)
		for (int j = 0; j < W; j ++)
			if (g[i][j] == 'X')  
			{
				xx = i;  yy = j;
				break;
			}

	H -= 2;   W -= 2;

	ans = 0;

	sVector2n cen = sVector2n(yy * 2 - 1, (H - xx) * 2 + 1), base;

	H *= 2;  W *= 2;

	sb.clear();

	int d;
	for (int i = -155; i <= 155; i ++)
		for (int j = -155; j <= 155; j ++)
		{
			if (i == 0 && j == 0)  continue;
			base = sVector2n(i * W, j * H);
			base.x += (i % 2)? (W - cen.x): cen.x;
			base.y += (j % 2)? (H - cen.y): cen.y;

			base = base - cen;

			if (Vec2Length2(base) <= D)
			{
				d = gcd(abs(base.x), abs(base.y));
				base.x /= d;  base.y /= d;
				sb.push_back(base.x * 100000LL + base.y);
			}
		}

	sort(sb.begin(), sb.end());
	sb.erase(unique(sb.begin(), sb.end()), sb.end());

	ans = sb.size();
	
	return ans;
}

int main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int k = 1; k <= T; k ++)
		cout << "Case #" << k << ": " << Work() << endl;

	return 0;
}