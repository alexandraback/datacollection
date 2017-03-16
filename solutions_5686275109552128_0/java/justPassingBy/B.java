import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class B {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		B main = new B();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("B-small-attempt2.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Bsmall.out", "UTF-8");
		for(int cas=1; cas<=T; cas++){
			int D = Integer.parseInt(scan.nextLine());
			String[] P_i = scan.nextLine().split(" ");
			ArrayList<Integer> P = new ArrayList<Integer>(10);
			int max = 0;
			int max_mins = max;
			for(int i=0; i<D; i++){
				P.add(Integer.parseInt(P_i[i]));
				max = (Integer.parseInt(P_i[i]) >= max) ? Integer.parseInt(P_i[i]) : max;
			}
			int lowest = max;
			//int ntops = 0;			
			for(int m = max-1; m>=1; m--){
				ArrayList<Integer> tops = new ArrayList<Integer>();
				for(int i=0; i<D; i++){
					if(P.get(i)>m){
						tops.add(P.get(i));
						//ntops++;
						if(tops.size() > max-m){
							break;
						}
					}
				}
				int mtm = movesTillMax(m, tops);
				//System.out.println(mtm);
				lowest = (mtm + m <= lowest) ? mtm + m: lowest;
				
			}
			//Integer.parseInt(size[0]);
			//scan.nextInt();
			
			
			writer.println("Case #"+cas+": "+lowest);
			System.out.println("Case #"+cas+": "+lowest);
				
		}		
		writer.close();
	}
	
	public int movesTillMax(int m, ArrayList<Integer> tops){
		int rest = 0;
		int moves = 0;
		for(int i=0; i<tops.size(); i++){
			rest+=tops.get(i)%m;
			moves+=(tops.get(i)-1)/m;
		}
		return moves;
	}
	
}
