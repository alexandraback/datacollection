#include <iostream>
#include <cmath>

using namespace std;

double collision_time(double x[], double s[], int line[], int n, int pair[])
{
	int i, j;
	double min_time = 30000;
	double time;
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if ((line[i] == line[j]) && (s[i] != s[j]))
			{
				time = fabs(fabs(x[i]-x[j])-5.0)/fabs(s[i]-s[j]);
				if (time < min_time) 
				{
					min_time = time;
					pair[0] = i;
					pair[1] = j;
				}
			}
		}
	}
//	cout<<"Min time "<<min_time<<endl;
	if (min_time > 20000) {return -1;}
	
	return min_time;
}

bool resolve_collision(double x[], double s[], int line[], int num_cars, int pair[], double dt)
{
	int i, a, b;
	for (i = 0; i < num_cars; i++)
	{
		x[i] += s[i]*dt;
	}
	a = pair[0];
	b = pair[1];
	double mid = 0.5*(x[a]+x[b]);
	int lc = (0==line[a])?1:0;
	for (i = 0; i < num_cars; i++)
	{
		if (line[i] == lc)
		{
			if (fabs(mid-x[i])<5.0) {return false;}
		}
	}
	if (s[a]<s[b]) {line[b] = lc;}
	else {line[a] = lc;}
	return true;
}

int main()
{
	int num_cases, curr_case;
	double ans;
	int num_cars;
	cin>>num_cases;
	int i;
	for (curr_case = 0; curr_case < num_cases; curr_case++)
	{
		cin>>num_cars;
		double x[num_cars], s[num_cars];
		int line[num_cars];
		char car_line;
		for (i = 0; i < num_cars; i++)
		{
			cin>>car_line>>s[i]>>x[i];
			line[i] = 1;
			if (car_line == 'L') {line[i] = 0;}
//			cout<<line[i]<<s[i]<<x[i]<<endl;		
		}
		double curr_time = 0.0;
		int pair[2];
		double dt = collision_time(x,s,line, num_cars, pair);
		while ((dt>0) && (resolve_collision(x,s,line,num_cars, pair, dt)))
		{
			curr_time += dt;
			dt = collision_time(x,s,line, num_cars, pair);
		}
		if (collision_time(x,s,line, num_cars,pair) < 0) {cout<<"Case #"<<(curr_case+1) <<": Possible"<<endl;}
		else{cout<<"Case #"<<(curr_case+1) <<": "<<curr_time+dt<<endl; }
	}
}
