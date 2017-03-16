namespace CodeJam
{
	using System;
	using System.IO;

	/// <summary>
	/// Helper for code jam example/test execution.
	/// </summary>
	public static class Example
	{
		/// <summary>
		/// Run a test by handling IO and call real worker.
		/// </summary>
		/// <param name="inputName">Input file name.</param>
		/// <param name="outputName">Output file name.</param>
		/// <param name="work">Real work.</param>
		public static void RunTest(string inputName, string outputName, Action<StreamReader, StreamWriter> work)
		{
			using (var result = File.OpenWrite(outputName))
			{
				using (var resultWriter = new StreamWriter(result))
				{
					using (var input = File.OpenText(inputName))
					{
						work(input, resultWriter);
					}
				}
			}
		}

		/// <summary>
		/// Dispatch a set of inputs as smaller work units.
		/// </summary>
		/// <param name="reader">Input reader.</param>
		/// <param name="writer">Output writer.</param>
		/// <param name="work">Smaller work.</param>
		public static void WorkCases(StreamReader reader, StreamWriter writer, Action<int, int, StreamReader, StreamWriter> work)
		{
			var cases = Convert.ToInt32(reader.ReadLine());

			for (var i = 0; i < cases; i++)
			{
				work(cases, i, reader, writer);
			}
		}

		/// <summary>
		/// Dispatch a set of inputs as smaller work units.
		/// </summary>
		/// <param name="reader">Input reader.</param>
		/// <param name="writer">Output writer.</param>
		/// <param name="work">Smaller work.</param>
		public static void WorkCases<T>(StreamReader reader, StreamWriter writer, Func<int, int, StreamReader, T> work)
		{
			var cases = Convert.ToInt32(reader.ReadLine());

			for (var i = 0; i < cases; i++)
			{
				writer.WriteLine("Case #{0}: {1}", i + 1, work(cases, i, reader));
			}
		}
	}
}
