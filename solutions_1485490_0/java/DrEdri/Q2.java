import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q2 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public int M;
		public long[][] boxes;
		public long[][] toys;
	}
			
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		ArrayList<long[]> boxes = new ArrayList<long[]>();
		ArrayList<long[]> toys = new ArrayList<long[]>();
		
		for (int i=0; i<p.N; i++) {
			long[] tmp = new long[2];
			tmp[0] = p.boxes[i][0];
			tmp[1] = p.boxes[i][1];
			boxes.add(tmp);
		}
		
		for (int i=0; i<p.M; i++) {
			long[] tmp = new long[2];
			tmp[0] = p.toys[i][0];
			tmp[1] = p.toys[i][1];
			toys.add(tmp);
		}

		long totalProduced = 0L;
		
		outer: while(boxes.size()>0 && toys.size()>0) {			
			if (boxes.get(0)[1]==toys.get(0)[1]) {
				//same kind
				if (boxes.get(0)[0]<toys.get(0)[0]) {
					totalProduced += boxes.get(0)[0];
					long[] t = toys.get(0);
					t[0] -= boxes.get(0)[0];
					toys.set(0, t);
					boxes.remove(0);
				} else {
					totalProduced += toys.get(0)[0];
					long[] b = boxes.get(0);
					b[0] -= toys.get(0)[0];
					if (b[0]==0) {
						boxes.remove(0);
					} else {
						boxes.set(0, b);
					}
					toys.remove(0);
				}
			} else {
				//different kinds
				long boxType = boxes.get(0)[1];
				long toyType = toys.get(0)[1];
				
				//See which is used first
				int indexBoxUsesToy = Integer.MAX_VALUE;
				int indexToyUsesBox = Integer.MAX_VALUE;
				for (int i=0; i<boxes.size(); i++) {
					if (boxes.get(i)[1]==toyType) {
						indexBoxUsesToy = i;
						break;
					}
				}
				
				for (int i=0; i<toys.size(); i++) {
					if (toys.get(i)[1]==boxType) {
						indexToyUsesBox = i;
						break;
					}
				}

				if (indexBoxUsesToy==Integer.MAX_VALUE) {
					toys.remove(0);
					continue;
				} else if (indexToyUsesBox==Integer.MAX_VALUE) {
					boxes.remove(0);
					continue;
				}
				
				
				if (indexBoxUsesToy < indexToyUsesBox) {
					//check between first and indexBoxUsesToy
					long expected = Math.min(toys.get(0)[0], boxes.get(indexBoxUsesToy)[0]);
					long bestExpected = expected;
					int toysIndex = -1;
					int boxesIndex = -1;
					for (int i=1; i<indexBoxUsesToy; i++) {
						long testType = boxes.get(i)[1];
						for (int j=0; j<indexToyUsesBox; j++) {
							if (toys.get(j)[1]==testType) {
								if (toys.get(j)[0]>bestExpected) {
									toysIndex = j;
									boxesIndex = i;
									bestExpected = toys.get(j)[0];
								}
							}
						}
					}
					if (bestExpected>expected) {
						int k=0;
						while (k<toysIndex) {
							toys.remove(0);
							k++;
						}
						k=0;
						while (k<boxesIndex) {
							boxes.remove(0);
							k++;
						}
						continue outer;
					}
					boxes.remove(0);
				} else if (indexBoxUsesToy > indexToyUsesBox) {
					long expected = Math.min(boxes.get(0)[0], toys.get(indexToyUsesBox)[0]);
					long bestExpected = expected;
					int toysIndex = -1;
					int boxesIndex = -1;
					for (int i=1; i<indexToyUsesBox; i++) {
						long testType = toys.get(i)[1];
						for (int j=0; j<indexBoxUsesToy; j++) {
							if (boxes.get(j)[1]==testType) {
								if (boxes.get(j)[0]>expected) {
									boxesIndex = j;
									toysIndex = i;
									bestExpected = boxes.get(j)[0];
								}
							}
						}
					}
					if (bestExpected>expected) {
						//better to do this instead
						int k=0;
						while (k<boxesIndex) {
							boxes.remove(0);
							k++;
						}
						k=0;
						while (k<toysIndex) {
							toys.remove(0);
							k++;
						}
						continue outer;
					}
					
					toys.remove(0);
				} else {
					long numBoxTypeInBoxes = 0;
					long numToyTypeInBoxes = 0;
					for (int i=0; i<boxes.size(); i++) {
						if (boxes.get(i)[1]==boxType) {
							numBoxTypeInBoxes += boxes.get(i)[0];
						} else if (boxes.get(i)[1]==toyType) {
							numToyTypeInBoxes += boxes.get(i)[0];
						}
					}

					long numBoxTypeInToys = 0;
					long numToyTypeInToys = 0;
					for (int i=0; i<toys.size(); i++) {
						if (toys.get(i)[1]==toyType) {
							numToyTypeInToys += toys.get(i)[0];
						} else if (toys.get(i)[1]==boxType) {
							numBoxTypeInToys += toys.get(i)[0];
						}
					}
				
					if (numBoxTypeInBoxes-numBoxTypeInToys > numToyTypeInToys-numToyTypeInBoxes) {
						//remove box type
						boxes.remove(0);
					} else if (numBoxTypeInBoxes-numBoxTypeInToys < numToyTypeInToys-numToyTypeInBoxes) {
						toys.remove(0);
					} else {
						//remove one with fewer
						if (boxes.get(0)[0]<toys.get(0)[0]) {
							boxes.remove(0);
						} else {
							toys.remove(0);
						}
					}
				}
			}
		}
		
		
		return ""+ totalProduced;
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].N = Integer.parseInt(pieces[0]);
				probs[i].M = Integer.parseInt(pieces[1]);
				probs[i].boxes = new long[probs[i].N][2];
				probs[i].toys = new long[probs[i].M][2];
				line = br.readLine();
				pieces = line.split(" ");
				for (int j=0; j<2*probs[i].N; j+=2) {
					probs[i].boxes[j/2][0] = Long.parseLong(pieces[j]); 
					probs[i].boxes[j/2][1] = Long.parseLong(pieces[j+1]); 
				}
				line = br.readLine();
				pieces = line.split(" ");
				for (int j=0; j<2*probs[i].M; j+=2) {
					probs[i].toys[j/2][0] = Long.parseLong(pieces[j]); 
					probs[i].toys[j/2][1] = Long.parseLong(pieces[j+1]); 
				}
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
