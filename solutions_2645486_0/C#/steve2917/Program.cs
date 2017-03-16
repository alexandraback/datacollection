using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace enegry
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter tw = new StreamWriter("output.txt", true);
            TextReader tr = new StreamReader("B-small-attempt2.in");
            tw.AutoFlush = true;


            int cases = Convert.ToInt32(tr.ReadLine());

            for (int _case = 1; _case <= cases; _case++)
            {
                Char _ch = Convert.ToChar(tr.Read());

                String _max = "";
                String _regain = "";
                String _act = "";

                while (char.IsNumber(_ch))
                {
                    _max += _ch;
                    _ch = Convert.ToChar(tr.Read());
                }

                int max = Convert.ToInt32(_max);
                _ch = Convert.ToChar(tr.Read());
                //_ch = Convert.ToChar(tr.Read());
                //tw.WriteLine("Arxiko : " + _start);
                Console.WriteLine("Max : " + max);

                while (char.IsNumber(_ch))
                {
                    _regain += _ch;
                    _ch = Convert.ToChar(tr.Read());
                }

                int regain = Convert.ToInt32(_regain);
                _ch = Convert.ToChar(tr.Read());
                Console.WriteLine("Regain : " + regain);

                while (char.IsNumber(_ch))
                {
                    _act += _ch;
                    _ch = Convert.ToChar(tr.Read());
                }
                int act = Convert.ToInt32(_act);
                Console.WriteLine("act : " + act);

                //tr.ReadLine();                                                //<--------------

                int max_action = 0;
                int max_action_no = 0;
                int[] actiontable = new int[act];

                for (int _action = 1; _action <= act; _action++)
                {
                    string _a = "";

                    _ch = Convert.ToChar(tr.Read());
                    while (char.IsNumber(_ch))
                    {
                        _a += _ch;
                        _ch = Convert.ToChar(tr.Read());
                    }

                    int _b = Convert.ToInt32(_a);
                    if (_b >= max_action)
                    {
                        max_action = _b;
                        max_action_no = _action;
                    }

                    actiontable[_action - 1] = _b;
                    //_ch = Convert.ToChar(tr.Read());
                }

                for (int _action = 1; _action <= act; _action++)
                {
                    Console.Write(actiontable[_action-1] + " ");
                }


                Console.WriteLine("Maxno: " + max_action_no);
                if (regain >= max)
                {
                    int output = 0;
                    for (int _action = 1; _action <= act; _action++)
                    {
                        output = output + actiontable[_action - 1] * max;
                    }
                    Console.WriteLine("Case #" + _case + ": " + output);
                    tw.WriteLine("Case #" + _case + ": " + output);
                }

                else
                {
                    int output = 0;
                    for (int _action = 1; _action <= act; _action++)
                    {
                        if (_action == max_action_no)
                        {
                            output = output + actiontable[_action - 1] * max;
                        }
                        else
                        {
                            output = output + actiontable[_action - 1] * regain;
                        }
                    }
                    Console.WriteLine("Case #" + _case + ": " + output);
                    tw.WriteLine("Case #" + _case + ": " + output);

                }

                //tw.WriteLine("Case #" + _case + ": " + _v);


               // tr.ReadLine();                                                     //<--------------

                

            }

            Console.Read();
        }
    }
}
