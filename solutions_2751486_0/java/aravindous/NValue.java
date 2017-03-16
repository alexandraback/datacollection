import java.awt.List;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.SortedSet;

import javax.naming.NameParser;

public class NValue{

    final static String PROBLEM_NAME = "diamond";
    final static String WORK_DIR = "C:\\Users\\aravinda\\workspace\\gcj2k13\\src\\inputs\\fair.in" ;
    String name = null;
    int n;
	
    public static void main(String[] args) throws Exception {
    	Scanner sc = new Scanner(new FileReader(WORK_DIR));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.print("Case #" + (caseNum+1) + ": ");
            new NValue().solve(sc);
        }
        sc.close();
    }

	private void solve(Scanner sc) {
        name = sc.next();
        n = sc.nextInt();
        int ans = 0;
        for (int start = 0; start < name.length(); start++) {
        	for (int end = start+1; end < name.length()+1; end++) {
				if(start <= end){
					if (go(name.substring(start,end), n))
						ans++;					
				}
        	}
        }
        System.out.println(ans);
	}

	private boolean go(String name, int n) {
		int count = 0;
		for (int i = 0; i < name.length(); i++) {			
			if(name.charAt(i)!='a' && name.charAt(i)!='e' && name.charAt(i)!='i'&& name.charAt(i)!='o'&& name.charAt(i)!='u'){
				count++;
				if (count == n) 
						return true;
			}
			else{				
				count = 0;
			}  
		}
		return false;
	}

}