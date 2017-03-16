import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class B {

	private static CodeJamIO io = new CodeJamIO();

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		try {
			init();

			int numCases = Integer.parseInt(io.readNextLine()[0]);
			for (int i=1; i <= numCases; i++) {
				io.debug("Solving Case #" + i + "...");
				solveCase(i);
				io.debug("Case #" + i + " solved!");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/**
	 * Performs initial computations
	 */
	private static void init() {

	}

	/**
	 * Solves a Test Case
	 *
	 * @param caseNum
	 * @throws java.io.IOException
	 */
	private static void solveCase(int caseNum) throws IOException {
		// Read input
        io.readNextLine();
		String[] trains = io.readNextLine();

		// Do the work
        String[] reducedTrains = new String[trains.length];
        for (int i=0; i<trains.length; i++) {
            reducedTrains[i] = reduce(trains[i]);
        }
        BigInteger n = solve(reducedTrains);

		// Print results
		io.printCase(caseNum).println(n.mod(new BigInteger("1000000007")));

	}

    private static BigInteger solve(String[] reducedTrains) {
        for (int i=0; i<reducedTrains.length; i++) {
            if (!validate(reducedTrains, i)) {
                return BigInteger.valueOf(0);
            }
        }
        Map<Character, Long> symTrains = countSymmetrical(reducedTrains);
        BigInteger n = null;
        if (symTrains.isEmpty()) {
            n = BigInteger.valueOf(1);
        } else {
            n = BigInteger.valueOf(0);
            for (Character c : symTrains.keySet()) {
                BigInteger permutations = factorial(symTrains.get(c));
                if (!existsInAsymmetrical(reducedTrains, c)) {
                    permutations = permutations.multiply(BigInteger.valueOf(2));
                }
                if (!permutations.equals(BigInteger.valueOf(1))) {
                    n = n.add(permutations);
                }
            }
        }

        return n;
    }

    private static boolean existsInAsymmetrical(String[] reducedTrains, Character c) {
        for (String reducedTrain : reducedTrains) {
            if (isSymmetrical(reducedTrain)) {
                continue;
            }
            for (int i=0; i<reducedTrain.length(); i++) {
                if (reducedTrain.charAt(i) == c) {
                    return true;
                }
            }
        }
        return false;
    }

    private static BigInteger factorial(long count) {
        BigInteger factorial = BigInteger.valueOf(1);
        for (long i=2; i<=count; i++) {
            factorial = factorial.multiply(BigInteger.valueOf(i));
        }
        return factorial;
    }

    private static Map<Character, Long> countSymmetrical(String[] reducedTrains) {
        Map<Character, Long> symTrains = new HashMap<Character, Long>();
        for (int i=0; i<reducedTrains.length; i++) {
            char firstChar = reducedTrains[i].charAt(0);
            if (isSymmetrical(reducedTrains[i])) {
                if (!symTrains.containsKey(firstChar)) {
                    symTrains.put(firstChar, 1L);
                } else {
                    symTrains.put(firstChar, symTrains.get(firstChar) + 1);
                }
            }
        }

        return symTrains;
    }

    private static boolean isSymmetrical(String reducedTrain) {
        return reducedTrain.charAt(reducedTrain.length()-1) == reducedTrain.charAt(0);
    }

    private static boolean validate(String[] reducedTrains, int i) {
        char checkChar = reducedTrains[i].charAt(0);
        for (int j=1; j<reducedTrains[i].length(); j++) {
            if (reducedTrains[i].charAt(j) == checkChar) {
                return false;
            }
        }

        boolean foundLast = false;
        for (int j=0; j<reducedTrains.length; j++) {
            if (j == i) {
                continue;
            }
            for (int k=0; k<reducedTrains[j].length()-1; k++) {
                if (reducedTrains[j].charAt(k) == checkChar) {
                    return false;
                }
            }
            if (reducedTrains[j].length()>1 && reducedTrains[j].charAt(reducedTrains[j].length()-1) == checkChar) {
                if (!foundLast) {
                    foundLast = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    private static String reduce(String train) {
        StringBuffer reduced = new StringBuffer(train.length());
        for (int i=0; i<train.length(); i++) {
            if (reduced.length() == 0 || train.charAt(i) != reduced.charAt(reduced.length()-1)) {
                reduced.append(train.charAt(i));
            }
        }
        return reduced.toString();
    }

    /**
	 * Input and Output CodeJam style
	 *
	 */
	private static class CodeJamIO {
		private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private static PrintWriter out = new PrintWriter(System.out, true);
		private static PrintWriter err = new PrintWriter(System.err, true);

		public String[] readNextLine() throws IOException {
			String line = in.readLine();
			String[] tokens = line.split("\\s+");
			return tokens;
		}

		public CodeJamIO printCase(int caseNum) { return print("Case #" + caseNum + ": " ); }
		
		public CodeJamIO print(Object o) { out.print(o); return this; }

		public CodeJamIO print(Object o[]) { return print(concat(o)); }

		public CodeJamIO print(Object o[][]) { return print(concat(o)); }

		public CodeJamIO println() { out.println(); return this; }

		public CodeJamIO printlnCase(int caseNum) { return printCase(caseNum).println(); }
		
		public CodeJamIO println(Object o) { return print(o).println(); }

		public CodeJamIO println(Object o[]) { return print(o).println(); }

		public CodeJamIO println(Object o[][]) { return print(concat(o)).println(); }

		public CodeJamIO println(List<Integer[]> l) { return print(concat(l)).println(); }

		
		private String concat(Object[] o) {
			StringBuffer buf = new StringBuffer(10*o.length);
			
			String delim = "";
			for (int i=0; i < o.length; i++) {
				buf.append(delim).append(o[i]);
				delim = " ";
			}
			return buf.toString();
		}
		
		private String concat(Object[][] o) {
			StringBuffer buf = new StringBuffer(100*o.length);
			for (int i=0; i < o.length; i++) {
				buf.append(concat(o[i])).append("\n");
			}
			return buf.toString();
		}

		private String concat(List<Integer[]> list) {
			StringBuffer buf = new StringBuffer();
			String delim = "";
			for (Object[] elm : list) {
				buf.append(delim).append(concat(elm)).append("\n");
			}
			return buf.toString();
		}

		public void debug(String message) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
		}

		public void debug(String message, Object[] o) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			err.println("\t" + concat(o));
		}

		public void debug(String message, Object[][] o) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			String values = concat(o);
			err.println("\t" + values.replaceAll("\n", "\n\t"));
		}

		public void debug(String message, List<Integer[]> list) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			String values = concat(list);
			err.println("\t" + values.replaceAll("\n", "\n\t"));
		}

	}

}
