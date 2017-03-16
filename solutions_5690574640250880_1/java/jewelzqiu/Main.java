import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("input"));
			PrintWriter writer = new PrintWriter(new BufferedWriter(
					new FileWriter("output")));
			int n = Integer.valueOf(reader.readLine());
			int row, column, num, total;
			StringBuilder sb;
			StringTokenizer tokenizer;
			for (int i = 0; i < n; i++) {
				tokenizer = new StringTokenizer(reader.readLine());
				row = Integer.valueOf(tokenizer.nextToken());
				column = Integer.valueOf(tokenizer.nextToken());
				num = Integer.valueOf(tokenizer.nextToken());
				total = row * column;
				sb = new StringBuilder();
				sb.append("Case #");
				sb.append(i + 1);
				sb.append(":\n");
				
				if (total <= num) {
					sb.append("Impossible");
					writer.println(sb.toString());
					continue;
				}
				
				if (total == num + 1) {
					sb.append('c');
					for (int j = 1; j < column; j++) {
						sb.append('*');
					}
					sb.append('\n');
					for (int j = 1; j < row; j++) {
						for (int k = 0; k < column; k++) {
							sb.append('*');
						}
						sb.append('\n');
					}
					writer.print(sb.toString());
					continue;
				}
				
				if (row == 1) {
					sb.append('c');
					for (int j = 1; j < total - num; j++) {
						sb.append('.');
					}
					for (int j = 0; j < num; j++) {
						sb.append('*');
					}
					writer.println(sb.toString());
					continue;
				}
				
				if (column == 1) {
					sb.append("c\n");
					for (int j = 1; j < total - num; j++) {
						sb.append(".\n");
					}
					for (int j = 0; j < num; j++) {
						sb.append("*\n");
					}
					writer.print(sb.toString());
					continue;
				}
				
				if (total - 4 < num) {
					sb.append("Impossible");
					writer.println(sb.toString());
					continue;
				}
				
				int count = total - num;
				int tempRow = -1, tempCol = -1, remaining = -1;
				boolean out = false;
				for (int j = 2; j <= column; j++) {
					int temp = count / j;
					int mod = count % j;
					if (temp < 2 || temp > row || temp == row && mod > 0) {
						continue;
					}
					
					if (mod == 0) {
						tempRow = temp;
						tempCol = j;
						remaining = 0;
						break;
					} else if (mod == 1) {
						if (temp > 2 && j > 2) {
							sb.append('c');
							for (int k = 1; k < j; k++) {
								sb.append('.');
							}
							for (int k = j; k < column; k++) {
								sb.append('*');
							}
							sb.append('\n');
							
							for (int k = 1; k < temp - 1; k++) {
								for (int k2 = 0; k2 < j; k2++) {
									sb.append('.');
								}
								for (int k2 = j; k2 < column; k2++) {
									sb.append('*');
								}
								sb.append('\n');
							}
							
							for (int k = 0; k < j - 1; k++) {
								sb.append('.');
							}
							for (int k = j - 1; k < column; k++) {
								sb.append('*');
							}
							sb.append('\n');
							
							sb.append("..");
							for (int k = 2; k < column; k++) {
								sb.append('*');
							}
							sb.append('\n');
							
							for (int k = temp + 1; k < row; k++) {
								for (int k2 = 0; k2 < column; k2++) {
									sb.append('*');
								}
								sb.append('\n');
							}
							out = true;
							writer.print(sb.toString());
							break;
						}
						continue;
					} else {
						tempRow = temp;
						tempCol = j;
						remaining = mod;
						break;
					}
				}
				
				if (out) {
					continue;
				}
				
				if (tempRow == -1) {
					sb.append("Impossible");
					writer.println(sb.toString());
					continue;
				}
				
				sb.append('c');
				for (int j = 1; j < tempCol; j++) {
					sb.append('.');
				}
				for (int j = tempCol; j < column; j++) {
					sb.append('*');
				}
				sb.append('\n');
				
				for (int j = 1; j < tempRow; j++) {
					for (int k = 0; k < tempCol; k++) {
						sb.append('.');
					}
					for (int k = tempCol; k < column; k++) {
						sb.append('*');
					}
					sb.append('\n');
				}
				
				if (remaining > 0) {
					for (int j = 0; j < remaining; j++) {
						sb.append('.');
					}
					for (int j = remaining; j < column; j++) {
						sb.append('*');
					}
					sb.append('\n');
					tempRow++;
				}
				
				for (int j = tempRow; j < row; j++) {
					for (int k = 0; k < column; k++) {
						sb.append('*');
					}
					sb.append('\n');
				}
				
				writer.print(sb.toString());
			}
			
			reader.close();
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
