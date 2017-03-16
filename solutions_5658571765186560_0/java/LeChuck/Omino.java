import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Omino {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO READER		
		//BufferedReader br= new BufferedReader(new FileReader("bum.in"));
		BufferedReader br= new BufferedReader(new FileReader("D-small-attempt0.in"));
		//BufferedReader br= new BufferedReader(new FileReader("A-large-practice(2).in"));
		
		// TODO WRITER
		PrintWriter pw = new PrintWriter("Omino.txt", "UTF-8");
		int T=Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i < T; i++){
			
			String[] tab =br.readLine().split(" ");
			int X = Integer.parseInt(tab[0]);
			int R = Integer.parseInt(tab[1]);
			int C = Integer.parseInt(tab[2]);
			if(R > C){
				int t = R;
				R = C;
				C = t;
			}
			String name = "GABRIEL";
			
			
			if(X>=7) name = "RICHARD";
			else if(R * C % X != 0) name = "RICHARD";
			else if(X > C || (X+1)/2 > R) name = "RICHARD";
			else if(X <= 3) name = "GABRIEL";
			else if((X+1)/2 == R) name = "RICHARD";
			
			
	
			System.out.print("Case #"+(i+1)+": "+name+"\n");
			pw.write("Case #"+(i+1)+": "+name+"\n");

		}
		pw.close();
	}
}