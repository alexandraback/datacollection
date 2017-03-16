import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args){ 
		Scanner scan = new Scanner(System.in);
		int total = scan.nextInt();
		for(int i=0; i<total;i++){
			String word = scan.next();
			char[] result = new char[word.length()];
			for(int j=0;j<word.length();j++){
				result[j] = word.charAt(j);
			}
			for(int j=1;j<result.length;j++){
				if(result[j]>=result[0]){
					char temp = result[j];
					for(int k=j;k>0;k--){
						result[k] = result[k-1];
					}
					result[0] = temp;
				}
			}
			System.out.print("Case #" + (i+1) + ": ");
			for(int j=0;j<result.length;j++){
				System.out.print(result[j]);
			}
			System.out.println();
		}
	}
}