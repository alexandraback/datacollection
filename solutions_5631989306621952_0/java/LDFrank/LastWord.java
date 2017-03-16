package cj16;

import java.io.*;
import java.util.LinkedList;

/**
 * Created by AmesingFlank on 4/16/16.
 */
public class LastWord {



    public static void main(String[] args){
        String raw[] = readFile("/Users/AmesingFlank/Downloads/q1test.in");
        int cases=Integer.valueOf(raw[0]);
        String[] ans=new String[cases];
        for (int i = 0; i < cases; i++) {
            ans[i]=solveOne(raw[i+1]);
        }
        writeFile("/Users/AmesingFlank/cj2016/QuestionA-small.txt",ans);
    }

    public static String solveOne(String s){
        String ans="";
        ans+=s.charAt(0);
        for (int i = 1; i <s.length() ; i++) {
            if((int)s.charAt(i)>=(int)ans.charAt(0)){
                ans=s.charAt(i)+ans;
            }
            else {
                ans=ans+s.charAt(i);
            }
        }
        return ans;
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
