import java.util.*;
//GREEDY SOLUTION -> DO NOT USE IN LARGE INPUT
public class CMain {
	
	public static String compare(String one, String two){
		if(one.charAt(0)=='1'){
			return two;
		}
		if(two.charAt(0)=='1'){
			return one;
		}
		if(one.charAt(0)==two.charAt(0)){
			return "-1";
		}
		if(one.charAt(0)=='i'){
			if(two.charAt(0)=='j') return "k";
			else return "-j";
		}
		if(one.charAt(0)=='j'){
			if(two.charAt(0)=='i') return "-k";
			else return "i";
		}
		if(one.charAt(0)=='k'){
			if(two.charAt(0)=='i') return "j";
			else return "-i";
		}
		return "1"; //<-- Something's gone wrong if reached
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int cases = in.nextInt();
		
		for(int i = 0;i<cases;i++){
			System.out.print("Case #");
			System.out.print(i+1);
			System.out.print(": ");
			int L = in.nextInt();
			int X = in.nextInt();
			int length = L*X;
			boolean negative = false;
			char seek = 'i';
			in.nextLine();
			String dijkstraPart = in.nextLine();
			String dijkstra = "";
			for(int j = 0; j < X; j++)
				dijkstra += dijkstraPart;
			String[] terms = dijkstra.split("");
			for(int d = 0; d<length-1;d++){
				if(terms[d].charAt(0)=='-'){
					terms[d] = terms[d].substring(1);
					negative = !negative;
				}
				if(terms[d+1].charAt(0)=='-'){
					terms[d+1] = terms[d+1].substring(1);
					negative = !negative;
				}
				if(terms[d].charAt(0)==seek && !negative){
					if(seek=='i') seek = 'j';
					else if(seek=='j') seek = 'k';
					else if(seek=='k') seek = '1';
				}
				else{
					terms[d+1] = compare(terms[d], terms[d+1]);
				}
			}
			if(terms[length-1].charAt(0)=='-'){
				terms[length-1] = terms[length-1].substring(1);
				negative = !negative;
			}
			if((seek=='1' && !negative && terms[length-1].charAt(0)=='1') || (seek=='k' && !negative && terms[length-1].charAt(0)=='k')){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}
}
