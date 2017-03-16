#include<iostream>
#include<cmath>
#include<string>

using namespace std;

long long int mulMatrix[4][4] = {{1, 2, 3, 4},{2, -1, 4, -3},{3, -4, -1, 2},{4, 3, -2, -1}};

long long int q_ctoi(char c)
{
  if (c == '1') return 1;
  if (c == 'i') return 2;
  if (c == 'j') return 3;
  if (c == 'k') return 4;
  return 0;
}

long long int q(long long int a, long long int b)
{
  long long int sign = 1;
  if (a < 0) 
  {
    sign *= -1;
    a *= -1;
  }
  if (b < 0) 
  {
    sign *= -1;
    b *= -1;
  }
  return sign*mulMatrix[a - 1][b - 1];
}

long long int qc(char a, char b)
{
  return q(q_ctoi(a), q_ctoi(b));
}


long long int evaluate_q(string s)
{
  int res = 1;
  for (long long int i = 0; (unsigned int) i < s.size(); ++i)
  {
    res = q(res, q_ctoi(s[i]));
  }
  return res;
}

int main()
{
  long long int T;
  cin >> T;
  for (long long int t = 1; t <= T; ++t)
  {
    long long int L, X;
    cin >> L >> X;
    string s;
    cin >> s;
    bool solved = false;
    long long int val = evaluate_q(s);
    long long int reps[4] = {1, val, evaluate_q(s + s), evaluate_q(s + s + s)};
    
    long long int preCalc_lr[L];
    long long int curr = 1;
    for (long long int i = 0; i < L; ++i) 
    {
      curr = q(curr, q_ctoi(s[i]));
      preCalc_lr[i] = curr;
    }
    long long int preCalc_rl[L];
    curr = 1;
    for (long long int i = L - 1; i >= 0; --i) 
    {
      curr = q(q_ctoi(s[i]), curr);
      preCalc_rl[i] = curr;
    }

    cout << "";
    //Buscamos corte para i
    for (long long int rep_i= 0; rep_i< 4 and !solved; ++rep_i)
    {
      long long int valReps = reps[rep_i];
      for (long long int i = 0; i < L and !solved; ++i)
      {
        long long int valCut = 1;
        if (i >= 1) valCut = preCalc_lr[i - 1];
        long long int valPrefix_j = preCalc_rl[i];//evaluate_q(prefix_j);
        if (q(valReps, valCut) == 2)  //we have found a plausible (4n + prefix)
        {
          long long int valCut_j = 1;
          long long int valPrefix_k = valPrefix_j;
          for (long long int j = 1; j < L - i + 1 and !solved; ++j)
          {
            char c = s[j + i - 1];
            long long int vc = q_ctoi(c);
            valCut_j = q(valCut_j, vc);//evaluate_q(prefix_j.substr(0,j));
            valPrefix_k = q(-1*vc, valPrefix_k);//evaluate_q(prefix_k); 
            
            if (valCut_j == 3)
            {
              for (long long int rep_k = 0; rep_k < 4 and !solved; ++rep_k)
              {
                long long int valReps_k = reps[rep_k];
                if (q(valPrefix_k, valReps_k) == 4)
                {
                  long long int extra_i = 1;
                  if ((X - extra_i - rep_i) % 4 == rep_k and X >= extra_i + rep_i) 
                  {
                    solved = true;
                  }
                }
              }
            }
          }
          for (long long int rep_j = 0; rep_j < 4 and !solved; ++rep_j)
          {
            long long int valReps_j = reps[rep_j];
            for (long long int j = 0; j < L + 1 and !solved; ++j)
            {
              long long int valCut_j = 1;
              if (j >= 1) valCut_j = preCalc_lr[j - 1];
              long long int valPrefix_k = 1;
              if (j < L) valPrefix_k = preCalc_rl[j];//evaluate_q(prefix_k);
              if (q(valPrefix_j, q(valReps_j, valCut_j)) == 3)
              {
                for (long long int rep_k = 0; rep_k < 4 and !solved; ++rep_k)
                {
                  long long int valReps_k = reps[rep_k];
                  if (q(valPrefix_k, valReps_k) == 4)
                  {
                    long long int extra_i = 1;
                    long long int extra_j = 1; 
                    if ((X - rep_i - rep_j - extra_i - extra_j) % 4 == rep_k and X >= rep_i + rep_j + extra_i + extra_j) 
                    {
                      solved = true;
                    }
                  }
                }
              }
            }
          } 
        } 
      } 
    }
    if (solved) cout << "Case #" << t << ": YES" << endl;
    else cout << "Case #" << t << ": NO" << endl;
  }
  
  return 0;
}








