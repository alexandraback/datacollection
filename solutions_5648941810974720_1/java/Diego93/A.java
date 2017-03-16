import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	static String[] nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("a.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("a.out"));
		int N = s.nextInt();
		s.nextLine();
		for (int i = 0; i < N; i++) {
			String str = s.nextLine();
			int[] counter = new int['Z' - 'A' + 1];
			for (int j = 0; j < str.length(); j++) {
				counter[str.charAt(j) - 'A']++;
			}
			int zeros = counter['Z' - 'A'];
			for (int k = 0; k < nums[0].length(); k++)
				counter[nums[0].charAt(k) - 'A'] -= zeros;
			int twos = counter['W' - 'A'];
			for (int k = 0; k < nums[2].length(); k++)
				counter[nums[2].charAt(k) - 'A'] -= twos;
			int fours = counter['U' - 'A'];
			for (int k = 0; k < nums[4].length(); k++)
				counter[nums[4].charAt(k) - 'A'] -= fours;
			int sixs = counter['X' - 'A'];
			for (int k = 0; k < nums[6].length(); k++)
				counter[nums[6].charAt(k) - 'A'] -= sixs;
			int eights = counter['G' - 'A'];
			for (int k = 0; k < nums[8].length(); k++)
				counter[nums[8].charAt(k) - 'A'] -= eights;
			int a1 = counter['O' - 'A'];
			for (int k = 0; k < nums[1].length(); k++)
				counter[nums[1].charAt(k) - 'A'] -= a1;
			int left = str.length() - a1 * nums[1].length() - zeros
					* nums[0].length() - twos * nums[2].length() - fours
					* nums[4].length() - sixs * nums[6].length() - eights
					* nums[8].length();

			for (int a3 = 0; a3 * nums[3].length() <= left; a3++) {
				boolean error3 = false;
				for (int k = 0; k < nums[3].length(); k++) {
					counter[nums[3].charAt(k) - 'A'] -= a3;
					if (counter[nums[3].charAt(k) - 'A'] < 0)
						error3 = true;
				}
				if (!error3) {
					left -= a3 * nums[3].length();
					for (int a5 = 0; a5 * nums[5].length() <= left; a5++) {
						boolean error5 = false;
						for (int k = 0; k < nums[5].length(); k++) {
							counter[nums[5].charAt(k) - 'A'] -= a5;
							if (counter[nums[5].charAt(k) - 'A'] < 0)
								error5 = true;
						}
						if (!error5) {
							left -= a5 * nums[5].length();
							for (int a7 = 0; a7 * nums[7].length() <= left; a7++) {
								boolean error7 = false;
								for (int k = 0; k < nums[7].length(); k++) {
									counter[nums[7].charAt(k) - 'A'] -= a7;
									if (counter[nums[7].charAt(k) - 'A'] < 0)
										error7 = true;
								}
								if (!error7) {
									left -= a7 * nums[7].length();
									for (int a9 = 0; a9 * nums[9].length() <= left; a9++) {
										boolean error9 = false;
										for (int k = 0; k < nums[9].length(); k++) {
											counter[nums[9].charAt(k) - 'A'] -= a9;
											if (counter[nums[9].charAt(k) - 'A'] < 0)
												error9 = true;
										}
										if (!error9) {
											left -= a9 * nums[9].length();

											if (left == 0) {
												out.write("Case #" + (i + 1)
														+ ": ");
												for (int k = 0; k < zeros; k++)
													out.write("0");
												for (int k = 0; k < a1; k++)
													out.write("1");
												for (int k = 0; k < twos; k++)
													out.write("2");
												for (int k = 0; k < a3; k++)
													out.write("3");
												for (int k = 0; k < fours; k++)
													out.write("4");
												for (int k = 0; k < a5; k++)
													out.write("5");
												for (int k = 0; k < sixs; k++)
													out.write("6");
												for (int k = 0; k < a7; k++)
													out.write("7");
												for (int k = 0; k < eights; k++)
													out.write("8");
												for (int k = 0; k < a9; k++)
													out.write("9");
												out.write("\n");
											}

											left += a9 * nums[9].length();
										}
										for (int k = 0; k < nums[9].length(); k++) {
											counter[nums[9].charAt(k) - 'A'] += a9;
										}
										if (error9)
											break;
									}

									left += a7 * nums[7].length();
								}
								for (int k = 0; k < nums[7].length(); k++) {
									counter[nums[7].charAt(k) - 'A'] += a7;
								}
								if (error7)
									break;
							}

							left += a5 * nums[5].length();
						}
						for (int k = 0; k < nums[5].length(); k++) {
							counter[nums[5].charAt(k) - 'A'] += a5;
						}
						if (error5)
							break;
					}

					left += a3 * nums[3].length();
				}
				for (int k = 0; k < nums[3].length(); k++) {
					counter[nums[3].charAt(k) - 'A'] += a3;
				}
				if (error3)
					break;
			}
		}
		out.close();	
	}

}
