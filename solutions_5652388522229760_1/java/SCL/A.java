import java.io.*;

public class A {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2016/io/A-large.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2016/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			long nl = Long.parseLong(input.readLine());
			long l = nl;
			boolean[] used = new boolean[10];
			if(l == 0){
				pw.println("Case #"+(i+1)+": INSOMNIA");
			}else{
				while(true){
					String s = String.valueOf(l);
					boolean ok = true;
					for(int j = 0 ; j < s.length(); j++){
						used[s.charAt(j) - 48] = true;
					}
					for(int j = 0 ; j < used.length ; j++){
						if(!used[j]){
							ok = false;
							break;
						}
					}
					if(ok){
						pw.println("Case #"+(i+1)+": "+l);
						break;
					}
					l += nl;
				}
			}
		}
		pw.flush();
		input.close();
		pw.close();
	}
}
