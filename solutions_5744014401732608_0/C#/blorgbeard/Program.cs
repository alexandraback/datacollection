using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace slides
{
    class Program
    {
        static List<Tuple<int, int>> GetInput()
        {
            var cases = int.Parse(Console.ReadLine());
            var result = new List<Tuple<int, int>>(cases);
            for (int i = 0; i < cases; i++)
            {
                var splut = Console.ReadLine().Split().Select(int.Parse).ToList();
                result.Add(Tuple.Create(splut[0], splut[1]));
            }
            return result;
        } 

        static void Main(string[] args)
        {
            int i = 1;
            foreach (var problem in GetInput())
            {
                var state = Solve(problem.Item1, problem.Item2);
                Console.WriteLine("Case #{0}: {1}", i++, state.IsPossible ? "POSSIBLE" : "IMPOSSIBLE");
                if (state.IsPossible)
                {
                    Console.WriteLine(state.GetMatrix());
                }
            }

            try { Console.ReadKey(); }
            catch { }

        }

        static State Solve(int buildingCount, int wayCount)
        {
            var result = new State(buildingCount);

            // pre-fill the state with slides from 1 to every other node
            for (int i = 1; i < buildingCount; i++)
            {
                result.AddSlide(0, i);
            }

            while (true)
            {
                var ways = result.Ways;
                if (ways == wayCount)
                {
                    result.IsPossible = true;
                    return result;
                }

                if (result.IsFullOfSlides())
                {
                    result.IsPossible = false;
                    return result;
                }

                // find a place to add a slide
                // only slides from lower to higher indices are allowed
                var target = wayCount - ways;

                var slides = result.PossibleSlides().ToList();
                foreach (var s in slides)
                {
                    s.Ways = result.WaysTo(s.StartPoint) * result.WaysFrom(s.EndPoint);
                }

                var slide = slides.OrderByDescending(t => t.Ways).FirstOrDefault(t => t.Ways <= target);

                if (slide == null)
                {
                    // fudge
                    result.IsPossible = false;
                    return result;
                }

                result.AddSlide(slide.StartPoint, slide.EndPoint);
            }            
        }
    }

    class State
    {
        public bool IsPossible { get; set; }

        public int Ways
        {
            get { return WaysTo(Buildings.Count - 1); }
        }

        public string GetMatrix()
        {
            var sb = new StringBuilder(Buildings.Count * (Buildings.Count + 2));
            for (int i = 0; i < Buildings.Count; i++)
            {
                for (int j = 0; j < Buildings.Count; j++)
                {
                    sb.Append(Buildings[i].OutgoingSlides.Any(t => t.EndPoint == j) ? "1" : "0");
                }
                sb.AppendLine();
            }
            return sb.ToString().TrimEnd();
        }

        public List<Building> Buildings { get; set; }

        public State(int buildings)
        {
            Buildings = Enumerable.Range(1, buildings).Select(t => new Building()).ToList();
        }

        public void AddSlide(int source, int destination)
        {
            Slide slide = new Slide()
            {
                StartPoint = source,
                EndPoint = destination,
            };
            Buildings[source].OutgoingSlides.Add(slide);
            Buildings[destination].IncomingSlides.Add(slide);
        }

        public IEnumerable<Slide> PossibleSlides()
        {
            for (int b1 = 0; b1 < Buildings.Count - 1; b1++)
            {
                for (int b2 = Buildings.Count - 1; b2 > b1; b2--)
                {
                    if (!Buildings[b1].OutgoingSlides.Any(t=>t.EndPoint==b2))
                        yield return new Slide() {StartPoint = b1, EndPoint = b2};
                }
            }
        }

        public bool IsFullOfSlides()
        {
            // if every building has every possible slide (a slide to every building higher in number than it)
            // then we are full.
            return
                Enumerable.Range(0, Buildings.Count)
               .All(b => Buildings[b].OutgoingSlides.Count == Buildings.Count - (b + 1));
        }

        public int WaysTo(int building)
        {
            if (building == 0) return 1;
            return Buildings[building].IncomingSlides.Sum(slide => WaysTo(slide.StartPoint));
        }

        public int WaysFrom(int building)
        {
            if (building == Buildings.Count-1) return 1;
            return Buildings[building].OutgoingSlides.Sum(slide => WaysFrom(slide.EndPoint));
        }

    }

    internal class Building
    {
        public List<Slide> OutgoingSlides { get; set; }
        public List<Slide> IncomingSlides { get; set; }

        public Building()
        {
            OutgoingSlides = new List<Slide>();
            IncomingSlides = new List<Slide>();
        }
    }

    class Slide
    {
        public int StartPoint { get; set; }
        public int EndPoint { get; set; }
        //public bool Exists { get; set; }
        public int Ways { get; set; }
    }
}
