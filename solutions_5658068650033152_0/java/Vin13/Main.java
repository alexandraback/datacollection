import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
 
public class Main {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("C-small-attempt0.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				String[] line = br.readLine().split(" ");
				int row = Integer.parseInt(line[0]);
				int col = Integer.parseInt(line[1]);
				int enc = Integer.parseInt(line[2]);
				
				
				if (row <= 2 || col <= 2 || enc < 5) {
					System.out.println("Case #" + (i+1) + ": " + enc);
					continue;
				}
				
				int stones = 4;
				int inside = 1;
				
				int usedRow = 3;
				int usedCol = 3;
				
				if (stones + inside >= enc) {
					System.out.println("Case #" + (i+1) + ": " + stones);
					continue;
				}
				
				int level = 1;
				
				while (true) {
					if (usedRow < row) {
						stones += 1;
						if (stones + inside >= enc) {
							break;
						}
						stones += 1;
						inside += 1;
						if (stones + inside >= enc) {
							break;
						}
						for (int j = 0; j < level && usedCol+j < col; j++) {
							stones += 1;
							inside += 1;
							if (stones + inside >= enc) {
								break;
							}
						}
						if (stones + inside >= enc) {
							break;
						}
						usedRow++;
					}
					else if (usedCol < col) {
						stones += 1;
						if (stones + inside >= enc) {
							break;
						}
						stones += 1;
						inside += 1;
						if (stones + inside >= enc) {
							break;
						}
						for (int j = 0; j < level && usedRow+j < row; j++) {
							stones += 1;
							inside += 1;
							if (stones + inside >= enc) {
								break;
							}
						}
						if (stones + inside >= enc) {
							break;
						}
						usedCol++;
					}
					else
						break;
				}

				if (stones + inside >= enc) {
					System.out.println("Case #" + (i+1) + ": " + stones);
					continue;
				}
				
				
				System.out.println("Case #" + (i+1) + ": " + (enc-inside));
				continue;
				
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}