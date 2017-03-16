#include "../common.h"

string raw;

void Readin() {
  getline(cin, raw);
}

void Work() {  // process one case
  const string goo = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra"
                     "dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re"
                     "ujdr lkgc jvqz";
  const string eng = "our language is impossible to understand there are twenty"
                     "six factorial possibilities so it is okay if you want to"
                     "just give upzq";

  map<char, char> g2e, e2g;
  forall (i, goo) g2e[goo[i]] = eng[i], e2g[eng[i]] = goo[i];

  string out;
  forall (i, raw) out.append(1, g2e[raw[i]]);
  cout << out << endl;
}

int main() {
  const string main_filename = 
      SetFile(" A-small-attempt0           ");

  int num_test;  cin >> num_test;
  assert(Eoln(cin));  Readln(cin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    cout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Readin();
    Work();
    //cout << ans << endl;
  }

  if (!SeekEof(cin)) cerr << "Wrong! Not at EOF!" << endl;
  fclose(stdin);
  fclose(stdout);

  cerr << "\n--------------- OUTPUT: ----------------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

