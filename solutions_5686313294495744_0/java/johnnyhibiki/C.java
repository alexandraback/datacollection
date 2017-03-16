import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {
	
	public static void main(String[] args){
		new C().run();
	}
	
	int n;
	String[] a, b;
	
	void run(){
		Scanner sc = new Scanner(System.in);
		
		int testNum = sc.nextInt();
		for(int t=1;t<=testNum;t++){
			n = sc.nextInt();
			a = new String[n];
			b = new String[n];
			for(int i=0;i<n;i++){
				a[i] = sc.next();
				b[i] = sc.next();
			}
			String ans = fnc();
			System.out.println("Case #" + t + ": " + ans);
		}
	}
	
	String fnc(){
		String ans = "";

		int cnt = 0;
		for(int i=0;i<n;i++){
			boolean f = false;
			for(int j=0;j<n;j++){
				if(i!=j){
					if(a[i].equals(a[j]) || a[i].equals(b[j])){
						for(int k=0;k<n;k++){
							if(i!=k && j!=k){
								if(b[i].equals(a[k]) || b[i].equals(b[k])){
									cnt++;
									f = true;
									break;
								}
							}
						}
					}
				}
				if(f){
					break;
				}
			}
		}
		
		ans += cnt;
		
		return ans;
	}

}
