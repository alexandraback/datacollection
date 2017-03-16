using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

class AddressOfOperator
{
    static void Main()
    {

        string[] lines = System.IO.File.ReadAllLines(@"C:\Users\varun\Desktop\A-small-attempt0.in");
        System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\Users\varun\Desktop\output.txt");

        // Display the file contents by using a foreach loop.
        int count1 = int.Parse(lines[0]);
        int case1=1;
        int i = 0;
        int r = 0;
        while (r<count1)
        {
            Dictionary<int, List<int>> lst = new Dictionary<int, List<int>>();

            int newcount = int.Parse(lines[++i]);
            bool flag1 = false;
            for (int m = 1; m <= newcount; m++)
            {
                i++;
                string[] numbers1 = lines[i].Split(' ');
                List<int> numbers = new List<int>();
                for (int l = 1; l < numbers1.Length; l++)
                {
                   numbers.Add(int.Parse( numbers1[l]));
                }
                //numbers.RemoveAt(0);
                lst.Add(m, numbers);
            }

            //Process list.
            foreach (int key in lst.Keys)
            {
               // List<int> toFindPaths = lst[key];
                 List<int> a= new List<int>();
                    for(int k=1;k<=newcount;k++)
                    {
                      //  if(!toFindPaths.Contains(k))
                        a.Add(k);
                    }
             //   a.Except(toFindPaths);
                a.Remove(key);
               flag1= checkPaths(key, a, lst);
               if (flag1)
                   break;
            }

            string output = flag1 ? "Yes" : "No";
            file.WriteLine(string.Format("Case #{0}: {1}", case1++, output));
            r++;
        }


       
        file.Close();
        Console.WriteLine("abc");
       
        Console.ReadLine();
    }

    private static bool checkPaths(int key, List<int> a, Dictionary<int, List<int>> lst)
    {
        
        foreach (int toelement in a)
        {
            int count = 0;
            foreach (int m in lst[key])
            {
                if (m == toelement)
                {
                    if ((++count) > 1)
                    {
                        return true;
                    }
                }
                if (checkPath(m, toelement, lst))
                {
                    if ((++count) > 1)
                    {
                        return true;
                    }
                }
                //check toElement from lst[key]
            }
        }

        return false;
    }

    private static bool checkPath(int key, int toelement, Dictionary<int, List<int>> lst)
    {
        bool flag = false;
        foreach (int m in lst[key])
        {
            if (m == toelement)
            {
                return true;
            }
            else
            {
                flag= checkPath(m, toelement, lst);
                if (flag)
                { return flag; }
            }
        }
        return false;
    }
}
