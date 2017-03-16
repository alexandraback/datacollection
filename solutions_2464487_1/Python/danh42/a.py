
def ringscost(rmin, r):
   rmax = rmin + 2 * (r-1)
   return  r + r * 2 * ((rmax + rmin) // 2)

def maxrings(rmin, t):
   if ringscost(rmin, 1) > t: return 0
   rc=1
   while ringscost(rmin, rc) <= t:
      rc *= 2
   minr=rc//2
   maxr=rc
   while (minr+1<maxr):
      rc = (maxr+minr)//2
      if ringscost(rmin, rc) <= t:
         minr=rc
      else:
         maxr=rc
   return minr

def main():
   import sys
   lines=open(sys.argv[1],'r').readlines()
   T=int(lines[0].strip())
   for tc in range(T):
      a,b=lines[tc+1].strip().split()
      r,t=int(a), int(b)
      print("Case #"+str(tc+1)+": "+str(maxrings(r,t)))
main()
