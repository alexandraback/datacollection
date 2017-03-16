import java.io.*;
import java.util.*;


public class BFF{
    static int pairs;
    
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
            pairs = 0;
            String line = sc.nextLine();
            String[] arr = line.split(" ");
            boolean[] traversed = new boolean[n];
            Student[] students = new Student[n];
            for(int i = 0; i < n; i++){
                students[i] = new Student(i);
            }
            for(int i = 0; i < n; i++){
                students[i].bff = Integer.parseInt(arr[i])-1;
                students[students[i].bff].parents.add(i);
                if (students[students[i].bff].bff == i){
                    pairs++;
                }
            }

            int curr = getNext(traversed);
            int maxVal = 0;
            while(curr != -1){
                traversed[curr] = true;
                boolean[] newTraversed = new boolean[traversed.length];
                int val = students[curr].traverse(students, newTraversed);
                if(val > maxVal){
                    maxVal = val;
                }
                curr = getNext(traversed);
            }
            //out.println(maxVal);
            bw.write("Case #" + (test+1) + ": " + maxVal + "\n");
        }



        bw.close();
        out.close();
    }

    public static int getNext(boolean[] traversed){
        for(int i = 0; i < traversed.length; i++){
            if(!traversed[i]){
                return i;
            }
        }
        return -1;
    }


    public static class Student{
        ArrayList<Integer> parents;
        int index;
        int bff;
        int value;
        public Student(int index){
            this.index = index;
            parents = new ArrayList<Integer>();
            bff = -1;
        }
        public int traverse(Student[] students, boolean[] traversed){
            traversed[index] = true;
            return 1 + students[bff].traverse(students, traversed, index);
        }

        public int traverse(Student[] students, boolean[] traversed, int target){
            traversed[index] = true;
            if(!traversed[bff]){
                return 1 + students[bff].traverse(students, traversed, target);
            } else{
                if(students[bff].bff == index){
                    return Math.max(backTraverse(students, traversed), 2*pairs - 1);
                }if (bff == target){
                    return 1;
                } else {
                    return -10000;
                }
            }
        }

        public int backTraverse(Student[] students, boolean[] traversed){
            traversed[index] = true;
            ArrayList<Integer> vals = new ArrayList<Integer>();
            for(int i = 0; i < parents.size(); i++){
                if(!traversed[parents.get(i)]){
                    vals.add(students[parents.get(i)].backTraverse(students, traversed));
                }
            }
            
            if(vals.size() == 0){
                return 1;
            }
            int max = -100;
            for(int i = 0; i < vals.size(); i++){
                if(vals.get(i) > max){
                    max = vals.get(i);
                }
            }
            return 1 + max;
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
