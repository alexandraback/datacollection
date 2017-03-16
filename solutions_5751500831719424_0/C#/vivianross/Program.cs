using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        class Solver
        {
            struct WordMap
            {
                public char Character;
                public int Qty;
            }

            public string solve(System.IO.StreamReader p_Reader)
            {
                int string_numbers = Convert.ToInt32(p_Reader.ReadLine());

                List<List<WordMap>> strings = new List<List<WordMap>>();

                for (int i = 0; i < string_numbers; i++)
                {
                    List<WordMap> list = new List<WordMap>();
                    string word = p_Reader.ReadLine();

                    AddNewCharacter(list, word, 0);
                    char last_character = word[0];
                    
                    for (int j = 1; j < word.Length; j++)
                    {
                        if (word[j] != last_character)
                        {
                            last_character = word[j];
                            AddNewCharacter(list, word, j);
                        }
                        else
                        {
                            WordMap word_map = list[list.Count - 1];
                            word_map.Qty += 1;
                            list[list.Count - 1] = word_map;
                        }
                    }

                    strings.Add(list);
                }

                List<WordMap> first_word = strings[0];

                if (strings.Any(element => element.Count != first_word.Count))
                { 
                    return "Fegla Won";
                }

                int total_moves = 0;

                //Percorrendo cada caracter.
                for(int i = 0; i < first_word.Count; i++)
                {
                    for(int j = 1; j < strings.Count; j++)
                    {
                        if (strings[j][i].Character != first_word[i].Character)
                        {
                            return "Fegla Won";
                        }
                    }

                    List<int> qtys = strings.Select(_element => _element[i].Qty).OrderBy(_element1 => _element1).ToList();
                    List<int> qtys_distincts = qtys.Distinct().ToList();                    

                    if (qtys_distincts.Count > 1)
                    {
                        List<int> qty_qtys_distintics = new List<int>();

                        for (int q = 0; q < qtys_distincts.Count; q++)
                        {
                            int quantidade = qtys.Where(_element => _element == qtys_distincts[q]).Count();
                            qty_qtys_distintics.Add(quantidade);
                        }

                        int character_moves = Int32.MaxValue;

                        for (int q = 0; q < qtys_distincts.Count; q++)
                        {
                            int instance_moves = 0;

                            for (int q1 = 0; q1 < qtys_distincts.Count; q1++)
                            {
                                if (q1 != q)
                                {
                                    int distance = qtys_distincts[q1] - qtys_distincts[q];
                                    instance_moves += ((int)Math.Abs(distance)) * qty_qtys_distintics[q1];                                    
                                }
                            }

                            character_moves = Math.Min(instance_moves, character_moves);
                        }

                        total_moves += character_moves;
                    }
                }

                return total_moves + "";
            }

            private void AddNewCharacter(List<WordMap> strings, string word, int index)
            {
                WordMap word_map = new WordMap();
                word_map.Character = word[index];
                word_map.Qty = 1;
                strings.Add(word_map);
            }
        }

        static String Path
        {
            get
            {
                return @"C:\Users\Nilson\Desktop\vivian-codejam\round-1B\a\arquivo\";
            }
        }

        static void Main(string[] args)
        {
            Solver v_Solver = new Solver();
            StreamReader v_InputStream = new StreamReader(Path + "A-small-attempt1.in");
            int v_NumberOfCases = Convert.ToInt32(v_InputStream.ReadLine());

            StreamWriter v_Writer = new StreamWriter(Path + "Output.txt");
            for (int i = 1; i <= v_NumberOfCases; i++)
            {
                v_Writer.WriteLine(String.Format("Case #{0}: {1}", i, v_Solver.solve(v_InputStream)));
            }
            v_InputStream.Close();
            v_Writer.Flush();
            v_Writer.Close();
        }
    }
}
