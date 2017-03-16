package googlecodejam2012.round1b.equalsums;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Set;

import scala.actors.threadpool.Arrays;

public class EqualSums {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(
					args[1]) : new OutputStreamWriter(System.out));
			try {
				int numLines = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numLines; ++i) {
					String line = br.readLine();
					long[][] equalSums = equalSums(line);
					if (equalSums.length > 0) {
						out.write("Case #" + i + ":" + lineSep
								+ print(equalSums[0]) + lineSep
								+ print(equalSums[1]) + lineSep);
					} else {// this should not happen because of constraints
						out.write("Case #" + i + ":" + lineSep + "Impossible"
								+ lineSep);

					}
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static long[][] equalSums(String line) {
		String[] parts = line.split(" ");
		long[] nums = new long[Integer.parseInt(parts[0])];
		for (int i = parts.length; i-- > 1;) {
			nums[i - 1] = Long.parseLong(parts[i]);
		}
		Arrays.sort(nums);
		Set<Long> possibleSums = new HashSet<Long>();
		for (long l : nums) {
			possibleSums.add(l);
		}
		for (int i = 0; i < nums.length; i++) {
			long l0 = nums[i];
			for (int j = i + 1; j < nums.length; j++) {
				long l1 = nums[j];
				Long sum = Long.valueOf(l0 + l1);
				if (possibleSums.contains(sum)) {
					long s = sum.longValue();
					if (Arrays.binarySearch(nums, s) >= 0) {
						return new long[][] { { l0, l1 }, { l1 + l0 } };
					} else {
						for (int i1 = 0; i1 < nums.length; i1++) {
							long l2 = nums[i1];
							for (int j1 = i1 + 1; j1 < nums.length; j1++) {
								long l3 = nums[j1];
								if (s == l2 + l3) {
									return new long[][] { { l0, l1 },
											{ l2, l3 } };
								}
							}
						}
					}
				} else {
					possibleSums.add(sum);
				}
			}
		}
		for (int i = 0; i < nums.length; i++) {
			long l0 = nums[i];
			for (int j = i + 1; j < nums.length; j++) {
				long l1 = nums[j];
				for (int k = j + 1; k < nums.length; k++) {
					long l2 = nums[k];
					Long sum = Long.valueOf(l0 + l1 + l2);
					if (possibleSums.contains(sum)) {
						long s = sum.longValue();
						if (Arrays.binarySearch(nums, s) >= 0) {
							return new long[][] { { l0, l1, l2 },
									{ l2 + l1 + l0 } };
						} else {
							for (int i1 = 0; i1 < nums.length; i1++) {
								long l3 = nums[i1];
								for (int j1 = i1 + 1; j1 < nums.length; j1++) {
									long l4 = nums[j1];
									if (s == l4 + l3) {
										return new long[][] { { l0, l1, l2 },
												{ l3, l4 } };
									}
								}
							}
							for (int i1 = 0; i1 < nums.length; i1++) {
								long l3 = nums[i1];
								for (int j1 = i1 + 1; j1 < nums.length; j1++) {
									long l4 = nums[j1];
									for (int k1 = j1 + 1; k1 < nums.length; k1++) {
										long l5 = nums[k1];
										if (s == l5 + l4 + l3) {
											return new long[][] {
													{ l0, l1, l2 },
													{ l3, l4, l5 } };
										}
									}
								}
							}
						}
					} else {
						possibleSums.add(sum);
					}
				}
			}
		}
		for (int i = 0; i < nums.length; i++) {
			long l0 = nums[i];
			for (int j = i + 1; j < nums.length; j++) {
				long l1 = nums[j];
				for (int k = j + 1; k < nums.length; k++) {
					long l2 = nums[k];
					for (int l = k + 1; l < nums.length; l++) {
						long l3 = nums[l];
						Long sum = Long.valueOf(l0 + l1 + l2 + l3);
						if (possibleSums.contains(sum)) {
							long s = sum.longValue();
							if (Arrays.binarySearch(nums, s) >= 0) {
								return new long[][] { { l0, l1, l2, l3 },
										{ l3 + l2 + l1 + l0 } };
							} else {
								for (int i1 = 0; i1 < nums.length; i1++) {
									long l4 = nums[i1];
									for (int j1 = i1 + 1; j1 < nums.length; j1++) {
										long l5 = nums[j1];
										if (s == l4 + l5) {
											return new long[][] {
													{ l0, l1, l2, l3 },
													{ l4, l5 } };
										}
									}
								}
								for (int i1 = 0; i1 < nums.length; i1++) {
									long l4 = nums[i1];
									for (int j1 = i1 + 1; j1 < nums.length; j1++) {
										long l5 = nums[j1];
										for (int k1 = j1 + 1; k1 < nums.length; k1++) {
											long l6 = nums[k1];
											if (s == l5 + l4 + l6) {
												return new long[][] {
														{ l0, l1, l2, l3 },
														{ l4, l5, l6 } };
											}
										}
									}
								}
								for (int i1 = 0; i1 < nums.length; i1++) {
									long l4 = nums[i1];
									for (int j1 = i1 + 1; j1 < nums.length; j1++) {
										long l5 = nums[j1];
										for (int k1 = j1 + 1; k1 < nums.length; k1++) {
											long l6 = nums[k1];
											for (int ll1 = k1 + 1; ll1 < nums.length; ll1++) {
												long l7 = nums[ll1];
												if (s == l5 + l4 + l6 + l7) {
													return new long[][] {
															{ l0, l1, l2, l3 },
															{ l4, l5, l6, l7 } };
												}
											}
										}
									}
								}
							}
						} else {
							possibleSums.add(sum);
						}
					}
				}
			}
		}
		// can this ever happen??
		return new long[][] {};
	}

	private static String print(long[] set) {
		StringBuilder sb = new StringBuilder();
		for (long d : set) {
			sb.append(d);
			sb.append(' ');
		}
		sb.setLength(sb.length() - 1);
		return sb.toString();
	}
}
