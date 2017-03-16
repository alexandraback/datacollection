import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.commons.math3.Field;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).mainB();
	}
	
	public long GCD(long a, long b){
		if (a<=0){
			return b;
		}
		return GCD(b%a,a);
	}
	
//	public BigInteger fact(int nr, BigInteger mod){
//		fact(nr, mod, BigInteger.ONE);
//	}
//	
//	public BigInteger fact(int nr, BigInteger mod, BigInteger s){
//		
//	}
	
	public long fact(int nr, long mod){
		if (nr<=1){
			return 1;
		}
		return (nr*fact(nr-1,mod))%mod;
	} 
	
	public void main(){
//		scanFile("x-small-attempt0.in");
//		scanFile("x-large.in");
		s.useDelimiter(Pattern.compile("\\s"));
//		outputInFile("As0_0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){

		}
	}
	
	public class Tr implements Comparable<Tr>{
		char f;
		char e;
		long nr;
		
		public Tr(char f, char e) {
			super();
			this.f = f;
			this.e = e;
			nr=1L;
		}

		@Override
		public String toString() {
			return "Tr ["+nr+"*"+f + ""+ e + "]";
		}

		@Override
		public int compareTo(Tr o) {
			if (f!=o.f){
				return f-o.f;
			}else{
				return e-o.e;
			}
//			return 0;
		}
		
		
		
		
	}
	
	long MOD=1000000007L;
	public void mainB(){
		scanFile("B-small-attempt1.in");
//		scanFile("x-large.in");
//		s.useDelimiter(Pattern.compile("\\s"));
		outputInFile("Bs1_0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			int N=s.nextInt();
			List<Tr> ls=new ArrayList<Tr>();
			List<Integer> inner=new ArrayList<Integer>();
			List<Integer> outer=new ArrayList<Integer>();
			boolean impossible=false;
			for (int j=0;j<N;j++){
				String tr=s.next();
				char f=tr.charAt(0);
				char e=tr.charAt(tr.length()-1);
				char b=f;
				char li=0;
				outer.add((int) f);

				for (int k=1;k<tr.length()-1;k++){
					char trk=tr.charAt(k);
					if (trk!=b){
						if (li!=0){
							if (outer.contains((int)li)){
								impossible=true;
							}
							inner.add((int)li);
						}
						if (inner.contains((int)trk)||e==f){
							impossible=true;
//							errln("%d %d",j,k);
//							break;
						}else{
							li=trk;
//							inner.add((int) trk);
						}
					}
					b=trk;
				}
				if (li!=0&&li!=e){
					inner.add((int)li);
				}
				outer.add((int) e);
				if (inner.contains((int)f)||inner.contains((int)e)){
					impossible=true;
//					break;
				}
				ls.add(new Tr(f,e));
//				ls.add(s.next());
			}
//			showln("%s %s", inner,outer);
			errln("%s %s",ls, impossible);
			List<Tr> ls3=new ArrayList<Tr>();
			if (!impossible){
//				showln("imp!");
				Collections.sort(ls);
				List<Tr> ls2=new ArrayList<Tr>();
				Tr last=ls.get(0);
				int c=1;
				for (int k=1;k<ls.size();k++){
					if (last.compareTo(ls.get(k))!=0){
						last.nr=fact(c,MOD);
						ls2.add(last);
						last=ls.get(k);
						c=1;
					}else{
						if (last.e!=last.f){
							impossible=true;
							break;
						}
						c++;
					}
				}
				last.nr=fact(c,MOD);
				ls2.add(last);
//				showln("%s",ls2);
				if (!impossible){
					while(!ls2.isEmpty()&&!impossible){
						Tr first=ls2.get(0);
//						char e=first.e;
						int idx=0;
						for (int j=1;j<ls2.size();j++){
							if (first.e==ls2.get(j).f){
								if (ls2.get(j).f==ls2.get(j).e){
									idx=j;
									break;
								}
								if (idx==0){
									idx=j;
								}else{
									impossible=true;
									break;
								}
							}
						}
						if (idx!=0){
							Tr r=ls2.get(idx);
							ls2.remove(idx);
							first.e=r.e;
							first.nr=(first.nr*r.nr)%MOD;
							continue;
						}
						idx=0;
						for (int j=1;j<ls2.size();j++){
							if (first.f==ls2.get(j).e){
								if (ls2.get(j).f==ls2.get(j).e){
									idx=j;
									break;
								}
								if (idx==0){
									idx=j;
								}else{
									impossible=true;
									break;
								}
							}
						}
						if (idx!=0){
							Tr r=ls2.get(idx);
							ls2.remove(idx);
							first.f=r.f;
							first.nr=(first.nr*r.nr)%MOD;
							continue;
						}
						ls2.remove(0);
						ls3.add(first);
					}
				}
			}
			long tot=1L;
			if (!impossible){
				for (Tr t: ls3){
					tot=(tot*t.nr)%MOD;
				}
				tot=(tot*fact(ls3.size(),MOD))%MOD;
			}else{
				tot=0L;
			}
//			showln("%s", ls3);
			showln("Case #%d: %d",i+1,tot);
		}
	}
	
	public void mainA(){
//		scanFile("A-small-attempt0.in");
		scanFile("A-large.in");
		s.useDelimiter(Pattern.compile("\\s|/"));
//		outputInFile("Al0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			long P=s.nextLong();
			long Q=s.nextLong();
			long g=GCD(P,Q);

			long Pd=P/g;
			long Qd=Q/g;
			int p=0;
			boolean impossible=false;
			while ((Qd&1)==0){
				Qd=Qd>>1;
				p++;
			}
//			showln("p=%d",p)
//			showln("Qd==2^%d",p);
			if (p==0){
//				showln("%d/%d %d",P,Q,g);
			}
			if (Qd==1&&p<=40){
				for (int j=p-1;j>=0;j--){
					if (((Pd>>j)&1)==1){
						showln("Case #%d: %d",i+1,p-j);
						break;
					}
				}
			}else{
				impossible=true;
				showln("Case #%d: impossible",i+1);
			}
		}
	}


}
