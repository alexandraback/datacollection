import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class B {
	
	public static void greedy_fill(char[] array, int start, int number){
		for(int i = start; i < array.length; i++){
			if(array[i] != '?'){ continue; }
			array[i] = (char)(number + '0');
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		for(int tt = 1; tt <= T; tt++){
			final char[] C = sc.next().toCharArray();
			final char[] J = sc.next().toCharArray();
			
			long min_abs_value = Long.MAX_VALUE;
			long min_C_value = Long.MAX_VALUE;
			long min_J_value = Long.MAX_VALUE;
			char[] min_C = null;
			char[] min_J = null;
			
			int sign = 0;
			for(int i = 0; i < C.length; i++){
				if(sign == 0){
					if(C[i] == '?' && J[i] == '?'){
						// 3ë
						{
							final char[] C_copy = C.clone(); C_copy[i] = '0'; 
							final char[] J_copy = J.clone(); J_copy[i] = '1'; 
							
							greedy_fill(C_copy, i + 1, 9);
							greedy_fill(J_copy, i + 1, 0);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						{
							final char[] C_copy = C.clone(); C_copy[i] = '1'; 
							final char[] J_copy = J.clone(); J_copy[i] = '0'; 
							
							greedy_fill(C_copy, i + 1, 0);
							greedy_fill(J_copy, i + 1, 9);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						C[i] = J[i] = '0';
					}else if(C[i] == '?' && J[i] != '?'){ 
						// 3ë
						if(J[i] != '9'){
							final char[] C_copy = C.clone(); C_copy[i] = (char)(J[i] + 1);
							final char[] J_copy = J.clone(); 
							
							greedy_fill(C_copy, i + 1, 0);
							greedy_fill(J_copy, i + 1, 9);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						if(J[i] != '0'){
							final char[] C_copy = C.clone(); C_copy[i] = (char)(J[i] - 1);
							final char[] J_copy = J.clone(); 
							
							greedy_fill(C_copy, i + 1, 9);
							greedy_fill(J_copy, i + 1, 0);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						C[i] = J[i];
					}else if(C[i] != '?' && J[i] == '?'){ 
						// 3ë
						if(C[i] != '9'){
							final char[] C_copy = C.clone();
							final char[] J_copy = J.clone(); J_copy[i] = (char)(C_copy[i] + 1);
							
							greedy_fill(C_copy, i + 1, 9);
							greedy_fill(J_copy, i + 1, 0);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						if(C[i] != '0'){
							final char[] C_copy = C.clone(); 
							final char[] J_copy = J.clone(); J_copy[i] = (char)(C_copy[i] - 1);
							
							greedy_fill(C_copy, i + 1, 0);
							greedy_fill(J_copy, i + 1, 9);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						J[i] = C[i];
					}else if(C[i] > J[i]){
						// ë≈ÇøêÿÇË
						{
							final char[] C_copy = C.clone();
							final char[] J_copy = J.clone(); 
							
							greedy_fill(C_copy, i + 1, 0);
							greedy_fill(J_copy, i + 1, 9);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						sign = 1;
						break;
					}else if(C[i] < J[i]){
						// ë≈ÇøêÿÇË
						{
							final char[] C_copy = C.clone();;
							final char[] J_copy = J.clone(); 
							
							greedy_fill(C_copy, i + 1, 9);
							greedy_fill(J_copy, i + 1, 0);
							
							final long C_value = Long.parseLong(String.valueOf(C_copy));
							final long J_value = Long.parseLong(String.valueOf(J_copy));
							final long abs_value = Math.abs(C_value - J_value);
							
							if(abs_value < min_abs_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value < min_C_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
								min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
							}
						}
						sign = -1;
						break;
					}
				}
			}
			
			if(sign == 0){
				final char[] C_copy = C.clone();
				final char[] J_copy = J.clone();
				
				final long C_value = Long.parseLong(String.valueOf(C_copy));
				final long J_value = Long.parseLong(String.valueOf(J_copy));
				final long abs_value = Math.abs(C_value - J_value);
					
				if(abs_value < min_abs_value){
					min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
				}else if(abs_value == min_abs_value && C_value < min_C_value){
					min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
				}else if(abs_value == min_abs_value && C_value == min_C_value && J_value < min_J_value){
					min_abs_value = abs_value; min_C_value = C_value; min_J_value = J_value; min_C = C_copy; min_J = J_copy;
				}
			}
			
			System.out.printf("Case #%d: %s %s\n", tt, String.valueOf(min_C), String.valueOf(min_J));
		}
	}
	
	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;
 
		public Scanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}
 
		private void getLine() {
			try {
				while (!hasNext()) {
					tok = new StringTokenizer(br.readLine());
				}
			} catch (IOException e) { /* ignore */
			}
		}
 
		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}
 
		public String next() {
			getLine();
			return tok.nextToken();
		}
 
		public int nextInt() {
			return Integer.parseInt(next());
		}
 
		public long nextLong() {
			return Long.parseLong(next());
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public void close() {
			try {
				br.close();
			} catch (IOException e) { /* ignore */
			}
		}
	}
}
