#include<iostream>
#include<fstream>

using namespace std;
ifstream ii("2.in");
ofstream oo("o.txt");
int N,k;

void print(int o)
{
	if(o==1)oo<< "Case #" << k << ": RICHARD";
	if (o == 2)oo<< "Case #" << k << ": GABRIEL";
	if (k != N) oo<< "\n";
}


int main()
{
	int N,x,r,c;
	int n,i,j,t,sum,L;
	int mat[2005], mm[2005];
	cout << "AAA";
	
	ii >> N;
	for (k=1; k<N+1; k++){
		ii >> x >> r >> c;
		if (r > c){ i = r, r = c; c = i; }
		
		if (x > 6) {print(1);continue;}
		if (r*c%x != 0){print(1);continue;}
		if (x > c){print(1);continue;}
		if (x == 2){
			if (c*r % 2 == 0){ print(2); continue; }
			else { print(1); continue; }
		}
		if (x == 3){
			if (r == 1){print(1); continue;}
			print(2); continue;
		}
		if (x == 4){
			if (r == 1){print(1); continue;}
			if (r == 2){ print(1); continue; }
			print(2); continue;
		}
		if (x == 5){
			if (r <= 2){ print(1); continue; }
			if (r == 3 && c == 5){print(1); continue;}
			print(2); continue;
		}
		if (x == 6){
			if (r <= 4){ print(1); continue; }
			print(2); continue;
		}
		print(2);
	}

	ii.close();
	oo.close();


}