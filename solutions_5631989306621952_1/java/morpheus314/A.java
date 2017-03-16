import java.util.Scanner;

public class A {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			
			int tc = sc.nextInt();
			
			for(int i=0; i< tc; ++i){
				String input = sc.next();
				
				String result = "";
				
				char[] c = input.toCharArray();
				result += c[0];
				
				for(int a=1; a<c.length; ++a){
					if(c[a] < c[0]){
						result += c[a];
					}
					else if(c[a] >= result.charAt(0)){
						result = c[a] + result;
					}
					else{
						result += c[a];
					}
				}
				
				System.out.printf("Case #%d: %s%n", i+1, result);
			}
			
			
			
			
			
			
			
			sc.close();
		}
}
