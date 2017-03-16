using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam13.Round1B2013
{
    public class A : ITest
    {
        public string Process(List<string> file)
        {
            var line = file.First();
            file.RemoveAt(0);

            var line2 = file.First();
            file.RemoveAt(0);

            var mySize = Int32.Parse(line.Split(' ')[0]);
            var others = line2.Split(' ').Select(x => Int32.Parse(x)).OrderBy(y => y).ToList();

            if (mySize == 1)
                return others.Count.ToString();

            var moves = Score(mySize, others);

            return moves.ToString();
        }

        public int Score(int mySize, List<int> others)
        {
            while (others.Any())
            {
                if (mySize > others[0])
                {
                    mySize += others[0];
                    others.RemoveAt(0);
                    continue;
                }
                else
                {
                    // see what would happen if we 
                    var testOthers = new List<int>(others);                    
                    testOthers.Insert(0, mySize - 1);

                    var testScore = 1 + Score(mySize, testOthers);
                    return (testScore < others.Count) ? testScore : others.Count;

                    // else we decide what to do...
                }
            }

            return 0;
        }
    }
}
