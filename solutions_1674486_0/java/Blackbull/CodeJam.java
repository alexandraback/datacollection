import java.util.*;
public class CodeJam {

	public static class Nodo{
		public int id;
		public ArrayList<Nodo> hijos;
		Nodo(int id){
			this.id=id;
			hijos= new ArrayList<Nodo>();
		}
			
	}
	public static void main(String[] args) {
		int tc,n, npadres;
		ArrayList<Nodo> cola= new ArrayList<Nodo>();
		ArrayList<Nodo> elegibles= new ArrayList<Nodo>();
		
		Scanner sc= new Scanner(System.in);
		tc=sc.nextInt();
		for(int t=1; t<=tc; t++){
			cola.clear();
			elegibles.clear();
			n= sc.nextInt();
			boolean[] hash= new boolean[n+1];			
			Nodo[] nodos= new Nodo[n+1];
			boolean diam=false;
			for(int nodo=1; nodo<=n; nodo++){
				nodos[nodo]= new Nodo(nodo);				
			}
			for(int i=1; i<=n; i++){
				npadres=sc.nextInt();
				for(int padre=0; padre<npadres; padre++)
					nodos[sc.nextInt()].hijos.add(nodos[i]);
			}
			for(int pos=1; pos<=n; pos++)
				if(nodos[pos].hijos.size()>=2)
					elegibles.add(nodos[pos]);
			for(Nodo nodo: elegibles){
				for(Nodo no: nodo.hijos)
					cola.add(no);
				while(!cola.isEmpty()){
					Nodo actual=cola.remove(0);
					//System.out.println("El nodo actual es: "+ actual.id);					
					if(hash[actual.id]){
						diam=true;
						break;					
					}
					else
						hash[actual.id]=true;
					for(Nodo no2: actual.hijos)
						cola.add(no2);					
				}
				for(int i=1; i<=n; i++)
					hash[i]=false;
			}
			if(diam)
				System.out.println("Case #"+t+": Yes");
			else
				System.out.println("Case #"+t+": No");
		}
		
	}

}
