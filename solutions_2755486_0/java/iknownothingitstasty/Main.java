import java.io.*;
import java.util.*;
class ComparatorUser implements Comparator{
	public int compare(Object arg0, Object arg1){
		return ((int[])arg0)[0] - ((int[])arg1)[0];
	}
}
public class  Main
{
	
	public static void main(String[] args) throws FileNotFoundException 
	{
	    FileInputStream psi = null;
	    PrintStream pso = null;
	    Scanner sc = null;
	    int num = 0;
	    byte[][] mtx = new byte[4][4];
	    psi = new FileInputStream("D:\\Users\\Rophyll\\Downloads\\C-small-attempt0.in");
		pso = new PrintStream(new FileOutputStream("D:\\Users\\Rophyll\\Downloads\\out1.in"));
		System.setIn(psi);
		System.setOut(pso);
		sc = new Scanner(System.in);
		
		num = sc.nextInt();
		for(int x = 0; x < num; x++){//each case
			int n = sc.nextInt();
			int[][] tribes = new int[n][8];
			List<int[]> attacks = new ArrayList<int[]>();
			for(int j = 0;j < n; j++)
				for(int k = 0; k < 8; k++)
					tribes[j][k] = sc.nextInt();
			for(int j = 0; j < n; j++){
				for(int k = 0; k < tribes[j][1]; k++){
					int[] attack = new int[4];
					attack[0] = tribes[j][0]+k*tribes[j][5];
					attack[1] = tribes[j][2]+k*tribes[j][6];
					attack[2] = tribes[j][3]+k*tribes[j][6];
					attack[0] = tribes[j][4]+k*tribes[j][7];
					attacks.add(attack);
				}
			}
			ComparatorUser comparator = new ComparatorUser();
			Collections.sort(attacks, comparator);
			Map wall = new HashMap();
			Map rec = new HashMap();
			int count = 0;
			for(int i = 0; i < attacks.size(); i++){
				boolean flag = false;
				for(int p = attacks.get(i)[1]; p < attacks.get(i)[2]; p++){
					if(!wall.containsKey(p) || (int)wall.get(p) < attacks.get(i)[3]){
						if(!rec.containsKey(p) || (int)rec.get(p) < attacks.get(i)[3]){
							rec.put(p, attacks.get(i)[3]);
						}
						flag = true;
					}
				}
				if(flag)
					count++;
				if(i == attacks.size() - 1 || attacks.get(i+1)[0] != attacks.get(i)[0]){
					Iterator it = rec.entrySet().iterator();
					while(it.hasNext()){
						Map.Entry entry = (Map.Entry)it.next();
						wall.put(entry.getKey(), entry.getValue());
					}
					rec = new HashMap();
				}
			}
			
			System.out.println("Case #"+(x+1)+": "+count);// + calc(mtx));
		}
	}
}