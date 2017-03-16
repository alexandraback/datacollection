#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	int n, m, under;
	float a[201], total, x, y, last, temp;

	FILE * file;
	ifstream in;
	//file.open("file.txt"); //open a file
	file = fopen ("file.txt","w");

	in.open("input.txt");

	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> m;
		total = 0;
		for (int t = 0;  t< m; t++)
		{
			in >> a[t];
			total += a[t];
		}

		fprintf ( file, "Case #%d:", i + 1);

		for (int t = 0;  t < m; t++)
		{
			
			x = a[t];
			last = 0;
			while (true)
			{
				y = total;
				under = 0;
				for (int j = 0; j < m; j++)
				{
					if (a[j] <= x)
					{
						under++;
						y -= (x - a[j]);
					}
				}

				if (y < 0) break;

				y /= under;

				bool ex = true;
				temp = 1000;
				if (y > 0)
				{
					for (int j = 0; j < m; j++)
					{
						if (a[j] > x && a[j] <= x + y && a[j] < temp)
						{
							ex = false;
							temp = a[j];
						}
					}
				}

				if (ex) break;
				x = temp;
				last = y;
			}

			if (y < 0)
			{
				fprintf ( file, " %.6f", last / total * 100);
				continue;
			}

			y += (x - a[t]);

			fprintf ( file, " %.6f", y / total * 100);
		}

		fprintf ( file, "\n");
	}
	fclose (file);
    return 0;
}