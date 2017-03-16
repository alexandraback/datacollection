#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>
#include <set>
#include <list>
#include <cmath>

using namespace std;

int debug = 0;

int N;
int A;
double D;


double otherPos[2000];
double otherTime[2000];
double accel[250];

double otherVel;

double otherArrivesHome;
double iArriveHome;

int Quadratic(double a, double b, double c, double &r1, double &r2)
{
  double disc = b*b - 4 * a * c;
  double root1, root2;

  if (disc < 0)
  {
    printf("discrimant %f\n", disc);
    return 0;
  }

  root1 = -b + sqrt(disc) / (2 * a);
  root2 = -b - sqrt(disc) / (2 * a);

  assert(root1 > root2);

  assert(root2 < 0);

}

int main(int argc, char *argv[])
{
  int T;
  
  assert(scanf("%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {

    assert(scanf("%lf %d %d", &D, &N, &A) == 3);

    for(int i = 0; i < N; i++)
    {
      assert(scanf("%lf %lf", &otherTime[i], &otherPos[i]) == 2); 

      if (debug)
      printf("[%d] other time/pos %f %f\n", i, otherTime[i], otherPos[i]);
    }
    
    for(int i = 0; i < A; i++)
    {
     assert(scanf("%lf", &accel[i]) == 1);
    }

    otherVel = (otherPos[1] - otherPos[0]) / otherTime[1];

    double otherDistHome = D - otherPos[0];
    double otherTimeHome = otherDistHome / otherVel;
    
    if (debug)
    {
      printf("Othervel = %f\n", otherVel);
      printf("OtherTimeHome = %f\n", otherTimeHome);
    }

    printf ("Case #%d:\n", t);

    for(int i = 0; i < A; i++)
    {
      double ac = accel[i];

      double myTimeHome = sqrt(2 * D / ac);

 
      double timeHome;
     
      if (otherPos[0] >= D)
        timeHome = myTimeHome;
      else
        timeHome = max(myTimeHome, otherTimeHome);
     
       printf("%.40f\n", timeHome);
    }


    fflush(stdout);
  }  
}

