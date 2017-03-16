from math import floor
from math import sqrt

def reader(inFile):
   case = [int(z) for z in inFile.readline().split()]
   return case

def solver(case):
   paint = case[1]
   ring = case[0]
   b = 2*ring-1
   s = long(b**2+8*paint)
   if (s >= 0):
      k1 = (-b+sqrt(s))/4
      k2 = (-b-sqrt(s))/4
   if k1>0:
      rings = int(floor(k1))
   else:
      rings = int(floor(k2))
   if (paint < (2*rings**2+rings*b)):
       rings-=1
   return rings

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/code/1A/", "A").run()
