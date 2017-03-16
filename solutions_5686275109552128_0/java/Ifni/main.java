import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class main {
	public static void write(PrintWriter file, int idx, String str){
		file.println("Case #"+idx+": "+str);
	}
	public static void write(PrintWriter file, int idx, int ans){
		file.println("Case #"+idx+": "+ans);
	}	

	static class PQsort implements Comparator<Integer> {		 
		public int compare(Integer one, Integer two) {
			return two - one;
		}
	}	
	public static int divide(PriorityQueue<Integer> heap2, int j, int split){
		PriorityQueue<Integer> heap=new PriorityQueue<Integer>(heap2);
		if(j<=0)
			return heap.peek().intValue();
		if (j==1&&split==3)
			return heap.peek();
		if (split==2){
				int temp = heap.poll().intValue();
				if(temp%2==0){
					heap.offer(temp/2); heap.offer(temp/2);}
				else{
					heap.offer(temp/2+1); heap.offer(temp/2);}
				return Math.min(Math.min(heap.peek()+1, divide(heap, j-1,2)+1), divide(heap, j-1,3)+1);}
		if (split==3){
			int temp = heap.poll().intValue();
			if(temp%3==0){
				heap.offer(temp/3); heap.offer(temp/3);heap.offer(temp/3);}
			else if(temp%3==1){
				heap.offer(temp/3+1); heap.offer(temp/3);heap.offer(temp/3);}
			else{
				heap.offer(temp/3+1); heap.offer(temp/3+1);heap.offer(temp/3);}
			return Math.min(Math.min(heap.peek()+2, divide(heap, j-2,2)+2), divide(heap, j-2,3)+2);}
		return 0;
	}
	
	
	public static void main(String[] args) throws IOException {
     	String epreuve="B-small-attempt1.in";
		File entry = new File(epreuve);
		Scanner scin= new Scanner(entry);
		File out = new File("Output"+epreuve);
		out.createNewFile();
		PrintWriter scout= new PrintWriter(out);	
		// Set up of the problem
		int T = scin.nextInt();
		int temp;
		PriorityQueue<Integer> heap; PQsort pqs = new PQsort();
		for (int i=1; i<= T; i++){
			int D=scin.nextInt();System.out.println(i); heap=new PriorityQueue<Integer>(2*D,pqs);
			for(int j=0; j<D; j++)
				heap.offer(scin.nextInt());
			int DM=heap.peek();
			int ans=Math.min(Math.min(DM,divide(heap, DM,2)), divide(heap,DM,3));
			write(scout, i,ans);
		}
			
		scin.close();
		scout.close();
	}

}
