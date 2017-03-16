import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class CJ2016C {
	
	static String convertBase(String num, int b1, int b2){
		return Long.toString(Long.parseLong(num, b1), b2);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		//Scanner scan = new Scanner(new File("CJ2016C.in"));
		int t,n,j,cnt,divs,lastDiv = 1;
		String str;
		long num;
		long arr[] = new long[11];
		boolean ok;
		t = scan.nextInt();
		for(int t2 = 1; t2 <= t; t2++){
			System.out.printf("Case #%d:\n",t2);
			n = scan.nextInt();
			j = scan.nextInt();
			cnt = 0;
			str = "";
			for(int i = 0; i < n-2; i++) str += '0';
			//System.out.println(str);
			str = '1' + str + '1';
			//str = "010101";
			while (cnt < j){
				ok = true;
				//System.out.println(str);
				//System.out.println(str);
				for(int b = 2; b <= 10 & ok; b++){
					//System.out.println(b);
					num = Long.parseLong(str,b);
					//System.out.println(num);
					//System.out.printf("b:%d num:%d\n",b,num);
					divs = 0;
					for(int i = 2; i <= Math.sqrt(num); i++){
						if (num%i == 0){ 
							divs++;
							arr[b] = i;
							break;
						}
					}
					if (divs == 0){
						ok = false;
					}
				}
				
				if (ok){
					System.out.print(str);
					for(int i = 2; i <= 10; i++) System.out.printf(" %d",arr[i]);
					System.out.println();
					cnt++;
				}
				
				num = Long.parseLong(str,2);
				num++;
				str = convertBase(""+num, 10, 2);
				while (str.charAt(str.length()-1) == '0'){
					num = Long.parseLong(str,2);
					num++;
					str = convertBase(""+num, 10, 2);
				}
				
			}
		}
		

	}

}
