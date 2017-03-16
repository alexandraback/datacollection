using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problem_B
{
    class Program
    {
        class C_AND_J_Strings
        {
            public string C;
            public string J;

            public C_AND_J_Strings(string C, string J)
            {
                this.C = C;
                this.J = J;
            }
        }

        enum State
        {
            SAME,
            C_Bigger,
            J_Bigger
        }

        static void Main(string[] args)
        {
            // Num of cases:
            int T = Int32.Parse(Console.ReadLine());

            for (int caseNum = 1; caseNum <= T; caseNum++)
            {
                string temp = Console.ReadLine();
                string[] temp2 = temp.Split(new char[] { ' ' , '\t'});
                string C = temp2[0].Trim();
                string J = temp2[1].Trim();

                HandleCase(caseNum, C, J);
            }
        }

        static void HandleCase(int caseNum, string C, string J)
        {
            C_AND_J_Strings result = solve(C, J, State.SAME, 0);

            Console.WriteLine("Case #" + caseNum.ToString() + ": " + result.C + " " + result.J);
        }


        static C_AND_J_Strings solve(string C, string J, State state, int index)
        {
            if (C.Length == index)
            {
                return new C_AND_J_Strings(C,J);
            }
            else if ((C[index] != '?') && (J[index] != '?'))
            {
                if (state == State.SAME)
                {
                    if (Convert.ToInt32(C[index]) > Convert.ToInt32(J[index]))
                    {
                        state = State.C_Bigger;
                    }
                    else if (Convert.ToInt32(C[index]) < Convert.ToInt32(J[index]))
                    {
                        state = State.J_Bigger;
                    }
                }

                return solve(C, J, state, index + 1);
            }
            else if (state == State.C_Bigger)
            {
                if (C[index] == '?')
                {
                    C = SetCharInString(C, index, '0');
                }

                if (J[index] == '?')
                {
                    J = SetCharInString(J, index, '9');
                }

                return solve(C, J, state, index + 1);
            }
            else if (state == State.J_Bigger)
            {
                if (C[index] == '?')
                {
                    C = SetCharInString(C, index, '9');
                }

                if (J[index] == '?')
                {
                    J = SetCharInString(J, index, '0');
                }

                return solve(C, J, state, index + 1);
            }
            else
            {
                C_AND_J_Strings same;
                C_AND_J_Strings C_Bigger;
                C_AND_J_Strings J_Bigger;

                if ((C[index] == '?') && (J[index] == '?'))
                {
                    // Try same:
                    C = SetCharInString(C, index, '0');
                    J = SetCharInString(J, index, '0');
                    same = solve(C, J, state, index + 1);

                    // Try C Bigger:
                    C = SetCharInString(C, index, '1');
                    J = SetCharInString(J, index, '0');
                    C_Bigger = solve(C, J, State.C_Bigger, index + 1);

                    // Try J Bigger:
                    C = SetCharInString(C, index, '0');
                    J = SetCharInString(J, index, '1');
                    J_Bigger = solve(C, J, State.J_Bigger, index + 1);
                }
                else if (C[index] == '?')
                {
                    // Try same:
                    C = SetCharInString(C, index, J[index]);
                    same = solve(C, J, state, index + 1);

                    // Try C Bigger:
                    if (J[index] == '9')
                        C_Bigger = null;
                    else
                    {
                        char TheChar = Convert.ToChar((Convert.ToInt32(J[index]) + 1));
                        C = SetCharInString(C, index, TheChar);
                        C_Bigger = solve(C, J, State.C_Bigger, index + 1);
                    }

                    // Try J Bigger:
                    if (J[index] == '0')
                        J_Bigger = null;
                    else
                    {
                        char TheChar = Convert.ToChar((Convert.ToInt32(J[index]) - 1));
                        C = SetCharInString(C, index, TheChar);
                        J_Bigger = solve(C, J, State.J_Bigger, index + 1);
                    }
                }
                else // J[index] == '?'
                {
                    // Try same:
                    J = SetCharInString(J, index, C[index]);
                    same = solve(C, J, state, index + 1);

                    // Try C Bigger:
                    if (C[index] == '0')
                        C_Bigger = null;
                    else
                    {
                        char TheChar = Convert.ToChar((Convert.ToInt32(C[index]) - 1));
                        J = SetCharInString(J, index, TheChar);
                        C_Bigger = solve(C, J, State.C_Bigger, index + 1);
                    }

                    // Try J Bigger:
                    if (C[index] == '9')
                        J_Bigger = null;
                    else
                    {
                        char TheChar = Convert.ToChar((Convert.ToInt32(C[index]) + 1));
                        J = SetCharInString(J, index, TheChar);
                        J_Bigger = solve(C, J, State.J_Bigger, index + 1);
                    }
                }

                // Pick Best:
                return GetBetter(GetBetter(same, C_Bigger), J_Bigger);
            }
        }

        static C_AND_J_Strings GetBetter(C_AND_J_Strings pair1, C_AND_J_Strings pair2)
        {
            if (pair1 == null)
                return pair2;
            else if (pair2 == null)
                return pair1;

            UInt64 pair1_diff = DiffOfStrings(pair1.C, pair1.J);
            UInt64 pair2_diff = DiffOfStrings(pair2.C, pair2.J);

            if (pair1_diff < pair2_diff)
                return pair1;
            else if (pair1_diff > pair2_diff)
                return pair2;
            else
            {
                UInt64 pair1_cVal = ValueOfString(pair1.C);
                UInt64 pair2_cVal = ValueOfString(pair2.C);

                if (pair1_cVal < pair2_cVal)
                    return pair1;
                else if (pair1_cVal < pair2_cVal)
                    return pair2;
                else
                {
                    UInt64 pair1_jVal = ValueOfString(pair1.J);
                    UInt64 pair2_jVal = ValueOfString(pair2.J);

                    if (pair1_jVal < pair2_jVal)
                        return pair1;
                    else 
                        return pair2;
                }
            }
        }

        static string SetCharInString(string str, int pos, char TheChar)
        {
            return str.Substring(0, pos) + TheChar + str.Substring(pos + 1);
        }

        static UInt64 ValueOfString(string str)
        {
            return Convert.ToUInt64(str);
        }

        static UInt64 DiffOfStrings(string C, string J)
        {
            UInt64 cVal = ValueOfString(C);
            UInt64 jVal = ValueOfString(J);

            if (cVal > jVal)
                return cVal - jVal;
            else
                return jVal - cVal;
        }

    }
}
