package gcj2014.r1c;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author scbit
 */
public class P2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P2().run();
    }
    PrintWriter pw;
static long mod=1000000007;

    void run() throws Exception{
        File infile=new File("B-large (5).in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            long result = 0;
            int N=sc.nextInt();
            if(case_i==15){
                result=0;
            }
            t.badcs=new int[256];
            List<t> ts=new ArrayList<t>();
            for(int i=0;i<N;i++){
                t tt=new t(sc.next());
                ts.add(tt);
            }
            boolean imp=false;
            for(int i=0;i<N;i++){
                t tt=ts.get(i);
                if(tt.bad){
                    imp=true;
                    break;
                }
                if(t.badcs[tt.head]>0 || t.badcs[tt.end]>0){
                    imp=true;
                    break;
                }
            }
            if(!imp){
                ccircle:     for(char curc='a';curc<='z';curc++){
                    int toui=-1,weii=-1;
                    int toucount=0,weicount=0;
                    int allcount=0;
                    
                    for(int i=0;i<ts.size();i++){
                        t tt=ts.get(i);
                        if(tt.typeall){
                            if(tt.head==curc){
                                allcount++;
                                continue;
                            }
                        }
                        if(tt.end==curc){
                            if(toucount>0){
                                imp=true;
                                break ccircle;
                            }
                            toui=i;
                            toucount++;
                        }
                        if(tt.head==curc){
                            if(weicount>0){
                                imp=true;
                                break ccircle;
                            } 
                            weii=i;
                            weicount++;
                        }
                    }
                    if(toui>-1 && toui==weii){
                        imp=true;
                        break;
                    }
                    if((toucount+weicount+allcount)>=2){
                        List<t> newts=new ArrayList<t>();
                        char mergehead=curc,mergeend=curc;
                        long mergecount=1;
                        if(toui>-1){
                            t tou=ts.get(toui);
                            mergehead=tou.head;
                            mergecount=(mergecount*tou.count) %mod;
                        }
                        if(weii>-1){
                            t wei=ts.get(weii);
                            mergeend=wei.end;
                            mergecount=(mergecount*wei.count) %mod;
                        }
                        for(int i=0;i<allcount;i++){
                            mergecount=(mergecount*(i+1)) %mod;
                        }
                        newts.add(new t(mergehead, mergeend, mergecount));
                        for (int i = 0; i < ts.size(); i++) {
                            t tt = ts.get(i);
                            if (tt.typeall) {
                                if (tt.head == curc) {
                                    continue;
                                }
                            }
                            if(i==toui) continue;
                            if(i==weii) continue;
                            newts.add(tt);
                        }
                        ts=newts;
                    }
                    
                }
            }
            if(imp){
                result=0;
            }else{
                result=1;
                for(int i=0;i<ts.size();i++){
                    result=(result*(i+1)) % mod;
                    result=(result*ts.get(i).count) % mod;
                }
            }
            String outputstr=String.format("Case #%d: %s\n", case_i,result);
            pw.printf(outputstr);
            System.out.printf(outputstr);
        }
        pw.close();
    }

}

class t{
    char head;
    char end;
    String str;
    static Pattern samep=Pattern.compile("\\A([a-z])\\Z");
    static int[] badcs=new int[256];
//    List<Character> othercs=new ArrayList<Character>();
    boolean typeall=true;; //all the same char?
    boolean bad=false;
    long count=1;
    public t(char h,char e,long c ){
        head=h;
        end=e;
        count=c;
        typeall=false;
    }
    public t(String s){
        str=s;
        head=s.charAt(0);
        end=s.charAt(s.length()-1);
        if(badcs[head]>0 || badcs[end]>0){
            bad=true;
            return;
        }
        for( int i=0;i<s.length();i++){
            if(s.charAt(i)==head){
            }else{
                typeall=false;
                break;
            }
        }
        if(typeall) return;
        int ss=0,ee=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=head){
                ss=i;
                break;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)!=end){
                ee=i;
                break;
            }
        }
        char last=' ';
        for(int i=ss;i<=ee;i++){
            char thisc=s.charAt(i);
            if(thisc==last) continue;
            if(badcs[thisc]>0){
                bad=true;
                return;
            }
            badcs[thisc]=1;
//            othercs.add(s.charAt(i));
            last=thisc;
        }
        if(head==end){
            if(!typeall){
                bad=true;
            }
        }
    }
}