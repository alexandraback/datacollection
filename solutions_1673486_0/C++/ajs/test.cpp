#include <iostream>
#include <cstdlib>
using namespace std;

int main( int argc, const char* argv[] )
{
  int casex, casen;
  cin >> casex;
  for (int casen = 1; casen<casex+1; casen++)
  {
    int n, total;
    double sets[100000], typing=1;
    cin >> n >> total;
    for (int j=0; j < n; j++)
    {
        cin >> sets[j];
    }
    for (int j=0; j < n; j++)
    {
        typing*=sets[j];
    }
    double typscore=(total - n + 1)*typing+(total - n + total+ 2)*(1-typing) ;
    double entscore=total+2, min;
    min = entscore<typscore?entscore:typscore;
    for (int j=0; j < n; j++)
    {
        double typ=1;
        for (int k=0; k < j; k++)
        {
            typ*=sets[k];
        }
        if (typ*(total - n + 1 + (n-j)*2)+(1-typ)*(total - n + total+ 2 + (n-j)*2) < min)
            min=typ*(total - n + 1 + (n-j)*2)+(1-typ)*(total - n + total+ 2 + (n-j)*2);
            //cout << "deb " << typ << " " << typ*(total - n + 1 + (n-j)*2)+(1-typ)*(total - n + total+ 2 + (n-j)*2) << endl;
    }
    
    cout << "Case #" << casen << ": " << min << endl;
  }
}