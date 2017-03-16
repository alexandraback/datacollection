#include<iostream>
#include<fstream>

using namespace std;


int bb[5][5] = { 0, 0, 0, 0, 0,
0, 1, 2, 3, 4,
0, 2, -1, 4, -3,
0, 3, -4, -1, 2,
0, 4, 3, -2, -1, };


int L, X;
int mat[10010];
int art[10010];
int mna[10010];

ifstream ii("1.txt");
ofstream oo("o.txt");

int pow(int a, int b)
{
	if (a<0 && b<0)	return bb[-a][-b];
	if (a>0 && b>0)	return bb[a][b];
	if (a<0 && b>0)	return -bb[-a][b];
	if (a>0 && b<0)	return -bb[a][-b];
	cout << "ERROR POW\n";
	return 0;

}

int over_a(int s, int a)
{
	int ns=1;
	int i;
	if (a < 0){ ns *= -1; a *= -1; }
	for (i = 1; i < 5; i++){
		if (bb[a][i] == s)return ns*i;
		if (bb[a][i] == -s)return (-1)*ns*i;
	}
	cout << "ERROR OVER-A\n";
	return 0;
}
/*
int over_d(int s, int d)
{
	int i;
	int ns = 1;
	if (d < 0){ ns *= -1; d *= -1; }
	if (s < 0){ ns *= -1; s *= -1; }
	for (i = 1; i < 5; i++){
		if (bb[i][d] == s)return ns*i;
	}
	cout << "ERROR OVER-D\n";
	return 0;
}
*/
void input()
{
	int i,j;
	char c1,c2,c3,c;
	ii >> L;
	X = 0;
	for (;;){
		ii >> c1;
		if (c1 - '0' < 0 || c1 - '0'>9)break;
		X = (X * 10 + c1 - '0')%1000;
	}
	ii.putback(c1);
	if (X > 12) X = 12 + X % 4;
	
	art[0] = 1;

	for (i = 1; i <= L; i++){
		ii >> c;
		switch (c)
		{
		case 'i':
			mat[i] = 2;
			break;
		case 'j':
			mat[i] = 3;
			break;
		case 'k':
			mat[i] = 4;
			break;
		default:
			cout << "ERROR INPUT";
			break;
		}
		art[i] = pow(art[i - 1], mat[i]);
	}
	mna[L + 1] = 1;
	for (i = 1; i <= L; i++){
		mna[i]=over_a(art[L],art[i-1]);
	}
}
int main()
{
	int K, N;
	int i, j;
	int n, k, t,sum,URA, sumi, sumj, sumqi, sumqk;
	int q1, q2, l1, l2;
	int mm[2005];
	cout << "AAA";


	ii >> N;
	for (K=1; K<N+1; K++){
		
		input();
 		URA = 0;
		sumqi = 1;
		for (q1 = 0; q1 < X; q1++){
			for (l1 = 1; l1 <= L; l1++){
				if (pow(sumqi, art[l1]) != 2)continue;
				sumqk = 1;
				for (q2 = 0; q2 < X - q1 ; q2++){
					for (l2 = 1; l2 <= L ; l2++){
						if (pow(mna[L-l2+1],sumqk) != 4)continue;
						if (q1 + q2 == X - 1 && l1 + l2 >= L)break;
						if (q1 + q2 == X - 1){
							if (over_a(art[L - l2], art[l1]) == 3){
								cout << q1 << " " << l1 << " " << q2 << " " << l2<<"\n";
								URA = 1; break; }
							continue;
						}
						if (q1 + q2 < X - 1){
							sum = 1;
							i = X - q1 - q2 - 2;
							for (j = 0; j < i; j++){
								sum = pow(sum, art[L]);
							}
							sum = pow(mna[l1 + 1], sum);
							sum = pow(sum, art[L - l2]);
							if (sum == 3){
								cout << q1 << " " << l1 << " " << q2 << " " << l2<<"\n";
								URA = 1; break; }
							continue;
						}
						cout << "ERRROR CIKLERUM\n";
					}
					if (URA == 1)break;
					sumqk = pow(sumqk, art[L]);
				}
				if (URA == 1)break;
			}
			if (URA == 1)break;
			sumqi = pow(sumqi, art[L]);
		}
		if (URA==1)	oo << "Case #" << K << ": " <<  "YES";
		else oo << "Case #" << K << ": " << "No";
		if (K == N)break;
		oo << "\n";
	}

	ii.close();
	oo.close();


}