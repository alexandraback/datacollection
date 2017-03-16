package problemC;

import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;

import utils.InputReader;

public class SolverC {
	public static void main(String[] args) throws IOException {
		LinkedList<String> input = InputReader.read("C:/Users/Danielle/Desktop/C-small-attempt0.in");
		int num = Integer.parseInt(input.removeFirst());
		int i = 1;
		for (String string : input) {
			if (i > num) {
				System.err.println(i+">"+num);
				break;
			}
			HashSet<IntegerPair> map = new HashSet<IntegerPair>();
			String[] split = string.split(" ");
			int min = Integer.parseInt(split[0]);
			int max = Integer.parseInt(split[1]);
			for (int cur = min; cur < max; cur++){
				String str = ""+cur;
				for (int k = 1; k < str.length(); k++){
					int test = Integer.parseInt(str.substring(k)+str.substring(0, k));
					if (test != cur && test >= min && test <= max) {
						map.add(new IntegerPair(test, cur));
					}
				}
			}
			System.out.println("Case #"+(i++)+": "+map.size());
		}
	}
	
	private static class IntegerPair{
		private final int i1, i2, hash;
		
		public IntegerPair(int i1, int i2) {
			this.i1 = i1;
			this.i2 = i2;
			hash = i1+i2;
		}
		
		@Override
		public int hashCode() {
			return hash;
		}
		
		@Override
		public boolean equals(Object obj) {
			if (obj == this) return true;
			if (obj instanceof IntegerPair){
				IntegerPair other = (IntegerPair) obj;
				return (other.i1 == i1 && other.i2 == i2) || (other.i2 == i1 && other.i1 == i2);
			}
			return false;
		}
	}
}
