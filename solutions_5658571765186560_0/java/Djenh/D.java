package Qualification_2015;

import java.util.Scanner;

/**
 *
 * @author utilisateur
 */
public class Ominous_Omino {
    public static void main (String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int nbTest, ominoX, ligne, colonne, reste;
        String resultat="";
        
        nbTest = sc.nextInt();
        
        for (int p=0; p<nbTest; p++)
        {
            ominoX = sc.nextInt();
            ligne = sc.nextInt();
            colonne = sc.nextInt();
            
            reste = (ligne*colonne)%ominoX ;
            
            if (reste !=0)
                resultat = "RICHARD" ;
            
            else if (( (ominoX-1)> ligne)  || (ominoX-1)>colonne)
                resultat="RICHARD";
            
            else
                resultat = "GABRIEL";
                    
            
            
            System.out.println("Case #"+(p+1)+": "+resultat);
        }
    }
}
