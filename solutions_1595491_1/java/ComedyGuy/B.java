import java.util.Scanner;

public class B {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int testCount = scanner.nextInt();
        for (int test = 1; test <= testCount; test++){
            int numGooglers = scanner.nextInt();
            int numSurprise = scanner.nextInt();
            int cutScore = scanner.nextInt();
            int qtdePass = 0;
            for (int pointsCount = 0; pointsCount<numGooglers;pointsCount++){
                int points = scanner.nextInt();
                int testMinor= points/3;
                int testDist= points%3;

                if (testMinor>=cutScore) {
                    qtdePass+=1;
                    continue;
                }

                if(testMinor<cutScore && testDist>0){
                    if(testMinor+1 >= cutScore){
                        qtdePass+=1;
                        testDist-=1;
                        continue;
                    } else{
                        if(testMinor+2>=cutScore && testDist>=2 && numSurprise>0) {
                            qtdePass+=1;
                            numSurprise-=1;
                            testDist-=1;
                            continue;
                        }
                    }
                }

                if(testMinor<cutScore && testDist==0 && testMinor!=0){
                    if(testMinor+1 >= cutScore && numSurprise>0){
                        qtdePass+=1;
                        numSurprise-=1;
                        continue;
                    }
                }

            }

            System.out.println("Case #" + (test) + ": "+qtdePass);
        }
    }
}
