#include<iostream>

namespace codejam
{
	bool checkup(int**arr, int m, int n, int i, int j)
	{
		int thisval = arr[i][j];
		int up = i;
		while(up >= 0)
		{
			if(arr[up][j] > thisval)
			{
				return false;
			}
			up--;
		}
		return true;
	}
	bool checkdown(int**arr, int m, int n, int i, int j)
	{
		int thisval = arr[i][j];
		int down = i;
		while(down < m)
		{
			if(arr[down][j] > thisval)
			{
				return false;
			}
			down++;
		}
		return true;
	}
	bool checkleft(int**arr, int m, int n, int i, int j)
	{
		int thisval = arr[i][j];
		int left = j;
		while(left >= 0)
		{
			if(arr[i][left] > thisval)
			{
				return false;
			}
			left--;
		}
		return true;
	}
	bool checkright(int**arr, int m, int n, int i, int j)
	{
		int thisval = arr[i][j];
		int right = j;
		while(right < n)
		{
			if(arr[i][right] > thisval)
			{
				return false;
			}
			right++;
		}
		return true;
	}
	void lawnmower()
	{
		int cases;
		std::cin>>cases;
		for(int cs = 1; cs <= cases; cs++)
		{
			int m,n;
			std::cin>>m>>n;
			int** arr = new int*[m];
			for(int i = 0 ; i < m; i++)
				arr[i] = new int[n];
			for(int i  = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
				{
					std::cin>>arr[i][j];
				}
			}
			bool canbedone = true;
			for(int i = 0; i < m; i++)
			{
				bool found = false;
				for(int j = 0; j < n; j++)
				{
					bool vert = false,hor = false;
					if(!checkup(arr,m,n,i,j) || !checkdown(arr,m,n,i,j))
					{
						vert = true;
					}
					if(!checkleft(arr,m,n,i,j) || !checkright(arr,m,n,i,j))
					{
						hor = true;
					}
					if(vert && hor)
					{
						//std::cout<<i<<j<<std::endl;
						found = true;
						break;
					}
				}
				if(found)
				{
					canbedone = false;
					break;
				}
			}
			if(canbedone)
			{
				std::cout<<"Case #"<<cs<<": YES"<<std::endl;
			}
			else
				std::cout<<"Case #"<<cs<<": NO"<<std::endl;
			for(int i = 0 ; i < m; i++)
				delete[] arr[i];
			delete[] arr;
		}
	}
}

int main()
{

	

	codejam::lawnmower();

	return 0;
}
