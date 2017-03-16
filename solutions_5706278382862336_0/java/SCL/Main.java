import java.util.*;
import java.io.*;

public class Main {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014R1A/io/A-small-attempt3.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014R1A/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int k = 0 ; k < T ; k++){
			String[] s = input.readLine().split("\\/");
			long l1 = Long.parseLong(s[0]);
			long l2 = Long.parseLong(s[1]);
			for(int i = 2 ; i <= l1 ; i++){
				if(l1 % i == 0 && l2 % i == 0){
					l1 /= i;
					l2 /= i;
					i--;
				}
			}
			int count = 0;
			long nums = l2;
			boolean isok = true;
			while(nums != 1){
				if(nums % 2 != 0){
					isok = false;
					break;
				}else{
					nums /= 2;
					count++;
				}
			}
			if(!isok){
				pw.println("Case #"+(k+1)+": impossible");
			}else{
				if(l1*2 >= l2){
					pw.println("Case #"+(k+1)+": 1");
				}else{
					l1 -= 1;
					if(l1 == 0){
						pw.println("Case #"+(k+1)+": "+count);
					}else{
						System.out.println(l1+","+l2+","+count+","+isok);
						while(l1 != 1){
							l1 /= 2;
							count--;
						}
						if(!isok){
							pw.println("Case #"+(k+1)+": impossible");
						}else{
							pw.println("Case #"+(k+1)+": "+count);
						}
					}
				}
			}
			pw.flush();
		}
		input.close();
		pw.close();
	}
}