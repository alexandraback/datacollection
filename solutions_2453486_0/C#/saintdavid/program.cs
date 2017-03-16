using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class program
    {
        public static int GetOutcome(char[,] matrix)
        {
            int total = 0;           
            //X won
            for (int i = 0; i < 4; i++)
            {
                bool flag = true;
                for (int j = 0; j < 4; j++)
                    if ((matrix[i, j] == '.') || (matrix[i, j] == 'O'))
                        flag = false;
                if (flag) return 1;
            }
            for (int j = 0; j < 4; j++)
            {
                bool flag = true;
                for (int i = 0; i < 4; i++)
                    if ((matrix[i, j] == '.') || (matrix[i, j] == 'O'))
                        flag = false;
                if (flag) return 1;
            }

            bool flag2 = true;
            for (int i = 0; i < 4; i++)
                if ((matrix[i, i] == '.') || (matrix[i, i] == 'O'))
                    flag2 = false;                                                    
            if (flag2) return 1;

            flag2 = true;
            for (int i = 0; i < 4; i++)
                if ((matrix[i, 3 - i] == '.') || (matrix[i, 3 - i] == 'O'))
                    flag2 = false;
            if (flag2) return 1;

            //O won
            for (int i = 0; i < 4; i++)
            {
                bool flag = true;
                for (int j = 0; j < 4; j++)
                    if ((matrix[i, j] == '.') || (matrix[i, j] == 'X'))
                        flag = false;
                if (flag) return 2;
            }
            for (int j = 0; j < 4; j++)
            {
                bool flag = true;
                for (int i = 0; i < 4; i++)
                    if ((matrix[i, j] == '.') || (matrix[i, j] == 'X'))
                        flag = false;
                if (flag) return 2;
            }

            flag2 = true;
            for (int i = 0; i < 4; i++)
                if ((matrix[i, i] == '.') || (matrix[i, i] == 'X'))
                    flag2 = false;
            if (flag2) return 2;

            flag2 = true;
            for (int i = 0; i < 4; i++)
                if ((matrix[i, 3 - i] == '.') || (matrix[i, 3 - i] == 'X'))
                    flag2 = false;
            if (flag2) return 2;

            //All Full
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (matrix[i, j] != '.')
                        total++;
            if (total == 16) return 3;
            
            return 0;
        }

        public static void Main()
        {
            //List<string> input_lines = funcs.getInputDocs2(@"input.txt");
            List<string> input_lines = funcs.getInputDocs2(@"A-small-attempt1.in");
            
            int num = int.Parse(input_lines[0]);
            int count = 1;
            List<string> outlines = new List<string>();
            for (int samples = 0; samples < num; samples++)
            {
                char[,] matrix = new char[4, 4];
                for (int i = 0; i < 4; i++)
                {                    
                    string thisline = input_lines[count];
                    matrix[i, 0] = thisline[0]; matrix[i, 1] = thisline[1];
                    matrix[i, 2] = thisline[2]; matrix[i, 3] = thisline[3];
                    count++;
                }
                count++;                
                //Start Manipulating
                int outcome = GetOutcome(matrix);
                string t_out = "Case #" + (samples + 1).ToString() + ": ";
                if (outcome == 0) t_out += "Game has not completed";
                if (outcome == 1) t_out += "X won";
                if (outcome == 2) t_out += "O won";
                if (outcome == 3) t_out += "Draw";
                outlines.Add(t_out);
            }
            //funcs.WriteLines(@"output.txt", outlines);
            funcs.WriteLines(@"A-small-attempt1.out", outlines);
        }
    }
}
