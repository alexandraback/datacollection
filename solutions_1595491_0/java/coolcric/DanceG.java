
import java.io.*;
import java.util.*;

class B{}

public class DanceG {
	static Scanner scan;
	static PrintWriter writer;
	static HashMap<Integer, List<Integer>> map;
	
	
	public static void readProcessOutput() throws Exception{
	
		String outputStr = ""; String result = "";
		int index = 1;	
		
		int testCases = Integer.parseInt(scan.nextLine());
		//-------
		
		
		
		//-------
		
		while(index <= testCases ){	//runs testCases number of times
		
			System.out.println("Running testcase : " + index);
			int surprises = 0;
			int count = 0;
			//-----------
			Scanner temp = new Scanner(scan.nextLine());
			int N = temp.nextInt();
			int S = temp.nextInt();
			int p = temp.nextInt();
			int scores[] = new int[N];
			Integer triplet[][] = new Integer[N][3];
			map = new HashMap<Integer, List<Integer>>();
			
			for(int i =0; i < N; i++){
				scores[i] = temp.nextInt();
				int j = scores[i] / 3;
				triplet[i][0] = j + scores[i] % 3;
				if(triplet[i][0] <= 10)
					triplet[i][1] = triplet[i][2] = j;
				else{
					triplet[i][0] = 10;
					triplet[i][1] = j;
					triplet[i][2] = j+1;
				}			
				
				
				
				int min = (int) Collections.min(Arrays.asList(triplet[i]));
				int max = (int) Collections.max(Arrays.asList(triplet[i]));
				
				Arrays.sort(triplet[i]);
				if(triplet[i][2] < p)
					if(max - min == 0 && max != 0){
						triplet[i][0]--;
						triplet[i][2]++;
				}
				
				List<Integer> l = map.get(triplet[i][2]);
				if(l == null)
					l = new ArrayList<Integer>();
				
				l.add(i);
				map.put(triplet[i][2], l);
				
				if(triplet[i][2] - triplet[i][0] == 2){
					surprises++;
				}
			}
			
			Object keys[] = map.keySet().toArray();
			Arrays.sort(keys);
			int m = 0; int n = p;
			while((m = Arrays.binarySearch(keys, n++)) < 0 && n <= 10);
			int r = m;
			for(; m < keys.length && m >= 0; m++)
				count += map.get(((Integer) keys[m])).size();
			
			if(surprises > S){
				
				int diff = surprises - S;
				int j = 0, k = 0;
				while(j < diff && ((Integer) keys[k]) < p){
					//j += map.get(((Integer) keys[k++])).size();
					List<Integer> t = map.get(((Integer) keys[k++]));
					int u = t.size();
					while(--u >= 0){
						int v = t.get(u);
						Arrays.sort(triplet[v]);
						if(triplet[v][2] - triplet[v][0] == 2)
							j++;
						if(j == diff)
							break;
					}
				}
				
				if(k < keys.length && ((Integer) keys[k]) >= p){
					//count -= (diff - j);
					int un = diff - j;
					int s = keys.length - 1;
					while(un > 0){
						List<Integer> l =  map.get(((Integer) keys[s--]));
					
						int q = 0;
						while(q < l.size()){
							int o = l.get(q++);
							if(triplet[o][2] - triplet[o][0] == 2){
								triplet[o][2]--;
								triplet[o][0]++;
								Arrays.sort(triplet[o]);
								if(triplet[o][2] < p){
									count--;
								}
								un--;
								if(un == 0)
									break;
							}
						}
					}
				}
					
			}
			
			else if(surprises < S){
				
				
//				while(surprises < S){
//					List<Integer> l =  map.get(((Integer) keys[r++]));
//				
//					int q = 0;
//					while(q < l.size()){
//						int o = l.get(q++);
//						Arrays.sort(triplet[o]);
//						
//						if(triplet[o][2] - triplet[o][0] < 2 && triplet[o][2] <10){
//							triplet[o][2]++;
//							triplet[o][0]--;
//							surprises++;
//						}
//					
//						if(triplet[o][2] < p){
//							count--;
//						}
//						
//						if(surprises == S)
//							break;
//						
//					}
//				}			
//				
				
				
			}
			
			
			
		
			//------------
			
			
			outputStr = "Case #" + index + ": " + 			count;
			
			writer.println(outputStr);
			
			result = "";
			outputStr = "";
			index++;
			
		}

		scan.close();
		writer.close();
		
	}
	
	
	
	static void setApart(Integer [] arr){

	}
	

	
	public static void main(String[] args) throws Exception {
		
		Scanner in = new Scanner(System.in);
		String className = B.class.getSimpleName() ;
		int choice = 0;
		
		do{
				
			System.out.println("Enter your choice :");
			System.out.println("1) Solve small");
			System.out.println("2) Solve large");
			System.out.print("Choice : ");
			choice = in.nextInt();
			
		switch(choice){
			case 1 :
				scan = new Scanner(new File(className + "-small-practice.in"));
				writer = new PrintWriter(new BufferedWriter(new FileWriter(new File(className +"small.txt"))));
				readProcessOutput();
				System.out.println("Solved successfully!\n"); 
				break;
			case 2 :
				scan = new Scanner(new File(className + "-large-practice.in"));
				writer = new PrintWriter(new BufferedWriter(new FileWriter(new File(className +"large.txt"))));
				readProcessOutput();
				System.out.println("Solved successfully!\n"); 
				break;
		}
		
		
		}while (choice != 0);
		
		System.out.println("Program finished!");
		
	}
}
