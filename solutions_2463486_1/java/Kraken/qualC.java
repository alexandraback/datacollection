import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;

public class qualC {
	
	static TreeMap<BigInteger,ArrayList<Integer>> tr;
	static int[] nps;
	static int nsp=0;
	
	static boolean chk(int n,char a,int[] os,char m){
		BigInteger nm=getsquare(n,a,os,m);
		if (nm.compareTo(BigInteger.ZERO)==0) return true;
		while (!tr.isEmpty() && nm.compareTo(tr.firstKey())==1){
			ArrayList<Integer> ar=tr.get(tr.firstKey());
			for (Integer i : ar)
				nps[i]=nsp;
			tr.remove(tr.firstKey());
		}
		nsp++;
		return !tr.isEmpty();
	}
	
	static BigInteger getsquare(int n,char a,int[] os,char m){
		int sz=(m==0)?2*n:2*n+1;
		if (sz==0) return BigInteger.ZERO;
		char[] nm=new char[sz];
		Arrays.fill(nm, '0');
		nm[0]=nm[sz-1]=a;
		if (m!=0) nm[n]=m;
		for (int i : os)
			nm[i]=nm[sz-i-1]='1';
		BigInteger bn=new BigInteger(new String(nm));
		//System.out.println(bn+" "+bn.pow(2));
		return bn.pow(2);
	}
	
public static void main(String[] args) {
		String prblm="C"; boolean fl=true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			tr=new TreeMap<BigInteger,ArrayList<Integer>>();
			nps=new int[2*T];
			for (int i = 0; i < T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				BigInteger A=new BigInteger(tok[0]);
				BigInteger B=new BigInteger(tok[1]);
				A=A.subtract(BigInteger.ONE);
				if (tr.containsKey(A)) {
					ArrayList<Integer> ar=tr.get(A);
					ar.add(2*i);
				}
				else {
					ArrayList<Integer> ar=new ArrayList<Integer>();
					ar.add(2*i);
					tr.put(A,ar);
				}
				if (tr.containsKey(B)) {
					ArrayList<Integer> ar=tr.get(B);
					ar.add(2*i+1);
				}
				else{
					ArrayList<Integer> ar2=new ArrayList<Integer>();
					ar2.add(2*i+1);
					tr.put(B,ar2);
				}				
			}
			int n=0;
			boolean flg=true;
			while (flg){
				for (int j = 0; j < 2 && flg; j++) {
					for (int i = 0; i < ((n>0)?2:1) && flg; i++) {
						if (j>0) for (int k = 0; k < ((n>0)?3-i:4); k++)
								flg &= chk(n,(char)('1'+i),new int[]{},(char)('0'+k));
						else flg &= chk(n,(char)('1'+i),new int[]{},(char)0);
						if (i==0){
							for (int l = n-1; l > 0 && flg; l--) {
								if (j>0) for (int k = 0; k < 3; k++)
									flg &= chk(n,(char)('1'+i),new int[]{l},(char)('0'+k));
								else flg &= chk(n,(char)('1'+i),new int[]{l},(char)0);
								for (int k = n-1; k > l && flg; k--) {
									if (j>0) for (int p = 0; p < 2; p++)
										flg &= chk(n,(char)('1'+i),new int[]{l,k},(char)('0'+p));
									else flg &= chk(n,(char)('1'+i),new int[]{l,k},(char)0);
									for (int r = n-1; r > k && flg; r--){
										if (j>0) for (int p = 0; p < 2; p++)
											flg &= chk(n,(char)('1'+i),new int[]{l,k,r},(char)('0'+p));
										else flg &= chk(n,(char)('1'+i),new int[]{l,k,r},(char)0);
									}
								}
							}
						}
					}
				}
				n++;
			}
			for (int i = 0; i < T; i++) {
				System.out.println(nps[2*i+1]-nps[2*i]);
				fw.write("Case #"+(i+1)+": "+ (nps[2*i+1]-nps[2*i]) +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
