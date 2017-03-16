#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int x, int y)
{
  int r;

  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;

}

typedef struct {
  double x[2];
} V;

typedef struct {
  int x[2];
} IV;


#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define EPS (1e-6)

V roundv( V v) {
  V y;
  int i;
  for (i = 0; i <= 1; i++) {
    if (ABS(v.x[i] - round(v.x[i])) < EPS) {
      y.x[i] = round(v.x[i]);
    } else {
      y.x[i] = v.x[i];
    }
  }
  return y;
}

IV vtoiv(V v) {
  IV y;
  int i;
  for (i = 0; i < 2; i++) {
    y.x[i] = (int) floor(v.x[i]/2.0);
  }
  return y;
}

int iseven(double u) {
  return (u/2 == round(u/2));
}

class hall {
  int H, W, D;
  char map[31][31];
  V me;
  vector <IV> itans;
  vector <V> speeds;

public:


  int nspeeds(void) {
    return speeds.size();
  }

  V getme(void) {
    return me;
  }


  V ithspeed(int i) {
    return speeds[i];
  }

  void make_speeds(void) {
    int x, y;
    IV iv;
    V v;
    int i;

    itans.clear();
    speeds.clear();


    for (x = 0; x <= 50; x++) {
      for (y = 0; y <= 50; y++) {
	if ((x == 0) && (y == 0)) {
	  continue;
	}
	if (x > 0 && y > 0 && gcd(x, y) != 1) {
	  continue;
	}
	if (x == 0 && y > 1) {
	  continue;
	}
	if (y == 0 && x > 1) {
	  continue;
	}

	if (x == 0) {
	  iv.x[0] = x;
	  iv.x[1] = y;
	  itans.push_back(iv);
	  v.x[0] = 0;
	  v.x[1] = 1;
	  speeds.push_back(v);
	  iv.x[0] = x;
	  iv.x[1] = -y;
	  itans.push_back(iv);
	  v.x[0] = 0;
	  v.x[1] = -1;
	  speeds.push_back(v);
	} else if (y == 0) {
	  iv.x[0] = x;
	  iv.x[1] = y;
	  itans.push_back(iv);
	  v.x[0] = 1;
	  v.x[1] = 0;
	  speeds.push_back(v);
	  iv.x[0] = -x;
	  iv.x[1] = y;
	  itans.push_back(iv);
	  v.x[0] = -1;
	  v.x[1] = 0;
	  speeds.push_back(v);
	} else {
	  iv.x[0] = x;
	  iv.x[1] = y;
	  itans.push_back(iv);
	  v.x[0] = 1.0 / y;
	  v.x[1] = 1.0 / x;
	  speeds.push_back(v);

	  iv.x[0] = -x;
	  iv.x[1] = -y;
	  itans.push_back(iv);
	  v.x[0] = -1.0 / y;
	  v.x[1] = -1.0 / x;
	  speeds.push_back(v);

	  iv.x[0] = -x;
	  iv.x[1] = y;
	  itans.push_back(iv);
	  v.x[0] = -1.0 / y;
	  v.x[1] = 1.0 / x;
	  speeds.push_back(v);

	  iv.x[0] = x;
	  iv.x[1] = -y;
	  itans.push_back(iv);
	  v.x[0] = 1.0 / y;
	  v.x[1] = -1.0 / x;
	  speeds.push_back(v);
	}
      }
    }
    //    for (i = 0; i < itans.size(); i++) {
    //      cout << i << ", " << itans[i].x[0] << ", " << itans[i].x[1] << endl;
    //    }

  }


