import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;


public class InfiniteHouseofPancakes {

	public static void main(String[] args) throws IOException {
		String inputFile = "B-small-attempt5.in";
//		String inputFile = "input.txt";
		String outputFile = "output.txt";
		FileInputStream fstream = new FileInputStream(inputFile);
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		PrintWriter writer = new PrintWriter(outputFile, "UTF-8"); //result
		
		String strLine;
		strLine = br.readLine();
		int numCase = Integer.parseInt(strLine);
		
		for( int i = 0;i<numCase;i++){
			int D = 0;
			ArrayList<Integer> P = new ArrayList<Integer>();
			strLine = br.readLine();
			D = Integer.parseInt(strLine);
			strLine = br.readLine();
			String[] strArray = strLine.split(" ");
//			System.out.println(strLine);
			for(int j =0;j<D;j++){
				int pj =  Integer.parseInt(strArray[j]);
				int index = Collections.binarySearch(P, pj);
				if(index <0){
					P.add(-index-1, pj);
				}else{
					P.add(index, pj);
				}
				
			}
//			System.out.println();
			int maxStep = P.get(D-1);
			System.out.print("Case #"+(i+1)+" "+ P + ": ");
			int result2 = worker2(P);
			int result1 = worker1(P);
			int result = worker(P);
//			if(result1 > result){
//				System.out.println("==========1 is wrong");
//			}
			String result_str ="Case #"+(i+1)+": "+ Math.min(result2,Math.min(result1, result)); 
			writer.println(result_str);
			System.out.println(result2 + " " + result1 + " " + result);
//			System.out.println(result_str);
		}
		

		//Close the input stream
		br.close();
		writer.close();
	}
	public static int worker2(ArrayList<Integer> P){
		int l = P.size();
		int maxPancake = P.get(l-1);
		int maxStep = maxPancake;
		int g = maxPancake;
		
		for(int i = 1;i<g;i++){
			int t = tryG(P, i);
			if(t < maxStep){
				maxStep = t;
			}
		}
		return maxStep;
	}
	public static int worker1(ArrayList<Integer> P){
		int s = 0;
		int n = P.size();
		for(int i=0;i<n;i++){
			s = s  + P.get(i);
		}
		double g = Math.sqrt(s);
		int g1 = (int)Math.ceil(g);
		int g2 = (int)Math.floor(g);
		return Math.min(tryG(P, g1),tryG(P, g2));
	}
	public static int tryG(ArrayList<Integer> P, int g){
		int t=0;
		for(int i = 0;i<P.size();i++){
			if(P.get(i) > g){
				if(P.get(i) %g ==0){
					t = t + P.get(i) /g -1;
				}else{
					t = t + P.get(i)/g;
				}
				
			}
		}
		return t + g;
		
	}
	public static int worker( ArrayList<Integer> P){
//		System.out.println("input P: ");
//		System.out.println(P);
		int l = P.size();
		int maxPancake = P.get(l-1);
		int maxStep = maxPancake;
		
		if( maxPancake == 1){
			return 1;
		}else if(maxPancake == 2){
			return 2;
		}else if(maxPancake == 3){
			return 3;
		}
		
		int op = 0;
		
		while(true){
//			System.out.println(P);
			l = P.size();
			maxPancake = P.get(l-1);
			int d = getNumOfMax(P);
//			System.out.println("d: " + d);
			int maxHalf1 =  maxPancake/2;
			int maxHalf2 = maxPancake - maxHalf1;
			for(int i = 0;i<d;i++){
				P.remove(l-1);
				insertSortedArrayList(P, maxHalf1);
				insertSortedArrayList(P, maxHalf2);
				l++;
				op++;
			}
//			System.out.println("removded:");
//			System.out.println(P);
			
			l = P.size();
			int maxPancakeNew = P.get(l-1);
			int stepNew = maxPancakeNew + op;
//			System.out.println("stepNew: " + stepNew);
			if(maxStep <= stepNew){
				break;
			}else{
				maxStep = stepNew;
			}
		}
		
		
		return maxStep;
	}
	public static void insertSortedArrayList(ArrayList<Integer> P, int e){
		int index = Collections.binarySearch(P, e);
		if(index <0){
			P.add(-index-1,e);
		}else{
			P.add(index, e);
		}
	}
	public static int getNumOfMax(ArrayList<Integer> P){
		int l = P.size();
		int max = P.get(l-1);
		int d = 0;
		for(int i = l-1;i>=0;i--){
			if(P.get(i) == max){
				d++;
			}else{
				break;
			}
		}
		return d;
		
	}


}
