#include <iostream>
#include <cstdio>
using namespace std;
struct elem {
	long long x,y;
	elem(){}; elem(long long be1, long long be2) {
		x = be1; y = be2;
		long long jo = 1;
		long long ig = x; if (y < x) ig = y;
		//for (long long i = 1; i<=ig; i++) {
		//	if (x % i == 0 && y % i == 0) jo = i;
		//}
		x /= jo; y /= jo;
		
		if (x < 0 && y < 0) { x = 0-x; y = 0-y; }
		if (y < 0) { y = 0-y; x = 0-x; }
	}
};
elem osszead(elem a, elem b){
	return elem(a.x*b.y+b.x*a.y, a.y*b.y);
}
elem kivon(elem a, elem b){
	return elem(a.x*b.y-b.x*a.y, a.y*b.y);
}
elem szoroz(elem a, elem b){
	return elem(a.x*b.x, a.y*b.y);
}
elem reciprok(elem a){
	return elem(a.y,a.x);
}
elem oszt(elem a, elem b){
	return szoroz(a, reciprok(b));
}


int n,pos[100],speed[100];

int travel (int d1, int d2) {
	if (d1 < d2) return d2-d1;
	return travel(d1, d2+360);
}

int solve() {
	if (n == 1) return 0;
	
    if (speed[1] > speed[2]) { swap(speed[1], speed[2]); swap(pos[1], pos[2]); }
    
    int p1 = pos[1]; int p2 = pos[2];
    elem s1 = elem(360, speed[1]); elem s2 = elem(360, speed[2]);
    //printf("x\n");
    
    if (p1 <= p2) p1-=360;

    elem ido = oszt(elem(travel(p1, p2), 1), kivon(s1, s2));
    if (ido.x < 0) ido.x = 0 - ido.x;
    //printf("y\n");
    
    elem szamit = osszead(elem(p2, 1), szoroz(ido, s2));
    
    if (szamit.x > 360*szamit.y) return 0; return 1;
}

int main()
{
    int hany = 0; scanf("%d", &hany);
    for (int i = 1; i<=hany; i++) {

        n = 0;

        int hany2; scanf("%d", &hany2);
        for (int j = 1; j<=hany2; j++) {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            for (int l = 1; l<=b; l++) {
                n++;
                pos[n] = a; speed[n] = c+l-1;
            }
        }
        
        printf("Case #%d: %d\n", i, solve());
        
    }


    return 0;
}
