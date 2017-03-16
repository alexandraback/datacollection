using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows;

namespace GoogleCodeJamCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inputStream = new StreamReader("input.txt");
            StreamWriter outputStream = new StreamWriter("output.txt", false);

            int caseNumber = 1, totalTestCases, segmentCount, matchingSegmentCount;

            long possibleConfigurations = 0, addResult;
            TrainCar current, segment;
            List<TrainCar> trainSegments = new List<TrainCar>();
            Dictionary<char, List<TrainCar>> leftSideSegments = new Dictionary<char,List<TrainCar>>();
            Dictionary<char, List<TrainCar>> rightSideSegments = new Dictionary<char,List<TrainCar>>();
            bool possibleToAssemble;
            bool frontEndUsed, rearEndUsed;

            try
            {
                totalTestCases = Convert.ToInt32(inputStream.ReadLine());

                for (int a = 0; a < totalTestCases; a++)
                {
                    trainSegments.Clear();
                    leftSideSegments.Clear();
                    rightSideSegments.Clear();

                    segmentCount = Convert.ToInt32(inputStream.ReadLine());
                    string[] parts = inputStream.ReadLine().Split(' ');

                    for (int b = 0; b < parts.Length; b++)
                    {
                        current = new TrainCar(parts[b].ElementAt(0), parts[b], parts[b].ElementAt(parts[b].Length - 1));

                        trainSegments.Add(current);

                        if (!leftSideSegments.ContainsKey(current.LeftSide))
                        {
                            leftSideSegments.Add(current.LeftSide, new List<TrainCar>());
                        }
                        leftSideSegments[current.LeftSide].Add(current);

                        if (!rightSideSegments.ContainsKey(current.RightSide))
                        {
                            rightSideSegments.Add(current.RightSide, new List<TrainCar>());
                        }
                        rightSideSegments[current.RightSide].Add(current);
                    }

                    possibleToAssemble = true;
                    frontEndUsed = false;
                    rearEndUsed = false;
                    possibleConfigurations = 0;

                    //might have to check the characters on the inside of the traincar string for adjacency, string is stored on the TrainCar.

                    //check to see if the right sides match the left sides. Not getting number of combinations yet merely checking if possible
                    foreach (char k in rightSideSegments.Keys)
                    {
                        if (!leftSideSegments.ContainsKey(k))
                        {
                            if (rightSideSegments[k].Count > 1 || rearEndUsed)
                            {
                                possibleToAssemble = false;
                                possibleConfigurations = 0;
                            }

                            rearEndUsed = true;
                        }
                    }

                    if (possibleToAssemble)
                    {
                        //ensure that the combinations can actually fit all of the train cars
                        foreach (char k in leftSideSegments.Keys)
                        {
                            if (rightSideSegments.ContainsKey(k))
                            {
                                matchingSegmentCount = leftSideSegments[k].Count < rightSideSegments[k].Count ? leftSideSegments[k].Count : rightSideSegments[k].Count; //lesser of the 2

                                addResult = matchingSegmentCount * matchingSegmentCount;

                                if (possibleConfigurations == 0)
                                {
                                    possibleConfigurations = addResult;
                                }
                                else
                                {
                                    possibleConfigurations *= addResult;
                                }
                            }
                            else
                            {
                                if (leftSideSegments[k].Count > 1 || frontEndUsed) //mismatched train cars, cannot assemble a valid train. Only 1 can be allowed as the endpoint
                                {
                                    possibleToAssemble = false;
                                    possibleConfigurations = 0;
                                    break;
                                }

                                frontEndUsed = true;
                            }
                        }
                    }

                    //cut down by modulo 1,000,000,007 as per instructions...
                    possibleConfigurations = possibleConfigurations % 1000000007;

                    outputStream.WriteLine("Case #" + caseNumber.ToString() + ": " + possibleConfigurations.ToString());

                    caseNumber++;
                }
            }
            finally
            {
                inputStream.Close();
                outputStream.Close();
            }
        }
    }

    struct TrainCar
    {
        public char LeftSide;
        public string FullSegmentLabel;
        public char RightSide;
        
        public TrainCar(char leftSide, string fullSegmentLabel, char rightSide)
        {
            LeftSide = leftSide;
            FullSegmentLabel = fullSegmentLabel;
            RightSide = rightSide;
        }
    }
}
