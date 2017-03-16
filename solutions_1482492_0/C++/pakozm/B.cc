#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void solveEquation(double my_v0,
		   double my_acceleration,
		   double my_pos,
		   double other_car_v,
		   double other_car_pos,
		   double &sol1,
		   double &sol2) {
  double a   = my_acceleration*0.5;
  double b   = my_v0 - other_car_v;
  double c   = my_pos - other_car_pos;
  double sqr = sqrt(b*b - 4*a*c);
  sol1 = (-b + sqr) / my_acceleration;
  sol2 = (-b - sqr) / my_acceleration;
}

double computeTimeToGoal(double distance_to_goal,
			 double my_acceleration,
			 const vector<double> &other_car_times,
			 const vector<double> &other_car_positions) {
  double time_elapsed  = 0.0f;
  double my_velocity   = 0.0f;
  double my_pos        = 0.0f;
  double other_car_pos = other_car_positions[0];
  if (other_car_pos < distance_to_goal) {
    for (unsigned int i=1;
	 i<other_car_times.size() && my_pos < distance_to_goal; ++i) {
      double next_pos    = min(other_car_positions[i], distance_to_goal);
      double other_car_v = (other_car_positions[i]-other_car_positions[i-1])/(other_car_times[i]-other_car_times[i-1]);
      double t_sol1, t_sol2;
      solveEquation(my_velocity, my_acceleration, my_pos,
		    other_car_v, other_car_pos,
		    t_sol1, t_sol2);
      double pos = my_velocity*t_sol1 + 0.5*my_acceleration*t_sol1*t_sol1 + my_pos;
      //cout << "t1 " << t_sol1 << " "  << pos << " " << other_car_positions[i] << endl;
      if (pos >= next_pos) {
	solveEquation(my_velocity, my_acceleration, my_pos,
		      0.0f, next_pos,
		      t_sol1, t_sol2);
	//cout << "A: " << t_sol1 << endl;
	my_velocity   += t_sol1 * my_acceleration;
	time_elapsed  += t_sol1;
      }
      else if (t_sol1 < other_car_times[i]) {
	my_velocity   = other_car_v;
	time_elapsed += t_sol1 + (next_pos-pos)/other_car_v;
      }
      my_pos        = next_pos;
      other_car_pos = other_car_positions[i];
    }
    return time_elapsed;
  }
  else return sqrt(2*my_acceleration*distance_to_goal)/my_acceleration;
}

int main() {
  unsigned int T;
  cin >> T;
  vector<double> other_car_times;
  vector<double> other_car_positions;
  for (unsigned int i=0; i<T; ++i) {
    double D;
    unsigned int N, A;
    cin >> D >> N >> A;
    other_car_times.clear();
    other_car_positions.clear();
    for (unsigned int j=0; j<N; ++j) {
      double t,x;
      cin >> t >> x;
      other_car_times.push_back(t);
      other_car_positions.push_back(x);
    }
    other_car_times.push_back(other_car_times[N-1]);
    other_car_positions.push_back(other_car_positions[N-1]);
    printf("Case #%d:\n", (i+1));
    for (unsigned int j=0; j<A; ++j) {
      float my_acceleration;
      cin >> my_acceleration;
      printf("%.10g\n",computeTimeToGoal(D, my_acceleration,
					 other_car_times,
					 other_car_positions));
    }
  }
  return 0;
}
