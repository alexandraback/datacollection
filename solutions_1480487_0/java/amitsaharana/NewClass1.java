import java.io.*;
import java.util.*;
public class NewClass1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int z=0; z<t; z++) {
            StringTokenizer st  = new StringTokenizer(br.readLine()," ");
            int n = Integer.parseInt(st.nextToken());
            a[] a  = new a[n];
            double tot = 0;
            for(int j=0; j<n; j++) {
                a[j] = new a();
                a[j].d = Double.parseDouble(st.nextToken());
                a[j].i = j;
                tot+=a[j].d;
            }
            Arrays.sort(a, new b());
            double pointrem = tot;
            int i=1;
            for(; i<n; i++) {
                double temp = a[i-1].d;
                if(((a[i].d-temp)*i)>pointrem) break;
                pointrem -= ((a[i].d-temp)*i);
                //System.out.println(pointrem+" "+temp+" "+ans[i-1]);
                for(int j=(i-1); j>=0; j--) {
                    a[j].ans += (a[i].d-temp)/tot;
                    a[j].d = a[i].d;
                }
            }
            double toAdd = pointrem/(i*tot);
            //System.out.println(toAdd+" "+i);
            for(int j=0; j<i; j++) {
                a[j].ans+=toAdd;
                a[j].d +=pointrem/i;
            }
            Arrays.sort(a,new c());
            System.out.print("Case #"+(z+1)+": ");
            for(int k=0; k<n; k++) {
                
                System.out.print((a[k].ans*100)+" ");
            }
            
            System.out.println();
        }
    }
}
class a {
    double d=0;
    int i=0;
    double ans=0;
}
class b implements Comparator<a> {

    @Override
    public int compare(a o1, a o2) {
        if(o1.d<o2.d) return -1;
        if(o1.d>o2.d) return 1;
        return 0;
    }
    
}
class c implements Comparator<a> {

    @Override
    public int compare(a o1, a o2) {
        if(o1.i<o2.i) return -1;
        if(o1.i>o2.i) return 1;
        return 0;
    }
    
}