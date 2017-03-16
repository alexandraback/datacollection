using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Kingdom_Rush
{
	class Program
	{
		const int MaxStars = 2;

		class Level
		{
			public int[] StarsRequired;
			public int collectedStars = 0;
			private int id;

			public Level(int[] starsRequired, int id)
			{
				this.id = id;
				this.StarsRequired = starsRequired;
			}

			public override bool Equals(object obj)
			{
				return this.id == ((Level)obj).id;
			}
		}

		/*static int calcPlaythroughs(LinkedList<Level> levels, int stars)
		{
			int playedLevels = 0;

			while (levels.Count > 0) {
				Level levelToPlay = null;
				int rewardStars = 0;

				foreach (var level in levels)
					if (level.StarsRequired[MaxStars - 1] <= stars && level.collectedStars == 0) {
						levelToPlay = level;
						rewardStars = 2;
						break;
					}

				if (levelToPlay == null)
					foreach (var level in levels)
						if (level.StarsRequired[MaxStars - 1] <= stars && level.collectedStars > 0) {
							levelToPlay = level;
							rewardStars = 1;
							break;
						}

				if (levelToPlay == null) {
					List<Level> possibilities = new List<Level>();

					foreach (var level in levels)
						if (level.StarsRequired[MaxStars - 2] <= stars)
							possibilities.Add(level);

					rewardStars = 1;
					int bestPlaythroughs = int.MaxValue;

					foreach (var level in possibilities) {
						var newLevels = new LinkedList<Level>(levels);
						newLevels.Find(level).Value.collectedStars
						int playthroughs = calcPlaythroughs(new LinkedList<Level>(levels), stars + rewardStars);
					}
					
				}

				if (levelToPlay == null) {
					playedLevels = -1;
					break;
				}
				else {

					stars += rewardStars;
					playedLevels++;
					levelToPlay.collectedStars += rewardStars;

					if (levelToPlay.collectedStars == MaxStars)
						levels.Remove(levelToPlay);

				}
			}

			return playedLevels;
		}*/

		static void Main(string[] args)
		{
			Input input = new Input(new StreamReader(args[0]));
			TextWriter output = new StreamWriter("output.txt");
			int CasesCount = input.NextInt();

			for (int tCase = 1; tCase <= CasesCount; tCase++) {
				int levelCount = input.NextInt();

				LinkedList<Level> levels = new LinkedList<Level>();
				for (int level = 0; level < levelCount; level++)
					levels.AddLast(new Level(new int[] { 
						input.NextInt(),
						input.NextInt()
					}, level));

				int stars = 0;
				int playedLevels = 0;
				
				while (levels.Count > 0) {
					Level levelToPlay = null;
					int rewardStars = 0;

					foreach (var level in levels)
						if (level.StarsRequired[MaxStars - 1] <= stars && level.collectedStars == 0) {
							levelToPlay = level;
							rewardStars = 2;
							break;
						}

					if (levelToPlay == null)
						foreach (var level in levels)
							if (level.StarsRequired[MaxStars - 1] <= stars && level.collectedStars > 0) {
								levelToPlay = level;
								rewardStars = 1;
								break;
							}

					if (levelToPlay == null) {
						int twoStarReq = int.MinValue;

						foreach (var level in levels)
							if (level.StarsRequired[MaxStars - 2] <= stars && level.collectedStars == 0 && level.StarsRequired[MaxStars - 1] > twoStarReq) {
								levelToPlay = level;
								rewardStars = 1;
								twoStarReq = level.StarsRequired[MaxStars - 1];
							}
					}

					if (levelToPlay == null)
						break;
					else {
						
						stars += rewardStars;
						playedLevels++;
						levelToPlay.collectedStars += rewardStars;

						if (levelToPlay.collectedStars == MaxStars)
							levels.Remove(levelToPlay);
					}
				}

				if (levels.Count > 0)
					output.WriteLine("Case #{0}: {1}", tCase, "Too Bad");
				else
					output.WriteLine("Case #{0}: {1}", tCase, playedLevels);
			}

			output.Close();
		}
	}

	class Input
	{
		TextReader inputStream = null;
		Queue<string> currentLine = new Queue<string>();

		#region Constructors
		public Input(TextReader inputStream)
		{
			this.inputStream = inputStream;
		}

		public Input()
			: this(Console.In)
		{ }

		public Input(string filename)
			: this(new StreamReader(filename))
		{ }
		#endregion

		public string Next()
		{
			while (currentLine.Count == 0)
				foreach (string word in inputStream.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
					currentLine.Enqueue(word);

			return currentLine.Dequeue();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
		}

		public float NextFloat()
		{
			return float.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}
