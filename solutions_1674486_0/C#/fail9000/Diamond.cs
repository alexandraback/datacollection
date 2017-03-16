using System;
using System.Collections.Generic;
using System.Linq;

namespace CodeJamQualifications
{
    class Phony
    {
        public List<Phony> BaseClasses = new List<Phony>();
        public List<int> BaseIDs = new List<int>();
        public int ID;

        public Phony(int id)
        {
            ID = id;
        }

        public void AddBase(Phony phony)
        {
            BaseClasses.Add(phony);

            // add all id's of base classes
            BaseIDs.AddRange(phony.BaseIDs);
            BaseIDs.Add(phony.ID);
        }

        public Dictionary<Phony, int> GetInheritanceCount()
        {
            var dictionary = new Dictionary<Phony, int>();
            var ancestors = GetAllAncestors();

            foreach (var ancestor in ancestors)
            {
                if (dictionary.ContainsKey(ancestor))
                {
                    dictionary[ancestor]++;
                }
                else dictionary[ancestor] = 1;
            }

            return dictionary;
        }

        public List<Phony> GetAllAncestors()
        {
            var ancestors = new List<Phony>();
            var stack = new Stack<Phony>();

            BaseClasses.ForEach(stack.Push);

            while(stack.Count > 0)
            {
                var current = stack.Pop();
                ancestors.Add(current);

                current.BaseClasses.ForEach(stack.Push);
            }

            return ancestors;
        }
    }

    class Diamond : IProblem
    {
        public void Run()
        {
            var cases = int.Parse(Console.ReadLine());

            for (var i = 0; i < cases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, DoCase() ? "Yes" : "No");
            }

            //Console.ReadKey();
        }

        private bool HaveSameAncestor(Phony lhs, Phony rhs)
        {
            var first = lhs.GetAllAncestors();
            var second = rhs.GetAllAncestors();

            for (var i = 0; i < first.Count; i++)
            {
                for (var j = 0; j < second.Count; j++)
                {
                    if (first[i] == second[j]) return true;
                }
            }

            return false;
        }

        private bool DoCase()
        {
            var classes = int.Parse(Console.ReadLine());
            var classList = new List<Phony>();

            Enumerable.Range(1, classes).ToList().ForEach(n => classList.Add(new Phony(n)));


            for (var i = 1; i <= classes; i++)
            {
                var i1 = i;
                var current = classList.First(c => c.ID == i1);

                // connect it
                var connections = Console.ReadLine().Split(' ');
                for (var j = 0; j < int.Parse(connections[0]); j++)
                {
                    current.AddBase(classList.First(c => c.ID == int.Parse(connections[j + 1])));
                }
            }

            // return if any have same ancestor
            foreach (var phoney in classList)
            {
                var ancestorDict = phoney.GetInheritanceCount();
                foreach (var i in ancestorDict.Values)
                {
                    if (i > 1) return true;
                }
                //var baseClasses = phoney.BaseClasses;
                //for (int i = 0; i < baseClasses.Count; i++)
                //{
                //    for (int j = i + 1; j < baseClasses.Count; j++)
                //    {
                //        if (HaveSameAncestor(baseClasses[i], baseClasses[j])) return true;

                //        if (baseClasses[i].BaseClasses.Contains(baseClasses[j]) ||
                //            baseClasses[j].BaseClasses.Contains(baseClasses[i])) return true;


                //    }
                //}
            }
            return false;
        }
    }
}
