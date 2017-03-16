
package codejam_2014_qualification_4;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Codejam_2014_Qualification_4
{
    private static int T;
    private static int N;
    private static List<Double> Naomi_Fair;
    private static List<Double> Ken_Fair;
    private static final String filename = "D-small-attempt0";
    public static void main(String[] args)
    {
        String file_content = read_file(filename + ".in");
        try
        {
            PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
            Scanner sc = new Scanner(file_content);
            T = sc.nextInt();
            for(int t=0; t<T; t++)
            {
                Naomi_Fair = new ArrayList<Double>();
                Ken_Fair = new ArrayList<Double>();
                N = sc.nextInt();
                for(int i=0; i<N; i++)
                    Naomi_Fair.add(sc.nextDouble());
                for(int i=0; i<N; i++)
                    Ken_Fair.add(sc.nextDouble());
                Collections.sort(Naomi_Fair);
                Collections.sort(Ken_Fair);
                List<Double> Naomi_Cheat = new ArrayList<Double>(Naomi_Fair);
                List<Double> Ken_Cheat = new ArrayList<Double>(Ken_Fair);
                int fair_wins = 0;
                while(!Naomi_Fair.isEmpty())
                {
                    if(Naomi_Fair.get(Naomi_Fair.size()-1)>Ken_Fair.get(Ken_Fair.size()-1))
                    {
                        fair_wins++;
                        Ken_Fair.remove(0);
                    }
                    else
                    {
                        for(int i=Ken_Fair.size()-1; i>=0; i--)
                        {
                            if(Ken_Fair.get(i)<Naomi_Fair.get(Naomi_Fair.size()-1))
                            {
                                Ken_Fair.remove(i+1);
                                break;
                            }
                        }
                    }
                    Naomi_Fair.remove(Naomi_Fair.size()-1);
                }
                while(!Naomi_Cheat.isEmpty() && Naomi_Cheat.get(Naomi_Cheat.size()-1)<Ken_Cheat.get(Ken_Cheat.size()-1))
                {
                    Naomi_Cheat.remove(0);
                    Ken_Cheat.remove(Ken_Cheat.size()-1);
                }
                /*
                for(int i=0; i<Naomi_Cheat.size(); i++)
                    System.out.print(Naomi_Cheat.get(i) + " ");
                System.out.print(" --- ");
                for(int i=0; i<Ken_Cheat.size(); i++)
                    System.out.print(Ken_Cheat.get(i) + " ");
                System.out.println();
                        */
                int cheat_wins=0;
                while(!Naomi_Cheat.isEmpty() && Naomi_Cheat.get(Naomi_Cheat.size()-1)>Ken_Cheat.get(Ken_Cheat.size()-1))
                {
                    for(int i=0; i<Naomi_Cheat.size(); i++)
                    {
                        if(Naomi_Cheat.get(i)>Ken_Cheat.get(0))
                        {
                            cheat_wins++;
                            Naomi_Cheat.remove(i);
                            Ken_Cheat.remove(0);
                            break;
                        }
                    }
                    /*
                    for(int i=0; i<Naomi_Cheat.size(); i++)
                        System.out.print(Naomi_Cheat.get(i) + " ");
                    System.out.print(" --- ");
                    for(int i=0; i<Ken_Cheat.size(); i++)
                        System.out.print(Ken_Cheat.get(i) + " ");
                    System.out.println();
                            */
                }
                writer.println("Case #" + (t + 1) + ": " + cheat_wins + " " + fair_wins);
            }
            writer.close();
            sc.close();
        } catch(InputMismatchException imme) {
        } catch(FileNotFoundException e) {
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Codejam_2014_Qualification_4.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    private static String read_file(String f)
    {
        String file_content = "";
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(f));
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();
            while (line != null)
            {
                sb.append(line);
                sb.append("\n");
                line = br.readLine();
            }
            file_content = sb.toString();
        } catch (FileNotFoundException e) {
        } catch (IOException ex) {
            Logger.getLogger(Codejam_2014_Qualification_4.class.getName()).log(Level.SEVERE, null, ex);
        }
        return file_content;
    }
}

