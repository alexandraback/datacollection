package gcj2016.qualification;

import java.math.*;
import java.util.Arrays;

public class C {
	public BigInteger bi3 = new BigInteger("3");
	public BigInteger bi2 = new BigInteger("2");
	public BigInteger bi_tolerance = new BigInteger("1000000"); // tolerancelevel
	
	private String path = "/home/brunoff/data/dev/gcj/data/2016/qualification/";
	private int casescount;
	private Case[] Cases;
	private class Case {
		public Case(String[] strarr) { N = Integer.parseInt(strarr[0]); J = Integer.parseInt(strarr[1]); coins = new coin[J]; for(int j=0;j<J;j++) { coins[j] = new coin(); } }
		private int N, J;
		private coin[] coins;
	}
	private static class coin {
		public coin() {}
		//public coin(int coinbase10) { base10=coinbase10; }
		public coin(BigInteger coinbase10) { base10=coinbase10; }
		BigInteger base10 = BigInteger.valueOf(-101); long[] divs = /*new long[9]*/ { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
		String basendivs() { return base10+" "+divs[0]+" "+divs[1]+" "+divs[2]+" "+divs[3]+" "+divs[4]+" "+divs[5]+" "+divs[6]+" "+divs[7]+" "+divs[8]; }
		private static coin clone(coin origincoin) {
			coin returncoin = new coin(origincoin.base10);
			for(int i=2;i<=10;i++) returncoin.divs[i-2] = origincoin.divs[i-2];
			return returncoin;
		}
	}
	
	//void main points here (new gcj2016.qualification.C().solve("C-large");)
	public void solve(String filename) throws Exception {
		readfile(filename);
		for(int casenumber=0;casenumber<casescount;casenumber++)
			solvecase(casenumber);
		writeresult(filename);
	}
	
	private BigInteger nextcoin(BigInteger previouscoin) throws Exception {
		char[] previouscoinchr = String.valueOf(previouscoin).toCharArray();
		for(int c=previouscoinchr.length-2;c>=1;c--) {
			if(previouscoinchr[c]=='0') { previouscoinchr[c]='1'; break; }
			else
			if(previouscoinchr[c]=='1') { previouscoinchr[c]='0'; }
		}
		return new BigInteger(new String(previouscoinchr));
	}
	
	private coin nextcoin(coin origincoin) throws Exception {
		return new coin(nextcoin(origincoin.base10));
	}
	
	private BigInteger readasbase(BigInteger input, int base) {
		//try { return Long.parseUnsignedLong(String.valueOf(input),base); }
		//try { return BigInteger.valueOf(Long.parseLong(String.valueOf(input),base)); }
		//catch(Exception ex) { System.out.print(">"+input+","+base); throw ex; }
		//String inputstr = input.toString();
		String str = String.valueOf(input); //BigInteger bi = new BigInteger(str,base);
		BigInteger bi = BigInteger.ZERO;
		BigInteger bb = new BigInteger(String.valueOf(base));
		for(int i=str.length();i>0;i--) {
			bi=bi.add( new BigInteger(str.substring(i-1,i)).multiply(bb.pow(str.length()-i)) );
		}
		return bi;
	}
	
	private long aDivisor(BigInteger n) {
		//check if n is a multiple of 2
	    if (n.mod(bi2).compareTo(BigInteger.ZERO)==0) return 2;
	    //if not, then just check the odds
	    for(BigInteger bi=bi3;bi.multiply(bi).compareTo(n)<=0;bi=bi.add(bi2)) {
	    	if((n.mod(bi)).compareTo(BigInteger.ZERO)==0)
	            return bi.longValue();
	        if(bi.compareTo(bi_tolerance)==1)
	        	return -1;
	    }
	    return -1;
	}
	
	private void solvecase(int casenumber) throws Exception {
		Case Case = Cases[casenumber];
		
		//coin nextcoin = new coin(BigInteger.valueOf((long)Math.pow(10, (long)(Case.N-1))).add(BigInteger.ONE));
		char[] zeros = new char[Case.N - 2];
		Arrays.fill(zeros, '0');
		coin nextcoin = new coin(new BigInteger(("1"+(new String(zeros))+"1")));		
		for(int walletposition = 0;walletposition < Case.J;) {
			//System.out.print(".");
			for(int i=2;i<=10;i++) {
				nextcoin.divs[i-2] = aDivisor(readasbase(nextcoin.base10,i));
				if(nextcoin.divs[i-2]==-1) break;
			}
			if(nextcoin.divs[8]!=-1) {
				Case.coins[walletposition] = coin.clone(nextcoin);
				walletposition++;
				//System.out.println(walletposition+" "+nextcoin.base10+" "+nextcoin.divs[0]+" "+nextcoin.divs[1]+" "+nextcoin.divs[2]+" "+nextcoin.divs[3]+" "+nextcoin.divs[4]+" "+nextcoin.divs[5]+" "+nextcoin.divs[6]+" "+nextcoin.divs[7]+" "+nextcoin.divs[8]);
			}
			if(walletposition == Case.J) break;
			else nextcoin = nextcoin(nextcoin);
		}	
		
		System.out.println("Case #"+(casenumber+1)+":"+System.lineSeparator()+caseresult(Case));
	}
	
	private String caseresult(Case Case) {
		if(false) return (Case.N + " " + Case.J);
		String result = "";
		for(coin Coin : Case.coins)
			result += Coin.basendivs() + System.lineSeparator();
		return result;
	}
	
	private void writeresult(String filename) {
		try(java.io.Writer writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(new java.io.FileOutputStream(path+filename+".out")))) {
			for(int casenumber=0;casenumber<casescount;casenumber++)
				writer.write("Case #"+(casenumber+1)+":"+System.lineSeparator()+caseresult(Cases[casenumber])+System.lineSeparator());
		} catch (Exception ex) { ex.printStackTrace(); };
	}
	
	private void readfile(String filename) {
		try (java.io.BufferedReader reader = java.nio.file.Files.newBufferedReader(java.nio.file.Paths.get(path+filename+".in"))) {
			casescount = Integer.parseInt(reader.readLine());
			Cases = new Case[casescount];
			for(int casenumber=0;casenumber<casescount;casenumber++)
				Cases[casenumber] = new Case(reader.readLine().split(" ",2));
		} catch (java.io.IOException ioex) {
			ioex.printStackTrace();
		}
	}
}
