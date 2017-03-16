package google2012.qualy;

public class QualyCTupla {
	int cont=0;
	int max=-1;
	int b;
	
	public QualyCTupla(int b) {
		this.b = b;
	}

	public void reset(int b) {
		this.b = b;
		cont = 0;
		max = -1;
	}
}
