import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Osmos {
	
	private int T;
	
	public void solve(String in, String out) throws IOException {
		
		Scanner scanner = new Scanner(new File(in));
		Writer outFile = new FileWriter(out);
		
		T = scanner.nextInt();
		
		for (int i = 1; i <= T; ++i) {
			int A = scanner.nextInt();
			int N = scanner.nextInt();
			
			ArrayList<Integer> motes = new ArrayList<Integer>(N);
			for (int n = 0; n < N; ++n) {
				motes.add(scanner.nextInt());								
			}
			Collections.sort(motes);
			Collections.reverse(motes);
			
			int currentSize = A;
			while (!motes.isEmpty() && motes.get(motes.size() - 1) < currentSize) {
				currentSize += motes.get(motes.size() - 1);
				motes.remove(motes.size() - 1);				
			}			
			
			int minSteps = 0;
			
			if (motes.size() != 0) {
				
				minSteps = motes.size();
				int motesAdded = 0;
				int motesRemoved = 0;
				
				while (!motes.isEmpty()) {
					
					if (currentSize == 1) {
						motes.remove(0);
						motesRemoved++;
					}
					
					else {
						currentSize += currentSize - 1;
						motesAdded++;
						
						while (!motes.isEmpty() && motes.get(motes.size() - 1) < currentSize) {
							currentSize += motes.get(motes.size() - 1);
							motes.remove(motes.size() - 1);				
						}
					}
					if (motesAdded + motes.size() + motesRemoved < minSteps ) {
						minSteps = motesAdded + motes.size() + motesRemoved;
					}
				}
			}
			
			String str = "Case #"+i+": " + minSteps+'\n';
			outFile.write(str);
			System.out.println(str);	
		}
		
		outFile.flush();
		outFile.close();		
	}
}
public class Launcher {

	public static void main(String[] args) {
		Osmos osmos = new Osmos();

		try {
			osmos.solve("A-small-attempt0-1.in.txt", "out");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
