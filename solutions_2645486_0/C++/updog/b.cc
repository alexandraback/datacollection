#include "common.h"

int64 E, R;
int n;

void Readin() {  // process one case
  fin >> E >> R >> n;
  if (R > E) R = E;
}

struct Node {
  int64 val;
  int64 e;
};

void Work() {  // process one case
  int64 ans = 0;

  deque<Node> a;
  
  { Node node;
    fin >> node.val;
    node.e = E;
    a.push_back(node);
  }
  
  forint (i, 2, n) {
    
    int64 use = 0;
    while (use < R && !a.empty()) {
      int64 to_use = Min(a.front().e, R - use);
      ans += a.front().val * to_use;
      a.front().e -= to_use;
      use += to_use;
      if (a.front().e == 0) a.pop_front();
    }

    Node node;
    fin >> node.val;
    node.e = R;
    
    while (!a.empty() && node.val > a.back().val) {
      node.e += a.back().e;
      a.pop_back();
    }
    a.push_back(node);
  }

  forall (i, a) {
    ans += a[i].e * a[i].val;
  }

  fout << ans << endl;
}

int main() {
  const string main_filename = SetFile(/*@*/"B-small-attempt0        ");

  int num_test;  fin >> num_test;
  CHECK(Eoln(fin));  Readln(fin);
  
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

