import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Dijkstra {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO READER		
		//BufferedReader br= new BufferedReader(new FileReader("bum.in"));
		BufferedReader br= new BufferedReader(new FileReader("C-small-attempt7.in"));
		//BufferedReader br= new BufferedReader(new FileReader("A-large-practice(2).in"));
		
		// TODO WRITER
		PrintWriter pw = new PrintWriter("Dijkstra.txt", "UTF-8");
		int T=Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i < T; i++){
			String[] tab =br.readLine().split(" ");
			int L = Integer.parseInt(tab[0]);
			//int X=Integer.parseInt(tab[1].length()>2 ? tab[1].substring(tab[1].length()-2) : tab[1]);
			long X=Long.parseLong(tab[1]);
			String str = br.readLine();
	
			
				
			String a="NO";
			char current = '1';
			boolean minus = false;
			int finish=0;
			for(long j=0; j<X*L; j++){
				char temp = str.charAt((int)(j%L));
				
				if(current==temp){
					current='1';
					minus = !minus;
				}
				else if(current=='1')current=temp;
				else if(current=='i'&&temp=='j') current='k';
				else if(current=='i'&&temp=='k'){
					current='j';
					minus=!minus;
				}
				else if(current=='j'&&temp=='i'){
					current='k';
					minus=!minus;
				}
				else if(current=='j'&&temp=='k') current='i';
				else if(current=='k'&&temp=='i') current='j';
				else if(current=='k'&&temp=='j'){
					current='i';
					minus=!minus;
				}
				
				if(current=='i'&&finish==0){
					finish++;
					current='1';
				}
				else if(current=='j'&&finish==1){
					finish++;
					current='1';
				}
				else if(current=='k'&&finish==2){
					finish++;
					current='1';

				}
			}
			//&&X%2==1    &&X%4==2 ||(current!='1'&&finish==3)
			if((current=='1'&&!minus&&finish==3))a="YES";
			System.out.println();
			System.out.println("current "+(minus?"-":"")+current+" finish "+finish +" X "+X);//+" str: "+str);
	
			System.out.print("Case #"+(i+1)+": "+a+"\n");
			pw.write("Case #"+(i+1)+": "+a+"\n");

		}
		pw.close();
	}
}
