#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++)
	{
		int R, C, M;
		cin >> R >> C >> M;
		int libres=R*C-M;
		cout << "Case #" << tc << ":";
		cout << endl;
		//cout << R << " " << C << " " << M << endl;
		if(min(R, C)==1)
		{
			int printed=1;
			cout << 'c';
			for(int i=0; i<R; i++)
			{
				for(int j=0; j<C; j++)
				{
					if(i||j)
					{
						if(printed<libres)
						{
							cout << '.';
							printed++;
						}
						else
						{
							cout << '*';
						}
					}
				}
				cout << endl;
			}
		}
		else
		{
			if(libres==1)
			{
				for(int i=0; i<R; i++)
				{
					for(int j=0; j<C; j++)
					{
						if(i||j)
							cout << '*';
						else
							cout << 'c';
						
					}
					cout << endl;
				}
			}
			else
			{
				//cout << libres << endl;
				int printed=0;
				for(int r=0; r<R-1; r++)
					for(int c=0; c<C-1; c++)
					{
						//cout << (c+2)*(r+2) << endl;
						if(!printed && 2*c+2*r+4<=libres && (c+2)*(r+2)>=libres)
						{
							//cout << r << " " << c << endl;
							int cant=2*c+2*r+4;
							for(int i=0; i<R; i++)
							{
								for(int j=0; j<C; j++)
								{
									if(i||j)
									{
										if(i>=r+2 || j>=c+2)
										{
											cout << '*';
										}
										else
										{
											if(i<2 || j<2)
												cout << '.';
											else
											{
												if(cant<libres)
												{
													cout << '.';
													cant++;
												}
												else
													cout << '*';
											}
										}
									}
									else
									{
										cout << 'c';
									}
								}
								cout << endl;
							}
							printed=1;
						}
					}
				if(!printed) cout << "Impossible" << endl;
			}
		}
		
	}
}
