import java.io.*;
import java.util.*;

public class ProblemA{
	
		
	private static Scanner s = new Scanner(System.in);
	public static void main(String[] args){
		int t = Integer.parseInt(s.nextLine());
		
		for(int i = 0; i < t; i++){
			String testcase = s.nextLine();
			System.out.println("Case #"+(i+1)+": " + solve(testcase));
		}
	}
	
	public static String solve(String testcase){
		String answer = "";
		int gChar = 0;
		int zChar = 0;
		int xChar = 0;
		int wChar = 0;
		int uChar = 0;
		int oChar = 0;
		int fChar = 0;
		int rChar = 0;
		int sChar = 0;
		int iChar = 0;
		
		int[] series = new int[0];
		
		for (int i=0; i<testcase.length(); i++){
			if (testcase.charAt(i) == 'G'){
				gChar+=1;
			}else if (testcase.charAt(i) == 'Z'){
				zChar+=1;
			}else if (testcase.charAt(i) == 'X'){
				xChar+=1;
			}else if (testcase.charAt(i) == 'W'){
				wChar+=1;
			}else if (testcase.charAt(i) == 'U'){
				uChar+=1;
			}else if (testcase.charAt(i) == 'O'){
				oChar+=1;
			}else if (testcase.charAt(i) == 'F'){
				fChar+=1;
			}else if (testcase.charAt(i) == 'R'){
				rChar+=1;
			}else if (testcase.charAt(i) == 'S'){
				sChar+=1;
			}else if (testcase.charAt(i) == 'I'){
				iChar+=1;
			}
		}
		
		while(gChar>0){
			gChar--;
			iChar--;
			series = addElement(series, 8);
		}
		
		while(zChar>0){
			zChar--;
			rChar--;
			oChar--;
			series = addElement(series, 0);
		}
		
		while(xChar>0){
			xChar--;
			sChar--;
			iChar--;
			series = addElement(series, 6);
		}
		
		while(wChar>0){
			wChar--;
			oChar--;
			series = addElement(series, 2);
		}
		
		while(uChar>0){
			uChar--;
			fChar--;
			oChar--;
			rChar--;
			series = addElement(series, 4);
		}
		
		while(oChar>0){
			oChar--;
			series = addElement(series, 1);
		}
		
		while(fChar>0){
			fChar--;
			iChar--;
			series = addElement(series, 5);
		}
		
		while(rChar>0){
			rChar--;
			series = addElement(series, 3);
		}
		
		while(sChar>0){
			sChar--;
			series = addElement(series, 7);
		}
		
		while(iChar>0){
			iChar--;
			series = addElement(series, 9);
		}
		
		Arrays.sort(series);
		
		
		for(int i=0; i<series.length; i++){
			answer+= series[i] + "";
		}
		return answer;
	}
	
	public static int[] addElement(int[] a, int e){
		a = Arrays.copyOf(a, a.length + 1);
		a[a.length - 1] = e;
		return a;
	}
	
}