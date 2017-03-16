// c.durr - ecole polytechnique - 2011 - modal programmation efficace

/* Sudoku
	http://acm.tju.edu.cn/toj/showp1851.html (needs to read differently)
	http://www.spoj.pl/problems/EASUDOKU/

   backtracking simple

   mais il faut boucler seulement sur les cellules en conflit potentiel
*/
import java.io.File;
import java.math.BigInteger;
import java.util.*;

class pC {
    
	static BigInteger one = new BigInteger("1"); 
	static BigInteger zero = new BigInteger("0");
	static BigInteger two = new BigInteger("2");
	static BigInteger four = new BigInteger("4");
	static BigInteger five = new BigInteger("5");
	static BigInteger minusOne = new BigInteger("-1");
	//n = 10010101 is called 
    static BigInteger convert (BigInteger n, Integer base){
    	//System.out.println("base = "+base);
    	BigInteger ans = zero;
    	BigInteger pot = one;
    	
    	BigInteger Base = new BigInteger(base.toString());
    	while(n.compareTo(zero)>0){
    		if(n.getLowestSetBit()==0)
    			ans = ans.add(pot);
    		pot = pot.multiply(Base);   
    		n = n.divide(two);
    	}
    	return ans;    	
    }
    static String binaryR(BigInteger n){
    	return n.toString(2);
    	
    }
    //we look for n between 2^(N-1) and 2^N
    static BigInteger primeDivisor(BigInteger n){
    	//System.out.println("we test if "+n.intValue()+" is prime");
    	if(n.compareTo(one)==0) return minusOne;
    	BigInteger i = new BigInteger("2");
    	if(n.compareTo(i)==0) return minusOne;
    	if((n.mod(i)).compareTo(zero)==0)
    		return i;
    	i = i.add(one);
    	//System.out.println("i = "+i.longValue()+" n%i = "+n.mod(i)+" n = "+n );
    	if(n.compareTo(i)==0) return minusOne;
    	if((n.mod(i)).compareTo(zero)==0)
    		return i;
    	i=five;
    	if(n.compareTo(i)==0) return minusOne;
    	while((i.multiply(i)).compareTo(n) <= 0){
    		if((n.mod(i)).compareTo(zero)==0) return i;
    		i = i.add(two);
    		if((n.mod(i)).compareTo(zero)==0) return i;
    		i = i.add(four);
    	}    	
    	return minusOne;
    }
    static List<BigInteger> is_special(BigInteger n){
    	//System.out.println("we test n = "+n);
    	Integer base;
    	BigInteger elem;
    	List<BigInteger> lista = new ArrayList<BigInteger>();
    	for(int b=2; b<=10; b++){
    		base = new Integer(b);
    		elem = primeDivisor(convert(n, b));
    		//System.out.println("just left primeDivisor fo n = "+n+" and b = "+b);
    		lista.add(elem);
    		if(elem.compareTo(minusOne)==0)
    			return new ArrayList<BigInteger>();
    	}
    	return lista;    	
    }

    public static void main(String args[]) {
    	//System.out.println("something happened ");
    	Scanner in = new Scanner(System.in);
    	in.useLocale(Locale.US);
    	//System.out.println("something happened2 ");
    	//String fileName = in.nextLine();
    	//File file = new File(fileName);
    	/*pC obj = new pC();
    	String []s = new String[50];
    	s[0]  = "1000000000000000";
    	s[1]  = "1000000000000010";
    	s[2]  = "1000000000000100";
    	s[3]  = "1000000000000110";
    	s[4]  = "1000000000001000";
    	s[5]  = "1000000000001010";
    	s[6]  = "1000000000001100";
    	s[7]  = "1000000000001110";
    	s[8]  = "1000000000010000";
    	s[9]  = "1000000000010010";
    	s[10] = "1000000000010100";
    	s[11] = "1000000000010110";
    	s[12] = "1000000000011000";
    	s[13] = "1000000000011010";
    	s[14] = "1000000000011100";
    	s[15] = "1000000000011110";
    	s[16] = "1000000000100000";
    	s[17] = "1000000000100010";
    	s[18] = "1000000000100100";
    	s[19] = "1000000000100110";
    	s[20] = "1000000000101000";
    	s[21] = "1000000000101010";
    	s[22] = "1000000000101100";
    	s[23] = "1000000000101110";
    	s[24] = "1000000000110000";
    	s[25] = "1000000000110010";
    	s[26] = "1000000000110100";
    	s[27] = "1000000000110110";
    	s[28] = "1000000000111000";
    	s[29] = "1000000000111010";
    	s[30] = "1000000000111100";
    	s[31] = "1000000000111110";
    	s[32] = "1000000001000000";
    	s[33] = "1000000001000010";
    	s[34] = "1000000001000100";
    	s[35] = "1000000001000110";
    	s[36] = "1000000001001000";
    	s[37] = "1000000001001010";
    	s[38] = "1000000001001100";
    	s[39] = "1000000001001110";
    	s[40] = "1000000001010000";
    	s[41] = "1000000001010010";
    	s[42] = "1000000001010100";
    	s[43] = "1000000001010110";
    	s[44] = "1000000001011000";
    	s[45] = "1000000001011010";
    	s[46] = "1000000001011100";
    	s[47] = "1000000001011110";
    	s[48] = "1000000001100000";
    	s[49] = "1000000001100010";
		System.out.println("Case #1:");
		for(int j=0; j<50; j++){
			System.out.print(s[j]);
	    	for(int i=2; i<=10; i++){
	    		System.out.print(" "+i);	
	    	}
	    	System.out.println();
		}*/
    	/*
    	BigInteger hundred = new BigInteger("1000000000000000");
    	System.out.println(pC.primeDivisor(new BigInteger("1")));
    	System.out.println(pC.binaryR(hundred));
    	for(int i=2; i<=10; i++){
    		System.out.println(pC.convert( hundred, new Integer(i))+" - " + pC.primeDivisor(pC.convert(hundred, new Integer(i)) ) );	
    	}
    	*/
    	
    	
    	
    	
    	int t = in.nextInt();
    	int N ,J;
    	//System.out.println("something happened3 - t = "+t);
    	for(int ind=0; ind<t; ind++) {
    		N = in.nextInt();
    		J = in.nextInt();
    		BigInteger fN = two.pow(N-1).add(one);
    		System.out.println("Case #"+(ind+1)+":");
    		//System.out.println("Before entering the while, fN is equal to "+fN.longValue());
    		while(J>0 && fN.compareTo(two.pow(N))<0){
        		//System.out.println("the while starts with fN equal to "+fN.longValue());
    			//System.out.println("j = "+J);
    			List<BigInteger> lista = is_special(fN);
    			if(!lista.isEmpty()){
    				System.out.print(binaryR(fN)+" ");
    				J--;
        			for(BigInteger x : lista){
        				System.out.print(x.toString()+" ");
        			} 
            		System.out.println();
    			}
    			fN = fN.add(two);
    		} 		
    		
	    }
    }
}
