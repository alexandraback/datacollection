using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Diamond_Inheritance
{
	class Program
	{
		static void Main(string[] args)
		{
			Input input = new Input(new StreamReader(args[0]));
			TextWriter output = new StreamWriter("output.txt");
			int CasesCount = input.NextInt();

			for (int tCase = 1; tCase <= CasesCount; tCase++) {
				int nodeCount = input.NextInt();

				Dictionary<int, List<int>> nodes = new Dictionary<int, List<int>>();
				for (int i = 1; i <= nodeCount; i++) {
					int edgeCount = input.NextInt();
					nodes.Add(i, new List<int>());
					for (int e = 0; e < edgeCount; e++)
						nodes[i].Add(input.NextInt());
				}

				bool hasDiamond = false;
				for (int node = 1; node <= nodeCount && !hasDiamond; node++) {
					Dictionary<int, HashSet<int>> inheritance = new Dictionary<int, HashSet<int>>();
					for (int i = 1; i <= nodeCount; i++)
						inheritance.Add(i, new HashSet<int>());

					HashSet<int> closedNodes = new HashSet<int>();
					Queue<int> openNodes = new Queue<int>();
					openNodes.Enqueue(node);

					while (openNodes.Count > 0 && !hasDiamond) {
						int currNode = openNodes.Dequeue();

						foreach (var edge in nodes[currNode])
							if (inheritance[edge].Overlaps(inheritance[currNode]))
								hasDiamond = true;
							else {
								inheritance[edge].Add(currNode);
								inheritance[edge].UnionWith(inheritance[currNode]);
								if (!closedNodes.Contains(edge))
									openNodes.Enqueue(edge);
							}

						closedNodes.Add(currNode);
					}
				}

				output.WriteLine("Case #{0}: {1}", tCase, (hasDiamond) ? "Yes" : "No");
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
