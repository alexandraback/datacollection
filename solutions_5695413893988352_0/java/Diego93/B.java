import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class B {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("b.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("b.out"));
		int N = s.nextInt();
		s.nextLine();
		for(int i=0; i<N; i++){
			String[] inString = s.nextLine().split(" ");
			char[] s1 = inString[0].toCharArray();
			char[] s2 = inString[1].toCharArray();
			Set<Integer> l1 = getAll(s1);
			Set<Integer> l2 = getAll(s2);
			int diff = Integer.MAX_VALUE;
			int C = Integer.MAX_VALUE;
			int J = Integer.MAX_VALUE;
			for(Integer a : l1){
				for(Integer b : l2){
					if(Math.abs(a-b)<diff){
						C=a;
						J=b;
						diff=Math.abs(a-b);
					}else{
						if(Math.abs(a-b)==diff){
							if(a<C || (a==C && b<J)){
								C=a;
								J=b;								
							}
						}
					}
				}
			}
			switch(s1.length){
			case 1:
				out.write("Case #"+(i+1)+": "+String.format("%01d", C)+" "+String.format("%01d", J)+"\n");
				break;
			case 2:
				out.write("Case #"+(i+1)+": "+String.format("%02d", C)+" "+String.format("%02d", J)+"\n");
				break;
			case 3:
				out.write("Case #"+(i+1)+": "+String.format("%03d", C)+" "+String.format("%03d", J)+"\n");
				break;
			}
		}
		out.close();
	}
	
	static public Set<Integer> getAll(char[] s){
		Set<Integer> set = new TreeSet<Integer>();
		switch(s.length){
		case 1:
			for(int i=0; i<10; i++){
				char[] clone = s.clone();
				if(s[0]=='?'){
					clone[0]=(char)(i+'0');
				}
				set.add(Integer.valueOf(String.valueOf(clone)));
			}
			return set;
		case 2:
			for(int i=0; i<10; i++){
				for(int j=0; j<10; j++){
					char[] clone = s.clone();
					if(s[0]=='?'){
						clone[0]=(char)(i+'0');
					}
					if(s[1]=='?'){
						clone[1]=(char)(j+'0');
					}
					set.add(Integer.valueOf(String.valueOf(clone)));
				}
			}
			return set;
		case 3:
			for(int i=0; i<10; i++){
				for(int j=0; j<10; j++){
					for(int k=0; k<10; k++){
						char[] clone = s.clone();
						if(s[0]=='?'){
							clone[0]=(char)(i+'0');
						}
						if(s[1]=='?'){
							clone[1]=(char)(j+'0');
						}
						if(s[2]=='?'){
							clone[2]=(char)(k+'0');
						}
						set.add(Integer.valueOf(String.valueOf(clone)));
					}
				}
			}
			return set;
		}
		return null;
	}
}
