import java.util.*;

public class bff {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i = 1; i<t+1; i++){
			int n = in.nextInt();
			int[] kids = new int[n];
			for(int j = 0; j<n; j++){
				kids[j] = in.nextInt();
			}
			int max = 0;
			for(int j = 0; j<n; j++){
				//System.out.println(j);
				List<Integer> circle = new ArrayList<Integer>();
				circle.add(j+1);
				int x = kids[j];
				while(!circle.contains(x)){
					int nxt = kids[x-1];
					if(circle.contains(nxt)){
						if(circle.indexOf(nxt)==0 || circle.indexOf(nxt) == circle.size()-1){
							circle.add(0,x);
							x = kids[x-1];
						}else{
							break;
						}
					}else{
						circle.add(0,x);
						x = kids[x-1];
					}
				}
				boolean cycle = false;
				if(kids[circle.get(0)-1]== circle.get(circle.size()-1) || kids[circle.get(circle.size()-1)-1] == circle.get(0)){
					cycle = true;
					//System.out.println("cycle");
				}
				if(!cycle){
					boolean back = true;
					while(back){
						back = false;
						int y = circle.get(0);
						//System.out.println(y);
						for(int k = 0; k<n; k++){
							if(kids[k] == y && !(circle.contains(k+1))){
								//System.out.println(k + " fadd");
								circle.add(0, k+1);
								back = true;
								break;
							}
						}
					}
					boolean forw = true;
					while(forw){
						forw = false;
						int z = circle.get(circle.size()-1);
						//System.out.println(z);
						for(int k = 0; k<n; k++){
							if(kids[k] == z && !(circle.contains(k+1))){
								//System.out.println(k + " badd");
								circle.add(circle.size()-1, k+1);
								forw = true;
								break;
							}
						}
					}
				}
				
				if(circle.size() > max){
					max = circle.size();
				}
			}
			System.out.println("Case #"+i+": "+max);
		}
	}
}
