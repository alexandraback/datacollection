#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Board
{
	public:
		unsigned int
			width,
			height,
			right,
			top;
		vector<unsigned int>
			rows,
			cols;
		
		Board(unsigned int w, unsigned int h) :
			width(w),
			height(h),
			right(w - 1),
			top(h - 1),
			rows(h, 0),
			cols(w, 0)
		{ }
		unsigned int get_row()
		{
			return width - rows[top];
		}
		unsigned int get_col()
		{
			return height - cols[right];
		}
		void peel_row(unsigned int m)
		{
			for (unsigned int i = 0; i < m; ++i)
			{
				if (cols[right - i] < height)
					++cols[right - i];
			}
			rows[top] += m;
			--top;
		}
		void peel_col(unsigned int m)
		{
			for (unsigned int i = 0; i < m; ++i)
			{
				if (rows[top - i] < width)
					++rows[top - i];
			}
			cols[right] += m;
			--right;
		}
		void print()
		{
			for (unsigned int i = 0; i < height; ++i)
			{
				for (unsigned int j = 0; j < width; ++j)
				{
					if (i == 0 && j == 0)
						cout << 'c';
					else if (i >= height - cols[j])
						cout << '*';
					else
						cout << '.';
				}
				cout << endl;
			}
		}
};

void solve(unsigned int x, unsigned int y, unsigned int m)
{
	if (m >= x * y)
	{
		cout << "Impossible" << endl;
		return;
	}
	
	Board board (x, y);
	
	while (m)
	{
		if (board.right == 1 && board.top == 1)
		{
			if (m != 0 && m != 3)
			{
				cout << "Impossible" << endl;
				return;
			}
			
			if (m == 3)
			{
				board.peel_row(2);
				board.peel_col(1);
				m = 0;
			}
		}
		else if (board.right > board.top)
		{
			// peel y
			unsigned int
				over_peel = board.get_col(),
				under_peel = (over_peel > 2 ? over_peel - 2 : 0);
			
			if (m < under_peel)
				under_peel = m;
			
			if (over_peel && m >= over_peel)
			{
				board.peel_col(over_peel);
				m -= over_peel;
			}
			else if (under_peel)
			{
				board.peel_col(under_peel);
				m -= under_peel;
			}
			else
			{
				cout << "Impossible" << endl;
				return;
			}
		}
		else
		{
			// peel x
			unsigned int
				over_peel = board.get_row(),
				under_peel = (over_peel > 2 ? over_peel - 2 : 0);
			
			if (m < under_peel)
				under_peel = m;
			
			if (over_peel && m >= over_peel)
			{
				board.peel_row(over_peel);
				m -= over_peel;
			}
			else if (under_peel)
			{
				board.peel_row(under_peel);
				m -= under_peel;
			}
			else
			{
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	
	board.print();
}

int main()
{
	unsigned int count = 0;
	
	cin >> count;
	
	for (unsigned int i = 0; i < count; ++i)
	{
		unsigned int
			y = 0,
			x = 0,
			m = 0;
		
		cin >> y >> x >> m;
		
		cout << "Case #" << (i + 1) << ":" << endl;
		solve(x, y ,m);
	}
	
	return 0;
}
