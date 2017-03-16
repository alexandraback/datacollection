import java.io.*;
import java.util.LinkedList;

/**
 * Created by ldfrank533 on 15/5/10.
 */
public class Brattleship {
    public static void main(String[] args) {
        LinkedList<String> s=new LinkedList<String>();


        try {
            String encoding="GBK";
            File file=new File("/Volumes/2t2/Download/A-small-attempt0.in-4.txt");
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


        int trial=Integer.valueOf(s.get(0));
        String[] raw=new String[trial+1];
        int[][] resf=new int[trial][0];

        for (int i=0;i<trial+1;i++){
            raw[i]=s.get(i);
        }

        for(String x:raw){
            System.out.println(x);
        }

        System.out.println("--------------------------------------------------------------------");
        int[] R=new int[trial];
        int[] C=new int[trial];
        int[] W=new int[trial];
        for (int i = 0; i < trial; i++) {
            int[] temp=getarr(raw[i+1]);
            R[i]=temp[0];
            C[i]=temp[1];
            W[i]=temp[2];
        }
        for(int i:W){
            System.out.println(i);
        }
        int ii=0;
        System.out.println(run(R[ii],C[ii],W[ii]));
        System.out.println(R[ii]+""+C[ii]+""+W[ii]);
        int[] res=new int[trial];
        for (int i = 0; i <trial ; i++) {
            res[i]=run(R[i],C[i],W[i]);
        }
        try {


            String path = "/Users/ldfrank533/BrattleShipSmall.txt";//文件保存路径、名字
            File file = new File(path);
            BufferedWriter ow = new BufferedWriter(new FileWriter(file));

            for(int i=0;i<trial;i++){

                String temp="Case "+"#"+String.valueOf(i+1)+": "+res[i];

                ow.write(temp);

                ow.newLine();
            }

            ow.close();
            System.out.println("Finished Writing");
            //System.out.println(run(23));

        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }



    }
    public static int[] getarr(String numberString){
        String[] numbers = numberString.split("\\s+");
        int[] ints = new int[numbers.length];
        for (int i = 0; i < ints.length; i++)
            ints[i] = Integer.parseInt(numbers[i]);

        return  ints;
    }
    public static int run(int R,int C, int W){
        int remainder=C%W;
        int p=(C-remainder)/W;
        int res=p*R+W;
        if(remainder==0){
            res--;
        }
        return res;
    }
}
