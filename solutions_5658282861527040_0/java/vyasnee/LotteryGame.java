import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class LotteryGame {

	 
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 
		int a = 7;
		int b = 11;
		
		System.out.println(a&b);
		try {
			FileReader fr = new FileReader(new File(args[0]));
			
			BufferedReader br = new BufferedReader(fr);
			
			int numTestCase = Integer.parseInt(br.readLine());
			
			StringBuffer sbfResult = new StringBuffer();
		
			
			for(int i=0;i< numTestCase ; i++) {
				
				int ans =0 ;
				String ss[] = br.readLine().split(" ");
				int A = Integer.parseInt(ss[0]);
				int B = Integer.parseInt(ss[1]);
				int K = Integer.parseInt(ss[2]);
				
				int cnt =0;
				for(int k=0; k<A ; k++ ){
					
					for(int p=0; p<B; p++){
						int g = k&p; 
						//System.out.println(g + " " +A + "  " + B + " " + K);
						if( g >=0 && g  < K){
							cnt++;
						}
						
					}
				}
				
				sbfResult.append("Case #"+(i+1)+ ": " +  (cnt));
				sbfResult.append("\n");
			
			}
			System.out.println(sbfResult);
		    
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	
	
	private static int findNumOfMoves(String commonString, List<List<String>> commonStringAr, List<String> words) {
		// TODO Auto-generated method stub
		int cnt = 0;
		for(int i=0;i<commonString.length(); i++){
			int minCnt = -1; 
			
			for(int l=0;l<commonStringAr.size()-1; l++){
				int sz = commonStringAr.get(l).get(i).length();
				int cnt2 =0;
				for(int k=0;k<commonStringAr.size()-1; k++){
					if(l!=k){
						cnt2 += Math.abs(sz - commonStringAr.get(k).get(i).length());
					}
				}
				
				if(minCnt==-1){
					minCnt = cnt2;
				}else if(minCnt > cnt2){
					minCnt = cnt2;
				}
			}
			
			if(minCnt!=-1){
				cnt+= minCnt;
			}
			
			
			 
		}
		return cnt;
	}


	private static List<List<String>> cehckValid(List<String> words) {
		// TODO Auto-generated method stub
		List<String> wrds2 = new ArrayList<String>();
		String lastString = "";
		boolean first = true;
		List<List<String>> commWords = new ArrayList<List<String>>();
		for(String s : words){
			String s2 = ""+s.charAt(0);
			String s3 = s2;
			List<String> s3Ar = new ArrayList<String>();
			char c1 = s.charAt(0);
			for(int k=1;k< s.length() ; k++){
				if(c1==s.charAt(k)){
					s3+=s.charAt(k);
				}else{
					s3Ar.add(s3); 
					c1 = s.charAt(k);
					s2+= c1;
					s3=""+s.charAt(k); 
				}
			}
			s3Ar.add(s3);
			
			
			if(first){
				lastString  = s2;
				first = false;
			}
			if(!first && !lastString.equals(s2)){
				return null;
			}
			commWords.add(s3Ar);
			
		}

		List<String> laststrAr = new ArrayList<String>();
		laststrAr.add(lastString);
		commWords.add(laststrAr);
		return commWords;
	}


	private static int calculateOptimumSwitches(int n, int l,
			List<String> outlets, List<String> switchArrangements) {
		// TODO Auto-generated method stub
		
		//first find all matching switches
		List<String> outlets1 = new ArrayList<String>();
		List<String> switches1 = new ArrayList<String>();
		outlets1.addAll(outlets);
		switches1.addAll(switchArrangements);
		
		//will it remove duplicates as well? anyways no outlets is same initially and no device need same 
		outlets1.removeAll(switchArrangements);
		switches1.removeAll(outlets);
		
		if(outlets1.size()==0 && switches1.size()==0){
			
			return 0;
		}
		
		outlets1 = new ArrayList<String>();
		switches1 = new ArrayList<String>();
		
		outlets1.addAll(outlets);
		switches1.addAll(switchArrangements);
		
		
		List<String> ar1 = new ArrayList<String>();
		List<String> ar2 = new ArrayList<String>();
		StringBuffer seq1 = new StringBuffer();  
		int totalCnt = 0;
		
		List<Integer> switchMayReqList = new ArrayList<Integer>();
		List<Integer> switchReqList = new ArrayList<Integer>();
		
		Map<Integer, Boolean> map1 = new HashMap<Integer, Boolean>();
		for(int j=0;j<l ; j++){
			int zeroCnt = 0;
			int oneCnt = 0;
			int zeroCnt1 = 0;
			int oneCnt1 = 0;
			
		for(int i=0;i<n;i++){
			
				if(outlets1.get(i).charAt(j)!=switches1.get(i).charAt(j)){
					map1.put(j, false);
				}
			
				if('0'==outlets1.get(i).charAt(j)){
					zeroCnt++;
				}
				
				if('1' == outlets1.get(i).charAt(j)){
					oneCnt++;
				}
				
				if('0'==switches1.get(i).charAt(j)){
					zeroCnt1++;
				}
				
				if('1' == switches1.get(i).charAt(j)){
					oneCnt1++;
				}
				
				ar1.add(outlets1.get(i).charAt(j)+"");
				ar2.add(switches1.get(i).charAt(j)+"");
			}
			Collections.sort(ar1);
			Collections.sort(ar2); 
			if(zeroCnt==zeroCnt1 && oneCnt==oneCnt1 && (map1.get(j) !=null && map1.get(j)==false )){
				switchMayReqList.add(j);
			}else if(zeroCnt==oneCnt1 && zeroCnt1 == oneCnt){
				switchReqList.add(j);
			}else if(zeroCnt==zeroCnt1 && oneCnt==oneCnt1 ){
				
			} else {
				return -1;
			}
			
		}
		 
		 
		return switchReqList.size() + switchMayReqList.size();
	}

 

	private static int[]  getArrangement(BufferedReader br) throws IOException {
		
		 
			String row[] = br.readLine().split(" ");
			int[] arrng1 = new int[row.length]; 
			for(int i=0 ; i< row.length; i++){
				arrng1[i] = Integer.parseInt(row[i]);
			}
			 				
		 
		return arrng1;
	}

}
