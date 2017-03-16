#include <iostream.h>
#include <fstream.h>

// Code Jam 2014
// Qualification round
// Problem C. Minesweeper Master

int T;
int t;
int R, C, M;
int r, c, m;
int i,j;
int direction;
int impossible;
int solved;
char solution[50][50];
char copy[50][50];
int num;
int found;


int main(int argc, char *argv[])
{

	
	ifstream inFile;
	
	//inFile.open("test.in");
	if ( argc < 2 )
	{
		cout << "No input file given!" << endl;
		exit(1);
	}
	inFile.open(argv[1]);
	if ( !inFile )
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	
	inFile >> T;
	
	for (t=0;t<T;t++)
	{
		inFile >> R;
		inFile >> C;
		inFile >> M;
		
		for (i=0;i<50;i++)
		{
			for (j=0;j<50;j++)
			{
				solution[i][j] = '.';
			}
		}
		impossible = 0;
		
		
		
		r = 0;
		c = 0;
		m = M;
		direction = 0;
		
		if ( m>= R*C )
		{
			impossible = 1;
		}
		else
		{
			r = 0;
			c = 0;
			
			// slice and dice technique
			// fill an entire row or col at a time - whichever is shortest 
			// but always more than two
			// ( and only if there are enough bombs )
			
			while ( ((m>=(R-r)) && (r<(R-2))) || ((m>=(C-c)) && (c<(C-2))) )
			{
				found = 0;
				if ( ((R-r) > (C-c)) && (r<(R-2)) )
				{
					// fill row
					//m = m - (R-r);
					for (i=c;i<C;i++)
					{
						solution[r][i] = '*';
						m--;
					}
					r++;
					found = 1;
				}
				else if ( c<(C-2) )
				{
					// fill col
					for (i=r;i<R;i++)
					{
						solution[i][c] = '*';
						m--;
					}
					 c++;
					found = 1;
				}
				if ( found == 0 )
				{
					break;
				}
			}
			/*
			for (i=0;i<R;i++)
			{
				for (j=0;j<C;j++)
				{
					cout << solution[i][j] << " ";
				}
				cout << endl;
			}
			*/
			
			// now we have a rectangular field (R-r) x (C-c) and m bombs left
			// m < (R-r)
			// m < (C-c)
			
			// again fill on the longest side, we have to leave at least two free cells
			
			if ( (R-r == 2) && (C-c == 2) )
			{
				// only solvable if m==0 or m==3 ..
				// m==0 we dont need to handle here
				if ( m==3 )
				{
					solution[r][c] = '*';
					solution[r+1][c] = '*';
					solution[r][c+1] = '*';
					m = 0;
				}
				else if ( (m == 1) || (m == 2) )
				{
					impossible = 1;
					m = 0;
				}
			}
			else if ( R-r == 2 )
			{
				// handle 2 rows but larger columns
				if ( m%2 == 0 )
				{
					// might  be possible
					for (i=0;i<m/2;i++)
					{
						//cout << "filling: " << i << " r: " << r << " c: " << c << endl;
						solution[r][c] = '*';
						solution[r+1][c] = '*';
						c++;
					}
					m = 0;
				}
				else
				{
					impossible = 1;
				}
			}
			else if ( C-c == 2 )
			{
				// the opposite..
				if ( m%2 == 0 )
				{
					// might  be possible
					for (i=0;i<m/2;i++)
					{
						//cout << "filling: " << i << " r: " << r << " c: " << c << endl;
						solution[r][c] = '*';
						solution[r][c+1] = '*';
						r++;
					}
					m = 0;
				}
				else
				{
					impossible = 1;
				}
			}
			
			// take care of those with just one row or col
			if ( R == 1 && m > 0 )
			{
				// just fill in the row
				for (i=c;i<C;i++)
				{
					impossible = 0;
					solution[r][i] = '*';
					m--;
					if ( m== 0 )
					{
						break;
					}
				}
			}
			else if ( C == 1 && m > 0 )
			{
				// fill in the col
				for (i=r;i<R;i++)
				{
					impossible = 0;
					solution[i][c] = '*';
					m--;
					if ( m== 0 )
					{
						break;
					}
				}
			}
			
			
			if ( m > 0 )
			{
				// the largest of the two will have > 2 free places
				// hence m cannot be == to the largest of the two
				if ( (R-r) > (C-c) )
				{
					if ( R-r-m >= 2 )
					{
						for (i=0;i<m;i++)
						{
							solution[r+i][c] = '*';
						}
						m = 0;
					}
					else if ( R-r-m == 1 ) // actually this is the only option other than the above
					{
						for (i=0;i<m-1;i++)
						{
							solution[r+i][c] = '*';
						}
						if ( c<C-1 )
						{
							solution[r][c+1] = '*';
						}
						else
						{
							impossible = 1;
						}
						m = 0;
					}
					
				}
				else
				{
					if ( C-c-m >= 2 )
					{
						for (i=0;i<m;i++)
						{
							solution[r][c+i] = '*';
						}
						m = 0;
					}
					else if ( C-c-m == 1 ) // actually this is the only option other than the above
					{
						for (i=0;i<m-1;i++)
						{
							solution[r][c+i] = '*';
						}
						if ( r<R-1 )
						{
							solution[r+1][c] = '*';
						}
						else
						{
							impossible = 1;
						}
						m = 0;
					}
					
				}
			}
			
			/*
			for (i=0;i<R;i++)
			{
				for (j=0;j<C;j++)
				{
					cout << solution[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			*/
			// we only need to try solving it from bottom right corner
			
			// and only try to solve if not impossible..
			
			if ( impossible == 0 )
			{
				r = R-1;
				c = C-1;
				solved = 0;
				
				// attempt here
				// first copy the board
				for (i=0;i<R;i++)
				{
					for (j=0;j<C;j++)
					{
						copy[i][j] = solution[i][j];
					}
				}
				
				/*
					attempt to solve .. 
						fill in current position with number
						check board for '.' fields with a 0-adjacent field
							if found set current position and start over
						if not found check if there are any '.' left on board if no '.' board is solved
				*/
				i = r;
				j = c;
				found = 1;
				while (found)
				{
					found = 0;
					num = 0;
					// check all 8 adjacent fields - remember boundaries
					if ( i-1 >= 0 )
					{
						// there are 3 to the left of us
						if ( j-1 >= 0 )
						{
							if ( copy[i-1][j-1] == '*' )
							{
								num++;
							}
						}
						if ( copy[i-1][j] == '*' )
						{
							num++;
						}
						if ( j+1 < C )
						{
							if ( copy[i-1][j+1] == '*' )
							{
								num++;
							}
						}
					}
					if ( i+1 < R )
					{
						// and 3 to the right of us
						if ( j-1 >= 0 )
						{
							if ( copy[i+1][j-1] == '*' )
							{
								num++;
							}
						}
						if ( copy[i+1][j] == '*' )
						{
							num++;
						}
						if ( j+1 < C )
						{
							if ( copy[i+1][j+1] == '*' )
							{
								num++;
							}
						}
					}
					if ( j-1 >= 0 )
					{
						if ( copy[i][j-1] == '*' )
						{
							num++;
						}
					}
					if ( j+1 < C )
					{
						if ( copy[i][j+1] == '*' )
						{
							num++;
						}
					}
					
					copy[i][j] = 0x30+num;
					// look for a '.' with a 0-adjacent field
					for (i=0;i<R;i++)
					{
						for (j=0;j<C;j++)
						{
							if ( copy[i][j] == '.' )
							{
								if ( i-1 >= 0 )
								{
									// there are 3 to the left of us
									if ( j-1 >= 0 )
									{
										if ( copy[i-1][j-1] == '0' )
										{
											found = 1;
											break;
										}
									}
									if ( copy[i-1][j] == '0' )
									{
										found = 1;
										break;
									}
									if ( j+1 < C )
									{
										if ( copy[i-1][j+1] == '0' )
										{
											found = 1;
											break;
										}
									}
								}
								if ( i+1 < R )
								{
									// and 3 to the right of us
									if ( j-1 >= 0 )
									{
										if ( copy[i+1][j-1] == '0' )
										{
											found = 1;
											break;
										}
									}
									if ( copy[i+1][j] == '0' )
									{
										found = 1;
										break;
									}
									if ( j+1 < C )
									{
										if ( copy[i+1][j+1] == '0' )
										{
											found = 1;
											break;
										}
									}
								}
								if ( j-1 >= 0 )
								{
									if ( copy[i][j-1] == '0' )
									{
										found = 1;
										break;
									}
								}
								if ( j+1 < C )
								{
									if ( copy[i][j+1] == '0' )
									{
										found = 1;
										break;
									}
								}
							}
						}
						if ( found )
						{
							break;
						}
					}
					
				}
				// end while found
				solved = 1;
				
				for (i=0;i<R;i++)
				{
					for (j=0;j<C;j++)
					{
						if ( copy[i][j] == '.' )
						{
							solved = 0;
						}
						//cout << copy[i][j] << " ";
					}
					//cout << endl;
				}
				
				if ( solved )
				{
					solution[r][c] = 'c';
				}
	
			}
			// end if impossible==0
		}
		/*
		for (r=0;r<R;r++)
		{
			for (c=0;c<C;c++)
			{
				cout << solution[r][c] << " ";
			}
			cout << endl;
		}
		*/

		
		cout << "Case #" << t+1 << ": ";
		
		if ( impossible || (solved == 0) )
		{
			//cout << "R: " << R << " C: " << C << " M: " << M << endl;
			cout << endl;
			cout << "Impossible";
			cout << endl;
		}
		else
		{
			cout << endl;
			for (r=0;r<R;r++)
			{
				for (c=0;c<C;c++)
				{
					cout << solution[r][c];
				}
				cout << endl;
			}
		}
		
		
		
	}
		
		
	
	inFile.close();
	return 0;
}