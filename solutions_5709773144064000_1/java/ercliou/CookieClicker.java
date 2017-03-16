import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CookieClicker {

	private static final String LINE_SEPARATOR = "\n";

	public static void main(String[] args) throws IOException {
		
		long start = System.currentTimeMillis();
		String input = readFile("D:\\B-small-attempt0.in", StandardCharsets.UTF_8);
		int casesAmount = getSingle(0, input);
		
		for (int i = 0 ; i < casesAmount ; i++) {
			
			List<Double> variables = parseListToDouble(splitLines(i+1, 1, input, " "));
			
			Double farmCost = variables.get(0);
			Double productionBoost = variables.get(1);
			Double cookiesObjective = variables.get(2);
			
			Double totalTime = 0d;
			
			
			Double cookiesToMake;
			Double currentProduction = 2d;
			
			Double buyFarmTime;
			Double waitTime;
			
			Double currentCookie = 0d;
			
			boolean isFinished = false;
			
			 while (!isFinished) {
				
					
				cookiesToMake = cookiesObjective - currentCookie;
				
				buyFarmTime = (cookiesToMake + farmCost) / (currentProduction + productionBoost);
				waitTime = cookiesToMake / currentProduction; 
				
				
				if(buyFarmTime < waitTime && currentCookie >= farmCost){ // buyFarm
					currentProduction += productionBoost;
					currentCookie -= farmCost;
					
				} 
				
				// MAKE COOKIES!
				currentCookie += farmCost; // 500 cookies to next decision
				
				if(currentCookie < cookiesObjective){
					totalTime += farmCost / currentProduction; 
				} else {
					
					totalTime += cookiesToMake / currentProduction;
					isFinished = true;
				}
				
			}
			
			
			
			System.out.println("Case #"+ (i+1) +": " + totalTime);
			
			
		}
		
		System.out.println(System.currentTimeMillis() - start + " ms");
		
	}

	private static String readFile(String path, Charset encoding)
			throws IOException {
		byte[] encoded = Files.readAllBytes(Paths.get(path));
		return new String(encoded, encoding);
	}

	private static int getSingle(int lineIndex, String input) {
		String[] lines = input.split(LINE_SEPARATOR);
		return Integer.parseInt(lines[lineIndex]);
	}

	private static List<String> splitLines(int from, int linesAmount,
			String input, String separatorRegex) {
		String[] lines = input.split(LINE_SEPARATOR);
		List<String> tokens = new ArrayList<String>();
		for (int i = from; i < from + linesAmount; i++) {
			tokens.addAll(Arrays.asList(lines[i].split(separatorRegex)));
		}
		return tokens;
	}

	private static List<Integer> parseListToInteger(List<String> strings) {
		List<Integer> tokens = new ArrayList<Integer>();
		for (String s : strings) {
			tokens.add(Integer.parseInt(s));
		}
		return tokens;
	}

	private static List<Double> parseListToDouble(List<String> strings) {
		List<Double> tokens = new ArrayList<Double>();
		for (String s : strings) {
			tokens.add(Double.parseDouble((s)));
		}
		return tokens;
	}

	private static List<Integer> splitList(List<Integer> list, int from, int to) {
		List<Integer> result = new ArrayList<Integer>();
		for (int i = from; i <= to; i++) {
			result.add(list.get(i));
		}

		return result;
	}

}
