#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

double solve(double a, double b, double c){
  return (-b + sqrt(b*b-4*a*c))/2/a;
}

int main(){
  int tt; scanf("%d",&tt);
  for (int ti=1;ti<=tt;ti++){
    double D; 
    int n, an;
    scanf("%lf%d%d", &D, &n, &an);
    double T[n], X[n];
    for (int i=0;i<n;i++){
      scanf("%lf%lf", &T[i], &X[i]);
    }
    printf("Case #%d:\n",ti);
    for (int i=0;i<an;i++){
      double g;
      scanf("%lf", &g);

      
      double v_me = 0;
      double dis_me = 0;
      double curr_time = 0;

      for (int i=1;i<n;i++){
        double t_diff = T[i] - T[i-1];
        double v_oth = (X[i] - X[i-1]) / t_diff;
        if (X[i] > D){
          t_diff = (D - X[i-1]) / v_oth;
        }
        
        double new_dis = dis_me + v_me * t_diff + 0.5 * g * t_diff * t_diff;
        // position of other car
        double dis_other = X[i-1] + v_oth * t_diff;
        //printf("ddd %lf %lf\n", new_dis, dis_other);

        if (dis_other < new_dis){
          // intersect
          double tmp_t = solve(g*0.5, v_me, -(dis_other - dis_me));
          v_me = v_oth + g * tmp_t;

          //v_me = v_oth;
          dis_me = dis_other;
          curr_time += t_diff;
        }else{
          v_me = v_me + g * t_diff;
          dis_me = new_dis;
          curr_time += t_diff;
        }
        //printf("%lf %lf %lf\n", v_me, dis_me, curr_time);
      }
      if (fless(dis_me, D)){
        double remain = D - dis_me;
        //printf("remain %lf\n", remain);
        curr_time += solve(g*0.5, v_me, -remain);
      }

      printf("%.8lf\n", curr_time);

      //puts("");
    }



  }
  return 0;
}

