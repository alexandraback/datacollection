package gcjr1bpa;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        //VARIABLES
        Integer T=new Integer(0);
        ArrayList<Integer> N=new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> S=new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> SUM=new ArrayList<Integer>();
        ArrayList<ArrayList<Double>> M=new ArrayList<ArrayList<Double>>();
        //LEO
        File archin=new File(args[0]);
        FileReader in=null;
        BufferedReader bin=null;
        try{
            in=new FileReader(archin);
            bin=new BufferedReader(in);
            T=Integer.parseInt(bin.readLine());
            StringTokenizer st;
            for(int i=0;i<T;i++){
                st=new StringTokenizer(bin.readLine());
                N.add(Integer.parseInt(st.nextToken()));
                S.add(new ArrayList<Integer>());
                SUM.add(new Integer(0));
                for(int j=0;j<N.get(i);j++){
                    S.get(i).add(Integer.parseInt(st.nextToken()));
                    SUM.set(i,SUM.get(i)+S.get(i).get(j));
                }
            }
        }catch(Exception ex){
        }finally{
            try{
                bin.close();
            }catch(Exception ex){
            }
            try{
                in.close();
            }catch(Exception ex){
            }
        }
        //PROCESO
        for(int i=0;i<T;i++){
            M.add(new ArrayList<Double>());
            Integer NN=new Integer(N.get(i));
            Integer suma=new Integer(2*SUM.get(i));
            ArrayList<Boolean> yaesta=new ArrayList<Boolean>();
            for(int j=0;j<N.get(i);j++){
                M.get(i).add((100.0*(double)(suma-NN*S.get(i).get(j)))/((double)(NN*SUM.get(i))));
                yaesta.add(false);
            }
            boolean cambio=true;
            while(cambio){
                cambio=false;
                for(int j=0;j<N.get(i);j++){
                    if((M.get(i).get(j)<0)&&!yaesta.get(j)){
                        suma=suma-S.get(i).get(j);
                        NN=NN-1;
                        M.get(i).set(j, new Double(0.0));
                        cambio=true;
                        yaesta.set(j, true);
                        for(int k=0;k<N.get(i);k++){
                            if(!yaesta.get(k)){
                                M.get(i).set(k,(100.0*(double)(suma-NN*S.get(i).get(k)))/((double)(NN*SUM.get(i))));
                            }
                        }
                        break;
                    }
                }
            }
        }
        //ESCRIBO
        File archout=new File("out.txt");
        FileWriter out=null;
        BufferedWriter bout=null;
        try{
            out=new FileWriter(archout);
            bout=new BufferedWriter(out);
            for(int i=0;i<T;i++){
                bout.write("Case #"+(i+1)+":");
                for(int j=0;j<N.get(i);j++){
                    bout.write(" "+M.get(i).get(j));
                }
                bout.newLine();
            }
        }catch(Exception ex){
        }finally{
            try{
                bout.close();
            }catch(Exception ex){
            }
            try{
                out.close();
            }catch(Exception ex){
            }
        }
    }
}