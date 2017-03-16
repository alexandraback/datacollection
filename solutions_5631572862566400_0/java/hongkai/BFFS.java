import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;


public class BFFS {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("bffs.out"));
		//PrintStream out = System.out;
		int cases = kb.nextInt();
		for(int n=0; n < cases; n++) {
			out.print("Case #" + (n + 1) + ": ");
			
			int students = kb.nextInt();
			int[] bffs = new int[students];
			ArrayList<Integer>[] reverseBffs = new ArrayList[students];
			for(int i=0; i < students; i++)
				reverseBffs[i] = new ArrayList<Integer>();
			for(int i=0; i < students; i++) {
				int newStudent = kb.nextInt() - 1;
				bffs[i] = newStudent;
				reverseBffs[newStudent].add(i);
			}
			int[] reverseBffsLength = new int[students];
			int circleLen = 0;
			for(int i=0; i < students; i++) {
				int rounds = 0;
				ArrayList<Integer> friends = reverseBffs[i];
				//if (friends.size() == 1 && i == bffs[bffs[i]])
				//out.println(friends);
				while(friends.size() > 0) {
					boolean foundCircle = false;
					ArrayList<Integer> newFriends = new ArrayList<Integer>();
					
					for(Integer friend : friends) {
						if(bffs[i] == friend && bffs[friend] == i){
							foundCircle = true;
						}
						else
							for(Integer newFriend: reverseBffs[friend]) {
								//out.println(newFriend);
								if(newFriend != i) {
									newFriends.add(newFriend);
								}
								else
									foundCircle = true;
							}
					}
					
					if (foundCircle) {
						int myCircleLen = rounds + 2;
						if (myCircleLen > circleLen) {
							circleLen = myCircleLen;
						}
						if (myCircleLen == 2 && friends.size() == 1)
							break;
					}
					//out.println(newFriends);
					friends = newFriends;
					//out.println(friends);
					rounds++;
				}
				reverseBffsLength[i] = rounds;
				//out.println(" reverseBfflength: " + reverseBffsLength[i]);
			}
			
			int maxLen = 0;
			for(int i=0; i < students; i++) {
				if(i == bffs[bffs[i]])
					maxLen += reverseBffsLength[i] + 1;
			}
			
			if(maxLen > circleLen)
				out.print(maxLen);
			else
				out.print(circleLen);
			
			/*
			for(int i=0; i < students; i++) {
				boolean[] visited = new boolean[students];
				int j = i;
				visited[j] = true;
				int len = 1;
				while (bffs[j] != i) {
					if(visited[bffs[j]]) {
						len = 0;
						break;
					}
					else {
						j = bffs[j];
						visited[j] = true;
					}
				}
				if (len > circleLen) {
					circleLen = len;
				}
			}
			
			for(int i=0; i < students; i++)
				out.print(" " + bffs[i]);
			
			ArrayList<Integer>[] trees = new ArrayList[students];
			for(int i=0; i < students; i++) {
				trees[i] = new ArrayList<Integer>();
			}
			int maxLen = 0;
			for(int i=0; i < students; i++) {
				if (trees[i] == null) continue;
				else if (trees[bffs[i]] == null) {
					maxLen += removeStudent(trees, i);
				}
				
				else if (i == bffs[bffs[i]] ) {
					System.out.println(" found bffs!!! " + i + ' ' + bffs[i]);
					maxLen += removeStudent(trees, i);
					maxLen += removeStudent(trees, bffs[i]);
				}
				else {
					trees[bffs[i]].add(i);
				}
			}
			
			out.print("  circleLen: " + circleLen + ' ');
			out.print("  maxLen: " + maxLen + ' ');
			if(maxLen > circleLen)
				out.print(maxLen);
			else
				out.print(circleLen);
			*/
			out.println();
		}
		out.close();
	}
	
	public static int removeStudent(ArrayList<Integer>[] trees, int student) {
		if(trees[student] == null) return 0;
		if(trees[student].size() == 1) return 1;
		int students = 1;
		for (Integer newStudent : trees[student]) {
			students += removeStudent(trees, newStudent);
		}
		trees[student] = null;
		return students;
	}
}
