import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.HashSet;
import java.util.Scanner;


public class Round1A_3 {
	static HashSet<Integer> s = new HashSet<Integer>();
	static int maxSize = 0;
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(System.in);
		PrintWriter out = new PrintWriter("output.txt", "UTF-8");
		
		System.out.println("Input Filename: ");
		String filename = scan.nextLine();
		try {scan = new Scanner(new File(filename));}
		catch(Exception e){
			System.out.println("Invalid File Input");
			return;
		}
		
		int sets = scan.nextInt();
		for(int k = 1; k <= sets; ++k){
			int size = scan.nextInt();
			int[] bffs = new int[size];
			for(int j = 0; j < size; ++j){
				bffs[j] = scan.nextInt();
			}
			/*
			int i = 1;
			while(s.size() < size){
				System.out.println("I: " + i);
				s.add(i);
				int bff = bffs[i-1];
				if(s.contains(bff)){
					System.out.println("CONTAINS BFF! " + bff);
					boolean changed = false;
					for(int j = 0; j < size; ++j){
						System.out.println("J: " + bffs[j] + " I: " + i);
						if(bffs[j] == i && !s.contains(j+1)){
							System.out.println("FOUND A NEW ONE! " + (j+1));
							bff = j+1;
							changed = true;
							break;
						}
					}
					i = (changed) ? bff : 1;

				}
				else {
					i = bff;
				}
				//System.out.println("I-TO-ADD: " + i);
				if(i == 1) break;
			}
			*/
			
			backtracking(1, size, bffs);
			out.println("Case #" +k +": " + maxSize);
			//System.out.println(s.toString());
			s.clear();
			maxSize = 0;
		}
		out.close();
	}
	
	static boolean backtracking(int id, int size, int[] bffs){
		//System.out.println("\nNEW ITERATION!");
		s.add(id);
		int bff = bffs[id-1];
		int old_id = id;
		if(s.contains(bff)){
			//System.out.println("CONTAINS BFF! " + bff);
			for(int j = 0; j < size; ++j){
				//System.out.println(bffs[j] + " " + id);
				if(bffs[j] == id && !s.contains(j+1)){
					//System.out.println("FOUND A NEW ONE! " + (j+1));
					id = j+1;
					backtracking(id, size, bffs);
					id = old_id;
				}
			}
			id = 1;

		}
		else {
			id = bff;
		}
		
		if(id == 1){
			if(maxSize < s.size()){
				//System.out.println("NEW SIZE " + s.size());
				//System.out.println(s.toString());
				maxSize = s.size();
			}
			s.remove(old_id);
			return false;
		}
		else {
			backtracking(id, size, bffs);
		}
		return false;
	}
}
