import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import com.google.common.base.Joiner;
import com.google.common.collect.Lists;

public class Main {

	// using Google Guava, downloadable from: https://code.google.com/p/guava-libraries/

	public static void main(String[] args) throws Exception {
		File input = null;
		for (File f : new File(".").listFiles()) {
			if (f.isFile() && f.getName().endsWith(".in")) {
				input = f;
				break;
			}
		}
		Scanner s = new Scanner(input);
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 0; i < cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": ");

			s.nextLine();
			String[] split = s.nextLine().split(" ");
			Arrays.sort(split);

			int[] repeats = new int[27];

			long ans = -1;

			for (int j = 0; j < split.length; j++) {
				String one = split[j];
				char first = one.charAt(0);
				boolean same = true;
				if (one.length() > 1) {
					for (int k = 1; k < one.length(); k++) {
						if (one.charAt(k) != first) {
							same = false;
							break;
						}

					}
				}

				if (same) {
					if (++repeats[first - 'a'] > 1) {
						split[j] = null;
					} else {
						split[j] = String.valueOf(first);
					}
				}
			}

			outer:
			for (int j = 0; j < split.length; j++) {
				String one = split[j];
				if (one != null) {
					int length = one.length();

					char last = one.charAt(one.length() - 1);
					for (;;) {
						int foundIndex = -1;
						for (int k = 0; k < split.length; k++) {
							if (k != j && split[k] != null && split[k].charAt(0) == last) {
								if (foundIndex < 0) {
									one += split[k];
									if (split[k].length() == 1) {
										repeats[split[k].charAt(0) - 'a'] = 0;
									}
									split[k] = null;
									foundIndex = k;

									if (length == 1) {
										repeats[one.charAt(0) - 'a'] = 0;
									}

								} else {
									ans = 0;
									break outer;
								}
							}
						}
						last = one.charAt(one.length() - 1);
						split[j] = one;
						if (foundIndex < 0) {
							break;
						}
					}
				}
			}

			if (ans < 0) {
				ArrayList<String> cars = Lists.newArrayList();
				for (int j = 0; j < split.length; j++) {
					if (split[j] != null) {
						cars.add(split[j]);
					}
				}
				String joined = Joiner.on("").join(cars);
				char[] chars = new char[27];
				int zz = 0;
				fail:
				for (int k = 0; k < joined.length(); k++) {
					char current = joined.charAt(k);
					if (zz == 0 && chars[zz] == '\0') {
						chars[0] = current;
					} else if (chars[zz] != current) {
						for (int l = 0; l <= zz; l++) {
							if (chars[l] == current) {
								ans = 0;
								break fail;
							}
						}
						chars[++zz] = current;
					}
				}

				if (ans < 0) {
					ans = factorial(cars.size());
					for (String car : cars) {
						if (car.length() == 1) {
							ans *= factorial(repeats[car.charAt(0) - 'a']);
						}
					}
				}
			}


			w.write(String.valueOf(ans));
			w.write("\n");
		}
		w.close();
	}

	public static long factorial(int num) {
		if (num <= 2) {
			return num;
		} else {
			long result = 2;
			for (int i = 3; i <= num; i++) {
				result *= i;
			}
			return result;
		}

	}



}
