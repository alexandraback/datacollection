package Round1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Pogo {

	/**
	 * @param args
	 */

	public static String oneMove(int[] move) {
		if (move[0] == 0) {
			if (move[1] > 0)
				return "N";
			else
				return "S";
		} else {
			if (move[0] > 0)
				return "E";
			else
				return "W";
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br;
		try {
			int N;
			br = new BufferedReader(new FileReader("B-small-attempt0.in.txt"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line = br.readLine();
			N = Integer.parseInt(line);
			int count = 1;
			while (count <= N) {
				line = br.readLine();
				String[] strs = line.split(" ");
				String path = "";
				int dx = Integer.parseInt(strs[0]);
				int dy = Integer.parseInt(strs[1]);
				int x = 0;
				int y = 0;
				int[] start = new int[2];
				start[0] = x;
				start[1] = y;
				int[] end = new int[2];
				end[0] = dx;
				end[1] = dy;
				boolean flag = true;
				int jLength = 1;
				int[] move = { 0, 0 };
				while (flag) {
					if (Math.abs(end[0] - start[0]) > Math.abs(end[1]
							- start[1])) {
						if (Math.abs(end[0] - start[0]) >= jLength) {
							if (end[0] > start[0]) {
								move[0] = jLength;
								move[1] = 0;
							} else {
								move[0] = -jLength;
								move[1] = 0;
							}
						} else {
							if (end[0] > start[0]) {
								move[0] = -jLength;
								move[1] = 0;
							} else {
								move[0] = jLength;
								move[1] = 0;
							}
						}
					} else {
						if (Math.abs(end[1] - start[1]) >= jLength) {
							if (end[1] > start[1]) {
								move[1] = jLength;
								move[0] = 0;
							} else {
								move[1] = -jLength;
								move[0] = 0;
							}
						}else{
							if (end[1] > start[1]) {
								move[1] = -jLength;
								move[0] = 0;
							} else {
								move[1] = jLength;
								move[0] = 0;
							}}
					}
					path += oneMove(move);
					start[0] += move[0];
					start[1] += move[1];
					jLength += 1;
					System.out.println(move[0] + " " + move[1] + " " + start[0] + " " + start[1]);
					if (start[0] == end[0] && start[1] == end[1]) {
						flag = false;
					}
				}

				System.out.println("Case #" + count + ": " + path);
				pw.write("Case #" + count + ": " + path + "\n");
				pw.flush();
				count++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
