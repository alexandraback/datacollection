using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
	class Program
	{
		static int Squared(int x)
		{
			return x * x;
		}

		static int Gcd(int x, int y)
		{
			return x == 0 ? y : y == 0 ? x : Gcd(y, x % y);
		}

		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var parameters = Console.ReadLine().Split();
				var h = int.Parse(parameters[0]);
				var w = int.Parse(parameters[1]);
				var d = int.Parse(parameters[2]);
				var fieldTemplate = new bool[h * 2, w * 2]; // Multiplying the field coords by two so "my" coords will be integers
				var dSquared = Squared(d * 2); // d squared in new coords
				int meH = 0, meW = 0;
				for (var row = 0; row < h; row++)
				{
					line = Console.ReadLine();
					for (var col = 0; col < w; col++)
					{
						switch (line[col])
						{
							case '#':
								fieldTemplate[row * 2, col * 2] = true;
								fieldTemplate[row * 2, col * 2 + 1] = true;
								fieldTemplate[row * 2 + 1, col * 2] = true;
								fieldTemplate[row * 2 + 1, col * 2 + 1] = true;
								break;
							case 'X':
								meH = row * 2 + 1;
								meW = col * 2 + 1;
								break;
						}
					}
				}
				var result = 0;

				// for small data input use simplified calculations!
				meH -= 2;
				meW -= 2;
				var cellH = h*2 - 4;
				var cellW = w*2 - 4;

				if (Squared(2 * meH) <= dSquared)
					result++;
				if (Squared(2 * (cellH - meH)) <= dSquared)
					result++;
				if (Squared(2 * meW) <= dSquared)
					result++;
				if (Squared(2 * (cellW - meW)) <= dSquared)
					result++;

				for (var hStep = 1; Squared(hStep) <= dSquared; hStep++)
					for (var wStep = 1; Squared(hStep) + Squared(wStep) <= dSquared; wStep++)
						if (Gcd(hStep, wStep) == 1)
							for (var hDirection = -1; hDirection < 2; hDirection += 2)
								for (var wDirection = -1; wDirection < 2; wDirection += 2)
								{
									var iH = meH;
									var iW = meW;
									for (var stepNumber = 1; Squared(stepNumber * hStep) + Squared(stepNumber * wStep) <= dSquared; stepNumber++)
									{
										iH += hStep * hDirection;
										iW += wStep * wDirection;
										int remainderH, remainderW;
										if (meH == (Math.DivRem(iH, cellH, out remainderH) % 2 == 0 ? Math.Abs(remainderH) : cellH - Math.Abs(remainderH))
											&& meW == (Math.DivRem(iW, cellW, out remainderW) % 2 == 0 ? Math.Abs(remainderW) : cellW - Math.Abs(remainderW)))
										{
											result++;
											break;
										}
										if (iH % cellH == 0 && iW % cellW == 0)
										{
											if (Squared(2 * stepNumber * hStep) + Squared(2 * stepNumber * wStep) <= dSquared)
												result++;
											break;
										}
									}
								}
				Console.WriteLine("Case #{0}: {1}", testNumber, result);
			}
		}
	}
}
