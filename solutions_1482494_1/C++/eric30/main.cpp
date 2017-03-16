#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream in("E:\\GoogleCodeJam2012\\Round1A\\B-large.in");
	ofstream out("E:\\GoogleCodeJam2012\\Round1A\\B-large.out");

	if (in.is_open())
	{
		int cases;

	    in >> cases;

		for (int c = 1;c <= cases;++c)
		{
		    int result = 0;
			int n;

			in >> n;

			int table[1000][3];
			int played = 0;

			for (int i = 0;i < n;++i)
			{
				in >> table[i][0] >> table[i][1];

				// not played
				table[i][2] = 0;
			}

			//Main algo.
			int currentStar = 0;
			int lastCurrentStar = currentStar;

			while (played < n)
			{
				int min2StarNotPlayed = 2002;
				int indexNotPlayed = n;

				int min2StarPlayed = 2002;
				int indexPlayed = n;
				bool no2Star = true;

				// Find min 2 star without 1 used
                for (int i = 0;i < n;++i)
			    {
					int neededStar = table[i][1];

					if (currentStar >= neededStar)
					{
						if (table[i][2] == 0) 
						{
							if (neededStar < min2StarNotPlayed)
							{
								min2StarNotPlayed = neededStar;
								indexNotPlayed = i;
							}
						} 
						else if (table[i][2] == 1)
						{
							if (neededStar < min2StarPlayed) 
							{
								min2StarPlayed = neededStar;
								indexPlayed = i;
							}
						}
					}
			    }

				if (indexNotPlayed < n)
				{
					currentStar += 2;
					table[indexNotPlayed][2] = 2;
					result++;
					played++;

					no2Star = false;
				} 
				else if (indexPlayed < n)
				{
					currentStar++;
					table[indexPlayed][2] = 2;
					result++;
					played++;

					no2Star = false;
				}

				// No 2 star, find 1 star
				if (no2Star)
				{
					int max2Star = 0;
					int minIndex = n;

					for (int i = 0;i < n;++i)
					{
						int neededStar = table[i][0];
						
						if (currentStar >= neededStar)
						{
							if (table[i][2] == 0)
							{
								if (table[i][1] > max2Star)
								{
									minIndex = i;
									max2Star = table[i][1];
								}
							}
						}
					}

					if (minIndex < n)
					{
						currentStar++;
						table[minIndex][2] = 1;
						result++;
					}
				}

				if (lastCurrentStar == currentStar)
				{
					break;
				}
				else 
				{
					lastCurrentStar = currentStar;
				}
			}

			if (played < n)
			{
				out << "Case #" << c << ": Too Bad" << endl;
			} 
			else
			{
				out << "Case #" << c << ": " << result << endl;
			}
		}
	}

	return 0;
}
