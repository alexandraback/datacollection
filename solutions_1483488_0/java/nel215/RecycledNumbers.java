import java.util.*;


public class RecycledNumbers {
	void run(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int c=1 ; c<=T ; c++){
			Integer res = 0;
			int A = sc.nextInt();
			int B = sc.nextInt();
			for(int i=A ; i<=B ; i++){
				String s = String.valueOf(i);
				HashSet<Integer> used = new HashSet<Integer>();
				for(int j=0 ; j<s.length() ; j++){
					char top = s.charAt(0);
					s = s.substring(1)+top;
					int num = Integer.parseInt(s);
					if(used.contains((Integer)num))continue;
					used.add(num);
					if(i<num && num<=B)res++;
				}
			}
			System.out.println("Case #"+c+": "+res);
		}
	}
	public static void main(String[] args) {
		new RecycledNumbers().run();
	}

}
