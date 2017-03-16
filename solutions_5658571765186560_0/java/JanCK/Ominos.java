package nickname.jck.googlecodejam.cj2015.q1.ominos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import nickname.jck.googlecodejam.cj2015.q1.StandingOvation;

public class Ominos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		//String filenameInput = "A-sample.in";
		//String filenameOutput = "A-sample.out";

		String filenameInput = "D-small-attempt0.in";
		String filenameOutput = "D-small-attempt0.out";

		// String filenameInput = "A-large.in";
		// String filenameOutput = "A-large.out";

		Class currentClass = Ominos.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				int friendsToInvite = 0;
				String[] inputStringArray = input.readLine().split(" ");
				int X = Integer.parseInt(inputStringArray[0]);
				int R = Integer.parseInt(inputStringArray[1]);
				int C = Integer.parseInt(inputStringArray[2]);

				boolean canGabrielWin = true;
				//System.out.println("X " + X + " R " + R + " C " + C);
				if(R*C % X != 0){
					//the X-minos don't fit just by counting the squares.
					canGabrielWin = false;
					//System.out.println("product not divisible");
				}
				if (X >= 7) {
					canGabrielWin = false;
					// Richard chooses this 7-mino or some larger X-mino with
					// the same kind of hole:
					// ***
					// * *
					// **
					// and Gabriel can never will the hole

				}
				if (X == 6) {
					if (C == 1 || C == 2 || C == 3 || R == 1 || R == 2
							|| R == 3)
						canGabrielWin = false;
					// Richard chooses this 6-mino:
					// **
					// **
					// *
					// *
					// this is too big, if either of the R or C is <= 2
					// if R or C is 3, it's not working either
					// say R = 3 then Gabriel has to lay the element for example
					// like this
					// *
					// ****
					// *
					// to the left of this elment is a number of free squares
					// that is divisable by three.
					// Adding the field that is marked with an X
					// *
					// ****
					// X*
					// gives a number that is 1 mod 3. This is not divisable by
					// 6.
				}
				if (X == 5) {
					if (C == 1 || C == 2 || R == 1 || R == 2) {
						canGabrielWin = false;
					}
					if (C == 3 && R == 5) {
						canGabrielWin = false;
					}
					if (C == 5 && R == 3) {
						canGabrielWin = false;
					}
					// Richard chooses this 5-mino:
					// **
					//  **
					//   *
					// this is too big, if either of the R or C is <= 2
					// if R == 3 and C == 5 or the other way round, it's not working either
					// say R = 3 then 
					// to the right of this elment is a number of free squares
					// that is divisable by three.
					// Adding the field that is marked with an X
					// **X
					//  **
					//   *
					// gives a number that is 1 mod 3. This is not divisable by
					// 5 if there are not atleast 3 columns to the right of the element.
					// This is not possible for a 3-by-5 grid as the element take 3 columns itself
					// The same argument goes for every rotation or mirroring of the element.
				}
				if (X == 4) {
					if (C == 1 || C == 2 || R == 1 || R == 2) {
						canGabrielWin = false;
					}
					// Richard chooses this 4-mino:
					// ***
					//  *
					// this is too big, if either of the R or C is < 2
					// if R == 2 or C == 2, it's not working either
					// say R = 2 then 
					// to the right of this elment is a number of free squares
					// that is divisable by 2.
					// Adding the field that is marked with an X
					// ***
					//  *X
					// gives a number that is 1 mod 2. This is not divisable by
					// 4 
					// The same argument goes for every rotation or mirroring of the element.
				}
				if (X == 3) {
					if (C == 1  || R == 1 ) {
						canGabrielWin = false;
					}
					// Richard chooses this 3-mino:
					// **
					//  *
					// this is too big, if either of the R or C is < 2
				}

				String outputString = "Case #" + (i + 1) + ": "
						+ (canGabrielWin ? "GABRIEL" : "RICHARD");
				System.out.println(outputString);

				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
