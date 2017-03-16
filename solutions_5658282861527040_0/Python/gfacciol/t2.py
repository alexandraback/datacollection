f = open('in')
cases = int(f.readline())

for case in range(cases):
   A, B, K = map(int , f.readline().split())

   win = 0
   for a in range(A):
      for b in range(B):
         if  a&b < K:
            win+=1

#   print tend, t_next_farm, tend_next_speed
   print "Case #%d: %d"%(case+1, win)

