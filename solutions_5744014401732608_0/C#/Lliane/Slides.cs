using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.R1C2016
{
    class Slides
    {
        public static void Run(System.Windows.Forms.TextBox inputTB, System.Windows.Forms.TextBox outputTB, System.Windows.Forms.TextBox debugTB)
        {

            int nbCases = int.Parse(inputTB.Lines.First());

            for (int i = 0; i < nbCases; i++)
            {
                var dico = new Dictionary<String, Int32>();                
                var Nb = inputTB.Lines[i + 1].Split(' ');
                
                outputTB.Text += ("Case #" + (i + 1) + ": "+Slide(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]))+"\r\n");
            
                continue;
            }
        }

        private static string Slide(Int32 B, Int32 M)
        {
            if (B == 2)
            {
                if (M == 1)
                {
                    return "POSSIBLE\r\n"+
                        "01" + "\r\n" +
                        "00";
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }
            else if (B == 3)
            {
                if (M == 1)
                {
                    return "POSSIBLE\r\n" + 
                        "001" + "\r\n" +
                        "000" + "\r\n" +
                        "000";
                }
                else if (M == 2)
                {
                    return "POSSIBLE\r\n" + 
                        "011" + "\r\n" +
                        "001" + "\r\n" +
                        "000";
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }
            else if (B == 4)
            {
                if (M == 1)
                {
                    return "POSSIBLE\r\n" + 
                        "0001" + "\r\n" +
                        "0000" + "\r\n" +
                        "0000" + "\r\n" +
                        "0000";
                }
                else if (M == 2)
                {
                    return
                        "POSSIBLE\r\n" + 
                        "0011" + "\r\n" +
                        "0000" + "\r\n" +
                        "0001" + "\r\n" +
                        "0000";
                }
                else if (M == 3)
                {
                    return "POSSIBLE\r\n" + 
                        "0111" + "\r\n" +
                        "0001" + "\r\n" +
                        "0001" + "\r\n" +
                        "0000";
                }
                else if (M == 4)
                {
                    return "POSSIBLE\r\n" + 
                        "0111" + "\r\n" +
                        "0011" + "\r\n" +
                        "0001" + "\r\n" +
                        "0000";
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }
            else if (B == 5)
            {
                if (M == 1)
                {
                    return "POSSIBLE\r\n" + 
                        "00001" + "\r\n" +
                        "00000" + "\r\n" +
                        "00000" + "\r\n" +
                        "00000" + "\r\n" +
                        "00000";
                }
                else if (M == 2)
                {
                    return "POSSIBLE\r\n" + 
                        "00011" + "\r\n" +
                        "00000" + "\r\n" +
                        "00000" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }

                else if (M == 3)
                {
                    return "POSSIBLE\r\n" + 
                        "00111" + "\r\n" +
                        "00000" + "\r\n" +
                        "00001" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }
                else if (M == 4)
                {
                    return "POSSIBLE\r\n" + 
                        "01111" + "\r\n" +
                        "00001" + "\r\n" +
                        "00001" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }
                else if (M == 5)
                {
                    return "POSSIBLE\r\n" + 
                        "01111" + "\r\n" +
                        "00001" + "\r\n" +
                        "00011" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }
                else if (M == 6)
                {
                    return "POSSIBLE\r\n" + 
                        "01111" + "\r\n" +
                        "00011" + "\r\n" +
                        "00011" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }
                else if (M == 7)
                {
                    return "POSSIBLE\r\n" +
                        "01111" + "\r\n" +
                        "00110" + "\r\n" +
                        "00011" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }         
                else if (M == 8)
                {
                    return "POSSIBLE\r\n" + 
                        "01111" + "\r\n" +
                        "00111" + "\r\n" +
                        "00011" + "\r\n" +
                        "00001" + "\r\n" +
                        "00000";
                }                
                else
                {
                    return "IMPOSSIBLE";
                }
            }
            else if (B == 6)
            {
                if (M == 1)
                {
                    return "POSSIBLE\r\n" + 
                        "000001" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000";
                }
                else if (M == 2)
                {
                    return
                        "POSSIBLE\r\n" + 
                        "000011" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }

                else if (M == 3)
                {
                    return "POSSIBLE\r\n" + 
                        "000111" + "\r\n" +
                        "000000" + "\r\n" +
                        "000000" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +                        
                        "000000";
                }
                else if (M == 4)
                {
                    return "POSSIBLE\r\n" + 
                        "001111" + "\r\n" +
                        "000000" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 5)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 6)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000001" + "\r\n" +
                        "000001" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 7)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000001" + "\r\n" +
                        "000011" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 8)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000011" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 9)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000010" + "\r\n" +
                        "000111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 10)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 11)
                {
                    return "POSSIBLE\r\n" +
                        "011111" + "\r\n" +
                        "000110" + "\r\n" +
                        "000111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 12)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                        "000111" + "\r\n" +
                        "000111" + "\r\n" +
                        "000011" + "\r\n" +
                        "000001" + "\r\n" +
                        "000000";
                }
                else if (M == 13)
                {
                    return "POSSIBLE\r\n" +
                        "011111" + "\r\n" +
                            "001110" + "\r\n" +
                            "000110" + "\r\n" +
                            "000011" + "\r\n" +
                            "000001" + "\r\n" +
                            "000000";
                }
                else if (M == 14)
                {
                    return "POSSIBLE\r\n" +
                        "011111" + "\r\n" +
                            "001111" + "\r\n" +
                            "000110" + "\r\n" +
                            "000011" + "\r\n" +
                            "000001" + "\r\n" +
                            "000000";
                }
                else if (M == 15)
                {
                    return "POSSIBLE\r\n" +
                        "011111" + "\r\n" +
                            "001110" + "\r\n" +
                            "000111" + "\r\n" +
                            "000011" + "\r\n" +
                            "000001" + "\r\n" +
                            "000000";
                }
                else if (M == 16)
                {
                    return "POSSIBLE\r\n" + 
                        "011111" + "\r\n" +
                            "001111" + "\r\n" +
                            "000111" + "\r\n" +
                            "000011" + "\r\n" +
                            "000001" + "\r\n" +
                            "000000";
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }
            else
            {
                return "BUG";
            }
        }
    }
}

