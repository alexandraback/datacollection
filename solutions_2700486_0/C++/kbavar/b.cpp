#include <iostream>
using namespace std;

int main()
{
	long t, i, j, k, n, x, y, z;
	float a[100][100];
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> n >> x >> y;
		if (x<0) x=-1*x;
		if (x>10) x=10;
		if (y>10) y=10;

		for (i=0; i<100; i++)
			for (j=0; j<100; j++)
				a[i][j]=0;
			
		a[0][0]+=1;
		if (n==1) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[2][0]+=0.5;
		if (n==2) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[2][0]+=0.25;
		a[1][1]+=0.25;
		if (n==3) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[2][0]+=0.25;
		a[1][1]+=0.25;
		if (n==4) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[1][1]+=0.5;
		if (n==5) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[0][2]+=1;
		if (n==6) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[4][0]+=0.5;
		if (n==7) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[4][0]+=0.25;
		a[3][1]+=0.25;
		if (n==8) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[4][0]+=1/8;
		a[3][1]+=0.25;
		a[2][2]+=1/8;
		if (n==9) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[4][0]+=1/8;
		a[3][1]+=0.25;
		a[2][2]+=1/8;
		if (n==10) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[3][1]+=0.25;
		a[2][2]+=0.25;
		if (n==11) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[2][2]+=0.5;
		if (n==12) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[0][4]+=1;
		if (n==13) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[6][0]+=0.5;
		if (n==14) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[6][0]+=0.25;
		a[5][1]+=0.25;
		if (n==15) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[6][0]+=1/8;
		a[5][1]+=0.25;
		a[4][2]+=1/8;
		if (n==16) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[6][0]+=1/16;
		a[5][1]+=3/16;
		a[4][2]+=3/16;
		a[3][3]+=1/16;
		if (n==17) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[6][0]+=1/16;
		a[5][1]+=3/16;
		a[4][2]+=3/16;
		a[3][3]+=1/16;
		if (n==18) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[5][1]+=1/8;
		a[4][2]+=2/8;
		a[3][3]+=1/8;
		if (n==19) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[4][2]+=1/4;
		a[3][3]+=1/4;
		if (n==20) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
		a[3][3]+=1/2;
		if (n==21) cout << "Case #" << k+1 << ": " << a[x][y] <<  endl;
	}	
	return 0;
}
