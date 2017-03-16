import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;
import java.text.DecimalFormat;

public class ProblemA {
    
    public static void main(String[] args) {
	try {
	    FileWriter writer = new FileWriter("A-small-attempt.out");
	    BufferedWriter out = new BufferedWriter(writer);
	    String current, result;
	    result = "";
	    Scanner sc = new Scanner(new File("A-small-attempt1.in"));
	    int x = Integer.parseInt(sc.nextLine());
	    for (int k = 0; k < x; k++) {
		result = "Case #" + (k+1) + ": ";
		current = sc.nextLine();
		int classes = Integer.parseInt(current);
		int[][] graph = new int[classes][];
		boolean diamondPath = false;
		for (int i = 0; i < classes; i++) {
		    String[] line = sc.nextLine().split(" ");
		    int[] children = new int[Integer.parseInt(line[0])];
		    for (int z = 0; z < Integer.parseInt(line[0]); z++)
			children[z] = Integer.parseInt(line[z+1]);
		    graph[i] = children;
		}
		for (int i = 0; i < classes; i++) {
		    for (int z = 0; z < classes; z++) {
			int path = 0;
			if (z != i) {
			    path = findDiamondPath(i, z, graph);
			}
			if (path >= 2) {
			    diamondPath = true;
			}
		    }
		}
		if (diamondPath) {
		    result += "Yes";
		} else {
		    result += "No";
		}
		out.write(result);
		out.newLine();
	    }
	    out.close();
	} catch (Exception e) {
	    e.printStackTrace();
	}
    }


    public static double roundDecimals(double d) {
	DecimalFormat twoDForm = new DecimalFormat("#.######");
        return Double.valueOf(twoDForm.format(d));
    }

    public static int findDiamondPath(int start, int end, int[][] graph) {
	int[] children = graph[start];
	int count = 0;
	for (int i = 0; i < children.length; i++) {
	    if (children[i] == end + 1) {
		count++;
	    } else {
		count += findDiamondPath(children[i]-1, end, graph);
	    }
	}
	return count;
    }
}