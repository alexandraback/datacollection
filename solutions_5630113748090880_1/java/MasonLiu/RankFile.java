import java.io.*;
import java.util.*;


public class RankFile{
    public static void main(String[] args) throws Exception{
        MyScanner sc = new MyScanner();
        File outFile = new File("./out.txt").getAbsoluteFile();
        outFile.createNewFile();
        FileWriter fw = new FileWriter(outFile.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = sc.nextInt();
        for(int test = 0; test < t; test++){
            int n = sc.nextInt();
            HashMap<Integer, Integer> map = new HashMap<>();
            ArrayList<Integer> ans = new ArrayList<>();
            for(int i = 0; i < 2*n - 1; i++){
                String line  = sc.nextLine();
                String[] arr = line.split(" ");
                for(int j = 0; j < arr.length; j++){
                    int temp = Integer.parseInt(arr[j]);
                    if(map.containsKey(temp)){
                        map.put(temp, map.get(temp) + 1);
                    } else {
                        map.put(temp, 1);
                    }
                }
            }
            
            for(int key: map.keySet()){
                if(map.get(key) % 2 == 1){
                    ans.add(key);
                }
            }
            
            ans.sort(new Comparator<Integer>(){
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o1 - o2;
                }
            });
            String ansString = "";
            for(int i = 0; i < ans.size(); i++){
                ansString+= " " + ans.get(i);
            }
            bw.write("Case #" + (test+1) + ":" + ansString + "\n");
            //out.println("Case #" + (test+1) + ":" + ansString);
            
            
            /*int[][] map = new int[n][n];
            List[] lists = new List[2*n-1];
            PriorityQueue<List>[] pqueue = (PriorityQueue<List>[]) new PriorityQueue[(n+1)/2];
            
            for(int i = 0; i < lists.length; i++){
                lists[i] = new List(sc.nextLine());
                pqueue.add(lists[i]);
            }
            /*ArrayList<Integer>[] cols = (ArrayList<Integer>[]) new ArrayList[n];
            for(int i = 0; i < n; i++){
                cols[i] = new ArrayList<Integer>();
            }*/
            
        }

        bw.close();
        out.close();
    }
    public static class List implements Comparable<List>{
        int[] nums;
        int total;
        boolean isUsed;

        public List(String line){
            String[] temp = line.split(" ");
            total = 0;
            nums = new int[temp.length];

            for(int i = 0; i < temp.length; i++){
                nums[i] = Integer.parseInt(temp[i]);
                total += nums[i];
            }
        }
        @Override
        public int compareTo(List o) {
            return total - o.total;
        }
        
        public boolean has(ArrayList<Integer> arr){
            for(int i = 0; i < arr.size(); i++){
                if(arr.get(i) != nums[i]){
                    return false;
                }
            }
            return true;
        }

    }

    public static PrintWriter out;
    /*
    int n      = sc.nextInt();        // read input as integer
    long k     = sc.nextLong();       // read input as long
    double d   = sc.nextDouble();     // read input as double
    String str = sc.next();           // read input as String
    String s   = sc.nextLine();       // read whole line as String
    out.println(result);              // print via PrintWriter
     */
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
