/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamproject;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Jeje
 */
public class ReorderingTrainCars {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        FileInputStream handle = new FileInputStream("A-small-practice.in");
        FileOutputStream handle2 = new FileOutputStream("A-small-practice.out");
        BufferedReader reader = new BufferedReader(new InputStreamReader(handle));

        int nombreDeTests = Integer.parseInt(reader.readLine());

        for (int j = 0; j < nombreDeTests; j++) {
            int nombreWagons = Integer.parseInt(reader.readLine());
            String listeWagons = reader.readLine();
            String[] listeWagonsSplitted = listeWagons.split(" ");

            long nvalue = result(listeWagonsSplitted, nombreWagons);

            int nouveauJ = j + 1;
            handle2.write(("Case #" + nouveauJ + ": " + nvalue + "\n").getBytes());
        }
    }

    public static long result(String[] listeWagons, int nombreWagons) {
        long compteur=0;
        
        int []tableau=new int[nombreWagons];
        for(int i=0;i<nombreWagons;i++){
            tableau[i]=i;
        }
        for(int j=0;j<factorial(nombreWagons);j++){
            String chaine="";
            for(int i=0;i<nombreWagons;i++){
                chaine+=listeWagons[tableau[i]];
            }
            if(isValid(chaine)){
                compteur++;
            }
            nextPermutation(tableau);
        }
        
        return compteur;
    }
    
    public static boolean isValid(String uneChaine){
        List<Character>nonValides=new ArrayList<Character>();
        char ancienCaractereEnCours=uneChaine.charAt(0);
        for(int i=1;i<uneChaine.length();i++){
            if(uneChaine.charAt(i)==ancienCaractereEnCours){
            }
            else{
                if(nonValides.contains(uneChaine.charAt(i))){
                    return false;
                }
                nonValides.add(ancienCaractereEnCours);
                ancienCaractereEnCours=uneChaine.charAt(i);
            }
        }
        return true;
    }
    
    static boolean nextPermutation(int[] array) {
    // Find longest non-increasing suffix
    int i = array.length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i == 0)
        return false;
    
    // Let array[i - 1] be the pivot
    // Find rightmost element that exceeds the pivot
    int j = array.length - 1;
    while (array[j] <= array[i - 1])
        j--;
    // Now the value array[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    
    // Reverse the suffix
    j = array.length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    
    // Successfully computed the next permutation
    return true;
}
    
  public static List<List<Integer>> generatePerm(List<Integer> original) {
     if (original.size() == 0) { 
       List<List<Integer>> result = new ArrayList<List<Integer>>();
       result.add(new ArrayList<Integer>());
       return result;
     }
     Integer firstElement = original.remove(0);
     List<List<Integer>> returnValue = new ArrayList<List<Integer>>();
     List<List<Integer>> permutations = generatePerm(original);
     for (List<Integer> smallerPermutated : permutations) {
       for (int index=0; index <= smallerPermutated.size(); index++) {
         List<Integer> temp = new ArrayList<Integer>(smallerPermutated);
         temp.add(index, firstElement);
         returnValue.add(temp);
       }
     }
     return returnValue;
   }

    public static String nextPermutation(String unePermutation) {
        int taille = unePermutation.length();
        if (taille == 2) {
            if (unePermutation.charAt(0) < unePermutation.charAt(1)) {
                return unePermutation.charAt(1) + "" + unePermutation.charAt(0);
            }
            return unePermutation;
        }
        String subNext = nextPermutation(unePermutation.substring(1));
        if (!subNext.equals(unePermutation.substring(1))) {
            return unePermutation.charAt(0) + subNext;
        } else {
            char max = maximumParmi(unePermutation);
            char first = unePermutation.charAt(0);
            if (first == max) {
                return unePermutation;
            }
            char suivant = suivantParmi(unePermutation, first);
            return suivant + minimumPermutationSansElement(unePermutation, suivant);
        }
    }

    public static String minimumPermutationSansElement(String unePermutation, char unElement) {
        if (unePermutation.length() > 1) {
            char min = minimumHormis(unePermutation, unElement);
            String nouvelleChaine = unePermutation.replace("" + min, "");
            return min + minimumPermutationSansElement(nouvelleChaine, unElement);
        }
        return "";
    }

    public static char minimumHormis(String unePermutation, char unElement) {
        char minimum;
        if (unePermutation.charAt(0) != unElement) {
            minimum = unePermutation.charAt(0);
        } else {
            minimum = unePermutation.charAt(1);
        }
        for (int i = 0; i < unePermutation.length(); i++) {
            if (unePermutation.charAt(i) != unElement && unePermutation.charAt(i) < minimum) {
                minimum = unePermutation.charAt(i);
            }
        }
        return minimum;
    }

    public static char maximumParmi(String unePermutation) {
        char maximum = unePermutation.charAt(0);
        for (int i = 1; i < unePermutation.length(); i++) {
            if (unePermutation.charAt(i) > maximum) {
                maximum = unePermutation.charAt(i);
            }
        }
        return maximum;
    }

    public static char suivantParmi(String unePermutation, char unElement) {
        char candidat = '0';
        for (int i = 1; i < unePermutation.length(); i++) {
            if (unePermutation.charAt(i) > unElement && (candidat == '0' || unePermutation.charAt(i) < candidat)) {
                candidat = unePermutation.charAt(i);
            }
        }
        return candidat;
    }

    public static int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    public static List<Integer> indicesDesWagonsCommencantParHormisLesIndicesDejaPris(char unCaractere, String[] listeWagons, int nombreWagons, List<Integer> uneListeDIndicesAProscrire) {
        List<Integer> listeIndices = new ArrayList<>();
        for (int i = 0; i < nombreWagons; i++) {
            if (!uneListeDIndicesAProscrire.contains(i) && listeWagons[i].charAt(0) == unCaractere) {
                listeIndices.add(i);
            }
        }
        if (listeIndices.isEmpty()) {
            return null;
        }
        return listeIndices;
    }

}
