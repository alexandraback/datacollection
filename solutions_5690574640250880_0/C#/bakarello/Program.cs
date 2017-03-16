using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google_Jam_Q3
{
	class Program
	{
		static void Main(string[] args)
		{
			StreamWriter sWriter = new StreamWriter(new FileStream("output.txt", FileMode.Create));
			StreamReader sReader = new StreamReader(new FileStream("input", FileMode.Open));

			int count = int.Parse(sReader.ReadLine());

			for (int i = 0; i < count; i++)
			{
				int width, height, mines;
				string[] param = sReader.ReadLine().Split(' ');
				height = int.Parse(param[0]);
				width = int.Parse(param[1]);
				mines = int.Parse(param[2]);

				string output = ChechIfOneClick(width, height, mines);
				sWriter.Write("Case #" + (i + 1) + ":\n" + output);
			}
			sWriter.Dispose();
			sReader.Dispose();
		}

		static string ChechIfOneClick(int width, int height, int mines)
        {
			int c = width * height - mines;
            if (Math.Min(width, height) == 1)
            {
                char[] arr = new char[width * height];
                for (int i = 0; i < width * height; i++)
                {
                    if (i < mines)
                        arr[i] = '*';
                    else
                        arr[i] = '.';
                }
                arr[width * height - 1] = 'c';

				StringBuilder sb = new StringBuilder();
				foreach (char a in arr)
				{
					sb.Append(a);
					if (width == 1)
						sb.Append('\n');
				}
				if (height == 1)
					sb.Append('\n');

                return sb.ToString();
            }
            else if (Math.Min(width, height) == 2 && (c == 1 || (c % 2 == 0 && c >= 4)))
            {
                char[,] arr = new char[height, width];
				if (width == 2)
				{
					for (int i = 0; i < height; i++)
						for (int j = 0; j < width; j++)
						{
							if (i * width + j < mines)
								arr[i, j] = '*';
							else
								arr[i, j] = '.';
						}
					arr[height - 1, width - 1] = 'c';
				}
				else
				{
					for (int i = 0; i < width; i++)
						for (int j = 0; j < height; j++)
						{
							if (i * height + j < mines)
								arr[j, i] = '*';
							else
								arr[j, i] = '.';
						}
					arr[height - 1, width - 1] = 'c';
				}

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                        sb.Append(arr[i, j].ToString());
                    sb.Append('\n');
                }

                return sb.ToString();
            }
            else if(Math.Min(width,height)>2)
            {
                if (c == 1 || (c >= 4 && c != 5 && c != 7))
                {
					char[,] matrix = new char[height, width];
                    int[] hrz = new int[height];
                    int[] vrt = new int[width];
					
					for(int i = 0; i < c; i++)
					{
						int hId = 0;
						int vId = 0;

						for (int n = 0; n < height; n++)
							if (hrz[n] < width)
							{
								hId = n;
								break;
							}
						for (int n = 0; n < width; n++)
						{
							if (vrt[n] - hId == 0)
							{
								vId = n;
								break;
							}
							else if (vrt[n] - hId == 1 && hId != height - 1 && hId == 0)
							{
								vId = n;
								hId++;
								break;
							}
						}


						matrix[hId, vId] = '.';
						++hrz[hId];
						++vrt[vId];
					}

					if (c > 8)
					{
						int hr = 0;
						for (int n = 0; n < width; n++)
							if (vrt[n] == 1)
							{
								matrix[2, 0] = '.';
								matrix[2, 1] = '.';
								matrix[2, 2] = '.';

								matrix[0, n] = (char)0;
								matrix[0, n - 1] = (char)0;
								matrix[1, n - 1] = (char)0;
								break;
							}

						for (int i = 0; i < height; i++)
						{
							if (hrz[i] == 1)
							{
								if (i == 2)
								{
									matrix[i, 1] = '.';
									matrix[i, 2] = '.';

									matrix[0, width - 1] = (char)0;
									matrix[1, width - 1] = (char)0;
								}
								else
								{
									matrix[i, 1] = '.';

									matrix[i - 1, width - 1] = (char)0;
								}
							}
						}
					}

					StringBuilder sb = new StringBuilder();

					for(int i = 0; i < height; i++)
					{
						for(int j = 0; j < width; j++)
							sb.Append(matrix[i,j] != '.' ? '*' : '.');
						sb.Append('\n');
					}
					sb[0] = 'c';
					return sb.ToString();
				}
            }

            return "Impossible\n";
        }
	}
}
