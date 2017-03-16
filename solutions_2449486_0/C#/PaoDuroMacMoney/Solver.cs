using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lawnmower
{
    class Solver : ISolver
    {
        bool[,] v_Possible;
        int[,] v_Lawn;

        public string Solve(System.IO.StreamReader v_Reader)
        {
            String[] v_Dimensions = v_Reader.ReadLine().Split(' ');

            int v_Rows =int.Parse(v_Dimensions[0]);
            int v_Cols = int.Parse(v_Dimensions[1]);

            v_Lawn = new int[v_Rows, v_Cols];

            for (int i = 0; i < v_Rows; i++)
            {
                String[] v_Line = v_Reader.ReadLine().Split(' ');
                for (int j = 0; j < v_Cols; j++)
                {
                    v_Lawn[i, j] = int.Parse(v_Line[j]);
                }
            }

            v_Possible = new bool[v_Rows, v_Cols];
            
            for (int i = 0; i < v_Rows; i++)
            {
                int v_MaxInRow = 0;
                for (int j = 0; j < v_Cols; j++)
                {
                    v_MaxInRow = Math.Max(v_MaxInRow, v_Lawn[i, j]);
                }
                for (int j = 0; j < v_Cols; j++)
                {
                    v_Possible[i,j] = v_Lawn[i, j] == v_MaxInRow;
                }
            }

            
            for (int i = 0; i < v_Cols; i++)
            {
                int v_MaxInCol = 0;
                for (int j = 0; j < v_Rows; j++)
                {
                    v_MaxInCol = Math.Max(v_MaxInCol, v_Lawn[j, i]);
                }
                for (int j = 0; j < v_Rows; j++)
                {
                    v_Possible[j, i] = v_Possible[j, i] || v_Lawn[j, i] == v_MaxInCol;
                }
            }


            for (int i = 0; i < v_Rows; i++)
            {
                for (int j = 0; j < v_Cols; j++)
                {
                    if (!v_Possible[i,j])
                    {
                        return "NO";
                    }
                }
            }
            return "YES";
        }

        private int compare(int v_CompareHeigth, int i, int j)
        {
            int v_Height = v_Lawn[i, j];
            if (v_Height >= v_CompareHeigth)
            {
                v_Possible[i, j] = true;
                return v_Height;
            }
            return v_CompareHeigth;
        }
    }
}
