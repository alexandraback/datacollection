
public class Quaternion {
	private final int x0, x1, x2, x3; 

    // create a new object with the given components
    public Quaternion(int x0, int x1, int x2, int x3) {
        this.x0 = x0;
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
    }
    public Quaternion times(Quaternion b) {
        Quaternion a = this;
        int y0 = a.x0*b.x0 - a.x1*b.x1 - a.x2*b.x2 - a.x3*b.x3;
        int y1 = a.x0*b.x1 + a.x1*b.x0 + a.x2*b.x3 - a.x3*b.x2;
        int y2 = a.x0*b.x2 - a.x1*b.x3 + a.x2*b.x0 + a.x3*b.x1;
        int y3 = a.x0*b.x3 + a.x1*b.x2 - a.x2*b.x1 + a.x3*b.x0;
        return new Quaternion(y0, y1, y2, y3);
    }
    public Quaternion power(int n){
    	Quaternion product = new Quaternion(1,0,0,0);
    	for(int i = 0; i < n; i++){
    		product = this.times(product);
    	}
    	return product;
    }
    public boolean egal(Quaternion b) {
       return this.x0==b.x0&&this.x1==b.x1&&this.x2==b.x2&&this.x3==b.x3;
   }
    
    public String toString() {
        return x0 + " + " + x1 + "i + " + x2 + "j + " + x3 + "k";
    }
}
