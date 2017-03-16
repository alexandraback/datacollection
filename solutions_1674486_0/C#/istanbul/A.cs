// IOHelper.cs can be downloaded from http://kadiryazgan.com/codejam/IOHelper.cs.txt

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.Y2012.Round1C
{
	class A
	{
		class C
		{
			public int ID { get; set; }
			public List<C> Parents { get; set; }
			public C(int id)
			{
				this.ID = id;
				this.Parents = new List<C>();
			}

			public void GetParents(List<C> list)
			{
				foreach (var p in this.Parents)
				{
					list.Add(p);
					p.GetParents(list);
				}
			}

			public override string ToString()
			{
				return "[" + this.ID + "]";
			}
		}

		static void Main(string[] args)
		{
			new A("test");
			new A("A-small-0");
			//new A("A-large-0");
		}

		IOHelper io;

		public A(string inputName)
		{
			using (io = new IOHelper(inputName))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					int nClasses = io.ReadInt();
					C[] classes = new C[nClasses];
					for (int i = 0; i < nClasses; i++)
					{
						classes[i] = new C(i + 1);
					}

					for (int i = 0; i < nClasses; i++)
					{
						var parents = io.ReadIntArray().Skip(1).ToArray();
						foreach (int j in parents)
						{
							classes[i].Parents.Add(classes[j - 1]);
						}
					}


					bool ok = false;
					for (int i = 0; i < nClasses; i++)
					{
						if (classes[i].Parents.Count > 1)
						{
							List<C> generalList = new List<C>();
							foreach (var p in classes[i].Parents)
							{
								generalList.Add(p);
							}

							foreach (var p in classes[i].Parents)
							{
								List<C> localList = new List<C>();
								p.GetParents(localList);

								
								foreach (var l in localList)
								{
									if (generalList.Contains(l))
									{
										ok = true;
										goto exitLoop;
									}
									generalList.Add(l);
								}
							}

						}
					}

				exitLoop:

					io.WriteLine("Case #{0}: {1}", _case, ok ? "Yes" : "No");
				}
			}
		}
	}
}
