using System;
using System.Collections.Generic;
using System.Text;

class c_dijkstra {
   static void Main(string[] args) {
      MULT['1','1'] = "1";  MULT['1','i'] = "i";  MULT['1','j'] = "j";  MULT['1','k'] = "k";
      MULT['i','1'] = "i";  MULT['i','i'] = "-1"; MULT['i','j'] = "k";  MULT['i','k'] = "-j";
      MULT['j','1'] = "j";  MULT['j','i'] = "-k"; MULT['j','j'] = "-1"; MULT['j','k'] = "i";
      MULT['k','1'] = "k";  MULT['k','i'] = "j";  MULT['k','j'] = "-i"; MULT['k','k'] = "-1";
      (new c_dijkstra()).Run();
   }

   static string[,] MULT = new string[256,256];

   static string multiply(string s, string t) {
      string prod = MULT[ s[ s.Length-1 ], t[t.Length-1] ];
      if (s[0] == '-' && t[0] == '-' ||
          s[0] != '-' && t[0] != '-')
         return prod;
      return (prod[0] == '-') ? prod.Substring(1) : ("-" + prod);
   }
   
   void Run() {
      int TC = int.Parse(Console.ReadLine());
      for (int tc = 1; tc <= TC; ++tc) {
         string[] tok = Console.ReadLine().Split(' ');
         int L = int.Parse(tok[0]);
         long X = long.Parse(tok[1]);
         string S = Console.ReadLine();
         
         Dictionary< string, long >[] D = new Dictionary< string, long >[3];
         for (int s = 0; s < 3; ++s) {
            D[s] = new Dictionary< string, long >();
            D[s][ "1"] = D[s][ "i"] = D[s][ "j"] = D[s][ "k"] = 
            D[s]["-1"] = D[s]["-i"] = D[s]["-j"] = D[s]["-k"] = -1;
         }

         string cur = "1";
         int stage = 0;
         int x = 0;
         D[stage]["1"] = x;
         while (x < X) {
            for (int i = 0; i < L; ++i) {
               string nxt = multiply(cur, "" + S[i]);
//               Console.Error.WriteLine("{0} {1} {2} : {3} * {4} = {5}",
//                  x, i, x*L + i, cur, "" + S[i], nxt);
               if (nxt == "i" && stage == 0 ||
                   nxt == "k" && stage == 1) ++stage;
               cur = nxt;
            }
            ++x;
            if (D[stage][cur] >= 0)
               break;
            D[stage][cur] = x;
         }
         string res = "NO";
         Console.Error.WriteLine("Stage {0}", stage);
         if (stage == 2) {
            if (x < X) {
               // cycle
               Console.Error.WriteLine(
                  "Repeated after {0} iterations starting from {1}", x, D[stage][cur]);
               long preperiod = D[stage][cur];
               Console.Error.WriteLine("goal = {0}", D[stage]["-1"]);
               long cyclelen = (x - D[stage][cur]);
               if (D[stage]["-1"] >= 0 && (X - preperiod) % cyclelen == D[stage]["-1"] - preperiod)
                  res = "YES";
            }
            else {
               Console.Error.WriteLine("Ended before cycle");
               res = cur == "-1" ? "YES" : "NO";
            }
         }
         Console.WriteLine("Case #{0}: {1}", tc, res);
      }
   }
}