using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Brattleship
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"D:\Exercícios\Google Code Jam\2015\Round1C\Brattleship\A-large.in");
            int N = int.Parse(lines[0]);
            int reg_by_thread = (N / 16) + 1;

            string[] aux_lines = new string[lines.Length - 1];
            Array.Copy(lines, 1, aux_lines, 0, aux_lines.Length);
            Brattleship(aux_lines, 0);

            //for (int i = 0; i < N; i = i + reg_by_thread)
            //{
            //    int init = i * 2 + 1;
            //    int size = lines.Length - init > reg_by_thread * 2 ? reg_by_thread * 2 : lines.Length - init;
            //    string[] aux_lines = new string[size];
            //    Array.Copy(lines, init, aux_lines, 0, size);
            //    int base_idx = i;
            //    Thread thread = new Thread(() => MushroomMonster(aux_lines, base_idx));
            //    thread.Start();
            //}
        }

        static void Brattleship(string[] lines, int base_idx)
        {
            string[] result = new string[lines.Length];
            int result_idx = 0;

            for (int i = 0; i < lines.Length; ++i)
            {
                string[] parms = lines[i].Split(' ');
                int row = int.Parse(parms[0]);
                int col = int.Parse(parms[1]);
                int shipSize = int.Parse(parms[2]);

                int score = col / shipSize;
                score *= row;
                score += (shipSize - 1);

                if (col % shipSize > 0)
                {
                    ++score;
                }

                result[result_idx] = string.Format("Case #{0}: {1}", ++result_idx + base_idx, score);
            }

            File.WriteAllLines(string.Format(@"D:\Exercícios\Google Code Jam\2015\Round1C\Brattleship\resultado\resultado1{0}.txt", base_idx), result);
        }
    }
}