  void readmap(int h, int w, int d, vector <string> mps) {
    int i, j;
    H = h;
    W = w;
    D = d;
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
	map[i][j] = mps[i][j];
	if (map[i][j] == 'X') {
	  me.x[1] = 2 * i + 1;
	  me.x[0] = 2 * j + 1;
	}
      }
    }
  }


  
  V update_speed(V pos, V spd) {
    V newspd;
    V tmppos, tmppos2, tmppos3;
    IV I, I2, I3;

    if (iseven(pos.x[0]) && iseven(pos.x[1]) ) { // point
      tmppos.x[0] = pos.x[0] + spd.x[0];
      tmppos.x[1] = pos.x[1] + spd.x[1];
      I = vtoiv(tmppos);

      if (map[I.x[1]][I.x[0]] != '#') {
	newspd = spd;
	return newspd;

      }
      tmppos2.x[0] = pos.x[0] - spd.x[0];
      tmppos2.x[1] = pos.x[1] + spd.x[1];
      tmppos3.x[0] = pos.x[0] + spd.x[0];
      tmppos3.x[1] = pos.x[1] - spd.x[1];

      I2 = vtoiv(tmppos2);
      I3 = vtoiv(tmppos3);
      
      if (map[I2.x[1]][I2.x[0]] == '#' &&
	  map[I3.x[1]][I3.x[0]] == '#') {
	newspd.x[0] = -spd.x[0];
	newspd.x[1] = -spd.x[1];
	return newspd;
      }
      
      if (map[I2.x[1]][I2.x[0]] == '#' &&
	  map[I3.x[1]][I3.x[0]] != '#') {
	newspd.x[0] = spd.x[0];
	newspd.x[1] = -spd.x[1];
	return newspd;
      }

      if (map[I2.x[1]][I2.x[0]] != '#' &&
	  map[I3.x[1]][I3.x[0]] == '#') {
	newspd.x[0] = -spd.x[0];
	newspd.x[1] = spd.x[1];
	return newspd;
      }

      newspd.x[0] = 0;
      newspd.x[1] = 0;

      return newspd;

    } else if (iseven(pos.x[0])) {
      pos = roundv(pos);
      tmppos.x[0] = pos.x[0] + spd.x[0];
      tmppos.x[1] = pos.x[1];
      I = vtoiv(tmppos);

      if (map[I.x[1]][I.x[0]] != '#') {
	newspd = spd;
	return newspd;
      } else {
	newspd.x[0] = -spd.x[0];
	newspd.x[1] = spd.x[1];
	return newspd;
      }
    } else if (iseven(pos.x[1])) {
      pos = roundv(pos);
      tmppos.x[0] = pos.x[0];
      tmppos.x[1] = pos.x[1] + spd.x[1];
      I = vtoiv(tmppos);

      if (map[I.x[1]][I.x[0]] != '#') {
	newspd = spd;
	return newspd;
      } else {
	newspd.x[0] = spd.x[0];
	newspd.x[1] = -spd.x[1];
	return newspd;
      } 
    } else {
      newspd = spd;
      return newspd;
    }
  }

};

int debug = 0;


int main(void)
{

  int T, c;

  cin >> T;

  hall ha;

  for (c = 1; c <= T; c++) {
    int i, w, h, d, n;
    string s;
    vector <string> vs;
    double len;
    int cnt;
    

    ha.make_speeds();

    cin >> h;
    cin >> w;
    cin >> d;

    for (i = 0; i < h; i++) {
      cin >> s;
      vs.push_back(s);
    }
    ha.readmap( h,  w,  d, vs);


    n = ha.nspeeds();
    cnt = 0;

    for (i = 0; i < n; i++) {
      V v, newv;
      V me, x, newx;
      me = x = ha.getme();
      v = ha.ithspeed(i);
      len = 0;
      int scale;
      double dl = sqrt((v.x[0])*(v.x[0])+(v.x[1])*(v.x[1]));


      if (debug) {
	cout << "**** (" << v.x[0] << "," << v.x[1] << ") ****" << endl;
	cout << "(" << x.x[0] << "," << x.x[1] << ")";
      }

      while (1) {
	newx.x[0] = x.x[0] + v.x[0];
	newx.x[1] = x.x[1] + v.x[1];

	if (debug) {
	  cout << "(" << newx.x[0] << "," << newx.x[1] << ")";
	}

	newx = roundv(newx);
	len += dl; 

	//	if (ABS(len - round(len)) < EPS) {
	//	  len = round(len);
	//	}

	if (len > 2 * d + EPS) {
	  if (debug) {
	    cout << " NG" << endl;
	  }
	  break;
	}
	if (newx.x[0] == me.x[0] && newx.x[1] == me.x[1]) {
	  if (debug) {
	    cout << " OK" << endl;
	  }
	  cnt++;
	  break;
	}

	newv = ha.update_speed(newx, v);

	if (newv.x[0] == 0 && newv.x[1] == 0) {
	  if (debug) {
	    cout << " NG" << endl;
	  }
	  break;
	}
	x = newx;
	v = newv;
      }
    }
    cout << "Case #" << c << ": " << cnt << endl;
  }

  
  return 0;

}
