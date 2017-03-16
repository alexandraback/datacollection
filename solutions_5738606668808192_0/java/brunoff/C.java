package gcj2016.qualification;

public class C {
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
		public coin(long coinbase10) { base10=coinbase10; }
		long base10 = -101; long[] divs = /*new long[9]*/ { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
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
	
	private long nextcoin(long previouscoin) throws Exception {
		char[] previouscoinchr = String.valueOf(previouscoin).toCharArray();
		for(int c=previouscoinchr.length-2;c>=1;c--) {
			if(previouscoinchr[c]=='0') { previouscoinchr[c]='1'; break; }
			else
			if(previouscoinchr[c]=='1') { previouscoinchr[c]='0'; }
		}
		return Long.parseLong(new String(previouscoinchr));
	}
	
	private coin nextcoin(coin origincoin) throws Exception {
		return new coin(nextcoin(origincoin.base10));
	}
	
	private long readasbase(long input, int base) {
		return Long.parseLong(String.valueOf(input),base);
	}
	
	private long aDivisor(long n) {
	    //check if n is a multiple of 2
	    if (n%2==0) return 2;
	    //if not, then just check the odds
	    for(long i=3;i*i<=n;i+=2) {
	        if(n%i==0)
	            return i;
	    }
	    return -1;
	}
	
	private void solvecase(int casenumber) throws Exception {
		Case Case = Cases[casenumber];
		
		coin nextcoin = new coin((long)Math.pow(10, (long)(Case.N)-1)+1);
		for(int walletposition = 0;walletposition < Case.J;) {
			for(int i=2;i<=10;i++) {
				nextcoin.divs[i-2] = aDivisor(readasbase(nextcoin.base10,i));
				if(nextcoin.divs[i-2]==-1) break;
			}
			if(nextcoin.divs[8]!=-1) {
				Case.coins[walletposition] = coin.clone(nextcoin);
				walletposition++;
			}
			if(walletposition == Case.J) break;
			else nextcoin = nextcoin(nextcoin);
		}	
		
		//if(nextcoin);
		
		//Case.coins[0] = nextcoin;
		//Case.coins[1].base10 = nextcoin(Case.coins[0].base10);
		//Case.coins[2].base10 = nextcoin(Case.coins[1].base10);
		
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
