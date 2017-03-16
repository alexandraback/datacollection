using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Out_of_Gas
{
	class Program
	{
		class Period
		{
			public double startTime;
			public double endTime;
			public double startPosition;
			public double endPosition;

			public Period(double startTime, double endTime,	double startPosition, double endPosition, double maxPosition)
			{
				this.endPosition = endPosition;
				this.endTime = endTime;
				this.startPosition = startPosition;
				this.startTime = startTime;

				if (startPosition > maxPosition) {
					this.startPosition = maxPosition;
					this.endPosition = maxPosition;
					this.endTime = startTime;
				}
				if (endPosition > maxPosition) {
					this.endPosition = maxPosition;
					double v = (endPosition - startPosition) / (endTime - startTime);
					this.endTime = startTime + (maxPosition - startPosition) / v;
				}
			}

			public double velocity
			{
				get
				{
					return (endPosition - startPosition) / (endTime - startTime);
				}
			}

			public double dT
			{
				get { return (endTime - startTime); }
			}
		}

		static void Main(string[] args)
		{
			Input input = new Input(new StreamReader(args[0]));
			TextWriter output = new StreamWriter("output.txt");
			int CasesCount = input.NextInt();

			for (int tCase = 1; tCase <= CasesCount; tCase++) {
				double initialDistance = input.NextDouble();
				int blocadePositionCount = input.NextInt();
				int accelerationCount = input.NextInt();

				double lastTime = input.NextDouble();
				double lastPosition = input.NextDouble();
				List<Period> periods = new List<Period>();
				for (int i = 1; i < blocadePositionCount; i++) {
					double time = input.NextDouble();
					double position = input.NextDouble();
					
					periods.Add(new Period(
						lastTime,
						time,
						lastPosition,
						position,
						initialDistance
					));

					lastPosition = position;
					lastTime = time;
				}
				if (periods.Count ==0)
					periods.Add(new Period
					(
						lastTime,
						lastTime,
						lastPosition,
						lastPosition,
						initialDistance
					));

				output.WriteLine("Case #{0}:", tCase);
				for (int accelerationIndex = 0; accelerationIndex < accelerationCount; accelerationIndex++) {
					double a = input.NextDouble();
					double x = 0, v = 0, t = 0;

					foreach (Period period in periods) {
						//double maxPosition = x + v * period.dT + 0.5 * a * period.dT * period.dT;

						double C = period.startPosition - x;
						double B = period.velocity - v;
						double A = -0.5 * a;

						double interceptTime = (-B - Math.Sqrt(B * B - 4 * A * C)) / (2 * A);

						if (interceptTime > period.dT) {
							t += period.dT;
							x = x + v * period.dT + 0.5 * a * period.dT * period.dT;
							v += period.dT * a;
						}
						else {
							t += interceptTime;
							x = x + v * interceptTime + 0.5 * a * interceptTime * interceptTime;
							v = Math.Min(v + interceptTime * a, period.velocity);

							if (v > 0)
								t += (period.endPosition - x) / v;
							x = period.endPosition;
						}
					}

					if (x < initialDistance) {
						double C = initialDistance - x;
						double B = - v;
						double A = -0.5 * a;

						t += (-B - Math.Sqrt(B * B - 4 * A * C)) / (2 * A);
					}

					output.WriteLine(t.ToString(input.numberFormat));
				}
			}

			output.Close();
		}
	}

	class Input
	{
		TextReader inputStream = null;
		Queue<string> currentLine = new Queue<string>();
		public NumberFormatInfo numberFormat;
		
		#region Constructors
		public Input(TextReader inputStream)
		{
			this.inputStream = inputStream;

			numberFormat = new NumberFormatInfo();
			numberFormat.NumberDecimalSeparator = ".";
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
			return double.Parse(Next(), numberFormat);
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
