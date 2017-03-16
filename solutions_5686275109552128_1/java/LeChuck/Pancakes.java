import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;


public class Pancakes {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO READER		
		//BufferedReader br= new BufferedReader(new FileReader("bum.in"));
		BufferedReader br= new BufferedReader(new FileReader("B-large.in"));
		//BufferedReader br= new BufferedReader(new FileReader("A-large-practice(2).in"));
		
		// TODO WRITER
		PrintWriter pw = new PrintWriter("Pancakes1.txt", "UTF-8");
		int T=Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i < T; i++){
			int D = Integer.parseInt(br.readLine());
			String[] tab =br.readLine().split(" ");
			PriorityQueue<Integer> plates = new PriorityQueue<Integer>(Collections.reverseOrder());
			
			
			for(String s : tab) plates.add(Integer.parseInt(s));
			System.out.println("START plates: "+plates);
			plates.add(0);
			int minutes=0;

			ArrayList<Integer> max = new ArrayList<Integer>();
			while(0 < plates.peek()){
						
				max.add(plates.poll());
				int m1 = plates.peek();
				
				if(max.get(0) > max.size() + m1 && max.get(0) > max.size()+(max.get(0)+1)/2){
					System.out.println("max "+max);
					if(max.size()+(max.get(0)+2)/3 < (max.get(0)+1)/2 &&  m1 +2*max.size() <max.get(0) ){
						for(int m : max){
						plates.add((m+2)/3);
						plates.add((2*m+2)/3);
						minutes++;
						}
					}
					else{
					for(int m : max){
						
						plates.add((m+1)/2);
						plates.add(m/2);
						minutes++;
					}}
					max = new ArrayList<Integer>();
					System.out.println("plates " +plates);
				}
				
			}
			minutes+=max.get(0);
	
	
			System.out.println("Case #"+(i+1)+": "+minutes+"\n");
			pw.write("Case #"+(i+1)+": "+minutes+"\n");

		}
		pw.close();
	}
}
