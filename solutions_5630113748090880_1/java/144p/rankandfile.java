import java.util.*;

public class rankandfile {


	//YOUR PROBLEM DESCRIPTION PRANKED ME
	public static class listCompare implements Comparator<ArrayList<Integer>>{
	
		@Override
		public int compare(ArrayList<Integer> L1, ArrayList<Integer> L2) {
			int val = 0;
			int length = L1.size();
			for (int i = 0; i < length; i++) {
				if (L1.get(i) == L2.get(i)) continue;
				if (L1.get(i) > L2.get(i)) {
					val = 1;
					break;
				}	
				else if (L1.get(i) < L2.get(i)) {
					val = -1;
					break;
				}
			}
			return val;
		}

	}

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();

		for (int c = 0; c < cases; c++) {
			
			int size = in.nextInt();
			int order[][] = new int[size][size];
			boolean row[] = new boolean[size];
			boolean col[] = new boolean[size];

			int numlists = size*2-1;
			ArrayList<Integer> list = new ArrayList<Integer>();

			for (int i = 0; i < numlists; i++) {
				for (int j = 0; j < size; j++) {
					int read = in.nextInt();
					if (list.isEmpty()) {
						list.add(read);
					}
					else {
						if (list.contains(read)) {
							list.remove(new Integer(read));
						}
						else {
							list.add(read);
						}
					}
				}
			}
			
			Collections.sort(list);

			StringBuilder out = new StringBuilder("Case #" + (c+1) + ":");
			for (int i = 0; i < size; i++) {
				out.append(" " + list.remove(0));
			}

			System.out.println(out);
			
			//ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>(numlists);

			/*for (int i = 0; i < numlists; i++) {
				ArrayList<Integer> temp = new ArrayList<Integer>(size);
				for (int j = 0; j < size; j++) {
					temp.add(in.nextInt());
				}
				lists.add(temp);
			}*/

			/*Collections.sort(lists, new listCompare()); 
			System.out.println("Sorted!");

			for (int i = 0; i < numlists; i++) {
				System.out.println(lists.get(i));
			}

			for (int i = 0; i < numlists; i++) {
				
			}*/

		} //ENDFORC
		
			
	} //em

} //EM
