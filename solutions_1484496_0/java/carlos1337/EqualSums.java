package B;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

public class EqualSums {

	int num;
	
	ArrayList<Integer> construct=new ArrayList<Integer>(); 
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new File("C-small.out"));
		int t = sc.nextInt();
		for (int k = 1; k <= t; k++) {
		int n = sc.nextInt();
		int[] num= new int[n];
		for (int i = 0; i < num.length; i++) {
			num[i] = sc.nextInt();
		}
		
		ArrayList<EqualSums> sums = new ArrayList();
		Integer[] res1 = null;
		Integer[] res2 = null;
		Hashtable<Integer, EqualSums> table = new Hashtable<Integer, EqualSums>();
		inicial:for (int i = 0; i < num.length; i++) {
			if(table.containsKey(num[i])){
				res1 = table.get(num[i]).construct.toArray(new Integer[]{});
				res2 = new Integer[]{num[i]};
				break;
			}
			EqualSums n2 = new EqualSums();
			n2.num=num[i];
			n2.construct.add(num[i]);		
			table.put(num[i], n2);			
			ArrayList<EqualSums> nuevo= new ArrayList();
			for (EqualSums equalSums : sums) {
				EqualSums es = table.get(equalSums.num+num[i]);
				ArrayList<Integer> lst = new ArrayList(equalSums.construct);
				lst.add(num[i]);
				EqualSums nv = new EqualSums();
				nv.num = equalSums.num+num[i];
				nv.construct=lst;
				if(es != null){
					res1 = es.construct.toArray(new Integer[]{});					
					res2 = lst.toArray(new Integer[]{});
					break inicial;
				}else{				
					System.out.println("Added "+nv.num);
					nuevo.add(nv);
					table.put(nv.num, nv);
				}				
			}
			sums.add(n2);
			sums.addAll(nuevo);			
		}
		pw.println("Case #"+k+":");
		if (res1==null)
			pw.println("Impossible");
		else{
			String s1 = Arrays.toString(res1);
			String s2 = Arrays.toString(res2);
			pw.println(s1.substring(1,s1.length()-1).replace(",","").trim());
			pw.println(s2.substring(1,s2.length()-1).replace(",","").trim());
		}
			
		}
		pw.close();
	}
	
}
