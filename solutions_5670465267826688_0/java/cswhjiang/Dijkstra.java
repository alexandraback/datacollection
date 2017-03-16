import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;


public class Dijkstra {


	public static void main(String[] args)throws IOException {
		// TODO Auto-generated method stub
//		String inputFile = "B-small-attempt1.in";
		 Map<String,String> map; map = new HashMap<String, String>();
		 map.put("11", "1");map.put("1i", "i");map.put("1j", "j");map.put("1k", "k");
		 map.put("i1", "i");map.put("ii", "-1");map.put("ij", "k");map.put("ik", "-j");
		 map.put("j1", "j");map.put("ji", "-k");map.put("jj", "-1");map.put("jk", "i");
		 map.put("k1", "k");map.put("ki", "j");map.put("kj", "-i");map.put("kk", "-1");
		 
		
//		String inputFile = "input.txt";
		String inputFile = "C-small-attempt3.in";
		String outputFile = "output.txt";
		FileInputStream fstream = new FileInputStream(inputFile);
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		PrintWriter writer = new PrintWriter(outputFile, "UTF-8"); //result
		
		String strLine;
		strLine = br.readLine();
		int numCase = Integer.parseInt(strLine);
		
		for( int i = 0;i<numCase;i++){
			int L, X;
			strLine = br.readLine();
			String[] strArray = strLine.split(" ");
			
			L = Integer.parseInt(strArray[0]);
			X = Integer.parseInt(strArray[1]);
			
			strLine = br.readLine();

			boolean result = worker(strLine, X,map);
			String result_str;
			if(result == true){
				result_str ="Case #"+(i+1)+": YES"; 
			}else{
				result_str ="Case #"+(i+1)+": NO"; 
			}
			 
			writer.println(result_str);
			System.out.println(result_str);
		}
		

		//Close the input stream
		br.close();
		writer.close();
	}
	public static boolean worker(String s, int X, Map<String, String> map){
//		System.out.println("input: " + s);
		String r1 = reduce(s, map);
//		System.out.println("reduce: " + r1);
		String rX = combine(r1, X);
//		System.out.println("input: " + rX);
		String rXr = reduce(rX, map);
//		System.out.println("reduce: " + rXr);
		if(!rXr.equals("-1")){
			return false;
		}
		
		String sAll = combine(s, X);
		int L = sAll.length();
		String [] m1 = new String[L];
		m1[0] = sAll.charAt(0) + "";
		for(int i = 1;i<L;i++){
			m1[i] = reduce(m1[i-1] + sAll.charAt(i), map);
//			String temp = reduce(sAll.substring(0, i+1), map);
//			if(!m1[i].equals(temp)){
//				System.out.println("m1 is wrong");
//			}
		}
		String [] m3 = new String[L];
		m3[L-1] = sAll.charAt(L-1) + "";
		for(int i = L-2;i>=0;i--){
			if(m3[i+1].charAt(0) == '-'){
				m3[i] = reduce("-" + sAll.charAt(i) + m3[i+1].substring(1) , map);
			}else{
				m3[i] = reduce(sAll.charAt(i) + m3[i+1] , map);
			}
//			String temp = reduce(sAll.substring(i), map);
//			if(!m3[i].equals(temp)){
//				System.out.println("m3 is wrong");
//			}
		}
		
//		System.out.println(Arrays.toString(m1));
//		System.out.println(Arrays.toString(m3));
		for( int i = 0;i<L;i++){
			for(int j = i+1;j<L;j++){
//				System.out.println("(" + i + ", " + j + ")" + m1[i] + " " + m3[j]);
				if(  m1[i].equals("i") && m3[j].equals("k") ){
					return true;
//					String s2 = sAll.substring(i+1, j);
//					String re2 = reduce(s2, map);
//					if(re2.equals(j)){
//						return true;
//					}
				}
			}
		}
		
		return false;
	}
	public static String reduce(String s, Map<String, String> map){
//		System.out.println(s);
//		if(s.equals("1")){
//			return "";
//		}
		int l = s.length();
		if(l == 1 || l == 0){
			return s;
		}
		if(l == 2 && s.charAt(0) == '-'){
			return s;
		}
		
		boolean isNegative = s.charAt(0) == '-';
		if(isNegative){
			s = s.substring(1);
			l = l-1;
		}

		if(l == 2 ){
			if(isNegative){
				String rr = map.get(s);
				if(rr.charAt(0) == '-'){
					return rr.substring(1);
				}else{
					return "-" + rr;
				}			
			}else{
				return map.get(s);
			}			
		}

		
		String s1 = s.substring(0, l/2);
		String s2 = s.substring(l/2, l);
		String r1 = reduce(s1, map);
		String r2 = reduce(s2, map);
		
		String r = "";
		int ng = 0;
		if(isNegative)
			ng++;
		if(r1.length()>0 && r1.charAt(0) == '-'){
			r = r + r1.substring(1);
			ng++;
		}else{
			r = r + r1;
		}
		if(r2.charAt(0) == '-'){
			r = r + r2.substring(1);
			ng++;
		}else{
			r = r + r2;
		}
		
		if(ng%2 == 0){
			return  reduce(r, map);
		}else{
			return reduce("-" + r, map);
		}
		
	}
	public static String combineTwo(String s1, String s2){
		if(s2.charAt(0) != '-'){
			return s1 + s2;
		}
		s2 = s2.substring(1);
		if(s1.charAt(0) == '-'){
			return s1.substring(1) + s2;
		}else{
			return  "-" + s1 + s2;
		}
	}
	public static String combine(String s, int times){
		int l = s.length();
		boolean isNegative = s.charAt(0) == '-';
		if(isNegative){
			s = s.substring(1);
			l = l-1;
		}
		String r = "";
		for(int i = 0;i<times;i++){
			r = r + s;
		}
		if(isNegative && times % 2 == 1){
			return "-"+r;
		}else{
			return r;
		}
	}

}
