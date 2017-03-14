#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int D, dx, dy, ik, jk, nbOcc, debug = 0;

string s, t, grille[30];
stringstream out;
double dist;

int divise(int a, int b) {
	return (a * b >= 0) ? a / b : a / b - 1;
}

int sgn(int n) {
	return (n > 0) ? 1 : ((n < 0) ? -1 : 0);
}

int pgcd(int a, int b) {
	return (b == 0) ? a : pgcd(b, a % b);
}

int collisions(int xn, int xd, int yn, int yd, int nxn, int nxd, int nyn, int nyd) {
	int i = divise(yn * nyd + nyn * yd, 2 * yd * nyd) + ik;
	int j = divise(xn * nxd + nxn * xd, 2 * xd * nxd) + jk;
	if(debug) {
		cout << "NEW " << nxn << "/" << nxd << " " << nyn << "/" << nyd << endl;
		cout << "Collision " << xn << "/" << xd << " " << yn << "/" << yd << " -> " << i << " " << j << " " << endl;
	}
	char cC, cV, cH;
	bool posV = (nxn % nxd == 0);
	bool posH = (nyn % nyd == 0);
	if(debug)
		cout << "EXCLU: " << posV << " " << posH << endl;
	if(posV && posH)
		cC = grille[i + sgn(dy)][j + sgn(dx)];
	if(posV)
		cV = grille[i][j + sgn(dx)];
	if(posH)
		cH = grille[i + sgn(dy)][j];
	if(debug) {
		cout << cC << cV << cH << endl;
		// cout << i + sgn(dy) << " : " << j + sgn(dx) << endl;
	}
	if(posV && posH) {
		if(cC == '#') {
			if(cV == '#') {
				if(debug)
					cout << "cC et cV" << endl;
				dx *= -1;
			} if(cH == '#') {
				if(debug)
					cout << "cC et cH" << endl;				
				dy *= -1;
			} if(cV != '#' && cH != '#')
				return 0;
		}
	} else if(posV && cV == '#')
		dx *= -1;
	else if(posH && cH == '#')
		dy *= -1;
	return 1;
}

void avancer(int xn, int xd, int yn, int yd) {
	if(debug)
		cout << "-> Avancer " << xn << "/" << xd << " " << yn << "/" << yd << " " << dx << " " << dy << " " << dist << " " << D << endl;
	int nxn, nxd, nyn, nyd;
	if(dist > D)
		return;
	// cout << ": " << (int) ceil((double) yn / yd - 1) << " " << ceil(yn / yd + 1) << " " << yd << " -> " << floor((double) yn / yd + 1) << endl;
	int xcoin = (dx < 0) ? ceil((double) xn / xd - 1) : floor((double) xn / xd + 1);
	int ycoin = (dy < 0) ? (int) ceil((double) yn / yd - 1) : floor((double) yn / yd + 1);
	// cout << ceil((double) yn / yd - 1) << " " << ycoin << " " << " " << dy << endl;
	if(debug) {
		cout << "Coins " << xcoin << " " << ycoin << endl;
		cout << (double) dy * (xcoin * xd - xn) / xd << " " << (double) dx * (ycoin * yd - yn) / yd << endl;
	}
	if(dy == 0 || (double) (dy * (xcoin * xd - xn) / xd > (double) dx * (ycoin * yd - yn) / yd && dx * dy < 0)
	   || ((double) dy * (xcoin * xd - xn) / xd < (double) dx * (ycoin * yd - yn) / yd && dx * dy > 0)) {
		nxn = xcoin;
		nxd = 1;
		nyn = yn * dx * xd + dy * yd * (nxn * xd - xn);
		nyd = yd * dx * xd;
		// cout << "V" << endl;
	} else {
		nyn = ycoin;
		nyd = 1;
		nxn = xn * dy * yd + dx * xd * (nyn * yd - yn);
		nxd = xd * dy * yd;
		// cout << "H" << endl; 
	}
	int px = pgcd(nxn, nxd);
	int py = pgcd(nyn, nyd);
	nxn = nxn / px;
	nxd = nxd / px;
	nyn = nyn / py;
	nyd = nyd / py;
	// cout << "Et les nouveaux numéros sont " << nxn << "/" << nxd << " " << nyn << "/" << nyd << endl;
	if(xn * nxd + nxn * xd == xd * nxd && yn * nyd + nyn * yd == yd * nyd) {
		if(debug) {
			// cout << x << " jdfiushufqusdf " << y << " " << dist << endl;
			// cout << (1/2 - x) * (1/2 - x) << endl;
			// cout << (1/2 - y) * (1/2 - y) << endl;
		}
		dist += sqrt((0.5 - (double) xn / xd) * (0.5 - (double) xn / xd) + (0.5 - (double) yn / yd) * (0.5 - (double) yn / yd));
		// cout << "Victoire ! " << dist << endl;
	} else if(collisions(xn, xd, yn, yd, nxn, nxd, nyn, nyd) == 0) {
		// cout << "Mort." << endl;
		return;
	} else {
		// cout << "HOP " << x + nx << " " << (x + nx == 1) << " " << y + ny << " " << (y + ny == 1) << endl;
		dist += sqrt(((double) nxn / nxd - (double) xn / xd) * ((double) nxn / nxd - (double) xn / xd) + ((double) nyn / nyd - (double) yn / yd) * ((double) nyn / nyd - (double) yn / yd));
		avancer(nxn, nxd, nyn, nyd);
	}

}

void lancer(int dxi, int dyi) {
	// cout << dxi << " " << dyi << "…" << endl;
	dist = 0;
	dx = dxi;
	dy = dyi;
	avancer(1, 2, 1, 2);
	if(dist <= D) {
		// cout << "!" << dxi << " " << dyi << endl;
		nbOcc++;
	}
}

int main() {
	int H, W, T;
	pair<int, int> p;
	set<pair<int, int> >::iterator it;
	cin >> T;
	for(int i = 1 ; i <= T ; i++) {
		cin >> H >> W >> D;
		nbOcc = 0;
		// cout << H << " " << W << " " << D << endl;
		for(int j = 0 ; j < H ; j++)
			cin >> grille[j];
		for(int j = 0 ; j < H ; j++)
			for(int k = 0 ; k < W ; k++)
				if(grille[j][k] == 'X') {
					ik = j;
					jk = k;
				}
		set<pair<int, int> > fractions;
		for(int j = -D ; j <= D ; j++)
			for(int k = 1 ; k <= D ; k++)
				if(j * j + k * k <= D * D) {
					p = make_pair(j / abs(pgcd(j, k)), k / abs(pgcd(j, k)));
					fractions.insert(p);
				}
		// cout << "Nombre d'éléments : " << fractions.size() << endl;
		for(int signe = -1 ; signe <= 1 ; signe += 2)
			for(it = fractions.begin() ; it != fractions.end() ; it++) {
				/* if((*it).second == 9 && (*it).first == -7)
					cout << "Coucou !" << endl; */
				// if(debug)
					// cout << "-------> [" << signe * (*it).second << "] " << (*it).first << endl;
				lancer(signe * (*it).second, (*it).first);
			}
		// lancer(9, -7);
		lancer(0, 1);
		lancer(0, -1);
		cout << "Case #" << i << ": " << nbOcc << endl;
	}
	return 0;
}