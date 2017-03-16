using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Diamond {
	class Diamond {
		static void Main(string[] args) {
			using (StreamReader reader = new StreamReader(args[0])) {
				using (StreamWriter writer = new StreamWriter(args[1])) {
					int numproblems = int.Parse(reader.ReadLine());

					for (int n = 1; n <= numproblems; n++) {
						int numclasses = int.Parse(reader.ReadLine());

						SortedSet<int>[] inheritances = new SortedSet<int>[numclasses];
						SortedSet<int>[] reverses = new SortedSet<int>[numclasses];

						for (int i = 0; i < numclasses; i++) {
							inheritances[i] = new SortedSet<int>();
							reverses[i] = new SortedSet<int>();
						}

						SortedSet<int> heads = new SortedSet<int>();

						for (int i = 1; i <= numclasses; i++) {
							string[] tokens = reader.ReadLine().Split(' ');

							for (int j = 1; j <= int.Parse(tokens[0]); j++) {
								int parent = int.Parse(tokens[j]);
								inheritances[i - 1].Add(parent);
								reverses[parent - 1].Add(i);
							}

							if (inheritances[i - 1].Count == 0) {
								heads.Add(i);
							}
						}

						string test = "No";
						foreach (int head in heads) {
							if (CheckHead(head, inheritances, reverses)) {
								test = "Yes";
								break;
							}
						}

						writer.WriteLine("Case #" + n + ": " + test);
						Console.WriteLine("Case #" + n + ": " + test);
					}
				}
			}
		}

		private static bool CheckHead(int head, SortedSet<int>[] inheritances, SortedSet<int>[] reverses) {
			SortedSet<int> tested = new SortedSet<int>();
			SortedSet<int> frontier = new SortedSet<int>();
			frontier.Add(head);

			while (frontier.Count > 0) {
				SortedSet<int> new_frontier = new SortedSet<int>();

				foreach (int item in frontier) {
					if (tested.Contains(item)) {
						return true;
					}
					tested.Add(item);
					foreach (int child in reverses[item - 1]) {
						if (new_frontier.Contains(child)){
							return true;
						}
						new_frontier.Add(child);
					}
				}

				frontier = new_frontier;
			}

			return false;
		}
	}
}
