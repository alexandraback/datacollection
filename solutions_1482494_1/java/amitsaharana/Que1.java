import java.io.*;
import java.util.*;
public class Que1 {
    public static LinkedList<l> data;
    public static long r;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int z=1; z<=t; z++) {
            int n = Integer.parseInt(br.readLine());
            data = new LinkedList<l>();
            for(int i=0; i<n; i++) 
            {
                StringTokenizer st = new StringTokenizer(br.readLine()," ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                l temp = new l();
                temp.a = a;
                temp.b = b;
                data.add(temp);
            }
            r = 0; long tot = 0;
            boolean p = false;
            while(data.size()>0) {
                int temp = find();
                if(temp<0) {
                    p = true;
                    break;
                }  
                l ob = data.get(temp);
                //System.out.println(ob.a+" "+ob.b+" "+ob.c+" "+r+" "+tot);
                if(ob.c)
                {
                    r+=1;
                    tot+=1;
                    data.remove(temp);
                    
                }
                else 
                {
                    if(ob.b<=r){
                        r+=2;
                        tot+=1;
                        data.remove(temp);
                    }
                    else 
                    {
                        r+=1;
                        tot+=1;
                        ob.c = true;
                    }
                }
            }
            System.out.print("Case #"+z+": ");
            if(p) {
                System.out.println("Too Bad");
                
            }
            else {
                System.out.println(tot);
            }
        }
    }
    public static int find()
    {
        LinkedList<Integer> temp1 = new LinkedList<Integer>();
        for(int i=0; i<data.size(); i++) {
            l ob = data.get(i);
            if(ob.b<=r) return i;
            if(ob.c && ob.b>r) continue;
            if(ob.a<=r) temp1.add(i);
        }
        
        if(temp1.size()<=0) return -1;
        int max = temp1.get(0);
        for(int i: temp1) 
        {
            l ob = data.get(i);
            if(ob.b>=data.get(max).b) {
                max = i;
            }
        }
        return max;
    }
}
class l
{
    boolean c = false;
    int a = 0;
    int b = 0;
}