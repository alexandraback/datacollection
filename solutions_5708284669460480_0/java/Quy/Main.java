import java.io.FileInputStream;
import java.util.TreeMap;
import java.io.InputStream;
import java.util.Map;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Quy Doan
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    Map<String,Integer> wordList;
    void buildWordList(int remain,StringBuilder builder,String keyboard){
        if ( remain == 0 ){
            if ( wordList.containsKey(builder.toString())){
                wordList.put(builder.toString(),wordList.get(builder.toString())+1);
            }else{
                wordList.put(builder.toString(),1);
            }
        }else{
            for(int i = 0 ; i < keyboard.length() ; ++i){
                StringBuilder _builder = new StringBuilder(builder);
                _builder.append(keyboard.charAt(i));
                buildWordList(remain-1,_builder,keyboard);
            }
        }

    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int K = in.nextInt();
        int L = in.nextInt();
        int S = in.nextInt();
        String keyboard = in.next();
        String target = in.next();
        boolean[] appeared = new boolean[26];
        for(int i = 0 ; i < keyboard.length() ; ++i){
            appeared[keyboard.charAt(i)-'A'] = true;
        }

        boolean available = true;
        for(int i = 0 ;  i < target.length() ; ++i){
            available = available && appeared[target.charAt(i)-'A'];
        }
        if ( !available ){
            out.println("Case #"+testNumber+": 0.0000000");
            return;
        }
//        out.println(keyboard);
        wordList = new TreeMap<>();
        buildWordList(S, new StringBuilder(""),keyboard);
        int max = 0;
        int sum = 0;
        int totalWord = 0;
        Iterator it = wordList.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            String word = (String)pair.getKey();
            Integer freq = (Integer)pair.getValue();
            int count = 0;
            int start = 0;
            while((start = word.indexOf(target,start)) != -1){
                ++count;
                ++start;
            }
            max = Math.max(max,count);
            sum += count * freq;
            totalWord += freq;
            it.remove(); // avoids a ConcurrentModificationException
        }

//        out.println("Max "+max + " Sum "+sum);
        double result = 1.0 * sum / totalWord;
        result = 1.0 * max - result;
        out.printf("Case #%d: %.7f\n", testNumber, result);
    }
}

