package problemD;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemD {
	static Rational posX = null;
	static Rational posY = null;

	static Rational tarX = null;
	static Rational tarY = null;

	static boolean[][] array = null;

	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("D-practice.in"));
		Scanner sc = new Scanner(new File("D-small.in"));
		// Scanner sc = new Scanner(new File("D-large.in"));
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			// do case things here
			int H = sc.nextInt();
			int W = sc.nextInt();
			int D = sc.nextInt();
			D *= 2;
			array = new boolean[H][W];
			for (int j = 0; j < H; j++) {
				String s = sc.next();
				for (int k = 0; k < W; k++) {
					array[j][k] = (s.charAt(k) == '#');
					if (s.charAt(k) == 'X') {
						posX = new Rational(2 * k + 1, 1);
						posY = new Rational(2 * j + 1, 1);
						tarX = posX;
						tarY = posY;
					}
				}
			}
			int count = 0;
			boolean checked[][] = new boolean[2 * D + 1][2 * D + 1];
			for (int j = 2; j <= D; j += 2) {
				for (int x = -j; x <= j; x += 2) {
					if (D + j >= 0 && D + j < checked.length && D + x >= 0
							&& D + x < checked.length) {
						if (!checked[D + j][D + x]) {
							if (followRay(j, x, D)) {
								count++;
							}
							int k = 1;
							while (D + (k * j) >= 0
									&& D + (k * j) < checked.length
									&& D + (k * x) >= 0
									&& D + (k * x) < checked.length) {
								checked[D + (k * j)][D + (k * x)] = true;
								k++;
							}
						}
					}
					if (D + j >= 0 && D + j < checked.length && D + x >= 0
							&& D + x < checked.length) {
						if (!checked[D + x][D + j]) {
							if (followRay(x, j, D)) {
								count++;
							}
							int k = 1;
							while (D + (k * j) >= 0
									&& D + (k * j) < checked.length
									&& D + (k * x) >= 0
									&& D + (k * x) < checked.length) {
								checked[D + (k * x)][D + (k * j)] = true;
								k++;
							}
						}
					}

					if (D - j >= 0 && D - j < checked.length && D + x >= 0
							&& D + x < checked.length) {
						if (!checked[D - j][D + x]) {
							if (followRay(-j, x, D)) {
								count++;
							}
							int k = 1;
							while (D - (k * j) >= 0
									&& D - (k * j) < checked.length
									&& D + (k * x) >= 0
									&& D + (k * x) < checked.length) {
								checked[D - (k * j)][D + (k * x)] = true;
								k++;
							}
						}
					}
					if (D - j >= 0 && D - j < checked.length && D + x >= 0
							&& D + x < checked.length) {
						if (!checked[D + x][D - j]) {
							if (followRay(x, -j, D)) {
								count++;
							}
							int k = 1;
							while (D - (k * j) >= 0
									&& D - (k * j) < checked.length
									&& D + (k * x) >= 0
									&& D + (k * x) < checked.length) {
								checked[D + (k * x)][D - (k * j)] = true;
								k++;
							}
						}
					}
				}
			}
