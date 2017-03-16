#include <iostream>
#include <string>
#include <cmath>
#include <set>

#include <QDebug>
#include <QFile>
#include <QMap>
#include <QStringList>

using namespace std;


struct Classe {
  int id;
  QList<int> next;
  bool operator=(const Classe& other) {
    id = other.id;
    next = other.next;
  }
};

bool CheckAlreadyVisited(QList<int>& already_visited, int id) {
  //qDebug() << "already_visited:: id" << id;
  if (already_visited.contains(id)) {
    return false;
  }
  already_visited.append(id);
  return true;
}

bool Test(QList<Classe>& tab, const Classe& classe, QList<int>& already_visited) {
  if (!CheckAlreadyVisited(already_visited, classe.id))
    return false;
  foreach(const int next_id, classe.next) {
    //qDebug() << "next id: " << next_id;
    //qDebug() << tab[next_id-1].id;
    if (!Test(tab, tab[next_id-1], already_visited))
      return false;
  }
  return true;
}

int main(int argc, char **argv) {
  unsigned long long nb_test = 0;
  QFile myFile(argv[1]);
  if (!myFile.open(QIODevice::ReadOnly)) // Open the file
    cout << "Error while opening " << argv[0] << endl;
  QString first_line = myFile.readLine();
  nb_test = first_line.toInt();
  for (unsigned long long test_i=1; test_i<=nb_test; test_i++) {

    QString line1 = myFile.readLine();
    int nb_classes = line1.toInt();
    //qDebug() << "nb_classes : " << nb_classes;
    //Classe tab[nb_classes];
    QList<Classe> tab;
    for (unsigned int classe_i = 1; classe_i <= nb_classes; classe_i++) {
      Classe classe;
      tab.append(classe);
    }
    // Contruct tab
    for (unsigned int classe_i = 1; classe_i <= nb_classes; classe_i++) {
      Classe current_classe;
      current_classe.id = classe_i;

      QString line = myFile.readLine();
      QStringList line_splitted = line.split(" ");
      int nb_inh = line_splitted[0].toInt();
      //qDebug() << "nb_inh: " << nb_inh;
      for (unsigned int inh_i = 1; inh_i <= nb_inh; inh_i++) {
        int inh = line_splitted[inh_i].toInt();
        current_classe.next.append(inh);
      }
      tab[classe_i-1] = current_classe;
    }

    bool result = true;
    for (unsigned int classe_i = 1; classe_i <= nb_classes; classe_i++) {
      QList<int> already_visited;
      const Classe& current_classe = tab[classe_i-1];
      result &= Test(tab, current_classe, already_visited);
    }

    cout << "Case #" << test_i << ": " << (result ? "No" : "Yes") << endl;
  }

  return 0;
}

