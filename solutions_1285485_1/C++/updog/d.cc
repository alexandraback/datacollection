#include "common.h"
#include <boost/rational.hpp>

typedef boost::rational<int64> Rational;

double ToDbl(const Rational x) { return boost::rational_cast<double>(x); }

const double eps = 1e-8;

int m, n, max_dis;
int r_start, c_start;
vector<string> cells;

void Readin() {  // process one case
  fin >> m >> n >> max_dis;
  cells = vector<string>(m, string(n, 0));
  forall (i, cells) forall (j, cells[i]) {
    fin >> cells[i][j];
    CHECK(cells[i][j] == '#' || cells[i][j] == '.' || cells[i][j] == 'X');
    if (cells[i][j] == 'X') r_start = i, c_start = j;
  }
}

double Distance(const Rational &x0, const Rational &y0,
                const Rational &x1, const Rational &y1) {
  return sqrt(ToDbl(Sqr(x0 - x1) + Sqr(y0 - y1)));
}

bool CheckEnd(const Rational &x0, const Rational &y0,
              const Rational &x1, const Rational &y1,
              const double moved) {
  if (x0 + x1 == 2*r_start && y0 + y1 == 2*c_start) {
    if (moved + 0.5*Distance(x0, y0, x1, y1) <= max_dis + eps) return true;
  }
  return false;
}

void PassInOneCell(const int r, const int c,
                   const Rational &x, const Rational &y,
                   const int dx, const int dy,
                   Rational &new_x, Rational &new_y) {
  const Rational half = Rational(1, 2);
  Rational dis_x = (dx == 0 ? kIntMax : (dx > 0 ? r + half - x : x - r + half));
  Rational dis_y = (dy == 0 ? kIntMax : (dy > 0 ? c + half - y : y - c + half));
  CHECK(dis_x == kIntMax || (0 <= dis_x && dis_x <= 1));
  CHECK(dis_y == kIntMax || (0 <= dis_y && dis_y <= 1));
  CHECK(dis_x != kIntMax || dis_y != kIntMax);
  if (dis_y == kIntMax || (dis_x != kIntMax && dis_x * Abs(dy) <= dis_y * Abs(dx))) {
    new_x = x + Sign(dx) * dis_x;
    new_y = y + Sign(dy) * dis_x * boost::abs(Rational(dy, dx));
  } else {
    new_y = y + Sign(dy) * dis_y;
    new_x = x + Sign(dx) * dis_y * boost::abs(Rational(dx, dy));
  }
}  // PassInOneCell(...)

bool Simulate(const int ori_dx, const int ori_dy) {
  const Rational half = Rational(1, 2);
  
  int r = r_start, c = c_start;
  Rational x(r), y(c);
  int dx = ori_dx, dy = ori_dy;
  double moved = 0;
  
  do {
    Rational new_x, new_y;
    PassInOneCell(r, c, x, y, dx, dy, new_x, new_y);
    if (CheckEnd(x, y, new_x, new_y, moved)) return true;
    moved += Distance(x, y, new_x, new_y);
    if (moved > max_dis + eps) return false;
    
    int dr(0), dc(0);
    if (new_x == r - half) { dr = -1; CHECK(dx < 0); }
    if (new_x == r + half) { dr = +1; CHECK(dx > 0); }
    if (new_y == c - half) { dc = -1; CHECK(dy < 0); }
    if (new_y == c + half) { dc = +1; CHECK(dy > 0); }
    int rc_diff = Abs(dr) + Abs(dc);
    CHECK(IsBetween(rc_diff, 1, 2));

    // cerr << "newxy: " << new_x << ' ' << new_y << endl;
    // cerr << "dr dc: " << dr << ' ' << dc << endl << endl;

    x = new_x, y = new_y;
    
    if (rc_diff == 1) {
      if (cells[r + dr][c + dc] == '#') {
        if (Abs(dr) == 1) dx *= -1; else dy *= -1;
      } else {
        r = r + dr, c = c + dc;
      }
    } else {  // rc_diff == 2
      CHECK(dx != 0 && dy != 0);
      int cnt_sharp = 0;
      if (cells[r + dr][c] == '#') ++cnt_sharp;
      if (cells[r][c + dc] == '#') ++cnt_sharp;
      if (cells[r + dr][c + dc] == '#') ++cnt_sharp;
      
      if (cnt_sharp == 0) {
        r = r + dr, c = c + dc;
      } else if (cnt_sharp == 1) {
        if (cells[r + dr][c + dc] == '#') {
          return false;
        } else {
          r = r + dr, c = c + dc;
        }
      } else if (cnt_sharp == 3) {
        dx *= -1, dy *= -1;
      } else if (cnt_sharp == 2) {
        if (cells[r + dr][c + dc] != '#') {
          r = r + dr, c = c + dc;
        } else if (cells[r][c + dc] != '#') {
          dx *= -1;
          c += dc;
        } else {
          dy *= -1;
          r += dr;
        }
      }
    }

    if (!((r - half <= new_x && new_x <= r + half) ||
          (c - half <= new_y && new_y <= c + half))) {
      ABORT("Kao3!");
    }
  } while (true);
}

void Work() {  // process one case
  
  set<int> feasible_set;
  forint (dx, -max_dis, max_dis) {
    forint (dy, -max_dis, max_dis) {
      if (dx == 0 && dy == 0) continue;
      if (Sqr(dx) + Sqr(dy) > Sqr(max_dis)) continue;
      const int gcd = Abs(boost::gcd(dx, dy));
      if (gcd != 1) continue;
      const int id = dx * 10000 + dy;
      if (feasible_set.count(id) > 0) continue;
      if (Simulate(dx, dy)) feasible_set.insert(id);
    }
  }

  // if (feasible_set.size() < 20) {
  //   foritr (itr, feasible_set) cerr << *itr << endl;
  // }

  fout << feasible_set.size() << endl;
}

int main() {
  const string main_filename = 
      SetFile("       D-large.         ");

  int num_test;  fin >> num_test;
  assert(Eoln(fin));  Readln(fin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    fout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Readin();
    Work();
    //fout << ans << endl;
  }

  if (!SeekEof(fin)) ABORT("Wrong! Not at EOF!");
  fclose(stdin);
  fclose(stdout);

  cerr << "\n\n---------- OUTPUT of " + main_filename + ": ----------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

