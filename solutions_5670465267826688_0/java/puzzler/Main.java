import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;

public class Main {

	static enum Value {
		ONE('1', true), I('i', true), J('j', true), K('k', true), NEG_ONE('1',
				false), NEG_I('i', false), NEG_J('j', false), NEG_K('k', false);

		char value;
		boolean isPositive;

		Value(char value, boolean isPositive) {
			this.value = value;
			this.isPositive = isPositive;
		}

		Value negate() {
			switch (this) {
			case ONE:
				return NEG_ONE;
			case I:
				return NEG_I;
			case J:
				return NEG_J;
			case K:
				return NEG_K;
			case NEG_ONE:
				return ONE;
			case NEG_I:
				return I;
			case NEG_J:
				return J;
			case NEG_K:
				return K;
			default:
				return ONE;
			}
		}

		Value multiply(Value rhs) {
			return multiply(this, rhs);
		}

		Value reverseMultiply(Value lhs) {
			return multiply(lhs, this);
		}

		static Value multiply(Value lhs, Value rhs) {
			Value result;

			switch (lhs) {
			case ONE:
			case NEG_ONE:
				switch (rhs) {
				case ONE:
				case NEG_ONE:
					result = ONE;
					break;
				case I:
				case NEG_I:
					result = I;
					break;
				case J:
				case NEG_J:
					result = J;
					break;
				case K:
				case NEG_K:
				default:
					result = K;
					break;
				}
				break;

			case I:
			case NEG_I:
				switch (rhs) {
				case ONE:
				case NEG_ONE:
					result = I;
					break;
				case I:
				case NEG_I:
					result = NEG_ONE;
					break;
				case J:
				case NEG_J:
					result = K;
					break;
				case K:
				case NEG_K:
				default:
					result = NEG_J;
					break;
				}
				break;

			case J:
			case NEG_J:
				switch (rhs) {
				case ONE:
				case NEG_ONE:
					result = J;
					break;
				case I:
				case NEG_I:
					result = NEG_K;
					break;
				case J:
				case NEG_J:
					result = NEG_ONE;
					break;
				case K:
				case NEG_K:
				default:
					result = I;
					break;
				}
				break;

			case K:
			case NEG_K:
			default:
				switch (rhs) {
				case ONE:
				case NEG_ONE:
					result = K;
					break;
				case I:
				case NEG_I:
					result = J;
					break;
				case J:
				case NEG_J:
					result = NEG_I;
					break;
				case K:
				case NEG_K:
				default:
					result = NEG_ONE;
					break;
				}
			}

			if (lhs.isPositive && !rhs.isPositive || !lhs.isPositive
					&& rhs.isPositive) {
				result = result.negate();
			}

			return result;
		}
	}

	static Value segmentProduct(Vector<Value> segment) {
		Value result = Value.ONE;

		for (Value v : segment) {
			result = result.multiply(v);
		}

		return result;
	}

	static Vector<Value> getSegment(String s) {
		Vector<Value> result = new Vector<Value>(s.length());

		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			switch (c) {
			case 'i':
				result.add(Value.I);
				break;
			case 'j':
				result.add(Value.J);
				break;
			case 'k':
			default:
				result.add(Value.K);
				break;
			}
		}

		return result;
	}

	static Value times(Value v, long times) {
		Value product = Value.ONE;

		Value cursor = v;
		while (times > 0) {
			if (times % 2 == 1) {
				product = product.multiply(cursor);
			}
			times = times / 2;
			cursor = cursor.multiply(cursor);
		}

		return product;
	}

	static Value rollingIndex(Vector<Value> segment, int index, boolean forwards) {
		index = index % segment.size();
		if (!forwards) {
			index = segment.size() - index - 1;
		}
		return segment.elementAt(index);
	}

	static int countUntil(Value desired, Vector<Value> segment, int max,
			boolean forwards) {
		Value product = Value.ONE;
		for (int i = 0; i < max; ++i) {
			Value v = rollingIndex(segment, i, forwards);
			if (forwards) {
				product = product.multiply(v);
			} else {
				product = v.multiply(product);
			}
			if (product == desired) {
				return i + 1;
			}
		}

		return -1;

	}

	public static void main(String args[]) {
		Value goodProduct = Value.I.multiply(Value.J.multiply(Value.K));
		System.out.println(goodProduct);
		Scanner s = null;
		PrintWriter out = null;

		try {
			String inputFilename;
			if (args.length > 0) {
				inputFilename = args[0];
			} else {
				System.out.print("Input file name: ");
				BufferedReader in = new BufferedReader(new InputStreamReader(
						System.in));
				inputFilename = in.readLine();
			}

			File f = new File("data/" + inputFilename);
			String outputFilename = inputFilename.replaceFirst("(\\.in)?$",
					".out");

			s = new Scanner(new FileReader(f));
			out = new PrintWriter(new FileWriter("data/" + outputFilename));
			int testCases = s.nextInt();
			for (int t = 1; t <= testCases; ++t) {
				int len = s.nextInt();
				long times = s.nextLong();
				s.skip("\\s");
				String str = s.nextLine();
				if (str.length() != len) {
					throw new Exception("String " + str
							+ " not expected length.");
				}
				// System.out.println("str:" + str);
				Vector<Value> segment = getSegment(str);
				Value segmentProduct = segmentProduct(segment);
				Value timesProduct = times(segmentProduct, times);

				boolean correct = false;

				if (timesProduct != goodProduct) {
					System.out.println("bad because full product is "
							+ timesProduct + " rather than " + goodProduct);
					// bad
				} else {
					// so we know we have the right ultimate product can we get
					// "i" from the first N and "k" from the last O and leave
					// anything for J?
					int i = countUntil(Value.I, segment, 16 * len, true);
					if (i > 0) {
						int k = countUntil(Value.K, segment, 16 * len, false);
						if (k > 0) {
							correct = i + k + 1 <= len * times;
							System.out.println("result is " + correct
									+ " because i count is " + i
									+ " and k count is " + k + " and we have "
									+ len * times + " characters");
						} else {
							System.out
									.println("bad because couldn't generate K at end");
						}
					} else {
						System.out
								.println("bad because couldn't generate I at start");
					}
				}

				out.println("Case #" + t + ": " + (correct ? "YES" : "NO"));
			}

			out.close();
			s.close();
		} catch (Exception e) {
			System.err.println(e);
		} finally {
			if (null != out)
				out.close();
			if (null != s)
				s.close();
		}
	}
}
