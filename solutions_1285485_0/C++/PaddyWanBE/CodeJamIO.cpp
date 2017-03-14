#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;
using std::pair;

class CodeJamIO
{
	private:

		string append(const char* a, const char* b)
		{
			string c(a);
			c += b;
			return c;
		}
	public:

		CodeJamIO(const char* naam) : sc(append(naam, ".in").c_str()), ps(append(naam, ".out").c_str())
		{
			if(!sc.is_open() || !ps.is_open())
				throw "foutje";
			index = 0;
			sc >> size;
			//init
			next();
		}

		virtual ~CodeJamIO()
		{
		}

		void print()
		{
			ps << "Case #" << index << ": " << ss.str() << std::endl;
			ss.str("");
		}

		bool hasMore()const
		{
			return index < size;
		}

		void close()
		{
			sc.close();
			ps.close();
		}

	private:
		ifstream sc;
		ofstream ps;
		stringstream ss;
		int index;
		int size;

	public:

		void next()
		{
			//data
			int h;
			char c;
			sc >> h >> b >> l;
			matrix = new bool[b*h];
			for(int y = 0; y < h; y++)
			for(int x = 0; x < b; x++)
				{
					sc >> c;
					if(c == 'X')
					{
						ix = x;
						iy = y;
					}
					matrix[x+y*b] = (c =='#');
				}
			//end data
			index++;
		}

		void solve()
		{
			//calc
			const int kwl = l*l;
			if(l>=1)
			{
				int opl = 0;
				hoek.push_back(pair<int, int>(1,0));
				int x = 1;
				while(((x*x+1)) <= kwl)
				{
					int y = 1;
					while(((x*x+y*y)) <= kwl)
					{
						if(ggd(x,y)==1)
							hoek.push_back(pair<int, int>(x,y));
						y++;
					}
					x++;
				}
				for(int i = hoek.size()-1; i >= 0; i--)
				{
					//x,y
					if(ga(ix, iy, hoek[i].first, hoek[i].second))
						opl++;
					//-y,x
					if(ga(ix, iy, -hoek[i].second, hoek[i].first))
						opl++;
					//-x,-y
					if(ga(ix, iy, -hoek[i].first, -hoek[i].second))
						opl++;
					//y,-x
					if(ga(ix, iy, hoek[i].second, -hoek[i].first))
						opl++;
				}
				ss<<opl;
			}
			else
			{
				ss<<0;
			}
			hoek.clear();
			delete[] matrix;
			print();
		}
	private:
		//data
		int ix;
		int iy;
		int l;
		bool* matrix;
		int b;
		vector<pair<int,  int> > hoek;

		bool ga(int hx, int hy, int dx, int dy)
		{
			const int kwl = l*l;
			int sdx = abs(dx);
			int sdy = abs(dy);
			const int dadx = 2*sdx;
			const int dady = 2*sdy;
			while((sdx*sdx+sdy*sdy) <= kwl)
			{
				int sx = 1;
				int sy = 1;
				while((sx < dadx || dx == 0) && (sy < dady || dy==0))
				{
					if(sx *dady == sy*dadx)
					{//we gaan over een hoek
						int nx = hx + (dx>0?1:-1);
						int ny= hy+(dy>0?1:-1);
						if(isMuur(nx,ny))
						{
							if(isMuur(nx,hy))
							{
								dx=-dx;
								if(isMuur(hx,ny))
								{//terkaatsen
									dy=-dy;
								}
								else
								{//weerkaatsen op x
									hy = ny;
								}
							}
							else if(isMuur(hx,ny))
							{//weerkaatsen op enkel y
								dy=-dy;
								hx=nx;
							}
							else
								return false;
						}
						else
						{
							hy = ny;
							hx=nx;
						}
						sx+=2;
						sy+=2;
					}
					else if(sx *dady < sy*dadx)
					{//we moeten 1 verder x
						int nx = hx + (dx>0?1:-1);
						if(isMuur(nx,hy))//we botsen
							dx=-dx;
						else
							hx=nx;
						sx+=2;
					}
					else
					{//we moeten 1 verder y
						int ny=hy+(dy>0?1:-1);
						if(isMuur(hx,ny))
							dy=-dy;
						else
							hy=ny;
						sy+=2;
					}
				}
				while(sx < dadx)
				{
					int nx = hx + (dx>0?1:-1);
					if(isMuur(nx,hy))//we botsen
						dx=-dx;
					else
						hx=nx;
					sx+=2;
				}
				while(sy < dady)
				{
					int ny=hy+(dy>0?1:-1);
					if(isMuur(hx,ny))
						dy=-dy;
					else
						hy=ny;
					sy+=2;
				}
				sdx += abs(dx);
				sdy += abs(dy);
				if(hx == ix && hy == iy)
					return true;
			}
			return false;
		}

		bool isMuur(int x, int y)
		{
			return matrix[x+y*b];
		}
		
		int ggd(int a, int b)
		{
			int rest;
			while(b != 0)
			{
				rest = a % b;
				a = b;
				b = rest;
			}
			return a;
		}
};

using namespace std;

int main()
{
	CodeJamIO cd("D-small-attempt0");
	cd.solve();
	while(cd.hasMore())
	{
		cd.next();
		cd.solve();
	}
	cd.close();
	return 0;
}
