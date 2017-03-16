def Crash(i, Cars):
   overlap = [];
   for j in range(len(Cars)):
      if j != i:
         dV = Cars[i][0]-Cars[j][0];
         dR = Cars[i][1]-Cars[j][1];
         if (dV == 0):
            if (abs(dR) < 5):
               overlap.append( [0, 1e10] );     # Always next to each other;
         else:
            if (dV*dR > 0):                     # Faster car in front:
               if dR < 5:
                  overlap.append( [0, (5.-dR)/dV] );

            else:                               # Faster car behind:
               start = 0.;
               end = 0.;
               if abs(dR) > 5:
                  start = (abs(dR)-5.)/abs(dV);
               end   = (abs(dR)+5.)/abs(dV);
               overlap.append( [start, end] );            
            
   IntTime = [];
   for pair in overlap:
      if pair[0] not in IntTime:
         IntTime.append( pair[0] );
      if pair[1] not in IntTime:
         IntTime.append( pair[1] );
   IntTime.sort();
         
   return IntTime;
   


def Check(t0, cars):
   D = [];
   if t0 < 0:
      return False;
   
   for veh in cars:
      D.append( veh[0]*(t0+1e-6) + veh[1] );

#   if t0 > 10:
#      print "Woooooooooo", t0,  D
      
   for a in range(len(cars)):
      for b in range(len(cars)):
         for c in range(len(cars)):
            if (a != b) and (a != c) and (b != c):
               if (abs(D[a]-D[b]) < 5) and (abs(D[b]-D[c]) < 5) and (abs(D[a]-D[c]) < 5):
                  return True;

   return False;

   

T = int(raw_input());
for i in range(T):
   print "Case #%d:" % (i+1),;
   N = int(raw_input());
   Data = []
   Cars = [];
   ALL = [];
   for i in range(N):
      line = raw_input().split();
      ALL.append(line);
      Cars.append( map(int, line[1:] ) );
   if N <= 2:
      print "Possible";
   else:
      problem = [];
      times = [];
      for i in range(len(Cars)):
         times += Crash(i, Cars);
      times.sort();
      q = 0;
      while (q < len(times)-1):
         if times[q] == times[q+1]:
            times.pop(q);
         else:
            q += 1

      Crashed = False;
      q = 0;
      while (q < len(times)) and not Crashed:
         Crashed = Check(times[q], Cars);
         q += 1;
      if Crashed:
         ANSWER = times[q-1];
#         print "Old answer", ANSWER


      if len(times) == 0:
         print "Possible";

      else:
         Tmax = max(times);
         Crashed = False;
         time = 0.;
         dt = 3e-3;
         Car = [];
         for i in range(N):
            Car.append( ALL[i] );
            Car[-1][1] = int(Car[-1][1]);
            Car[-1][2] = float(Car[-1][2]);
         CrashedYet = False;
         while (time <= max(times)) and not CrashedYet:
            for i in range(N):
               Car[i][2] += Car[i][1]*dt;
            for i in range(N):
               for j in range(i):      # See if car i is about to hit car j;
                  if Car[i][0] == Car[j][0]:
                     if abs(Car[i][2] - Car[j][2]) < 5:  # Collision - change lanes!
                        if Car[i][0] == 'L':
                           Car[i][0] = 'R';
                        else:
                           Car[i][0] = 'L';
                        for k in range(N):
                           if (i != k) and (Car[i][0] == Car[k][0]) and (abs(Car[i][2] - Car[k][2]) < 5):
                              CrashedYet = True;
            time += dt;
#         print time
         ANSWER = 0;
         for tt in times:
            if tt <= time:
               ANSWER = tt;

         if ANSWER == 0:
            print "Possible"
         else:
            print ANSWER
                  
             
         
#      print Car
#      while (time


