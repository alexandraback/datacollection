using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace qr2015ProgC
{



   class qrProgC
   {
      public const string cInputFile = "C:\\Dev\\2015\\Qualify\\qrC\\C-large.in";
      public const string cOutputFile = "C:\\Dev\\2015\\Qualify\\qrC\\out.txt";
      public const string cExampleAnswerFile = "C:\\Dev\\2015\\Qualify\\qrC\\ea.txt";

      public static string[] sRow1 = {"1", "i",   "j",  "k"};
      public static string[] sRowi = { "i", "-1", "k",  "-j" };
      public static string[] sRowj = { "j", "-k", "-1", "i" };
      public static string[] sRowk = { "k", "j",  "-i", "-1" };

      public static string sInputString;

      static void Main(string[] args)
      {
         try
         {
            using (StreamWriter writer = new StreamWriter(cOutputFile))
            {
               using (StreamReader reader = new StreamReader(cInputFile))
               {
                  int numberOfTestCases = int.Parse(reader.ReadLine());

                  for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                  {
                     string row1 = reader.ReadLine();
                     string row2 = reader.ReadLine();

                     long lValue = long.Parse(row1.Split(' ')[0]);
                     long xValue = long.Parse(row1.Split(' ')[1]);
                     
                     sInputString  = row2;
                     
                     //Determine how many repeats it takes to get a "1"
                     string chunk = ComputeFromString(0, row2.Length);

                     bool is1 = false;
                     long iter = 1;
                     string le =  chunk;
                     while (!is1)
                     {
                        le = computeValue(le, chunk);
                        iter++;
                        if (le == "1")
                        {
                           is1 = true;
                        }
                     }

                     //Reduce the xValue to prevent unessasry repeats
                     if (xValue > iter)
                     {
                        long mod = xValue % iter;
                        xValue = mod + iter;
                     }
                    

                     const string cNo = "NO";
                     const string cYes = "YES";
                     string result = "";

                     int distinctLetters = row2.Distinct().Count();
                     
                     int iCount = 0;
                     int kCount = 0;

                     int test = 0;

                     //If all the same letters appear ijk can not be found
                     if (distinctLetters > 1)
                     {
                        sInputString = new String(Enumerable.Range(0, (int)xValue).SelectMany(o => row2).ToArray());
                        string entireString = ComputeFromString(0, sInputString.Length);

                        //Entire string must compute to IJK = -1 if does not we know we can not reduce it.
                        if (sInputString.Length >= 3 && entireString == "-1")
                        {
                           List<int> iEndPoints = new List<int>();
                           List<int> kStartPoints = new List<int>();

                           //Looks for i
                           string leftmost = sInputString[0].ToString();
                           if (leftmost == "i")
                           {
                              iEndPoints.Add(0);
                              iCount++;
                           }
                           for (int i = 1; i < sInputString.Length; i++)
                           {
                              leftmost = computeValue(leftmost, sInputString[i].ToString());
                              if (leftmost == "i")
                              {
                                 iEndPoints.Add(i);
                                 iCount++;
                              }
                           }


                           //Look for k
                           string rightmost = sInputString[sInputString.Length-1].ToString();
                           if (rightmost == "k")
                           {
                              kStartPoints.Add(sInputString.Length - 1);
                              kCount++;
                           }
                           for (int i = sInputString.Length - 2; i >= 0; i--)
                           {
                              rightmost = computeValue(sInputString[i].ToString(), rightmost);
                              if (rightmost == "k")
                              {
                                 kStartPoints.Add(i);
                                 kCount++;
                              }
                           }

                           //Check for j inbetween
                           bool found = false;
                           
                           for (int i = 0; i < iEndPoints.Count(); i++)
                           {
                              //Start of i to end of sInputString must compute to jk = i
                              string iToEnd = ComputeFromString(iEndPoints[i] + 1, sInputString.Length);
                              if (iToEnd == "i")
                              {
                                 for (int k = 0; k < kStartPoints.Count(); k++)
                                 {
                                    if (kStartPoints[k] > iEndPoints[i])
                                    {
                                       test++;
                                       
                                       string val = ComputeFromString(iEndPoints[i] + 1, kStartPoints[k]);
                                       if (val == "j")
                                       {
                                          found = true;
                                          break;
                                       }
                                    }
                                 }
                              }
                              if (found)
                              {
                                 break;
                              }
                           }

                           if (found)
                           {
                              result = cYes;
                           }
                           else
                           {
                              result = cNo;
                           }

                        }
                        else
                        {
                           result = cNo;
                        }
                     }
                     else
                     {
                        result = cNo;
                     }
      
                     string outputString = result;

                     //Output testcase 
                     string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + outputString;

                     Console.WriteLine(outputLine);
                     writer.WriteLine(outputLine);
                  }
               }
            }
         }
         catch (Exception exc)
         {
            Console.WriteLine(exc);
         }
         ///CompareResultWithExample();
      }

      static string ComputeFromString(int pStartPos, int pEndPos)
      {
         string leftMost = "";

         if (pStartPos < sInputString.Length)
         {

            leftMost = sInputString[pStartPos].ToString();

            for (int k = pStartPos + 1; k < pEndPos; k++)
            {
               leftMost = computeValue(leftMost, sInputString[k].ToString());
            }
         }
         return leftMost;
      }

      static bool FindSequence(int pOffset, char pCharToLookFor)
      {
         bool found = false;
         string leftMost;

         if (pOffset < sInputString.Length)
         {
            //k substring must be from offset to end of sInputString
            if (pCharToLookFor == 'k')
            {
               leftMost = sInputString[pOffset].ToString();
               if (leftMost == "k" && pOffset == sInputString.Length - 1)
               {
                  found = true;
               }
               else
               {
                  for (int k = pOffset + 1; k < sInputString.Length; k++)
                  {
                     leftMost = computeValue(leftMost, sInputString[k].ToString());
                  }
                  if (leftMost == "k")
                  {
                     found = true;
                  }
               }
            }
            else
            {
               leftMost = sInputString[pOffset].ToString();
               char nextChar = GetNextCharToSearchFor(pCharToLookFor);

               if (leftMost == pCharToLookFor.ToString())
               {
                  found = FindSequence(pOffset + 1, nextChar);
               }
               if (!found)
               {
                  for (int i = pOffset + 1; i < sInputString.Length; i++)
                  {
                     leftMost = computeValue(leftMost, sInputString[i].ToString());
                     if (leftMost == pCharToLookFor.ToString())
                     {
                        found = FindSequence(i + 1, nextChar);
                        if (found)
                        {
                           break;
                        }
                     }
                  }
               }
            }
         }


         return found;
      }

      static char GetNextCharToSearchFor(char pChar)
      {
         if (pChar == 'i')
         {
            return 'j';
         }
         else if (pChar == 'j')
         {
            return 'k';
         }
         return ' ';
      }
   
      static string computeValue(string pRowVal, string pColVal)
      {
         string v ="";
         bool isRowNeg = pRowVal.Contains('-');
         bool isColNeg = pColVal.Contains('-');

         char row = pRowVal[pRowVal.Length - 1];
         char col = pColVal[pColVal.Length - 1];
         
         int index = 0;

         if (col == '1') { index = 0; }
         else if (col == 'i') { index = 1; }
         else if (col == 'j') { index = 2; }
         else if (col == 'k') { index = 3; }


         if (row == '1'){  v = sRow1[index]; }
         else if (row == 'i') { v = sRowi[index]; }
         else if (row == 'j') { v = sRowj[index]; }
         else if (row == 'k') { v = sRowk[index]; }

         bool isVneg = v.Contains('-');

         //result is neg
         bool rowColNeg = (isColNeg && !isRowNeg) || (!isColNeg && isRowNeg);
         if (rowColNeg && isVneg)
         {
            v = v[v.Length - 1].ToString();
         }
         else if (rowColNeg && !isVneg)
         {
            v = "-" + v;
         }

         /*
         if ((isRowNeg && isVneg) ||
             (isColNeg && isVneg))
         {
            v = v[v.Length - 1].ToString();
         }
         else if ((isRowNeg && !isVneg) ||
                  (isColNeg && !isVneg))
         {
            v = "-" + v;
         }
          * */

         return v;
      }
   }


}
