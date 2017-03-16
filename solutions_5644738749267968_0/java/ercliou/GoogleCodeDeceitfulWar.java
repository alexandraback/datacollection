import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;


public class GoogleCodeDeceitfulWar {
	
	private static final String LINE_SEPARATOR = "\r\n";
	
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		String input = readFile("C:\\google\\input.txt", StandardCharsets.UTF_8);
		int casesAmount = getSingle(0, input);
		
		for (int i = 0 ; i < casesAmount ; i++) {
			int n = getSingle(3*i + 1, input);
			
			List<Double> naomiBlocks = parseListToDouble(splitLines(3*i+2, 1, input, " "));
			List<Double> kenBlocks = parseListToDouble(splitLines(3*i+3, 1, input, " "));
			Collections.sort(kenBlocks);
			List<Double> kenBlocks2 = new ArrayList<Double>(kenBlocks);
			
			int naomiWarPoints = 0;
			int naomiDeceitfulWarPoints = 0;
			
			// War
			for (Double block : naomiBlocks) {
				Iterator<Double> kenBlocksIterator = kenBlocks.iterator();
				boolean hasLargerThanNaomi = false;
				while(kenBlocksIterator.hasNext()) {
					Double kenBlock = kenBlocksIterator.next();
					if(block < kenBlock) {
						kenBlocksIterator.remove();
						hasLargerThanNaomi = true;
						break;
					}
				}
				if(!hasLargerThanNaomi) {
					kenBlocks.remove(0);
					naomiWarPoints++;
				}
			}
			
			// Deceitful War
			Collections.sort(naomiBlocks);
			for(int j = n; j > 0 ; j--) {
				for(int k = kenBlocks2.size(); k > 0 ; k--) {
					if(naomiBlocks.get(j-1) > kenBlocks2.get(k -1 )) {
						kenBlocks2.remove(k -1);
						naomiDeceitfulWarPoints++;
						break;
					}
				}
			}
			System.out.println("Case #" + i + ": " + naomiDeceitfulWarPoints + " " + naomiWarPoints);
		}
		
//		System.out.println(System.currentTimeMillis() - start + " ms");
	}
	
	private static String readFile(String path, Charset encoding) throws IOException {
		byte[] encoded = Files.readAllBytes(Paths.get(path));
		return new String(encoded, encoding);
	}
	
	private static int getSingle(int lineIndex, String input) {
		String [] lines = input.split(LINE_SEPARATOR);
		return Integer.parseInt(lines[lineIndex]);
	}
	
	private static List<String> splitLines(int from, int linesAmount, String input, String separatorRegex) {
		String [] lines = input.split(LINE_SEPARATOR);
		List<String> tokens = new ArrayList<String>();
		for(int i = from; i < from + linesAmount ; i++) {
			tokens.addAll(Arrays.asList(lines[i].split(separatorRegex)));
		}
		return tokens;
	}
	
	private static List<Double> parseListToDouble(List<String> strings) {
		List<Double> tokens = new ArrayList<Double>();
		for (String s : strings) {
			tokens.add(Double.parseDouble(s));
		}
		return tokens;
	}
	
	private static List<Integer> splitList(List<Integer> list, int from, int to) {
		List<Integer> result = new ArrayList<Integer>();
		for(int i = from; i <= to; i++) {
			result.add(list.get(i));
		}
		
		return result;
	}
	
	private static <T> List<T> intersection(List<T> list1, List<T> list2) {
        List<T> list = new ArrayList<T>();

        for (T t : list1) {
            if(list2.contains(t)) {
                list.add(t);
            }
        }

        return list;
    }
} 