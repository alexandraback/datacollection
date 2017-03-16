#include <fstream>
using namespace std;

int main()
{
  ifstream in("data.in");
  ofstream out("data.out");
  out.precision(6);
  out << fixed;
  
  int T; in >> T;

  for(int t = 0;t < T;++t)
  {
    int A,B;
    in >> A >> B;

    double* p = new double[A];
    for(int i = 0;i < A;++i)
      in >> p[i];

    double* success = new double[A+1]; //chance of success based on backspaces
    success[0] = 1.0;
    for(int i = 0;i < A;++i)
      success[0] *= p[i];
    for(int b = 1;b <= A;++b)
      success[b] = success[b-1]/p[A-b];

    double ans = B+2; //2 enters
    for(int b = 0;b <= A;++b)
    {
      double keystrokes = success[b]*(b + ((B-A)+b) + 1) + (1.0 - success[b])*(b + ((B-A)+b) + 1 + B + 1);
      if(keystrokes < ans)
        ans = keystrokes;
    }

    out << "Case #" << (t+1) << ": " << ans << "\n";
  }

  return 0;
}
