import java.util.HashMap;
import java.util.Scanner;


public class Dijkstra {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int testCases = reader.nextInt();
		for(int t = 0; t < testCases; t++){
			int length = reader.nextInt();
			int repeat = reader.nextInt();
			String s = reader.next();
			if(length != s.length()){
				throw new IllegalArgumentException();
			}
			Str sb = new Str(s, repeat);
			HashMap<Long, Character> map = new HashMap<Long, Character>();
			HashMap<Long, Boolean> map2 = new HashMap<Long, Boolean>();
			boolean through = false;
			boolean answer = false;
			//target is 'i'
			boolean sign = true;
			char sum = '1';
			for(long index = 0; index < sb.length()-2; index++){
				if(!sign(sum, sb.charAt(index))){
					sign = !sign;
				}
				sum = multiply(sum, sb.charAt(index));
				if(sum == 'i' && sign){
					//target is 'j'
					char sum2 = '1';
					boolean sign2 = true;
					
					for(long j = index+1; j < sb.length()-1; j++){
						if(!sign(sum2, sb.charAt(j))){
							sign2 = !sign2;
						}
						sum2 = multiply(sum2, sb.charAt(j));
						if(sum2 == 'j' && sign2){
							//target is 'k'
							char sum3 = '1';
							boolean sign3 = true;
							if(through){
								sum3 = map.get(j+1);
								sign3 = map2.get(j+1);
							} else{
								for(long k = sb.length() - 1; k >= j+1; k--){
									if(!sign(sb.charAt(k), sum3)){
										sign3 = !sign3;
									}
									sum3 = multiply(sb.charAt(k), sum3);
									map.put((long) k, sum3);
									map2.put((long) k, sign3);
								}
								through = true;
							}
							if(sum3 == 'k' && sign3){
								answer = true;
							}
						}
						if(answer){
							break;
						}
					}
				}
				if(answer){
					break;
				}
			}
			if(answer){
				System.out.println("Case #" + (t+1) + ": YES");
			} else{
				System.out.println("Case #" + (t+1) + ": NO");
			}
		}
		reader.close();
	}
	
	public static char multiply(char c1, char c2){
		if (c1 == '1'){
			return c2;
		}
		if (c2 == '1'){
			return c1;
		}
		if (c1 == c2) {
			return '1';
		}
		if (c1 == 'i'){
			if(c2 == 'j'){
				return 'k';
			}
			else if (c2 == 'k'){
				return 'j';
			}
		}
		if (c1 == 'j'){
			if(c2 == 'i'){
				return 'k';
			} else if (c2 == 'k'){
				return 'i';
			}
		} else if (c1 == 'k'){
			if(c2 == 'i'){
				return 'j';
			} else if (c2 == 'j'){
				return 'i';
			}
		}
		throw new IllegalArgumentException();
	}
	/**
	 * True is positive
	 * @param c1
	 * @param c2
	 * @return
	 */
	public static boolean sign(char c1, char c2){
		if(c1 == 'i' && c2 == 'i'){
			return false;
		}
		if(c1 == 'i' && c2 == 'k'){
			return false;
		}
		if(c1 == 'j' && c2 == 'i'){
			return false;
		}
		if(c1 == 'j' && c2 == 'j'){
			return false;
		}
		if(c1 == 'k' && c2 == 'j'){
			return false;
		}
		if(c1 == 'k' && c2 == 'k'){
			return false;
		}
		return true;
	}
	
	static class Str{
		String string;
		int repeat;
		Str(String string, int repeats){
			this.string = string;
			repeat = repeats;
		}
		
		public long length(){
			return string.length() * repeat;
		}
		
		public char charAt(long i){
			return string.charAt((int) (i % string.length()));
		}
	}
}
