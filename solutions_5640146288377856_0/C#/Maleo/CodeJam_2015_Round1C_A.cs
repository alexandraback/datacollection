using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace GoogleCodeJamV2
{
	public class CodeJam_2015_Round1C_A : ITestCase
	{
		public string GetTitle()
		{
			return "A. Brattleship";
		}

		public Func<string, int> LinesPerTestCase()
		{
			return x => 1;
		}

		public string Run(List<string> lines)
		{
			double rows = double.Parse (lines [0].Split(' ')[0]);
			double cols = double.Parse (lines [0].Split(' ')[1]);
			double sheepWidth = double.Parse (lines [0].Split(' ')[2]);

			if (sheepWidth == 1) {
				return (rows * cols).ToString ();
			} else {

				if (rows > 1) {
					throw new NotImplementedException ();
				} else {
					if (sheepWidth == cols) {
						return cols.ToString ();
					} else {

						if (cols % sheepWidth == 0) {
							return (cols / sheepWidth + sheepWidth - 1).ToString ();
						} else {
							return (Math.Floor ((cols - sheepWidth) / sheepWidth) + 1 + sheepWidth).ToString ();
						}

					}
				}
		
			}
		}
	}
}

