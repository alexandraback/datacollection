using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QualA
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\B-large.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {

                int cases = int.Parse(sr.ReadLine());

                for (int i = 1; i <= cases; i++)
                {
                    string dimensions = sr.ReadLine();
                    int height = int.Parse(dimensions.Split(' ').ElementAt(0));
                    int width = int.Parse(dimensions.Split(' ').ElementAt(1));

                    
                    //Read in the desired lawn
                    int tallest = 0;
                    int[,] lawn = new int[height, width];
                    for (int j = 0; j < height; j++)
                    {
                        string lawnStrip = sr.ReadLine();
                        for (int k = 0; k < width; k++)
                        {
                            lawn[j, k] = int.Parse(lawnStrip.Split(' ').ElementAt(k));
                            if (lawn[j, k] > tallest) tallest = lawn[j, k];
                        } 
                    }
                    //Grow our actual lawn
                    int[,] lawn2 = new int[height, width];
                    for (int j = 0; j < height; j++)
                        for (int k = 0; k < width; k++)
                            lawn2[j, k] = tallest;


                    for (int mowerHeight = tallest - 1; mowerHeight > 0; mowerHeight--)
                    {
                        //Left to right
                        for (int j = 0; j < height; j++)
                        {
                            bool noProblems = true;
                            for (int k = 0; k < width; k++)
                                if (mowerHeight < lawn[j, k]) //No good!
                                    noProblems = false;
                                
                            if (noProblems) //Mow away
                                for (int k = 0; k < width; k++)
                                    lawn2[j, k] = mowerHeight;
                        }

                        //Now top to bottom
                        for (int k = 0; k < width; k++)
                        {
                            bool noProblems = true;
                            for (int j = 0; j < height; j++)
                                if (mowerHeight < lawn[j, k]) //No good!
                                    noProblems = false;
                            
                            if (noProblems) //Mow away
                                for (int j = 0; j < height; j++)
                                    lawn2[j, k] = mowerHeight;
                        }                        
                    }


                    //if lawn2 looks like lawn, then we got what we want!
                    string theAnswer = "YES";
                    for (int j = 0; j < height; j++)
                        for (int k = 0; k < width; k++)
                            if (lawn[j, k] != lawn2[j, k]) theAnswer = "NO";
                    
                    string answer = "Case #" + i + ": " + theAnswer;
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.ReadLine();
        }
    }
}
