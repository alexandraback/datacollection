#include <iostream>
#include <set>

int trampa(std::set<double> naomi, std::set<double> ken)
{
   int puntos = 0;
   
   for (;;) {
      while (!naomi.empty( ) && *naomi.begin( ) < *ken.begin( )) {
         naomi.erase(naomi.begin( ));
         ken.erase(std::prev(ken.end( )));     
      }
   
      if (naomi.empty( )) {
         break;
      }
      
      puntos += 1;
      
      naomi.erase(naomi.begin( ));
      ken.erase(ken.begin( ));
   }
   
   return puntos;
}

int justo(std::set<double> naomi, std::set<double> ken)
{
   int puntos = 0;
   
   for (auto i = naomi.begin( ); i != naomi.end( ); ++i) {
      auto oponente = ken.lower_bound(*i);
      
      if (oponente == ken.end( )) {
         oponente = ken.begin( );
      }
      
      puntos += (*i > *oponente);
      ken.erase(oponente);
   }
   
   return puntos;
}

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int n;
      std::cin >> n;
      
      std::set<double> naomi, ken;
      
      for (int i = 0; i < n; ++i) {
         double temp;
         std::cin >> temp;
      
         naomi.insert(temp);
      }
      
      for (int i = 0; i < n; ++i) {
         double temp;
         std::cin >> temp;
      
         ken.insert(temp);     
      }
      
      std::cout << "Case #" << ti + 1 << ": " << trampa(naomi, ken) << ' ' << justo(naomi, ken) << '\n';
   }
}
