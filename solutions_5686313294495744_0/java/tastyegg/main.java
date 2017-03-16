package jamra2p3;

import java.io.*;
import java.util.*;

public class main {
    static boolean debugging = false;
    
    public static void main(String[] args) {
	Scanner in = null;
	if (debugging) {
	    try {
		in = new Scanner(new File("C-small-attempt3.in"));
	    } catch (FileNotFoundException ex) {}
	} else {
	    in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	}
	int testCases = in.nextInt();
	in.nextLine();
	for (int t = 0; t < testCases; t++) {
	    System.out.print("Case #" + (t+1) + ": ");
	    int listedTopicCount = in.nextInt();
	    in.nextLine();
	    ArrayList<String> listedTopics = new ArrayList();
	    for (int i = 0; i < listedTopicCount; i++) {
		listedTopics.add(in.nextLine());
	    }
	    int fakeWordCount = 0;
	    for (int i = 0; i < 10000; i++) {
		int fakeWordCounter = 0;
		ArrayList<String> fakeTopics = new ArrayList();
		ArrayList<String> sar1 = new ArrayList(), sar2 = new ArrayList();
		Collections.shuffle(listedTopics);
		for (String s : listedTopics) {
		    String[] stringSplit = s.split(" ");
		    if (sar1.contains(stringSplit[0]) && sar2.contains(stringSplit[1]) && !fakeTopics.contains(s)) {
			fakeWordCounter++;
			fakeTopics.add(s);
		    } else {
			if (!sar1.contains(stringSplit[0]))
			    sar1.add(stringSplit[0]);
			if (!sar2.contains(stringSplit[1]))
			    sar2.add(stringSplit[1]);
		    }
		}
		fakeWordCount = Math.max(fakeWordCount, fakeWordCounter);
	    }
	    System.out.println(fakeWordCount);
	}
    }
}
