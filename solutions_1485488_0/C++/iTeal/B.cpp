#include <iostream>
#include <iomanip>

using namespace std;

double access(int c1,int f1, int c2, int f2, int h) {
	if (c1-f2 < 50 || c2-f1 < 50 || c2-f2 < 50) return -1;
	if (c2 - h >= 50) return 0;
	double k = 50-(c2-h);
	return k / 10.0;
}

int main (int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++) {
		int m,n;
		int f[100][100];
		int c[100][100];
		int h;
		cin >> h >> m >> n;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> c[i][j];
			}
		}
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> f[i][j];
			}
		}
		
		double t[100][100];
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				t[i][j] = -1;
			}
		}
		
		int flag = 1;
		t[0][0] = 0;
		while (flag) {
			flag = 0;
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if (t[i][j] >= 0) {
						int x = i;
						int y = j+1;
						// case 1
						if (y < n) {
							double acc = access(c[i][j],f[i][j],c[x][y],f[x][y],h-10*t[i][j]);
							if (acc >= 0) {
								if (acc == 0 && t[i][j] == 0) {
									if (t[x][y] != 0) {
										t[x][y] = 0;
										flag = 1;
									}
								}
								else {
									double hc = h-10*(t[i][j]+acc);
									if (hc - f[i][j] >= 20) {
										double temp = t[i][j] + acc + 1;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									} else {
										double temp = t[i][j] + acc + 10;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									}
								}
							}
						}
						
						x = i;
						y = j-1;
						// case 2
						if (y >= 0) {
							double acc = access(c[i][j],f[i][j],c[x][y],f[x][y],h-10*t[i][j]);
							if (acc >= 0) {
								if (acc == 0 && t[i][j] == 0) {
									if (t[x][y] != 0) {
										t[x][y] = 0;
										flag = 1;
									}
								}
								else {
									double hc = h-10*(t[i][j]+acc);
									if (hc - f[i][j] >= 20) {
										double temp = t[i][j] + acc + 1;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									} else {
										double temp = t[i][j] + acc + 10;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									}
								}
							}
						}
						
						
						x = i+1;
						y = j;
						// case 3
						if (x < m) {
							double acc = access(c[i][j],f[i][j],c[x][y],f[x][y],h-10*t[i][j]);
							if (acc >= 0) {
								if (acc == 0 && t[i][j] == 0) {
									if (t[x][y] != 0) {
										t[x][y] = 0;
										flag = 1;
									}
								}
								else {
									double hc = h-10*(t[i][j]+acc);
									if (hc - f[i][j] >= 20) {
										double temp = t[i][j] + acc + 1;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									} else {
										double temp = t[i][j] + acc + 10;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									}
								}
							}
						}
						
						
						x = i-1;
						y = j;
						// case 4
						if (x >= 0) {
							double acc = access(c[i][j],f[i][j],c[x][y],f[x][y],h-10*t[i][j]);
							if (acc >= 0) {
								if (acc == 0 && t[i][j] == 0) {
									if (t[x][y] != 0) {
										t[x][y] = 0;
										flag = 1;
									}
								}
								else {
									double hc = h-10*(t[i][j]+acc);
									if (hc - f[i][j] >= 20) {
										double temp = t[i][j] + acc + 1;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									} else {
										double temp = t[i][j] + acc + 10;
										if (temp < t[x][y] || t[x][y] < 0) {
											t[x][y] = temp;
											flag = 1;
										}
									}
								}
							}
						}
						
					}
				}
			}
		}
		cout << "Case #" << ii << ": " << t[m-1][n-1] << endl;
	}
	return 0;
}
