package gcj2013.round1c;


import java.util.*;
import java.math.*;
import org.korifey.ffalg.*;

import common.AbstractRunner;

public class B extends AbstractRunner {
		
	
	@Override
	public void handleCase(int caseNumber) throws Exception {		
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		for (int i=0; i<Math.abs(x); i++) {
			if (x > 0) out.write("WE");
			else out.write("EW");
		}
		
		for (int i=0; i<Math.abs(y); i++) {
			if (y > 0) out.write("SN");
			else out.write("NS");
		}
		
		out.write("\n");
	}
	
	public static void main(String[] args) throws Exception {
		new B().init(SIZE.small).execute();
	}
}

