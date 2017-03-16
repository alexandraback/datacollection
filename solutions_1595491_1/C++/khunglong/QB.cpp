#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define file_in "B-large.in"
#define file_out "QB.out"



int main()
{
	int T, n, s, s1, p, m, i, j, x, y;
	
    FILE *fi;
    FILE *fo;
    fi = fopen(file_in, "r");
    fscanf(fi, "%d", &T);

    fo = fopen(file_out, "w");

  	for (i=0; i<T; i++)
  	{
		m = 0;
		s1 = 0;
		
		fscanf(fi, "%d %d %d", &n, &s, &p);
		for (j=0; j<n; j++)
		{
			
			fscanf(fi, "%d", &x);
			y = x/3;
			
			if (x%3==0)
			{
				if (y>=p)
				{
					m++;
				}
				else if (y+1>=p)
				{
					if (x>0) //tranh tr.hop x = 0, ko the co -1, 0, 1
					{
						m++;
						s1++;
					}
				}
			}
			else if (x%3==1)
			{
				if (y+1>=p)
				{
					m++;
				}
			}
			else
			{
				if (y+1>=p)
				{
					m++;
				}
				else if (y+2>=p)
				{
					if (x<29)   //tranh tr.h 29, ko the 9 9 11
					{
                        m++;
						s1++;
					}
				}
			}
		}

		//now maximun the number of pass m, not pass is n-m
		//	if num of surprise in m is s1 <= s, i.e missing s-s1
		//     	return m
		//  else num of surprise s1 > s: return m-(s1-s)
		
		//fprintf(fo, "m=%d, s1=%d\n", m, s1);
		if (s1<=s)
		{
            fprintf(fo, "Case #%d: %ld\n", i+1, m);
		}
		else
		{
            fprintf(fo, "Case #%d: %ld\n", i+1, m-(s1-s));
		}
  	}
  	fclose(fi);
  	fclose(fo);
}
