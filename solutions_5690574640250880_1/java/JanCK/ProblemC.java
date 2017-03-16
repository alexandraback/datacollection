package jck.codejam.cj2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Locale;

public class ProblemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// String filenameInput = "C-sample.in";
		// String filenameOutput = "C-sample.out";
		//String filenameInput = "C-small-attempt2.in";
		//String filenameOutput = "C-small-attempt2.out";
		 String filenameInput = "C-large.in";
		 String filenameOutput = "C-large.out";

		Class currentClass = ProblemC.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			System.out.println("Number of Testcases: " + numOfTestcases);
			NumberFormat nf = NumberFormat.getNumberInstance(Locale.ENGLISH);
			DecimalFormat df = (DecimalFormat) nf;
			df.setMinimumFractionDigits(6);

			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				String[] stringsRCM = input.readLine().split(" ");
				// r number of rows
				int r = Integer.parseInt(stringsRCM[0]);
				// c number of columns
				int c = Integer.parseInt(stringsRCM[1]);
				// m number of mines
				int m = Integer.parseInt(stringsRCM[2]);

				boolean possible = true;

				if (r == 1 || c == 1) {

				} else {

					if (r == 2 || c == 2) {
						if (r * c - m != 1) {
							if ((m & 1) != 0) {
								possible = false;
							}
							if (r * c - m == 2) {
								possible = false;
							}
						}
					} else {
						int nonmines = r * c - m;
						if (nonmines == 2 || nonmines == 3 || nonmines == 5
								|| nonmines == 7) {
							possible = false;
						}
					}
				}
				String grid = "";
				System.out.println("r: " + r + " c: " + c + " mines: " + m
						+ " possible: " + possible);
				if (possible) {
					boolean[][] gridmines = new boolean[r][c];
					if (r == 1 || c == 1) {
						if (r == 1) {
							for (int j = r * c - m; j < r * c; j++) {
								gridmines[0][j] = true;
							}
						} else {
							for (int j = r * c - m; j < r * c; j++) {
								// System.out.println("setting gridmines["+j+"][0] = true");
								gridmines[j][0] = true;

							}
						}
					} else {

						if (r == 2 || c == 2) {
							if (r * c - m == 1) {
								if (r == 2) {
									for (int j = 0; j < c; j++) {
										gridmines[0][j] = true;
										gridmines[1][j] = true;
									}
								} else {
									for (int j = 0; j < r; j++) {
										gridmines[j][0] = true;
										gridmines[j][1] = true;

									}
								}
								gridmines[0][0] = false;
							}
							if ((m & 1) == 0) {
								System.out
										.println("even number of mines, not just 1 free square, either r or c is 2");
								int falseTill = (r * c - m) / 2;
								if (r == 2) {
									for (int j = 0; j < falseTill; j++) {
										gridmines[0][j] = false;
										gridmines[1][j] = false;
									}
									for (int j = falseTill; j < c; j++) {
										gridmines[0][j] = true;
										gridmines[1][j] = true;
									}
								} else {
									for (int j = 0; j < falseTill; j++) {
										gridmines[j][0] = false;
										gridmines[j][1] = false;
									}
									for (int j = falseTill; j < r; j++) {
										gridmines[j][0] = true;
										gridmines[j][1] = true;
									}
								}
							}

						} else {
							int nonmines = r * c - m;
							if (nonmines == 1) {
								for (int j = 0; j < r; j++) {
									for (int k = 0; k < c; k++) {
										gridmines[j][k] = true;
									}
								}
								gridmines[0][0] = false;
							} else {
								if (nonmines == 4) {
									for (int j = 0; j < r; j++) {
										for (int k = 0; k < c; k++) {
											gridmines[j][k] = true;
										}
									}
									gridmines[0][0] = false;
									gridmines[0][1] = false;
									gridmines[1][0] = false;
									gridmines[1][1] = false;
								} else {
									if (nonmines == 6) {
										for (int j = 0; j < r; j++) {
											for (int k = 0; k < c; k++) {
												gridmines[j][k] = true;
											}
										}
										gridmines[0][0] = false;
										gridmines[0][1] = false;
										gridmines[1][0] = false;
										gridmines[1][1] = false;
										gridmines[2][0] = false;
										gridmines[2][1] = false;
									} else {
										if ((nonmines & 1) == 0) {
											System.out
													.println("general case, nonmines even");
											int minesleft = m;
											boolean specialcase = false;
											for (int j = 0; j < r - 2; j++) {
												for (int k = 0; k < c; k++) {
													if (minesleft > 0) {
														if(minesleft ==1 && ((c- k - 1 ==1)||((c- k - 1 ==0)&&specialcase))){
															gridmines[r - j - 1][c
																					- k - 1] = false;
															specialcase = true;
															
														}
														else{
														gridmines[r - j - 1][c
																- k - 1] = true;
														minesleft--;}
													} else {
														gridmines[r - j - 1][c
																- k - 1] = false;

													}
												}
											}
											for (int k = 0; k < c; k++) {
												if (minesleft > 0) {
													gridmines[0][c - k - 1] = true;
													gridmines[1][c - k - 1] = true;
													minesleft--;
													minesleft--;
												} else {
													gridmines[0][c - k - 1] = false;
													gridmines[1][c - k - 1] = false;

												}
											}
											assert (minesleft == 0);

										} else {
											System.out
													.println("general case, nonmines ("
															+ nonmines
															+ ") odd (mines: "
															+ m + ")");
											int minesleft = m;
											boolean specialcase = false;
											for (int j = 0; j < r - 2; j++) {
												for (int k = 0; k < c; k++) {
													if(minesleft ==1 && ((c- k - 1 ==1)||((c- k - 1 ==0)&&specialcase))){
														gridmines[r - j - 1][c
																				- k - 1] = false;
														specialcase = true;
														
													}else{

													if (minesleft > 0
															&& (r - j != 3 || c
																	- k > 3)) {
														// System.out.println("Setting gridmines["+(r
														// - j)+"]["+(c -
														// k)+"] = true");
														gridmines[r - j - 1][c
																- k - 1] = true;
														minesleft--;
													} else {
														gridmines[r - j - 1][c
																- k - 1] = false;

													}
													}
												}
											}
											for (int k = 0; k < c; k++) {
												if (minesleft > 0) {
													gridmines[0][c - k - 1] = true;
													gridmines[1][c - k - 1] = true;
													minesleft--;
													minesleft--;
												} else {
													gridmines[0][c - k - 1] = false;
													gridmines[1][c - k - 1] = false;

												}
											}
											assert (minesleft == 0);
										}
									}
								}

							}
						}
					}
					grid = gridToString(gridmines);
				} else {
					grid = "Impossible";
				}

				String outputString = "Case #" + (i + 1) + ":\n" + grid;
				System.out.println(outputString);

				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static String gridToString(boolean[][] gridmines) {
		int r = gridmines.length;
		int c = gridmines[0].length;
		StringBuilder result = new StringBuilder(r * c + r);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					result.append("c");
				} else {
					if (gridmines[i][j]) {
						result.append("*");
					} else {
						result.append(".");
					}
				}

			}
			if (i != r - 1) {
				result.append("\n");
			}
		}
		return result.toString();
	}
}
