import java.util.Scanner;


public class CloseMatch {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tests = s.nextInt();
		for(int t = 1; t <= tests; t++) {
			String c = s.next();
			String j = s.next();
			int cint = 0;
			int jint = 0;
			for(int i = 0 ; i < c.length(); i++) {
				if(c.charAt(i) == '?' ^ j.charAt(i) == '?') {
					if(c.charAt(i) == '?') {
						cint = cint*10 + Integer.parseInt(j.charAt(i)+"");
						jint = jint*10 + Integer.parseInt(j.charAt(i)+"");
						
					} else if(j.charAt(i) == '?') {
						cint = cint*10 + Integer.parseInt(c.charAt(i)+"");
						jint = jint*10 + Integer.parseInt(c.charAt(i)+"");
					}
				} else {
					if(c.charAt(i) == '?') {
						if(cint != jint) {
							cint *= 10;
							jint *= 10;
							int dif = Math.abs(cint - jint);
							if(cint <= jint) {
								cint += dif -1;
							} else {
								jint += dif -1;
							}
						}
					} else {
						cint += Integer.parseInt(c.charAt(i)+"");
						jint += Integer.parseInt(j.charAt(i)+"");
					}
				}
			}

			String cs = String.valueOf(cint);
			String js = String.valueOf(jint);
			while(cs.length() < c.length()) {
				cs = "0"+cs;
				js = "0"+js;
			}
			System.out.println("Case #"+t+": "+cs +" "+js);
		}
	}

}
