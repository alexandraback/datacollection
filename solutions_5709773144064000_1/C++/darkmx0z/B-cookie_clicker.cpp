#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>

double resuelve(double costo_granja, double beneficio, double objetivo)
{
   double transcurrido = 0;
   double pasivo = 2;
   double mejorar = objetivo / pasivo;
  
   while (transcurrido + costo_granja / pasivo < mejorar) {
      transcurrido += costo_granja / pasivo;
      pasivo += beneficio;
      mejorar = std::min(mejorar, transcurrido + objetivo / pasivo);
   }
   
   return mejorar;
}

int main( )
{
   int t;
   std::cin >> t;
   
   std::cout.setf(std::ios::fixed, std::ios::floatfield);
   std::cout.precision(7);
   
   for (int ti = 0; ti < t; ++ti) {
      double c, f, x;
      std::cin >> c >> f >> x;
      
      std::cout << "Case #" << ti + 1 << ": " << resuelve(c, f, x) << '\n';
   }
}
