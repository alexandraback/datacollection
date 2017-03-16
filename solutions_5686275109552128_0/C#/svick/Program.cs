using System;
using System.IO;
using System.Linq;
using C5;
using GCJ_base;

namespace GCJ_QB
{
    class Program
    {
        static void Main()
        {
            new GcjQB().Run();
        }
    }

    sealed class PancakeGroup : IComparable<PancakeGroup>
    {
        public int Pancakes { get; }
		public int Divisions { get; }
	    public int Result => (Pancakes - 1) / Divisions + 1;

	    public PancakeGroup(int pancakes)
		    : this(pancakes, 1)
	    {}

	    private PancakeGroup(int pancakes, int divisions)
	    {
			if (pancakes <= 0 || divisions <= 0)
				throw new ArgumentException();

		    Pancakes = pancakes;
		    Divisions = divisions;
	    }

	    public PancakeGroup Divide()
	    {
		    return new PancakeGroup(Pancakes, Divisions + 1);
	    }

	    public int CompareTo(PancakeGroup other)
	    {
		    return Result.CompareTo(other.Result);
	    }

	    public override string ToString() => $"{Pancakes} / {Divisions} = {Result}";
    }

    class GcjQB : Gcj
    {
        public GcjQB()
        {
            Problem = 'B';
            Small = true;
            Attempt = 2;
        }

        protected override string ComputeCase(TextReader reader)
        {
            reader.ReadLine();
            var numbers = ReadIntLine(reader);

            var heap = new IntervalHeap<PancakeGroup>();
            heap.AddAll(numbers.Select(x => new PancakeGroup(x)));

            int fixedSteps = 0;
	        int mostBefore = heap.FindMax().Result;
            int eatingSteps = mostBefore;

            int movingSteps = 0;

            while (!heap.IsEmpty && movingSteps < eatingSteps)
            {
	            var largestCurrent = heap.DeleteMax();

	            heap.Add(largestCurrent.Divide());

                movingSteps++;

                int mostAfter = heap.FindMax().Result;

                if (movingSteps < mostBefore - mostAfter)
                {
                    fixedSteps += movingSteps;

                    mostBefore = mostAfter;
                    eatingSteps = mostBefore;

                    movingSteps = 0;
                }
            }

            int result = fixedSteps + Math.Min(movingSteps, eatingSteps);

            return result.ToString();
        }
    }
}