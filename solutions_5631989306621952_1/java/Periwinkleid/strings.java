import java.util.*;
public class strings {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i = 1; i<t+1; i++){
			String s = in.next();
			
			List<String> tmp = new ArrayList<String>();
			tmp.add(s.substring(0, 1));
			for(int j = 1; j<s.length(); j++){
				String temp = s.substring(j, j+1);
				if(temp.compareTo(tmp.get(0)) >= 0){
					tmp.add(0, temp);
				}else{
					tmp.add(tmp.size(), temp);
				}
			}
			System.out.print("Case #"+i+":"+" ");
			for(int j = 0; j<tmp.size(); j++){
				System.out.print(tmp.get(j));
			}
			System.out.println();
		}
	}

}
