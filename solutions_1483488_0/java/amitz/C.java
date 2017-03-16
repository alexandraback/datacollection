package com.google.code;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

public class C extends GCJ {

	public C() throws IOException {
		super();
	}

	@Override
	protected void code(int count) throws IOException {
		readLine();
		int n = getIntInput(0);
		int m = getIntInput(1);
		int counter =0;
		if (m<10) {
			writeln(0);
			return;
		}
		n = Math.max(n, 10);
		
		
		for (int i=n;i<m+1;i++) {			
			String string = String.valueOf(i);
			HashMap<String, Object> done = new HashMap<String, Object>();
			for (int j=1;j<string.length();j++) {
				int spinned = Integer.parseInt(string.substring(j)+string.substring(0, j)); 
				if (spinned>i && spinned <=m) {
					if (done.containsKey(String.valueOf(spinned)))
						continue;
					done.put(String.valueOf(spinned), null);
					counter++;
				}				
			}			
		}
		writeln(counter);
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		new C().run();

	}

}
