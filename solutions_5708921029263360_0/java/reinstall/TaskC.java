import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class TaskC {

    public static void main(String args[]){
        File file = new File("C:\\tests\\inputC.txt");

        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();

        try(BufferedReader br = new BufferedReader(new FileReader(file))) {
            PrintWriter writer = new PrintWriter("C:\\tests\\outputC.txt", "UTF-8");
            int count = Integer.parseInt(br.readLine());

            for(int i = 0; i < count; i++) {
                String out = "Case #" + (i+1) + ": ";
                String[] line = br.readLine().split(" ");

                int j = Integer.parseInt(line[0]);
                int p = Integer.parseInt(line[1]);
                int s = Integer.parseInt(line[2]);
                int ak = Integer.parseInt(line[3]);

                String res = "";
                int cou = 0;
                int ok = 0;
oa:              for(int a = 1; a <= j; a++){
outer:              for(int b = 1; b <= p; b++){;
                        int k = ak;
cc:                      for(int c = 1; c <= s; c++){
                            if(map.containsKey(b)){
                                if(map.get(b).contains(c)){
                                    if(ok >= ak) {
                                        continue oa;
                                    }
                                    else{
                                        ok++;

                                        res += a + " " + b + " " + c + "\n";
                                        cou++;
                                        k--;

                                        if(k <= 0) continue outer;

                                        continue cc;

                                    }
                                }
                            }
                            else{
                                map.put(b, new ArrayList<Integer>());
                            }

                            if(!map.get(b).contains(c)) map.get(b).add(c);

                            res += a + " " + b + " " + c + "\n";
                            cou++;

                            if(c > 1) ok++;
                            if(ok >= ak) continue outer;

                            k--;

                            if(k <= 0) continue outer;

                        }
                    }
                }

                res = res.substring(0, res.length() - 1);
                out += cou + "\n";
                out += res;

                writer.println(out);
            }

            writer.flush();
            writer.close();
        }
        catch(Exception e){
            System.out.println("Error:" + e);
        }
    }

}

