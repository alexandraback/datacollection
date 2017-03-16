import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class R1C_3 {
	
	public static void main(String args[]){
		try {
			//System.setIn(new FileInputStream("C:\\Users\\ericc\\Desktop\\Question\\R1C\\Q3\\Q3.in"));
			System.setIn(new FileInputStream("C:\\Users\\ericc\\Desktop\\Question\\R1C\\Q3\\Q3-small.in"));
			//System.setIn(new FileInputStream("C:\\Users\\ericc\\Desktop\\Question\\R1C\\Q3\\Q3-large.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		int caseCount = 0;
		while(sc.hasNext()){
			int J = sc.nextInt();
			int P = sc.nextInt();
			int S = sc.nextInt();
			int K = sc.nextInt();
			if(sc.hasNext())
				sc.nextLine();
			
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			ArrayList<String> comb = new ArrayList<String>();
			int count = 0;
			for(int i = 1 ; i <= J ; i++){
				for(int j = 1 ; j <= P ; j++){
					for(int k = 1 ; k <= S ; k++){
						if(!((map.get(i + " " + j + " 0") == null || map.get(i + " " + j + " 0") < K) &&
								(map.get(i + " 0 " + k) == null || map.get(i + " 0 " + k) < K) &&
								(map.get("0 " + j + " " + k) == null || map.get("0 " + j + " " + k) < K)))
							continue;
						
						comb.add(i + " " + j + " " + k);
						
						count++;
						
						map.put(i + " " + j + " 0", map.get(i + " " + j + " 0") == null ? 1 : map.get(i + " " + j + " 0") + 1);
						map.put(i + " 0 " + k, map.get(i + " 0 " + k) == null ? 1 : map.get(i + " 0 " + k) + 1);
						map.put("0 " + j + " " + k, map.get("0 " + j + " " + k) == null ? 1 : map.get("0 " + j + " " + k) + 1);
					}
				}
			}
			
			caseCount++;
			System.out.println("Case #" + caseCount + ": " + count);
			for(String s : comb){
				System.out.println(s);
			}
		}
		
	}
}
