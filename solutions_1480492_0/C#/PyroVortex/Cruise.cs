using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Random {
	class Cruise {
		static void Main() {
			int T = int.Parse(Console.ReadLine());
			for (int t = 1; t <= T; t++) {
				int N = int.Parse(Console.ReadLine());
				var vehicles = new Tuple<bool, int, int>[N];
				for (int i = 0; i < N; i++) {
					var line = Console.ReadLine().Split(' ');
					vehicles[i] = new Tuple<bool, int, int>(line[0].ToLower().Equals("R"), int.Parse(line[1]), int.Parse(line[2]));
				}

				// Solve for all collision times.
				double[,] times = new double[N, N];
				var collisions = new List<Tuple<double,int,int>>();
				for (int i = 0; i < N; i++) {
					double P_i = vehicles[i].Item3;
					double S_i = vehicles[i].Item2;
					for (int j = i; j < N; j++) {
						// p + a*t == q + b*t
						// P1 - P2 == (S2-S1)*t
						// t = (P1-P2)/(S2-S1)
						double P_j = vehicles[j].Item3;
						double S_j = vehicles[j].Item2;

						double dp = P_i > P_j ? P_i - P_j - 5 : P_i - P_j + 5;
						double ds = vehicles[j].Item2 - vehicles[i].Item2;
						double time = dp / ds;
						times[i, j] = times[j,i] = time;
						if (time >= 0) {
							collisions.Add(new Tuple<double, int, int>(time, i, j));
						}
					}
				}

				if (collisions.Count < 1) {
					Console.WriteLine("Case #{0}: Possible", t);
					continue;
				}

				double firstCollision = double.PositiveInfinity;

				var collisionSequence = collisions.OrderBy(x => x.Item1);
				foreach (var collision in collisionSequence) {
					double time = collision.Item1;
					int i = collision.Item2, j = collision.Item3;
					var v1 = vehicles[i];
					var v2 = vehicles[j];

					double s1 = v1.Item2;
					double s2 = v2.Item2;
					
					double p1 = v1.Item3;
					double p2 = v2.Item3;

					double a1 = p1 + s1 * time;
					double a2 = p2 + s2 * time;

					double f1 = a1 + 5;
					double f2 = a2 + 5;

					bool b1 = false, b2 = false;
					int cik = -1, cjk = -1;
					// Are there vehicles blocking both cars?
					for (int k = 0; k < N && (!b1 || !b2); k++) {
						if (k == i || k == j) continue;
						double sk = vehicles[k].Item2;
						double pk = vehicles[k].Item3 + sk * time;
						if ((pk + 5 > a1 || (pk + 5 == a1 && sk > s1)) && (f1 > pk || (f1 == pk && s1 > sk))) {
							// V1 is blocked from lane shifting.
							b1 = true;
							cik = k;
						}
						if ((pk + 5 > a2 || (pk + 5 == a2 && sk > s2)) && (f2 > pk || (f2 == pk && s2 > sk))) {
							// V2 is blocked from lane shifting.
							b2 = true;
							cjk = k;
						}
					}
					if (b1 && b2) {
						if (v1.Item1 == v2.Item1) {
							// Speed change required.
							firstCollision = time;
						} else {
							// Isn't necessarily a collision
						}
					} else if (b1) {
						if (v1.Item1 == v2.Item1) {
							v2 = new Tuple<bool,int,int>(!v2.Item1, v2.Item2, v2.Item3);
						}
					} else if (b2) {
						if (v1.Item1 == v2.Item1) {
							v1 = new Tuple<bool, int, int>(!v1.Item1, v1.Item2, v1.Item3);
						}
					}
				}
				if (double.IsPositiveInfinity(firstCollision)) {
					Console.WriteLine("Case #{0}: Possible", t);
				} else {
					Console.WriteLine("Case #{0}: {1}", t, firstCollision);
				}
			}
		}
	}
}
