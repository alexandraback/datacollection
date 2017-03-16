import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class B {
	
	public static class Item implements Comparable<Item>{
		int num;
		int rel;
		int index;
		
		public Item(int num , int index, int rel){
			this.num = num;
			this.index = index;
			this.rel = rel;
		}
		public int compareTo(Item o){
			if(num < o.num)
				return -1;
			else if(num > o.num)
				return 1;
			else
				return 0;
		}
		public String toString(){
			return num + "\t" + index;
		}
	}
	
	public static int solve(int N , Item[] A, Item[] B){
		Arrays.sort(A);
		Arrays.sort(B);
		boolean[] used = new boolean[N];
		boolean[] complete = new boolean[N];
		for(int i = 0 ; i < N ; i ++){
			used[i] = false;
			complete[i] = false;
		}
		
		
		
		int time = 0;
		int sum = 0;
		int i = 0 ;
		
		while(i < N){
			int require = B[i].num;
			if(sum < require){
				
				while(sum < require){
					
					int maxj = -1;
					int maxvalue = -1;
					for(int j = 0 ; j < N ; j ++){
						if(used[A[j].index] || complete[A[j].index])
							continue;
						int value = A[j].rel;
						if(value > maxvalue && A[j].num <= sum){
							maxvalue = value;
							maxj = j;
						}
					}
					
					if(maxj < 0)
						return -1;
					
					sum = sum + 1;
					used[A[maxj].index] = true;
					time ++;
				}
				
				if(sum < require)
					return -1;
			}
			
			if(used[B[i].index]){
				sum = sum + 1;
			}else{
				sum = sum + 2;
			}
			complete[B[i].index] = true;
			time ++;
			i ++;
		}
		
		return time;
	}
	
	public static void main(String args[]) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("B-small-attempt3.in")));
	//	BufferedReader reader = new BufferedReader(new FileReader(new File("test.txt")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("B.txt")));
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		for(int i = 0 ; i < T ; i ++){
			line = reader.readLine();
			String tokens[] = line.split("\\s+");
			int N = Integer.parseInt(tokens[0]);
			Item[] A = new Item[N];
			Item[] B = new Item[N];
			for(int j = 0 ; j < N ; j ++){
				line = reader.readLine();
				tokens = line.split("\\s+");
				int aj = Integer.parseInt(tokens[0]);
				int bj = Integer.parseInt(tokens[1]);
				Item aitem = new Item(aj , j, bj);
				Item bitem = new Item(bj , j, aj);
				A[j] = aitem;
				B[j] = bitem;
			}
			int result = solve(N , A , B);
			System.out.println(i + "\t" + result);
			if(result >= 0)
				writer.write("Case #" + (i + 1) + ": " + result + "\r\n");
			else
				writer.write("Case #" + (i + 1) + ": Too Bad\r\n");
		}
		reader.close();
		writer.close();
	}

}
