import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class Osmos {
    static class Elem {
        public Elem(int size,int op) {
            this.size = size;
            this.op = op;
        }
        public int size;
        public int op;
        @Override
        public String toString() {
            return "Elem [size=" + size + ", op=" + op + "]";
        }
        
    }
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("osmos.txt"));
            int num = in.nextInt();
            for(int n = 1; n <= num; n++) {
                int ori = in.nextInt();
                int sz = in.nextInt();
                List<Integer> list = new ArrayList<Integer>();
                for(int i = 0; i < sz; i++) {
                    list.add(in.nextInt());
                }
                Collections.sort(list);
                if(ori == 1) {
                    System.out.println(String.format("Case #%d: %d", n,list.size()));
                    continue;
                }
                
                int cnt = 0;
                List<Elem> opList = new ArrayList<Elem>();
                opList.add(new Elem(ori,0));
                
                for(int i = 0; i < list.size(); i ++) {
                    int size = list.get(i);
                    //System.out.println("Sorb " + size + " with opList:" + opList.toString());
                    List<Elem> tmpList = new ArrayList<Elem>();
                    for(Elem elem : opList) {
                        if(elem.size > size) {
                            elem.size += size;
                            tmpList.add(elem);
                        } else {
                            // add 
                            Elem tmp = new Elem(elem.size,elem.op);
                            while(tmp.size <= size) {
                                tmp.op ++;
                                tmp.size = (tmp.size*2 -1); 
                            }
                            tmp.size += size;
                            tmpList.add(tmp);

                            // remove 
                            elem.op += 1;
                            tmpList.add(elem);
                        }
                    }
                    opList = tmpList;
                }
                
                int min = Integer.MAX_VALUE;
                for(Elem elem: opList) {
                    if(elem.op < min) {
                        min = elem.op;
                    }
                }
                
                System.out.println(String.format("Case #%d: %d", n,min));
                
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
