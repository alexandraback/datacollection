import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class a {
	public static class node implements Comparable<node> {
		int index;
		int val;

		node(int index, int val) {
			this.index = index;
			this.val = val;
		}

		@Override
		public int compareTo(node o) {
			if (o.val < val)
				return 1;
			else if (o.val > val)
				return -1;
			else if (o.index < index)
				return 1;
			else
				return -1;
		}

	}

	public static void main(String[] args) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		 BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		StringBuilder q = new StringBuilder();
		//PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		 PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			String y[] = in.readLine().split(" ");
			int a = Integer.parseInt(y[0]);
			int b = Integer.parseInt(y[1]);
			int k = Integer.parseInt(y[2]);
			int ans = 0;
			for (int j = 0; j < a; j++) {
				for (int j2 = 0; j2 < b; j2++) {
					if ((j & j2) < k) {

						ans++;
					}
				}
			}
			out.println("Case #" + (i + 1) + ": " + ans);

		}

		out.close();

	}
}