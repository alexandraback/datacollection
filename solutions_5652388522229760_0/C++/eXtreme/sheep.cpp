#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <assert.h>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

// Dwa z najczesciej uzywanych typow o dlugich nazwach - ich
// skrocenie jest bardzo istotne
typedef vector<int> VI;
typedef long long LL;

// W programach bardzo rzadko mozna znalezc w pelni zapisana
// instrukcje petli.
// Zamiast niej wykorzystywane sa trzy nastepujace makra:
// FOR - petla zwiekszajaca zmienna x od b do e wlacznie
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
// FORD - petla zmniejszajaca zmienna x od b do e wlacznie
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
// REP - petla zwiekszajaca zmienna x od 0 do n. Jest ona bardzo czesto
// wykorzystywana do konstruowania i przegladania struktur danych
#define REP(x, n) for(int x = 0; x < (n); ++x)
// Makro VAR(v,n) deklaruje nowa zmienna o nazwie v oraz typie i
// wartosci zmiennej n. Jest ono czesto wykorzystywane podczas operowania
// na iteratorach struktur danych z biblioteki STL, ktorych nazwy typow
// sa bardzo dlugie
#define VAR(v, n) __typeof(n) v = (n)
// ALL(c) reprezentuje pare iteratorow wskazujacych odpowiednio na pierwszy
// i za ostatni element w strukturach danych STL. Makro to jest bardzo
// przydatne chociazby w przypadku korzystania z funkcji sort, ktora jako
// parametry przyjmuje pare iteratorow reprezentujacych przedzial
// elementow do posortowania
#define ALL(c) (c).begin(), (c).end()
// Ponizsze makro sluzy do wyznaczania rozmiaru struktur danych STL.
// Uzywa sie go w programach, zamiast pisac po prostu x.size() ze wzgledu na to,
//
// iz wyrazenie x.size() jest typu unsigned int i w przypadku porownywania z
// typem int w procesie kompilacji generowane jest ostrzezenie
#define SIZE(x) ((int)(x).size())
// Bardzo pozyteczne makro sluzace do iterowania po wszystkich elementach
// w strukturach danych STL
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
// Skrot - zamiast pisac push_back podczas wstawiania elementow na koniec
// struktury danych, takiej jak vector, wystarczy napisac PB
#define PB push_back
// Podobnie - zamiast first bedziemy pisali po prostu ST
#define ST first
// a zamiast second - ND
#define ND second
#include <list>
template<class V, class E> struct Graph {
    // Typ krawedzi (Ed) dziedziczy po typie zawierajacym dodatkowe informacje zwiazane
    // z krawedzia (E). Zawiera on rowniez pole v, okreslajace numer wierzcholka, do
    // ktorego prowadzi krawedz. Zaimplementowany konstruktor pozwala na skrocenie
    // zapisu wielu funkcji korzystajacych ze struktury grafu
    struct Ed : E {
        int v;
        Ed(E p, int w) : E(p), v(w) {}
    };
    // Typ wierzcholka (Ve) dziedziczy po typie zawierajacym dodatkowe informacje z
    // nim zwiazane (V) oraz po wektorze krawedzi. To drugie dziedziczenie moze
    // wydawac sie na pierwszy rzut oka stosunkowo dziwne, lecz jest ono
    // przydatne - umozliwia latwe iterowanie po wszystkich krawedziach wychodzacych
    // z wierzcholka v: FOREACH(it, g[v])
    struct Ve : V,vector<Ed> {};
    // Wektor wierzcholkow w grafie
    vector<Ve> g;
    // Konstruktor grafu - przyjmuje jako parametr liczbe wierzcholkow
    Graph(int n=0) : g(n) {}
    // Funkcja dodajaca do grafu nowa krawedz skierowana z wierzcholka b do e,
    // zawierajaca dodatkowe informacje okreslone przez zmienna d
    void EdgeD(int b, int e, E d = E()) {
        g[b].PB(Ed(d,e));
    }
    void Write() {
        // Dla wszystkich wierzcholkow w grafie, zaczynajac od 0...
        REP(x, SIZE(g)) {
            // Wypisz numer wierzcholka
            cout << x << ":";
            // Dla kazdej krawedzi wychodzacej z przetwarzanego wierzcholka o numerze x
            // wypisz numer wierzcholka, do ktorego ona prowadzi
            FOREACH(it, g[x]) cout << " " << it->v;
            cout << endl;
        }
    }
    // Wektor sluzacy do odznaczania odwiedzonych wierzcholkow
    VI vis;
    // Wskaznik do konstruowanego grafu silnie spojnych skladowych
    Graph<V,E> *sccRes;
    // Funkcja przechodzaca graf za pomoca algorytmem DFS. Jest ona wykorzystywana
    // dwukrotnie: w pierwszej fazie podczas wyznaczania kolejnosci wierzcholkow dla
    // drugiej fazy, a nastepnie podczas drugiej fazy do wyznaczania silnie spojnych
    // skladowych oraz konstrukcji grafu silnie spojnych skladowych
    void SccDfs(int v,int nr, bool phase) {
        // Zaznacz wierzcholek jako odwiedzony
        g[v].t = 1;
        // Jesli wykonywana jest druga faza przeszukiwania, to ustaw dla wierzcholka
        // numer silnie spojnej skladowej
        if(!phase) vis[v] = nr;
        // Odwiedz kolejne wierzcholki oraz (jesli wykonywana jest druga faza)
        // dodaj krawedz do konstruowanego grafu silnie spojnych skladowych
        FOREACH(it, g[v]) if (g[it->v].t == -1)
            SccDfs(it->v, nr, phase);
        else if(!phase && nr > vis[it->v])
            sccRes->EdgeD(g[it->v].t, vis[it->v]=nr);
        // Jesli wykonywana jest pierwsza faza, to wstaw wierzcholek do listy,
        // a jesli druga, to zaktualizuj jego czas
        if(phase) vis.PB(v);
        else g[v].t = nr;
    }
    // Funkcja wyznaczajaca silnie spojne skladowe w grafie
    Graph<V,E> Scc() {
        // Graf gt to graf transponowany, a res to konstruowany graf silnie spojnych skladowych
        Graph<V,E> gt(SIZE(g)),res(SIZE(g)),*tab[]= {this, & gt};
        gt.sccRes=&res;
        gt.vis.resize(SIZE(g), -1);
        vis.clear();
        // Budowanie grafu transponowanego
        REP(i,SIZE(g)) FOREACH(it,g[i]) gt.EdgeD(it->v,i);
        // Przeprowadz dwie fazy algorytmu DFS...
        REP(i,2) {
            // Zaznacz wierzcholki jako nieodwiedzone
            FOREACH(it,tab[i]->g) it->t = -1;
            int comp=0,v;
            // Dla kolejnych nieodwiedzonych wierzcholkow wykonaj przeszukiwanie
            FORD(j,SIZE(g)-1,0)
            if (tab[i]->g[v=(i?vis[j]:j)].t == -1) tab[i]->SccDfs(v,comp++,1-i);
            if (i) res.g.resize(comp);
        }
        REP(i,SIZE(g)) g[i].t=gt.g[i].t;
        return res;
    }
    
};
struct Ve {
};
// Wzbogacenie wierzcholkow zawiera pole, w ktorym umieszczany jest numer
// silnie spojnej skladowej
struct Vs {
    int t;
};


/* YOU NEED THIS TOO!!!
 #include <string.h>
 */
int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "debug") == 0 ) {
        //        printf("== [RUNNING IN DEBUG MODE]==\n\n");
        char test_file_path[] = "/Users/horban/Dropbox/AlgPrak/in.txt";
        freopen(test_file_path, "r", stdin);
    }
    std::ios::sync_with_stdio(false);
    typedef long long ll;
    
    int t; cin >> t;
    REP(tnr, t) {
        ll n; cin >> n;
        cout << "Case #" << tnr + 1 << ": ";
        if (n == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }
        
        bool seen[10]; memset(seen, 0, sizeof(seen));
        FOR(i, 1, 1000000000) {
            ll k = n * i;
            while(k > 0) {
                int dig = k % 10;
                k /= 10;
                seen[dig] = 1;
            }
            int s = 0;
            REP(i, 10) s+=seen[i];
            if (s == 10) {
                cout << i * n << endl;
                break;
            }
        }
    }
    
    return 0;
}

