//			System.out.println(count);
			System.out.format("Case #%d: %d\n", i, count);
		}
	}

	private static boolean followRay(int dirX, int dirY, int max) {
		double distance = 0;
		posX = tarX;
		posY = tarY;
		distance += step(dirX, dirY);
		while (distance <= max) {
			if (tarX.equals(posX) && tarY.equals(posY)) {
				return true;
			}
			// check mirror, adjust direction
			if (dirX == 0) {
				if (posY.n == 1 && posY.z % 2 == 0) {
					int y = posY.z / 2;
					if (y >= array.length || y == 0) {
						return false;
					}
					int x = posX.z / posX.n / 2;
					if (dirY > 0 && array[y][x] || dirY < 0 && array[y - 1][x]) {
						dirY = -1 * dirY;
					}
				}
			} else if (dirY == 0) {
				if (posX.n == 1 && posX.z % 2 == 0) {
					int x = posX.z / 2;
					if (x >= array[0].length || x == 0) {
						return false;
					}
					int y = posY.z / posY.n / 2;
					if (dirX > 0 && array[y][x] || dirX < 0 && array[y][x - 1]) {
						dirX = -1 * dirX;
					}
				}
			}
			if (posX.n == 1 && posX.z % 2 == 0) {
				if (posY.n == 1 && posY.z % 2 == 0) {
					// corner
					int x = posX.z / 2;
					int y = posY.z / 2;
					boolean mirrored = false;
					if (dirX > 0) {
						if (array[y][x] && array[y - 1][x]) {
							dirX = -1 * dirX;
							mirrored = true;
						}
					} else {
						if (array[y][x - 1] && array[y - 1][x - 1]) {
							dirX = -1 * dirX;
							mirrored = true;
						}
					}
					if (dirY > 0) {
						if (array[y][x] && array[y][x - 1]) {
							dirY = -1 * dirY;
							mirrored = true;
						}
					} else {
						if (array[y - 1][x] && array[y - 1][x - 1]) {
							dirY = -1 * dirY;
							mirrored = true;
						}
					}
					if (!mirrored) {
						if (dirX > 0) {
							if (dirY > 0) {
								if (array[y][x]) {
									return false;
								}
							} else {
								if (array[y - 1][x]) {
									return false;
								}
							}
						} else {
							if (dirY > 0) {
								if (array[y][x - 1]) {
									return false;
								}
							} else {
								if (array[y - 1][x - 1]) {
									return false;
								}
							}
						}
					}
				} else {
					int x = posX.z / 2;
					if (x >= array[0].length || x == 0) {
						return false;
					}
					int y = posY.z / posY.n / 2;
					if (dirX > 0 && array[y][x] || dirX < 0 && array[y][x - 1]) {
						dirX = -1 * dirX;
					}
				}
			} else if (posY.n == 1 && posY.z % 2 == 0) {
				int y = posY.z / 2;
				if (y >= array.length || y == 0) {
					return false;
				}
				int x = posX.z / posX.n / 2;
				if (dirY > 0 && array[y][x] || dirY < 0 && array[y - 1][x]) {
					dirY = -1 * dirY;
				}
			}

			distance += step(dirX, dirY);
		}
		return false;
	}

	// steps until the next coord becomes integer
	private static double step(int dirX, int dirY) {
		if (dirY == 0) {
			if (dirX > 0) {
				posX = posX.plus(Rational.one);
			} else {
				posX = posX.minus(Rational.one);
			}
			return 1;
		}
		if (dirX == 0) {
			if (dirY > 0) {
				posY = posY.plus(Rational.one);
			} else {
				posY = posY.minus(Rational.one);
			}
			return 1;
		}

		if (posX.n == 1) {
			Rational distY = posY.fractal();
			Rational speed = new Rational(Math.abs(dirY), Math.abs(dirX));
			if (dirY > 0) {
				distY = Rational.one.minus(distY);
			}
			if (distY.equals(Rational.zero)) {
				distY = Rational.one;
			}
			if (distY.minus(speed).positive()) {
				if (dirX > 0) {
					posX = posX.plus(Rational.one);
				} else {
					posX = posX.minus(Rational.one);
				}
				if (dirY > 0) {
					posY = posY.plus(speed);
				} else {
					posY = posY.minus(speed);
				}
				return Math.sqrt(1 + speed.times(speed).value());
			} else {
				if (dirY > 0) {
					posY = posY.plus(distY);
				} else {
					posY = posY.minus(distY);
				}
				Rational distX = distY.divides(speed);
				if (dirX > 0) {
					posX = posX.plus(distX);
				} else {
					posX = posX.minus(distX);
				}
				return Math.sqrt(distY.times(distY).value()
						+ distX.times(distX).value());
			}
		} else {
			Rational distX = posX.fractal();
			Rational speed = new Rational(Math.abs(dirX), Math.abs(dirY));
			if (dirX > 0) {
				distX = Rational.one.minus(distX);
			}
			if (distX.minus(speed).positive()) {
				if (dirY > 0) {
					posY = posY.plus(Rational.one);
				} else {
					posY = posY.minus(Rational.one);
				}
				if (dirX > 0) {
					posX = posX.plus(speed);
				} else {
					posX = posX.minus(speed);
				}
				return Math.sqrt(1 + speed.times(speed).value());
			} else {
				if (dirX > 0) {
					posX = posX.plus(distX);
				} else {
					posX = posX.minus(distX);
				}
				Rational distY = distX.divides(speed);
				if (dirY > 0) {
					posY = posY.plus(distY);
				} else {
					posY = posY.minus(distY);
				}
				return Math.sqrt(distY.times(distY).value()
						+ distX.times(distX).value());
			}
		}
	}

//	private static void out(boolean[] array) {
//		System.out.println(Arrays.toString(array));
//	}
//
//	private static void out(boolean[][] array) {
//		int count = 0;
//		for (boolean[] a : array) {
//			System.out.print(count++ + ":");
//			out(a);
//		}
//	}

	private static class Rational {
		static final Rational one = new Rational(1, 1);
		static final Rational zero = new Rational(0, 1);

		public int z;
		public int n;

		// create and initialize a new Rational object
		public Rational(int z, int n) {
			if (n == 0) {
				throw new RuntimeException("Denominator is zero");
			}
			int g = gcd(z, n);
			this.z = z / g;
			this.n = n / g;

		}

		// return string representation of (this)
		public String toString() {
			if (n == 1) {
				return z + "";
			} else {
				return z + "/" + n;
			}
		}

		// return (this * b)
		public Rational times(Rational b) {
			return new Rational(this.z * b.z, this.n * b.n);
		}

		// return (this + b)
		public Rational plus(Rational b) {
			int z = (this.z * b.n) + (this.n * b.z);
			int n = this.n * b.n;
			return new Rational(z, n);
		}

		// return (this - b)
		public Rational minus(Rational b) {
			int z = (this.z * b.n) - (this.n * b.z);
			int n = this.n * b.n;
			return new Rational(z, n);
		}

		// return fractal amount
		public Rational fractal() {
			return new Rational(z % n, n);
		}

		// return (1 / this)
		public Rational reciprocal() {
			return new Rational(n, z);
		}

		// return (this / b)
		public Rational divides(Rational b) {
			return this.times(b.reciprocal());
		}

		public boolean positive() {
			return z * n >= 0;
		}

		public boolean equals(Rational r) {
			return r.z == this.z && r.n == this.n;
		}

		public double value() {
			return 1.0 * z / n;
		}

		private int gcd(int m, int n) {
			if (0 == n)
				return m;
			else
				return gcd(n, m % n);
		}
	}
}
