public class JamCoin
{
    private int[] digitsOrig;
    private int n;
    private long[] divisors = new long[9];
    
    JamCoin(int n)
    {
        this.n = n;
        
        //Initialize the array of 1s and 0s
        this.digitsOrig = new int[n];
        this.digitsOrig[0] = 1;
        for(int i = 1; i < (n-1); i++) this.digitsOrig[i] = 0;
        this.digitsOrig[n-1] = 1;
        
        //Calculate array of 9 initial divisors
        for(int i = 0; i < 9; i++) this.divisors[i] = findDivisor(coinBaseB(i+2));
    }
    
    public void incrementJam()
    {
        long binaryJam = coinBaseB(2);
        binaryJam += 2;
        //System.out.println("incrementing...");
        for(int i = 0; i < this.n; i++)
        {
            //System.out.println("for loop...");
            //System.out.println(binaryJam);
            digitsOrig[this.n - i - 1] = (int) binaryJam%2;
            binaryJam = binaryJam / 2;
        }
        
        //Calculate array of 9 initial divisors
        for(int i = 0; i < 9; i++) this.divisors[i] = findDivisor(coinBaseB(i+2));        
    }
    
    private long findDivisor(long input)
    {
        int thresh = (int) Math.sqrt(input) + 1;
        for(int i = 2; i < thresh; i++)
        {
            if(input%i == 0) return i;
        }
        return -1;
    }

    public long coinBaseB(int b)
    {
        long output = 0;
        long baseValue = 1;
        for(int i = 0; i < this.n; i++)
        {
            output += digitsOrig[this.n - i - 1]*baseValue;
            baseValue *= b;
        }
        return output;
    }
    
    public boolean isValidJam()
    {
        for(int i = 0; i < 9; i++)
        {
            if(this.divisors[i] == -1) return false;
        }
        return true;
    }
    
    public String divisorString()
    {
        String output = "";
        for(int i = 0; i < 9; i++) output += (this.divisors[i] + " ");
        return output;
    }
    
    public String toString()
    {
        String output = "";
        for(int i = 0; i < digitsOrig.length; i++) output += digitsOrig[i];
        return output;
    }
}