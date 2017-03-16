using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace codejam_Csharp {
	public partial class Form1 : Form {
		public Form1() {
			InitializeComponent();
		}
		string[] test;
		int n;
		BigInteger left, right, middle, mx, r, t, l;

		bool isOK(BigInteger m) {
			BigInteger k = r + m * 2 - 1;
			k = k * (k + 1);
			if (2 * (t + l) < k) {
				return false;
			}
			return true;
		}

		string input;
		private void button1_Click(object sender, EventArgs e) {
			StreamReader sr = new StreamReader(@"C:\A-large.in");
			input = sr.ReadToEnd(); sr.Close();
			test = input.Split(new string[] { "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries);
			n = Convert.ToInt32(test[0]);

			StreamWriter sw = new StreamWriter(@"C:\output.txt");
			for (int i = 1; i <= n; i++) {
				r = BigInteger.Parse(test[i].Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries)[0]);
				t = BigInteger.Parse(test[i].Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries)[1]);

				left = mx = 0; right = 707106781;
				l = (r * (r - 1)) / 2; 
				
				for (; left <= right; ) {
					middle = (left + right) >> 1;
					if (isOK(middle)) {
						left = middle + 1;
						if (mx < middle) { mx = middle; }
					} else {
						right = middle - 1;
					}
				}
				sw.WriteLine("Case #" + i + ": " + mx);
			}
			sw.Flush(); sw.Close();
		}
	}
}
