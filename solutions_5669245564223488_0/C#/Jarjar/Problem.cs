using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ32
{
    public class Problem
    {
        long modulo = 1000000007;
        public Problem()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        string result = string.Empty;
                        int nbWagons = Int32.Parse(sr.ReadLine());
                        string lineWagons = sr.ReadLine();
                        result = Handle(lineWagons, nbWagons);

                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }
                    sw.Flush();
                }

            }
        }

        string Handle(string lineWagons, int nbWagons)
        {
            string result = string.Empty;

            string[] setOfWagons = lineWagons.Split(new char[] { ' ' });
            List<string> wagons = new List<string>();
            List<string> excludedLetters = new List<string>();
            for (int i = 0; i < nbWagons; i++)
            {
                // simplify to handle easily internal letters further. abbbccc -> abc and as aa and aa are two different wagons, aa and aaa still remain two different wagons in the form of a and a.
                string wag = simplify(setOfWagons[i]);
                foreach (string s in excludedLetters)
                {
                    if (wag.Contains(s))
                        return "0"; // FAIL
                }
                string beg = wag.Substring(0, 1);
                string end = wag.Substring(wag.Length - 1, 1);
                if (beg == end && wag.Length > 1) // aba
                    return "0"; // FAIL
                if (wag.Length > 2)
                {
                    for (int j = 1; j < wag.Length - 1; j++)
                    {
                        string toExclude = wag.Substring(j, 1);
                        if (beg == toExclude || end == toExclude) // if interior is also end or exclude, then fail
                            return "0"; // FAIL
                        if (!excludedLetters.Contains(toExclude))
                            excludedLetters.Add(toExclude);
                    }
                }
                if (beg != end)
                    wagons.Add(beg + end); // by the time, we will have exclude all interior letters and we will just keep ab bc cd a b c and then we need to compose from that
                else
                    wagons.Add(beg);
            }
            List<List<string>> trainSubSet = new List<List<string>>();
            long count = 1;
            long subelements = 0;
            List<long> subcount = new List<long>();
            while (wagons.Count > 0)
            {
                long countWag = 1;
                subelements++;
                string wag = wagons[0];
                List<String> subset = new List<string>();
                subset.Add(wag);
                trainSubSet.Add(subset);
                wagons.Remove(wag);
                if (wag.Length == 2)
                {
                    string beg = wag.Substring(0, 1);
                    string end = wag.Substring(1, 1);
                    if (wagons.FindAll(wagon => wagon.Length == 2 && wagon[0] == wag[0]).Count > 0) return "0";
                    if (wagons.FindAll(wagon => wagon.Length == 2 && wagon[1] == wag[1]).Count > 0) return "0";
                    // Fill the subset with single item that can be placed anywhere.
                    List<string> singleStarter = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == wag[0]));
                    subset.AddRange(singleStarter);
                    wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == wag[0]));
                    countWag *= factoriel(singleStarter.Count);
                    countWag %= modulo;
                    var singleEnder = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == wag[1]));
                    subset.AddRange(singleEnder);
                    countWag *= factoriel(singleEnder.Count);
                    countWag %= modulo;
                    wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == wag[1]));

                    // Now let's find next element to complete the chain
                    List<string> nextElements = wagons.FindAll(wagon => wagon[0] == end[0]);
                    while (nextElements.Count > 0)
                    {
                        if (nextElements.Count > 1) // more than one next elements and the single items already handled
                            return "0"; // FAIL
                        // Fill the subset with single item that can be placed anywhere.
                        string next = nextElements[0];
                        wagons.Remove(next);
                        singleEnder = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == next[1]));
                        subset.AddRange(singleEnder);
                        countWag *= factoriel(singleEnder.Count);
                        countWag %= modulo;
                        wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == next[1]));
                        nextElements = wagons.FindAll(wagon => wagon[0] == next[1]);
                    }
                    // End of nextElements / End of this subtrain
                    
                    // Now let's find previous element to complete the chain
                    List<string> prevElements = wagons.FindAll(wagon => wagon.Length > 1 && wagon[1] == beg[0]);
                    while (prevElements.Count > 0)
                    {
                        if (prevElements.Count > 1) // more than one next elements and the single items already handled
                            return "0"; // FAIL
                        // Fill the subset with single item that can be placed anywhere.
                        string prev = prevElements[0];
                        wagons.Remove(prev);
                        singleStarter = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == prev[0]));
                        subset.AddRange(singleStarter);
                        countWag *= factoriel(singleStarter.Count);
                        countWag %= modulo;
                        wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == prev[0]));
                        prevElements = wagons.FindAll(wagon => wagon.Length >1 && wagon[1] == prev[0]);
                    }
                    // End of previous elements / End of the beginning of this subtrain / End of this subtrain
                }
                else if (wag.Length == 1)
                {
                    string beg = wag.Substring(0, 1);
                    string end = wag.Substring(0, 1); // It's the same, I know
                    // Fill the subset with single item that can be placed anywhere.
                    List<string> singleStarter = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == wag[0]));
                    subset.AddRange(singleStarter);
                    wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == wag[0]));
                    countWag *= factoriel(singleStarter.Count+1); // including wag that is similar to them
                    countWag %= modulo;
                    List<string> singleEnder;

                    // Now let's find next element to complete the chain
                    List<string> nextElements = wagons.FindAll(wagon => wagon[0] == end[0]);
                    while (nextElements.Count > 0)
                    {
                        if (nextElements.Count > 1) // more than one next elements and the single items already handled
                            return "0"; // FAIL
                        // Fill the subset with single item that can be placed anywhere.
                        string next = nextElements[0];
                        wagons.Remove(next);
                        singleEnder = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == next[1]));
                        subset.AddRange(singleEnder);
                        countWag *= factoriel(singleEnder.Count);
                        countWag %= modulo;
                        wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == next[1]));
                        nextElements = wagons.FindAll(wagon => wagon[0] == next[1]);
                    }
                    // End of nextElements / End of this subtrain

                    // Now let's find previous element to complete the chain
                    List<string> prevElements = wagons.FindAll(wagon => wagon.Length >1 && wagon[1] == beg[0]);
                    while (prevElements.Count > 0)
                    {
                        if (prevElements.Count > 1) // more than one next elements and the single items already handled
                            return "0"; // FAIL
                        // Fill the subset with single item that can be placed anywhere.
                        string prev = prevElements[0];
                        wagons.Remove(prev);
                        singleStarter = wagons.FindAll(wagon => wagon.Length == 1 && (wagon[0] == prev[0]));
                        subset.AddRange(singleStarter);
                        countWag *= factoriel(singleStarter.Count);
                        countWag %= modulo;
                        wagons.RemoveAll(wagon => wagon.Length == 1 && (wagon[0] == prev[0]));
                        prevElements = wagons.FindAll(wagon => wagon.Length > 1 && wagon[1] == prev[0]);
                    }
                    // End of previous elements / End of the beginning of this subtrain / End of this subtrain
                }
                subcount.Add(countWag);
            }

            count = factoriel(subcount.Count);
            foreach (long c in subcount)
            {
                count *= c;
                count %= modulo;
            }
            result = count.ToString();
            return result;
        }


        long Count(List<string> subset)
        {
            List<string> simplified = new List<string>();
            foreach (string s in subset)
            {
                for (int i = 1; i < s.Length - 1; i++)
                {
                    foreach (string s2 in subset)
                    {

                    }
                }
            }
            
            return 1;
        }

        string simplify(string input)
        {
            string output = string.Empty;
            char last = ' ';
            for (int i = 0; i < input.Length; i++)
            {
                if (last == input[i])
                    continue;
                last = input[i];
                output += input[i];
            }
            return output;
        }

        long factoriel(long input)
        {
            long result = 1;
            if (input == 0)
                return result;
            for (long i = 1; i <= input; i++)
            {
                result *= i;
                result %= modulo;
            }
            return result;
        }
       }
}
