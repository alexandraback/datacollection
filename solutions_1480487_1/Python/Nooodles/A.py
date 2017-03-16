



T = int(raw_input());
for i in range(T):
   print "Case #%d:" % (i+1),;
   Ji = map(int, raw_input().split());
   N = Ji.pop(0);
   X = sum(Ji);
   #print N, X, Ji

   # Total score of all contestants will be 2*X;
   # If you have a score of 2*X/N, you're safe

   for q in range(1):                      # Relic code...
#      Goal = 2.*X/N;     # Basic goal
#      Need = Goal-Ji[i];
#      if Need <= 0:
#         print '0.0', 
#      else:
#         print 100.*Need/X,

      Pnt = 100./X;
      Req = [0.]*N;
      ToDis = X;
#      print X, Pnt, Req
      while (ToDis > 0):
         need = [];
         Min = min(Ji);
         for i in range(N):
            if Ji[i] == Min:
               need.append(i);
         if len(need) < ToDis:
            ToDis -= len(need);
            for i in need:
               Ji[i] += 1;
               Req[i] += Pnt;
         else:
            for i in need:
               Req[i] += (Pnt*ToDis)/len(need);
            ToDis = 0;

      for f in Req:
         print f,
      print 
   

