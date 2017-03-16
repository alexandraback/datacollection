using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace round1
{
    class Program
    {
        public static StreamReader reader=null;
        static void Main(string[] args)
        {
            String InputFile = @"C:\Input.in";
            String OutputFile = @"C:\Output.txt";

            if (args.Length > 0)
            {
                InputFile = args[0];

                Console.WriteLine("...........");
            }


            reader = new StreamReader(InputFile);
            StreamWriter myFile = File.CreateText(OutputFile);

            int testcases = Convert.ToInt32(reader.ReadLine());
            string result;

            for (int i = 0; i < testcases; i++)
            {
                result = function(reader.ReadLine());
                myFile.WriteLine("Case #" + (i + 1) + ": " + result);
            }

            myFile.Close();
            reader.Close();

        }

        //public static String[] input = new String[210];

       
        public static int[,] learn;
        public static int[] temparr = new int[100000];
        public static int temppointer = 0;

        static string function(String inputstring)
        {
            

           int input = Convert.ToInt32(inputstring);

            learn = new int[input,input];

            for (int i = 0; i < input; i++)
            {
                string temp = reader.ReadLine();
                string[] arr = temp.Split(' ');
                for (int j = 0; j <= Convert.ToInt32(arr[0]); j++)
                {
                    learn[i, j] = Convert.ToInt32(arr[j]);
                }

            }

            

            for (int i = 1; i <= input; i++)
            {
                temppointer = 1;
                temparr[0] = i;
                if (insert(i) == false)
                {
                    return "Yes";
                }
            }

            return "No";            
        }

        //public static void clear()
        //{
        //    for (int i = 0; i < temparr.Length; i++)
        //    {
        //        temparr[i] = -1;
        //    }

        //}

       

        public static bool insert(int x)
        {
            if (x == 0)
                return true;
            
                for (int i = 1; i <= Convert.ToInt32(learn[x-1, 0]); i++)
                {
                    for (int j = 0; j < temppointer; j++)
                    {
                        if (temparr[j] == learn[x-1, i])
                            return false;
                    }

                    temparr[temppointer++] = learn[x-1, i];
                    if (insert(learn[x-1, i]) == false)
                        return false;

                }
                return true;
           

            
        }

       
    }
}
