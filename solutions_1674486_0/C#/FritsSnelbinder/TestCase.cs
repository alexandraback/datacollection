using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace DiamondInheritance
{
	public class TestCase
	{
		private static CultureInfo _ci = null;

		/// <summary>
		/// Returns a CultureInfo that doesn't emit the '.' thousand separator.
		/// </summary>
		public static CultureInfo Culture
		{
			get
			{
				if (_ci == null)
				{
					_ci = (CultureInfo)CultureInfo.InvariantCulture.Clone();
					_ci.NumberFormat.NumberGroupSizes = new int[0];
				}

				return _ci;
			}
		}

		public class Class
		{
			public int Id;
			public int[] Parents;

			public static List<Class> Classes;

			public Class(int id, IEnumerable<int> parents)
			{
				Id = id;
				Parents = parents.ToArray();
			}

			private List<Class> _roots = null;

			public List<Class> GetRoots()
			{
				if (_roots == null)
				{
					_roots = new List<Class>();
					List<Class> parents = GetParents();
					if (parents.Count == 0)
					{
						_roots.Add(this);
					}
					else
					{
						foreach (Class node in GetParents())
						{
							_roots.AddRange(node.GetRoots());
						}
					}
				}

				return _roots;
			}

			public List<Class> GetParents()
			{
				return Parents.Select(id => Classes[id]).ToList();
			}

			public override string ToString()
			{
				string parents = string.Join(", ", Parents.Select(p => p.ToString()).ToArray());
				return string.Format("Class ID={0}, parents=({1})", Id, parents);
			}
		}

		public List<Class> Classes { get; private set; }

		public TestCase(IEnumerable<Class> classes)
		{
			Classes = new List<Class>(classes);
		}

		public string CalculateResult()
		{
			Class.Classes = this.Classes;

			//For all nodes that inherit from more than 1 parent..
			foreach (Class cls in Classes.Where(c => c.Parents.Length > 1))
			{
				//Determine the roots through each of its parents. If they share a root, the diagram 
				//contains a diamond.
				Dictionary<int, int> known = new Dictionary<int, int>();
				try
				{
					List<Class> parents = cls.GetParents();
					foreach (Class p in parents)
					{
						foreach(Class root in p.GetRoots())
							known.Add(root.Id, root.Id);
					}
				}
				catch (Exception)
				{
					return "Yes";
				}
			}

			return "No";
		}

		public static TestCase Parse(string[] lines, int startLine, out int linesConsumed)
		{
			int classCount = Int32.Parse(lines[startLine]);

			List<Class> classes = new List<Class>(classCount + 1);
			classes.Add(new Class(0, new int[] { 0 }));

			for (int index = 0; index < classCount; index++)
			{
				int[] values = lines[startLine + 1 + index].Trim().Split(' ')
					.Select(nr => Int32.Parse(nr))
					.ToArray();

				classes.Add(new Class(index + 1, values.Skip(1)));
			}

			linesConsumed = 1 + classCount;
			return new TestCase(classes);
		}
	}
}
