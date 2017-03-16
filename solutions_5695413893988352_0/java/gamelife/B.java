
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;



public class B {

	private static int gcd(int a, int b) {
	    BigInteger b1 = BigInteger.valueOf(a);
	    BigInteger b2 = BigInteger.valueOf(b);
	    BigInteger gcd = b1.gcd(b2);
	    return gcd.intValue();
	}
	private static int getBit(int num, int i){
		return (num>>i) & 1 ;
	}


	public static void main(String[] args) {
		new B().run();
    }
	
	private void run() {
		PrintWriter writer =  null ;
		FileReader reader = null;
		try{
			reader = new FileReader("input.txt");
			reader = new FileReader("B-small-attempt1.in");
//			reader = new FileReader("B-large-practice.in");
			
			writer = new PrintWriter("small-out2.txt", "UTF-8");
//			writer = new PrintWriter("large-out.txt", "UTF-8");
		}catch(Exception e){
			System.out.println(" Exception " + e) ;  
			return;
		}

        Scanner input = new Scanner(reader);

        int numCases = input.nextInt();
//        input.next() ;
        for (int n = 0; n < numCases; n++)
        {
        	str1 =   input.next() ;
        	str2 =   input.next() ;
        	solve2();
        	System.out.println("Case #"+ (n+1) + ": " + str1 + " " + str2) ;  
        	writer.println("Case #"+ (n+1) + ": " + str1 + " " + str2) ;  

	
        }
        if(writer !=null){
        	writer.close();
        }
        if(reader !=null){
        	try{
        		reader.close();
        	}catch(Exception e){
        		System.out.println(e.toString()) ;
        	}
        }
        if(input !=null){
        	input.close();
        }
	}
	
	String str1 , str2 ;
	char[] chars1,chars2;
	
	void solve2(){
		int min = 999 ; 
		
//		chars1 = str1.toCharArray() ;
//		chars2 = str2.toCharArray() ;
//		
//		char ch1 = chars1[0]  , ch2 = chars1[1] , ch3 = chars1[2];
//		char ch4 = chars2[0]  , ch5 = chars2[1] , ch6 = chars2[2];
//		if(ch1 == '?'){
//			  for (int i = 0; i < 9; i++){
//				  ch1 = (char)i ;
//			  }
//		}else{
//			
//		}
		String result1 = "", result2 = "" ;
		
		 for (int i = 0; i < 999; i++){
			 String tmp1 = String.valueOf(i);
			 if(tmp1.length() > str1.length()){
				 break;
			 }
			 
			 for (int j = 0; j < 999; j++){
//				 String tmp1 = String.valueOf(i);
				 String tmp2 = String.valueOf(j);
				 if(tmp2.length() > str2.length()){
					 break;
				 }
				 
				 while(tmp1.length() != str1.length()){
					 tmp1 = "0" + tmp1 ;
				 }
				 while(tmp2.length() != str2.length()){
					 tmp2 = "0" + tmp2 ;
				 }
//				 System.out.println("min: "+ min + " : " + tmp1 + " " + tmp2) ;  
				 
				 int index1 = 0 , index2 = 0 ;
				 boolean match1 = true , match2 = true; 
				 while(index1 < str1.length()){
					 if(str1.charAt(index1) != tmp1.charAt(index1)
							 && str1.charAt(index1) != '?'){
						 match1 = false ;
						 break;
					 }
					 index1++ ;
				 }
				 if(!match1){
					 continue;
				 }
				 
				 while(index2 < str2.length()){
					 if(str2.charAt(index2) != tmp2.charAt(index2)
							 && str2.charAt(index2) != '?'){
						 match2 = false ;
						 break;
					 }
					 index2++ ;
				 }
				 if(!match2){
					 continue;
				 }
				 
				 if(min > Math.abs(Integer.valueOf(tmp1) - Integer.valueOf(tmp2))){
					 result1 = tmp1 ;
					 result2 = tmp2 ;
					 min =  Math.abs(Integer.valueOf(tmp1) - Integer.valueOf(tmp2)) ;
					 
//					 System.out.println("min: "+ min + " : " + result1 + " " + result2) ;  
				 }
				 
			 }
		 }
		 
		 str1 = result1;
		 str2 = result2;
	}

	String solve(){
		chars1 = str1.toCharArray() ;
		chars2 = str2.toCharArray() ;
		int index = 0 ;
		int tryMax = -1 ;
		
		while(index < str1.length()){
			char ch1 = chars1[index];
			char ch2 = chars2[index];
			if(tryMax == -1){
				
				if( ch1 == '?' && ch2 == '?'){
					chars1[index] = '0';
					chars2[index] = '0';
					index ++ ;
					continue;
				}
				if(ch1 == ch2  ){
					index ++ ;
					continue;
				}
				if( ch1 == '?' ){
					chars1[index] = ch2;
					index ++ ;
					continue;
				}
				if( ch2 == '?' ){
					chars2[index] = ch1;
					index ++ ;
					continue;
				}
				
				if( ch1 < ch2 ){
					tryMax = 1 ;
					index ++ ;
					continue;
				}else{
					tryMax = 2 ;
					index ++ ;
					continue;
				}
			}else{
				if(tryMax == 1){
					if( ch1 == '?' ){
						chars1[index] = '9';
					}
					if( ch2 == '?' ){
						chars2[index] = '0';
					}
				}else{
					if( ch2 == '?' ){
						chars2[index] = '9';
					}
					if( ch1 == '?' ){
						chars1[index] = '0';
					}
				}
				index ++ ;
				continue;
				
			}
		}
		
		str1 = new String(chars1) ;
		str2 = new String(chars2) ;

		return "" ;
	}
}






