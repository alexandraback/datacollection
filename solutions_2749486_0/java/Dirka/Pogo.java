import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Pogo {

	static String filename = "B-small-attempt0.in";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(filename));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			for (int i = 1; i <= T; i++) {
				line = br.readLine();
				String temp[] = line.split("\\s");
				int x = Integer.parseInt(temp[0]);
				int y = Integer.parseInt(temp[1]);

				int xz = 0;
				int yz = 0;

				int pogo = 1;
				String seq = "";
				while (xz != x || yz != y) {

					if (x > 0) { // going east
						if (y > 0) { // going north
							if (xz + pogo <= x) {
								xz += pogo++;
								seq += "E";
							} else {
								if (yz + pogo <= y) {
									yz += pogo++;
									seq += "N";
								} else {
									if (xz != x) {
										xz -= pogo++;
										seq += "W";										
									} else {
										yz -= pogo++;
										seq += "S";
									}
								}
							}
						} else { // Going south
							if (xz + pogo <= x) {
								xz += pogo++;
								seq += "E";
							} else {
								if (yz - pogo >= y) {
									yz -= pogo++;
									seq += "S";
								} else {
									if (xz != x) {
										xz -= pogo++;
										seq += "W";										
									} else {
										yz += pogo++;
										seq += "N";
									}
								}
							}
						}
					} else { // going west
						if (y > 0) { // going north
							if (xz - pogo >= x) {
								xz -= pogo++;
								seq += "W";
							} else {
								if (yz + pogo <= y) {
									yz += pogo++;
									seq += "N";
								} else {
									if (xz != x) {
										xz += pogo++;
										seq += "E";										
									} else {
										yz -= pogo++;
										seq += "S";
									}
								}
							}
						} else { // Going south
							if (xz - pogo >= x) {
								xz -= pogo++;
								seq += "W";
							} else {
								if (yz - pogo >= y) {
									yz -= pogo++;
									seq += "S";
								} else {
									if (xz != x) {
										xz += pogo++;
										seq += "E";										
									} else {
										yz += pogo++;
										seq += "N";
									}
								}
							}
						}
					}
				}
				System.out.println("Case #" + i + ": " + seq);
			}

			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
