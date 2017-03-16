import sys

flag = []
edge = []
visit = []

def fx(n):
   global flag, edge, visit
   flag[n] = flag[n] + 1
   visit[n] = True

   if flag[n] > 1:
      return True

   for n2 in edge[n]:
      if fx(n2):
         return True

   return False


f = open("input")
T = int(f.readline())
for t in range(0, T):
   N = int(f.readline())
   edge = []
   visit = []
   found = False
   for n in range(0, N):
      values = f.readline().split()
      visit.append(False)
      r = []
      for e in range(0, int(values[0])):
         r.append(int(values[e + 1]) -1)
      edge.append(r)

   for n in range(0, N):
      if not visit[n]: 
         
         flag = []
         for ni in range(0, N):
            flag.append(0)

         if fx(n):
            found = True
            break

   
   if found:
      print "Case #%d: Yes" % (t + 1)
   else:
      print "Case #%d: No" % (t + 1) 

      


         
