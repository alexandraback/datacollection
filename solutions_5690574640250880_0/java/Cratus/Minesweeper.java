import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Minesweeper {

	static String infile = "G:/Dev/workspace/CodeJam14/ProblemC/input.in",
			outfile = "G:/Dev/workspace/CodeJam14/ProblemC/output.out";
	static String prefix = "Case #";
	static BufferedReader br;
	static BufferedWriter bw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(infile));
		bw = new BufferedWriter(new FileWriter(outfile));
		solve();
		bw.flush();
		bw.close();
		br.close();
	}

	static void solve() throws IOException {
		int T = Integer.parseInt(getNextLine());
		for (int i = 1; i <= T; i++) {
			String[] split = getNextLine().split(" ");
			String result = "";
			int R = Integer.parseInt(split[0]), C = Integer.parseInt(split[1]), M = Integer
					.parseInt(split[2]);
			if(M==0) {
				for (int rx = 0; rx < R; rx++) {
					for (int ry = 0; ry < C; ry++) {
						if(rx==0 && ry==0)
							result = result + "c";
						else
							result = result + ".";
					}
					result = result + "\n";
				}
			} else if(R*C-M==1) {
				for (int rx = 0; rx < R; rx++) {
					for (int ry = 0; ry < C; ry++) {
						if(rx==0 && ry==0)
							result = result + "c";
						else
							result = result + "*";
					}
					result = result + "\n";
				}
			} else {
				if (R == 1) {
					if ((C - M) < 2)
						result = "Impossible";
					else {
						result = result + "c";
						for (int j = 1; j < C; j++) {
							if (C - j > M)
								result = result + ".";
							else
								result = result + "*";
						}
					}
				} else if (C == 1) {
					if ((R - M) < 2)
						result = "Impossible";
					else {
						result = result + "c" + "\n";
						for (int j = 1; j < R; j++) {
							if (R - j > M)
								result = result + ".";
							else
								result = result + "*";
							if (j < R - 1)
								result = result + "\n";
						}
					}
				} else {
					int dots = R * C - M;
					if (dots < 4) {
						result = "Impossible";
					} else {						
						for(int startR = 1; startR<R;startR++) {
							for(int startC = 1; startC<C; startC++) {
								int count = (startR+1)*(startC+1);
								int remaining = dots - count;
								if(remaining==0) {
									for (int rx = 0; rx < R; rx++) {
										for (int ry = 0; ry < C; ry++) {
											if(rx==0 && ry==0)
												result = result + "c";
											else if (rx<=startR && ry<=startC)
												result = result + ".";
											else {
												result = result + "*";
											} 
										}
										result = result + "\n";
									}
									break;
								} else if(remaining<0) {
									break;
								} else if(remaining==1){
									continue;
								} else {
									int rowPossible = 0, colPossible = 0, cornerPossible = 0;
									if(startR<R-1)
										rowPossible = startC+1;
									if(startC<C-1)
										colPossible = startR+1;
									if(startR<R-1 && startC<C-1)
										cornerPossible++;
									if(remaining<=(rowPossible + colPossible + cornerPossible)) {
										for (int rx = 0; rx < R; rx++) {
											for (int ry = 0; ry < C; ry++) {
												if(rx==0 && ry==0)
													result = result + "c";
												else if (rx<=startR && ry<=startC)
													result = result + ".";
												else {
													if(remaining<rowPossible) {
														if(rx==startR+1 && ry<remaining	) {
															result = result + ".";
														} else {
															result = result + "*";
														}
													} else if(remaining<colPossible) {
														if(ry==startC+1 && rx<remaining) {
															result = result + ".";
														} else {
															result = result + "*";
														}
													} else if(remaining == rowPossible + colPossible + cornerPossible) {
														if(rx==startR+1 && ry<=startC+1) {
															result = result + ".";
														} else if(rx<=startR+1 && ry==startC+1) {
															result = result + ".";
														} else {
															result = result + "*";
														}
													} else if(remaining == rowPossible + colPossible) {
														if(rx==startR+1 && ry<=startC) {
															result = result + ".";
														} else if(rx<=startR && ry==startC+1) {
															result = result + ".";
														} else {
															result = result + "*";
														}
													} else if(remaining<(rowPossible + colPossible)) {
														 int rowLimit = 0, colLimit = 0;
														 if(remaining - rowPossible==1)
															 rowLimit = remaining-2;
														 else {
															 rowLimit = rowPossible;
														 }
														 colLimit = remaining - rowLimit;
														 if(rowLimit==1 || colLimit==1) {
															 result = "Impossible";
															 break;
														 } else if(rx==startR+1 && ry<rowLimit) {
															 result = result + ".";
														 } else if(ry==startC+1 && rx<colLimit) {
															 result = result + ".";
														 } else {
															 result = result + "*";
														 }
													}
												} 
											}
											if(result.equals("Impossible"))
												break;
											result = result + "\n";
										}
										break;
									}
								}
								
							}
							if(!result.isEmpty()) break;
						}
					}
				}
			}
			if (result == "")
				result = "Impossible";
			writeLine(prefix + i + ":\n" + result.trim());
		}
	}

	static void writeLine(String next) throws IOException {
		bw.write(next);
		bw.write("\n");
	}

	static String getNextLine() throws IOException {
		String next = br.readLine();
		if (next == null)
			return null;
		while (next != null && next.trim().isEmpty()) {
			next = br.readLine();
		}
		return next;
	}

}
