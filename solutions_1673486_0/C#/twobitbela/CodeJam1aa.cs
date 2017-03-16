using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam1aa
{
    class CodeJam1aa
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            using (StreamReader reader = new StreamReader("../../in.1aa.txt"))
            {
                int numberOfCases = int.Parse(reader.ReadLine());

                for (int currentCase = 1; currentCase <= numberOfCases; currentCase++)
                {
                    int[] inputs = reader.ReadLine().Split(' ').Select(o => int.Parse(o)).ToArray();

                    int keysTypes = inputs[0];
                    int charactersInPassword = inputs[1];

                    decimal[] percentForEachKey = reader.ReadLine().Split(' ').Select(o => decimal.Parse(o)).ToArray();
                    decimal[] wrongPercentForEachKey = percentForEachKey.Select(o => 1m - o).ToArray();

                    //keep typing
                    //keep typing and it's correct
                    int correct = charactersInPassword - keysTypes + 1;
                    //keep typing and it's incorrect
                    int incorrect = correct + charactersInPassword + 1;
                    
                    decimal result = 1000m;

                    if (keysTypes == 1)
                    {
                        decimal keepTypingExpected = (percentForEachKey[0] * correct) + (wrongPercentForEachKey[0] * incorrect);
                        decimal backSpace = 2 + charactersInPassword + 1;
                        decimal enterRightAway = 1 + charactersInPassword + 1;

                        result = keepTypingExpected;
                        if (backSpace < result)
                        {
                            result = backSpace;
                        }
                        if (enterRightAway < result)
                        {
                            result = enterRightAway;
                        }
                    }

                    else if (keysTypes == 2)
                    {
                        decimal cc = percentForEachKey[0] * percentForEachKey[1];
                        decimal ic = wrongPercentForEachKey[0] * percentForEachKey[1];
                        decimal ci = percentForEachKey[0] * wrongPercentForEachKey[1];
                        decimal ii = wrongPercentForEachKey[0] * wrongPercentForEachKey[1];

                        decimal keepTyping = ((charactersInPassword - keysTypes + 1) * cc)
                                             + ((charactersInPassword - keysTypes + 1 + charactersInPassword + 1) * (ic + ci + ii));
                        decimal backSpace = ((charactersInPassword - keysTypes + 1 + 2) * (cc + ci))
                                            + ((charactersInPassword - keysTypes + 1 + charactersInPassword + 1 + 2) * (ic + ii));
                        decimal backSpace2 = ((charactersInPassword - keysTypes + 1 + 4) * (1));

                        decimal enterRightAway = charactersInPassword + 2;

                        result = keepTyping;
                        if (backSpace < result)
                        {
                            result = backSpace;
                        }
                        if (backSpace2 < result)
                        {
                            result = backSpace2;
                        }
                        if (enterRightAway < result)
                        {
                            result = enterRightAway;
                        }
                    }
                    else if (keysTypes == 3)
                    {
                        //backspace once

                        //backspace twice

                        //backspace thrice

                        //press enter

                        decimal ccc = percentForEachKey[0] * percentForEachKey[1] * percentForEachKey[2];
                        decimal icc = wrongPercentForEachKey[0] * percentForEachKey[1] * percentForEachKey[2];
                        decimal cic = percentForEachKey[0] * wrongPercentForEachKey[1] * percentForEachKey[2];
                        decimal iic = wrongPercentForEachKey[0] * wrongPercentForEachKey[1] * percentForEachKey[2];
                        decimal ici = wrongPercentForEachKey[0] * percentForEachKey[1] * wrongPercentForEachKey[2];
                        decimal iii = wrongPercentForEachKey[0] * wrongPercentForEachKey[1] * wrongPercentForEachKey[2];
                        decimal cii = percentForEachKey[0] * wrongPercentForEachKey[1] * wrongPercentForEachKey[2];
                        decimal cci = percentForEachKey[0] * percentForEachKey[1] * wrongPercentForEachKey[2];

                        decimal keepTyping = ((charactersInPassword - keysTypes + 1) * ccc)
                                             + ((charactersInPassword - keysTypes + 1 + charactersInPassword + 1) * (1 - ccc));
                        decimal backSpace = ((charactersInPassword - keysTypes + 1 + 2) * (ccc + cci))
                                            + ((charactersInPassword - keysTypes + 1 + charactersInPassword + 1 + 2) * (1 - (ccc + cci)));
                        decimal backSpace2 = ((charactersInPassword - keysTypes + 1 + 4) * (ccc + cci + cic + cii))
                                            + ((charactersInPassword - keysTypes + 1 + charactersInPassword + 1 + 4) * (1 - (ccc + cci + cic + cii)));

                        decimal backSpace3 = 100000m;
                        decimal enterRightAway = charactersInPassword + 2;

                        result = keepTyping;
                        if (backSpace < result)
                        {
                            result = backSpace;
                        }
                        if (backSpace2 < result)
                        {
                            result = backSpace2;
                        }
                        if (enterRightAway < result)
                        {
                            result = enterRightAway;
                        }

                    }





                    output.AppendLine("Case #" + currentCase + ": " + result.ToString("f6"));
                }

                reader.Close();
            }

            using (StreamWriter writer = new StreamWriter("../../out.1aa.txt"))
            {
                writer.Write(output.ToString());
                writer.Close();
            }
        }
    }
}
