package codejam.CJ2015;

import java.util.Scanner;

public class QRC {

	private enum Quartenion{
		I,
		J,
		K,
		O,
		MI,
		MJ,
		MK,
		MO;
		
		public static Quartenion read(String s){
			if(s == null) return O;
			if(s.equals("i")) return I;
			if(s.equals("j")) return J;
			if(s.equals("k")) return K;
			return O;
		}
		
/*		private static boolean isNegative(Quartenion a){
			if(a != null) return a.isNegative();
			return false;
		}*/
		
		private boolean isNegative(){
			return (this == MI)||(this == MJ)||(this == MK)||(this == MO);
		}
		
		private Quartenion getPositive(){
			if(this == MI) return I;
			if(this == MJ) return J;
			if(this == MK) return K;
			if(this == MO) return O;
			return this;
		}
		
		private Quartenion getNegative(){
			if(this == I) return MI;
			if(this == J) return MJ;
			if(this == K) return MK;
			if(this == O) return MO;
			return this;
		}
		
		public static Quartenion multiply(Quartenion a, Quartenion b){
			boolean negative = a.isNegative() ^ b.isNegative();
			a = a.getPositive();
			b = b.getPositive();
			Quartenion result = null;
			if(a == O) result = b;
			else if(b == O) result = a;
			else if(a == b){
				result = O;
				negative = !negative;
			} else if(a == I){
				if(b == J) result = K;
				if(b == K){
					result = J;
					negative = !negative;
				}
			} else if(a == J){
				if(b == I){
					result = K;
					negative = !negative;
				}
				if(b == K) result = I;
			} else if(a == K){
				if(b == I) result = J;
				if(b == J){
					result = I;
					negative = !negative;
				}
			}
			if(negative) result = result.getNegative();
			return result;
		}
		
		public Quartenion multiply(Quartenion a){
			return multiply(this, a);
		}
		
		public static Quartenion product(String s){
			if(s == null) return O;
			Quartenion result = O;
			for(int j=0; j<s.length(); j++){
				result = result.multiply(read(s.substring(j, j+1)));
			}
			return result;
		}
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int l = in.nextInt();
			long x = in.nextLong();
			String s = in.next();
			boolean result = true;
			Quartenion product = Quartenion.product(s);
			//System.out.println(product.toString());
			if(product == Quartenion.O) result = false;
			else if(product == Quartenion.MO) result = (x % 2) == 1;
			else result = (x % 4) == 2;
			//if(!result) System.out.println("product condition");
			
			if(result){
				int lastJ = 0;
				int lastK = 0;
				int achieved = 0;
				Quartenion[] achievements = {Quartenion.I, Quartenion.J, Quartenion.K};
				Quartenion current = Quartenion.O;
				for(int k = 0; k<x; k++){
					for(int j = 0; j<l; j++){
						current = current.multiply(Quartenion.read(s.substring(j, j+1)));
						//System.out.println(current);
						if(current == achievements[achieved]){
							achieved++;
							lastJ = j;
							lastK = k;
							current = Quartenion.O;
						} else if((k-lastK>4)||((k-lastK==4)&&(j>=lastJ))){
							result = false;
							//System.out.println("overshot condition: k=" + k + " lastK=" + lastK + " j=" + j + " lastJ=" + lastJ + " achieved=" + achieved + " current=" + current);
							break;
						}
						if(achieved == 3) break;
					}
					if(!result) break;
					if(achieved == 3) break;
				}
				if(achieved < 3){
					result = false;
					//System.out.println("unachievement condition");
				}
			}
			
			System.out.print("Case #" + i + ": ");
			
			if(result) System.out.print("YES");
			else System.out.print("NO");
			
			System.out.println();
		}
		
		in.close();
	}
}
