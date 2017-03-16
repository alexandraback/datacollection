#include "stdafx.h"

int main()
{
	int t = 0;
	int n, m;
	FILE* fin = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("b.txt", "w");
	fscanf(fin, "%d", &t);

	int map[101][101];
	bool empty[101][101];

	for (int it = 0; it < t; it++)
	{
		fscanf(fin, "%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				fscanf(fin, "%d", &map[i][j]);
				empty[i][j] = false;
			}

		// Start backward weeding.
		while (true)
		{
			// Find the lowest column or row.

			// Find lowest row.
			int minRowHeight = 1000;
			int minColumnHeight = 1000;
			int minRowId = -1;
			int minColumnId = -1;
			for (int i = 0; i < n; i++)
			{
				int rowHeight;
				bool inRow = true;
				bool containsNonEmpty = false;
				for (int j = 0; j < m; j++)
				{
					if (!empty[i][j])
					{
						rowHeight = map[i][j];
						containsNonEmpty = true;
						break;
					}
				}
				if (!containsNonEmpty) continue;

				for (int j = 0; j < m; j++)
				{
					if (!empty[i][j] && map[i][j] != rowHeight)
					{
						inRow = false;
						break;
					}
					if (empty[i][j] && map[i][j] > rowHeight)
					{
						inRow = false;
						break;
					}
				}
				if (inRow && rowHeight < minRowHeight && containsNonEmpty)
				{
					minRowHeight = rowHeight;
					minRowId = i;
				}
			}

			minColumnHeight = 1000;
			for (int i = 0; i < m; i++)
			{
				int columnHeight;
				bool inColumn = true;
				bool containsNonEmpty = false;
				for (int j = 0; j < n; j++)
					if (!empty[j][i])
					{
						columnHeight = map[j][i];
						containsNonEmpty = true;
						break;
					}
				if (!containsNonEmpty) continue;

				for (int j = 0; j < n; j++)
				{
					if (!empty[j][i] && map[j][i] != columnHeight)
					{
						inColumn = false;
						break;
					}
					if (empty[j][i] && map[j][i] > columnHeight)
					{
						inColumn = false;
						break;
					}
				}
				if (inColumn && columnHeight < minColumnHeight && containsNonEmpty)
				{
					minColumnHeight = columnHeight;
					minColumnId = i;
				}
			}

			if (minRowHeight < minColumnHeight)
			{
				for (int i = 0; i < m; i++)
				{
					empty[minRowId][i] = true;
					map[minRowId][i] = minRowHeight;
				}
			}
			else if (minColumnHeight < minRowHeight)
			{
				for (int i = 0; i < n; i++)
				{
					empty[i][minColumnId] = true;
					map[i][minColumnId] = minColumnHeight;
				}
			}
			else // minRowHeight == minColumnHeight
			{
				if (minColumnHeight > 100)
				{
					// Check if we have finished.
					bool finished = true;
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							if (empty[i][j] == false)
							{
								finished = false;
								break;
							}
						if (finished == false) break;
					}

					if (finished)
					{
						fprintf(fout, "Case #%d: YES\n", it + 1);
						break;
					}
					else
					{
						fprintf(fout, "Case #%d: NO\n", it + 1);
						break;
					}
				}
				else // minRowHeight == minColumnHeight <= 100
				{
					for (int i = 0; i < m; i++)
					{
						empty[minRowId][i] = true;
						map[minRowId][i] = minRowHeight;
					}
				}
			}
		}
	}

	return 0;
}