#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas) {
    cout << "Case #" << cas << ":" << endl;
    int r, c, m;
    cin >> r >> c >> m;
    if (r*c - m == 1) {
      for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c; ++j) cout << '*';
        cout << endl;
      }
      for (int j = 0; j < c - 1; ++j) cout << '*';
      cout << 'c' << endl;
    }
    else if (r == 1) {
      if (m <= c - 2) {
        int j;
        for (j = 0; m > 0; ++j, --m) cout << '*';
        for (; j < c - 1; ++j) cout << '.';
        cout << "c" << endl;
      }
      else cout << "Impossible" << endl;
    }
    else if (c == 1) {
      if (m <= r - 2) {
        int i;
        for (i = 0; m > 0; ++i, --m) cout << '*' << endl;
        for (; i < r - 1; ++i) cout << '.' << endl;
        cout << "c" << endl;
      }
      else cout << "Impossible" << endl;
    }
    else if (r == 2) {
      if (m%2 == 1 or r*c - m < 4) cout << "Impossible" << endl;
      else {
        int j;
        for (j = 0; j < m/2; ++j) cout << '*';
        for (; j < c; ++j) cout << '.';
        cout << endl;
        for (j = 0; j < m/2; ++j) cout << '*';
        for (; j < c - 1; ++j) cout << '.';
        cout << 'c';
        cout << endl;
      }
    }
    else if (c == 2) {
      if (m%2 == 1 or r*c - m < 4) cout << "Impossible" << endl;
      else {
        for (int i = 0; i < r - 1; ++i) {
          if (m > 0) {
            cout << "**" << endl;
            m -= 2;
          }
          else cout << ".." << endl;
        }
        cout << ".c" << endl;
      }
    }
    else {
      if (r*c - m == 7 or r*c - m == 5 or r*c - m < 4) cout << "Impossible" << endl;
      else {
        while (r > 3) {
          if (m < c) break;
          for (int j = 0; j < c; ++j, --m) cout << '*';
          cout << endl;
          --r;
        }
        if (r > 3) {
          int j;
          for (j = 0; j < c - 2 and m > 0; ++j, --m) cout << '*';
          for (; j < c; ++j) cout << '.';
          cout << endl;
          --r;
          if (m == 1) {
            cout << '*';
            for (j = 1; j < c; ++j, --m) cout << '.';
          }
          else for (j = 0; j < c; ++j, --m) cout << '.';
          cout << endl;
          --r;
          while (r > 1) {
            for (int j = 0; j < c; ++j) cout << '.';
            cout << endl;
            --r;
          }
          for (int j = 0; j < c - 1; ++j) cout << '.';
          cout << 'c' << endl;
        }
        else {
          int j;
          for (j = 0; j < m/3; ++j) cout << '*';
          for (int r = 0; r < m - 3*(m/3); ++r, ++j) cout << '*';
          for (; j < c; ++j) cout << '.';
          cout << endl;
          
          for (j = 0; j < m/3; ++j) cout << '*';
          for (; j < c; ++j) cout << '.';
          cout << endl;
          
          for (j = 0; j < m/3; ++j) cout << '*';
          for (; j < c - 1; ++j) cout << '.';
          cout << 'c' << endl;
        }
      }
    }
  }
}
