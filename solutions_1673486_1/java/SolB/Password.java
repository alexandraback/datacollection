import java.util.Scanner;

public class Password
{
    public static void main(String[] args)
    {
        Scanner jin=new Scanner(System.in);

        int rounds=jin.nextInt();
        for(int round=1; round<=rounds; round++)
        {
            int typed=jin.nextInt(), length=jin.nextInt();
            //System.out.println("Got 1st 2, expect "+length);
            double[] successLikelihood=new double[typed];

            for(int index=0; index<successLikelihood.length; index++)
                successLikelihood[index]=jin.nextDouble();

            double[] options=new double[typed+2];
            //for(int checkBack=0; checkBack<length; index++)
            //{
                double oddsFor;

                //keep typing
                oddsFor=probableSuccess(0, typed, length, successLikelihood);
                options[0]=oddsFor*(length-typed)+(1-oddsFor)*(length*2-typed+1);

                //backspace
                for(int hits=1; hits<=typed; hits++)
                {
                    oddsFor=probableSuccess(hits, typed, length, successLikelihood);
                    //System.out.println("::"+oddsFor);
                    options[hits]=oddsFor*(length-typed+hits*2)+(1-oddsFor)*(length*2-typed+hits*2+1);
                }

                //giveup
                options[options.length-1]=length+1;

                double min=length*3;
                for(double choice : options) min=Math.min(min, choice); //System.out.println(":"+choice);}

                System.out.println("Case #"+round+": "+(min+1));
            //}
        }
    }

    private static double probableSuccess(int backDigits, int typed, int length, double[] likelihoods) //probability of being correct until _ digits back
    {
        //System.out.println(backDigits+" "+likelihoods.length);
        double success=1;
        for(int index=0; index<likelihoods.length-backDigits; index++)
            success*=likelihoods[index];
        return success;
    }
}
