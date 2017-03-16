package diamond;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class diamond {

	public static void main(String[] args) {
		if (args.length != 2)
			throw new IllegalArgumentException("No file specified");

		List<String> data = new ArrayList<String>();
		List<String> results = new ArrayList<String>();
		try {
			FileInputStream fstream = new FileInputStream(args[0]);
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			while ((strLine = br.readLine()) != null) {
				data.add(strLine);
			}
			in.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}

		if (data.size() == 0)
			throw new IllegalArgumentException("No data in file");

		int noTestCases = Integer.parseInt(data.get(0));
		/*
		if (data.size() != noTestCases + 1)
			throw new IllegalArgumentException("Number of test cases is not "
					+ noTestCases);
		 */
		int count=1;
		for (int i = 1; i <= noTestCases; i++) {
			int noClazzes = Integer.parseInt(data.get(count));
			List<clazz> cx = new ArrayList<clazz>();
			for (int c=1;c<=noClazzes;c++) {
				count++;
				clazz cl = new clazz(c,data.get(count));
				cx.add(cl);
			}
			count++;
			results.add("Case #" + i + ": " + parse(cx));
		}

		try {
			FileWriter fostream = new FileWriter(args[1]);
			BufferedWriter out = new BufferedWriter(fostream);
			for (int i =0;i<results.size();i++) {
				String s = results.get(i);
				System.out.println(s);
				out.write(s);
				if (i<results.size()-1)
					out.newLine();
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static String parse(List<clazz> c) {

		TestCase tc = new TestCase(c);
		return tc.getResult();

	}

	private static class TestCase {

		boolean result;
		List<clazz> clazzes; 

		public TestCase(List<clazz> cx) {
			result = false;
			clazzes = cx;
			/*
			StringTokenizer st = new StringTokenizer(input, " ");
			if (st.countTokens() ==0 )
				throw new IllegalArgumentException("no value found");

			int no = Integer.parseInt(st.nextToken());
			if (st.countTokens() != no)
				throw new IllegalArgumentException("Wrong no of values");

			int id =1;

			clazzes = new ArrayList<clazz>();
			while (st.hasMoreTokens()) {
				clazz c = new clazz(id,st.nextToken());
				clazzes.add(c);
				id++;

			}
			 */

			for (clazz c : clazzes) {
				List<Integer> p = c.getParents();
				List<Integer> allP = new ArrayList<Integer>();
				Stack<Integer> s = new Stack<Integer>();
				for (Integer i : p) {
					s.push(i);
					allP.add(i);
				}

				while (!s.empty()) {
					Integer i = s.pop();

					clazz c2 = findClazz(i);
					List<Integer> p2 = c2.getParents();
					for (Integer i2: p2){
						if (allP.contains(i2)) {
							result=true;
							return;
						}
						s.push(i2);
						allP.add(i2);
					}

				}
			}

		}

		private clazz findClazz(int i) {
			for(clazz c : clazzes) {
				if (c.getId() == i)
					return c;
			}
			return null;
		}

		public String getResult() {
			return result?"Yes":"No";
		}	




	}

	public static class clazz {
		private int id;
		private List<Integer> parents;

		public clazz(int id, String input) {
			this.id = id;
			StringTokenizer st = new StringTokenizer(input, " ");
			if (st.countTokens() ==0 )
				throw new IllegalArgumentException("no value found");

			int no = Integer.parseInt(st.nextToken());
			if (st.countTokens() != no)
				throw new IllegalArgumentException("Wrong no of values");


			parents = new ArrayList<Integer>();
			while (st.hasMoreTokens()) {
				Integer s = Integer.parseInt(st.nextToken());				
				parents.add(s);
			}

		}

		public List<Integer> getParents() {return parents;}
		public int getId() {return id;}
	}

}
