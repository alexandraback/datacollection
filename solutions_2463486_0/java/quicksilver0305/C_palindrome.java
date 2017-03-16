package gcj2013;


public class C_palindrome {
	int digit;
	int[] pal;
	
	public C_palindrome(int maxdigit) {
		this.digit = 1;
		this.pal   = new int[maxdigit*2];

		// Set "1" as Initial Value 
		for(int i=0; i<maxdigit*2; i++){
			pal[i]   = 0;
		}
		pal[0] = 1;
	}

	public void inc(){
		int i;
		int[] carry = new int[digit+2];
		
		Boolean full = true;

		//Initialization
		for(i=0; i<digit+1; i++){
			carry[i] = 0;
		}
		
		//Digit Check
		for(i=0; i<digit; i++){
			if(pal[i] != 9){ full = false; }
		}
		
		//Digit Overflow Case
		if(full){
			for(i=0; i<digit; i++){
				pal[i] = 0;
			}
			pal[digit] = 1;
			digit++;
		}
		//Normal Increment Case
		else{
			pal[digit/2]++;
		}
		
		//check Carryover
		for(i=digit/2; i<digit; i++){
			pal[i] += carry[i];
			if(pal[i]>9){
				carry[i+1] = pal[i]/10;
				pal[i]   = pal[i]%10;
			}
			else{
				carry[i+1] = 0;
			}
		}
		
		//mirror to Lower Digit
		for(i=0; i<digit/2; i++){
			pal[i] = pal[digit-i-1];
		}
	}	
	public String square(){
		int i,j;
		int[] square = new int[2*digit];
		int[] carry  = new int[2*digit+1];
		
		String str = "";
		
		//Initialization
		for(i=0; i<2*digit; i++){
			carry[i]  = 0;
			square[i] = 0;
		}
		carry[2*digit] = 0;
		
		for(i=0; i<digit; i++){
			for(j=0; j<digit; j++){
				square[i+j] += pal[i]*pal[j];
			}
		}
				
		//check Carryover
		for(i=0; i<2*digit; i++){
			square[i] += carry[i];
			if(square[i]>9){
				carry[i+1] = square[i]/10;
				square[i]  = square[i]%10;
			}
			else{
				carry[i+1] = 0;
			}
		}
		
		//return Number
		if(square[2*digit-1] == 0) {str = ""; }
		else                       {str = String.valueOf(square[2*digit-1]);} 
		for(i=1; i<2*digit; i++){
			str += String.valueOf(square[2*digit-1-i]);
		}
		
		return str;
	}	
	
}
