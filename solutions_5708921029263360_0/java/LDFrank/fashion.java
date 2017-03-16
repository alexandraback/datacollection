package cj16;

import java.io.*;
import java.util.LinkedList;

/**
 * Created by AmesingFlank on 5/8/16.
 */
public class fashion {

    public static void main(String[] args){
        String raw[] = readFile("/Users/AmesingFlank/Downloads/qc.in");
        int cases=Integer.valueOf(raw[0]);
        for (int i = 0; i <cases ; i++) {
            String[] temp=solveOne(i+1,raw[i+1]);
            for (String s:temp){
                System.out.println(s);
            }
        }

    }
    public static String[] solveOne(int caseNo, String data){
        int[] dataArr=getarr(data);
        int J=dataArr[0];
        int P=dataArr[1];
        int S=dataArr[2];
        int K=dataArr[3];
        int[][] jp=new int[J][P];
        int[][] ps=new int[P][S];
        int[][] js=new int[J][S];
        int total=0;
        LinkedList<String> ans=new LinkedList<>();
        for (int j = 0; j <J ; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s <S ; s++) {
                    if(jp[j][p]<K && ps[p][s]<K && js[j][s]<K){
                        total++;
                        ans.add(String.valueOf(j+1)+" "+String.valueOf(p+1)+" "+String.valueOf(s+1));
                        jp[j][p]++;
                        ps[p][s]++;
                        js[j][s]++;
                    }
                }
            }
        }

        String[] anstr=new String[total+1];
        anstr[0]="Case #"+caseNo+": "+total;
        for (int i = 0; i <total ; i++) {
            anstr[i+1]=ans.get(i);
        }
        return anstr;
    }

    public static int[] getarr(String numberString){
        String[] numbers = numberString.split("\\s+");
        int[] ints = new int[numbers.length];
        for (int i = 0; i < ints.length; i++)
            ints[i] = Integer.parseInt(numbers[i]);

        return  ints;
    }

    public static String[] readFile(String path){
        LinkedList<String> s=new LinkedList<String>();


        try {
            String encoding="GBK";
            File file=new File(path);
            if(file.isFile() && file.exists()){ //判断文件是否存在
                InputStreamReader read = new InputStreamReader(
                        new FileInputStream(file),encoding);//考虑到编码格式
                BufferedReader bufferedReader = new BufferedReader(read);
                String lineTxt = null;
                while((lineTxt = bufferedReader.readLine()) != null){
                    s.add(lineTxt);
                }
                read.close();
            }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
        }

        String[] ans=new String[s.size()];
        for (int i = 0; i < s.size(); i++) {
            ans[i]=s.get(i);
        }
        return ans;
    }

    public static void writeFile(String path,String[] res){
        try {

            int trial=res.length;
            File file = new File(path);
            BufferedWriter ow = new BufferedWriter(new FileWriter(file));

            for(int i=0;i<trial;i++){

                String temp="Case "+"#"+String.valueOf(i+1)+": "+res[i];
                System.out.println(temp);
                ow.write(temp);

                ow.newLine();
            }

            ow.close();
            System.out.println("Finished Writing");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}
