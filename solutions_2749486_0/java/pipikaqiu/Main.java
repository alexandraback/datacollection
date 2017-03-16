package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public int x,y;
    public int base = 400;
    public int [][] best = new int [800][800];
    public ArrayList<Status> history = new ArrayList<Status>();
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        history.add(new Status(0, 0, 1, -1, ' '));
        Status cur;
        for (int i = 0; i < 2500000; i++) {
            //System.out.println(i);
            cur = history.get(i);
            if(cur.x+base <0 || cur.y+base<0 || cur.x+base > 799 || cur.y+base >799) continue;
            if(best[cur.x+base][cur.y+base]==0 && history.size()<2500000){
                best[cur.x+base][cur.y+base] = i;
                history.add(new Status(cur.x, cur.y+cur.curStepNum, cur.curStepNum+1, i, 'N'));
                history.add(new Status(cur.x+cur.curStepNum, cur.y, cur.curStepNum+1, i, 'E'));
                history.add(new Status(cur.x-cur.curStepNum, cur.y, cur.curStepNum+1, i, 'W'));
                history.add(new Status(cur.x, cur.y-cur.curStepNum, cur.curStepNum+1, i, 'S'));
            }
//            if(cur.x!=0 && cur.y!=0 && best[cur.x+base][cur.y+base]==0)
//                best[cur.x+base][cur.y+base] = i;
//            if(cur.curStepNum - history.get(best[cur.x+base][cur.y+base]).curStepNum <= 1 && history.size()<5000000){
//                history.add(new Status(cur.x, cur.y+cur.curStepNum, cur.curStepNum+1, i, 'N'));
//                history.add(new Status(cur.x+cur.curStepNum, cur.y, cur.curStepNum+1, i, 'E'));
//                history.add(new Status(cur.x-cur.curStepNum, cur.y, cur.curStepNum+1, i, 'W'));
//                history.add(new Status(cur.x, cur.y-cur.curStepNum, cur.curStepNum+1, i, 'S'));
//            }
        }
        System.out.println(history.get(2500000).curStepNum);
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            x = Integer.parseInt(split[0]);
            y = Integer.parseInt(split[1]);
            // output
            System.out.println("Case #"+(caseNum+1)+":"+myPrint(best[x+base][y+base]));
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(myPrint(best[x+base][y+base]));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
    
    public String myPrint(int _index){
        if(_index == 0) return "";
        return myPrint(history.get(_index).lastIndex) +history.get(_index).lastStepWay;
    }
    
    public class Status{
        public int x,y,curStepNum,lastIndex;
        public char lastStepWay;
        public Status(int _x, int _y, int _curStepNum, int _lastIndex, char _lastStepWay){
            x=_x;
            y=_y;
            curStepNum = _curStepNum;
            lastIndex = _lastIndex;
            lastStepWay = _lastStepWay;
        }
    }
}