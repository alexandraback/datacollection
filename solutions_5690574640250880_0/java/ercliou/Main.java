import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
        private static final String LINE_SEPARATOR = "\n";
    	
    	public static void main(String[] args) throws IOException {
    		long start = System.currentTimeMillis();
    		String input = readFile("C:\\google\\C-small-attempt0.in", StandardCharsets.UTF_8);
    		int casesAmount = getSingle(0, input);
    		
    		for (int i = 0 ; i < casesAmount ; i++) {
    			List<Integer> caseArgs = parseListToInteger(splitLines(i+1, 1, input, " "));
    			Case cCase = new Case();
    			cCase.Rows =  caseArgs.get(0);
    			cCase.Columns = caseArgs.get(1);
    			cCase.Mines = caseArgs.get(2);
    			
    			
    			int [][] solution = new int[cCase.Columns][cCase.Rows];
    			
    			if(!CheckFeasibility(cCase, solution)){
    				solution = null;
    			}

    			System.out.println("Case #" + (i+1) + ":");
    			if(solution != null) {
    				printMatrix(solution, cCase.Columns, cCase.Rows);
    			} else {
    				System.out.println("Impossible");
    			}
    			
    		}
    		
    		System.out.println(System.currentTimeMillis() - start + " ms");
    	}
    	
    	private static List<Integer> parseListToInteger(List<String> strings) {
    		List<Integer> tokens = new ArrayList<Integer>();
    		for (String s : strings) {
    			tokens.add(Integer.parseInt(s));
    		}
    		return tokens;
    	}

    	private static void printMatrix(int[][] matrix, int r, int c) {
    		StringBuilder sb = new StringBuilder();
    			for(int j=0; j < c; j++) {
    				for(int i = 0; i < r ; i++) {
    				switch (matrix[i][j]) {
    				case -2:
    					sb.append("* ");
    					break;
    				case -1:
    					sb.append("c ");
    					break;
//    				case 0:
//    					sb.append(". ");
//    					break;
    				default:
    					sb.append(". ");
    					break;
    				}
    			}
    			sb.append("\n");
    		}
    		System.out.print(sb.toString());
    	}


    	private static List<String> splitLines(int from, int linesAmount, String input, String separatorRegex) {
    		String [] lines = input.split(LINE_SEPARATOR);
    		List<String> tokens = new ArrayList<String>();
    		for(int i = from; i < from + linesAmount ; i++) {
    			tokens.addAll(Arrays.asList(lines[i].split(separatorRegex)));
    		}
    		return tokens;
    	}
    	
    	private static String readFile(String path, Charset encoding) throws IOException {
    		byte[] encoded = Files.readAllBytes(Paths.get(path));
    		return new String(encoded, encoding);
    	}
    	
    	private static int getSingle(int lineIndex, String input) {
    		String [] lines = input.split(LINE_SEPARATOR);
    		return Integer.parseInt(lines[lineIndex]);
    	}

        private static boolean CheckFeasibility(Case cCase, int[][] answer)
        {
            boolean solved = false;

            if (cCase.Mines > 0)
            {
                for (int i = 0; i < cCase.Columns; i++)
                {
                    for (int j = 0; j < cCase.Rows; j++)
                        answer[i][j] = -2;
                }
                answer[0][0] = -1;
            }
            else
            {
                for (int i = 0; i < cCase.Columns; i++)
                {
                    for (int j = 0; j < cCase.Rows; j++)
                        answer[i][j] = 0;
                }
                answer[0][0] = -1;
                return true;
            }

            int notBombs = cCase.Rows * cCase.Columns - cCase.Mines;

            if (notBombs == 1)
                return true;

            if (Math.min(cCase.Rows, cCase.Columns) == 1)
            {
                if (cCase.Columns == 1)
                    for (int i = 1; i < notBombs; i++)
                        answer[0][i] = 0;
                else
                    for (int i = 1; i < notBombs; i++)
                        answer[i][0] = 0;
                solved = true;
            }
            else
                for (int i = Math.max(cCase.Rows, cCase.Columns); i >= 2; i--)
                {
                    int div = notBombs / i;
                    int res = notBombs % i;
                    boolean cheat = false;

                    if (div >= 2 && ((div < Math.min(cCase.Rows, cCase.Columns) && res >= 0) || (div == Math.min(cCase.Rows, cCase.Columns) && res == 0)))
                    {
                        if (res == 1 && div > 2 && i > 2 && Math.min(cCase.Rows, cCase.Columns) > 2)
                            cheat = true;
                        if (res == 1 && !cheat)
                            continue;

                        if (cCase.Columns >= cCase.Rows)
                        {
                            for (int a = 0; a < i; a++)
                                for (int b = 0; b < div; b++)
                                    answer[a][b] = 0;
                            for (int a = 0; a < res; a++)
                                answer[a][div] = 0;
                            answer[0][0] = -1;
                            if (cheat)
                            {
                                answer[res][div] = 0;
                                answer[i - 1][div - 1] = -2;
                            }
                            solved = true;
                            break;
                        }
                        else
                        {
                            for (int a = 0; a < div; a++)
                                for (int b = 0; b < i; b++)
                                    answer[a][b] = 0;
                            for (int a = 0; a < res; a++)
                                answer[div][a] = 0;
                            answer[0][0] = -1;
                            if (cheat)
                            {
                                answer[div][res] = 0;
                                answer[div - 1][i - 1] = -2;
                            }
                            solved = true;
                            break;
                        }
                    }
                }

            return solved;
        }
    }