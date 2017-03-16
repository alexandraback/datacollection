import java.io.*;
import java.util.*;

public class diamond {
	private ArrayList<Integer> inherited_from_at_least_two = new ArrayList<Integer>();
	private TreeMap<Integer, ArrayList<Integer>> input_data = new TreeMap<Integer, ArrayList<Integer>>();
	private int total_classes;
	private boolean result;

	private void go() throws NumberFormatException, IOException {
		File infile = new File("A-small-attempt3.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream(infile)));
		int total_cases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= total_cases; i++) {
			processinput(br);
			preprocess();
			if (inherited_from_at_least_two.size() == 0) {
				System.out.println("Case #" + i + ": No");
				continue;
			} else {
				for (int j = 0; j < inherited_from_at_least_two.size(); j++) {
					int curclass_no = inherited_from_at_least_two.get(j);
					ArrayList<Integer> inherited_from = (ArrayList<Integer>) input_data
							.get(curclass_no).clone();
					ArrayList <Integer> inherite_root = new ArrayList <Integer>();
					inner: while (true) {
						boolean flag = false;
						ArrayList <Integer> current = (ArrayList<Integer>) inherited_from.clone();
						for(int k=0;k<current.size();k++){
							inherited_from.remove(new Integer(current.get(k)));
							ArrayList <Integer>inherited_from_2 = (ArrayList<Integer>) input_data.get(current.get(k)).clone();
							if(inherited_from_2.size()==0)inherite_root.add(current.get(k));
							else{
								for(int l=0; l<inherited_from_2.size();l++){
									inherited_from.add(inherited_from_2.get(l));
								}
								flag = true;
							}
						}
						if(!flag)break inner;
					}
					Set <Integer>root_set = new HashSet<Integer>(inherite_root);
					//System.out.println(root_set);
					//System.out.println(inherite_root);
					if(root_set.size()!=inherite_root.size())result=true;
				}

				if (result)
					System.out.println("Case #" + i + ": Yes");
				else
					System.out.println("Case #" + i + ": No");
			}
			flush();
		}
	}

	public static void main(String[] args) {
		try {
			new diamond().go();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		} catch (NumberFormatException ex) {
			ex.printStackTrace();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

	private void processinput(BufferedReader br) throws NumberFormatException,
			IOException {
		total_classes = Integer.parseInt(br.readLine());
		for (int i = 1; i <= total_classes; i++) {
			String curclass = br.readLine();
			if (curclass.equals("0"))
				input_data.put(i, new ArrayList<Integer>());
			else {
				String[] inherited_from = curclass.split(" ");
				ArrayList<Integer> cur_inherit = new ArrayList<Integer>();
				for (int j = 1; j <= Integer.parseInt(inherited_from[0]); j++) {
					cur_inherit.add(Integer.parseInt(inherited_from[j]));
				}
				input_data.put(i, cur_inherit);
			}
		}
	}

	private void flush() {
		inherited_from_at_least_two.clear();
		input_data.clear();
		total_classes = 0;
		result = false;
	}

	private void preprocess() {
		try {
			for (int i = 1; i <= total_classes; i++) {
				ArrayList<Integer> curclass = input_data.get(new Integer(i));
				if (curclass.size() < 2)
					continue;
				else
					inherited_from_at_least_two.add(i);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
