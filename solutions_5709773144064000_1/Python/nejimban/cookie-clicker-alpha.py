# si achat d'une ferme, le faire le plus tôt possible
# minimiser C*sum(2/(2+k*F), k=0..(r-1)) + X/(2+r*F) pour r entier ≥ 0
# r nombre de fermes achetées
# achat de r+1 fermes nécessite au moins r*(C/2) secondes
#   si r*(C/2) ≥ X, nul besoin d'acheter une (r+1)-ème ferme
#   donc r < 2*X/C

from math import ceil
from sys import stdin

T = stdin.readline() # ignored
cases = [tuple(float(y) for y in x.split()) for x in stdin.read().splitlines()]
for i, (C, F, X) in enumerate(cases, 1):
  m = X/2
  s = 0
  for r in range(1, ceil(2*X/C)):
    s += 1.0/(2+(r-1)*F)
    m = min(m, C*s + X/(2+r*F))
  print('Case #%d: %.12f' % (i, m))
