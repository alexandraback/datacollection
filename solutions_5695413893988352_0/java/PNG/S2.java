import java.io.*;
import java.util.*;

public class S2 {
	
	public static void main(String[] args) throws Exception {
		try (Scanner sc = new Scanner(System.in);
				BufferedWriter out = new BufferedWriter(new FileWriter(new File("out.txt")))) {
			int T = sc.nextInt();
			for (int i = 1; i <= T; i++) {
				String cs = sc.next();
				String js = sc.next();
				
				StringBuilder ca = new StringBuilder();
				StringBuilder ja = new StringBuilder();
				
				int l = cs.length();
				for (int j = 0; j < l; j++) {
					char cd = cs.charAt(j);
					char jd = js.charAt(j);
					
					if (ca.toString().equals(ja.toString())) {
						if (cd != '?' && jd != '?') {
							ca.append(cd);
							ja.append(jd);
						} else if (cd == '?' && jd == '?') {
							if (j + 1 < l) {
								char cn = cs.charAt(j + 1);
								char jn = js.charAt(j + 1);
								if (cn == '?' || jn == '?') {
									if (cd == jd && cd == '?') {
										cd = '0';
										jd = '0';
									} else if (cd == '?') {
										cd = jd;
									} else {
										jd = cd;
									}
									ca.append(cd);
									ja.append(jd);
								} else {
									int diff = Math.abs(cn - jn);
									if (diff < 5) {
										ca.append('0');
										ja.append('0');										
									} else {
										if (cn > '5') {
											ca.append('0');
											ja.append('1');
										} else if (jn > '5') {
											ca.append('1');
											ja.append('0');
										} else {
											ca.append('0');
											ja.append('0');											
										}
									}
								}
							} else {
								ca.append('0');
								ja.append('0');
							}
						} else {
							if (j + 1 < l) {
								char cn = cs.charAt(j + 1);
								char jn = js.charAt(j + 1);
								if (cn == '?' || jn == '?') {
									if (cd == jd && cd == '?') {
										cd = '0';
										jd = '0';
									} else if (cd == '?') {
										cd = jd;
									} else {
										jd = cd;
									}
									ca.append(cd);
									ja.append(jd);						
								} else {
									int diff = Math.abs(cn - jn);
									if (diff < 5) {
										if (cd == '?') {
											cd = jd;
										} else {
											jd = cd;
										}
										ca.append(cd);
										ja.append(jd);										
									} else {
										if (cn > '5') {
											if (cd == '?') {
												cd = jd == '0' ? '0' : (char) (jd - 1);
											} else {
												jd = cd == '9' ? '9' : (char) (cd + 1);
											}
											ca.append(cd);
											ja.append(jd);
										} else if (jn > '5') {
											if (cd == '?') {
												cd = jd == '9' ? '9' : (char) (jd + 1);
											} else {
												jd = cd == '0' ? '0' : (char) (cd - 1);
											}
											ca.append(cd);
											ja.append(jd);
										} else if (cd == '5') {
											if (cd == '?') {
												cd = jd == '0' ? '0' : (char) (jd - 1);
											} else {
												jd = cd;
											}
											ca.append(cd);
											ja.append(jd);
										} else {
											if (cd == '?') {
												cd = jd;
											} else {
												jd = cd == '0' ? '0' : (char) (cd - 1);
											}
											ca.append(cd);
											ja.append(jd);
										}
									}
								}
							} else {
								if (cd == '?') {
									cd = jd;
								} else {
									jd = cd;
								}
								ca.append(cd);
								ja.append(jd);
							}
						}
					} else {
						if (cd != '?' && jd != '?') {
							ca.append(cd);
							ja.append(jd);
						} else {
							int cb = Integer.parseInt(ca.toString());
							int jb = Integer.parseInt(ja.toString());
							if (cb == jb) {
								if (cd == jd && cd == '?') {
									cd = '0';
									jd = '0';
								} else if (cd == '?') {
									cd = jd;
								} else {
									jd = cd;
								}
								ca.append(cd);
								ja.append(jd);
							} else if (cb > jb) {
								cd = cd == '?' ? '0' : cd;
								jd = jd == '?' ? '9' : jd;
								ca.append(cd);
								ja.append(jd);
							} else {
								cd = cd == '?' ? '9' : cd;
								jd = jd == '?' ? '0' : jd;
								ca.append(cd);
								ja.append(jd);									
							}
						}
					}
					
				}
				
				out.write("Case #");
				out.write(String.valueOf(i));
				out.write(": ");
				
				out.write(ca.toString());
				out.write(" ");
				out.write(ja.toString());
				
				out.write("\n");
				
			}
		}
	}

}
