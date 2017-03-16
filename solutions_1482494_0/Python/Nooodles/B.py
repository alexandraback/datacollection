def RunSlow(N, data):
   one = [];
   for i in range(N):
      one.append( data[i][0] );
      one.append( data[i][1] );
   one.sort();

#   print one 
   for i in range(2*N):
      if one[i] > i:
         return False;
   
   return  True;
   

def RunGreedy(N, data):
   Nstar = 0;
   Saves = 0;
   one = [];
   two = [];
   for pair in data:
      two.append(pair);

   while (Nstar < 2*N):       # Play the game!
#      print Nstar, one, two
      i = 0;
      Decided = False;
      
      while (i < len(one)) and not Decided:           # Can remove a singleton
         if Nstar >= one[i]:
            Decided = True;
            Nstar += 1;
            one.pop(i);
         else:
            i += 1;

      if not Decided:
         i = 0;
         while( i < len(two)) and not Decided:        # Can do a pair
            if Nstar >= two[i][1]:
               Decided  = True;
               Nstar += 2;
               Saves += 1;
               two.pop(i);
            else:
               i += 1;

      if not Decided:
         i = 0;
         j = 0;      high = 0;
         while (i < len(two)):
            if Nstar >= two[i][0]:
               if two[i][1] > high:
                  high = two[i][1];
                  j = i;

            i += 1;
         Nstar += 1;
         one.append( two[j][1] );
         two.pop(j);
            
   print Nstar - Saves;
      
   
   


T = int(raw_input());
for i in range(T):
   print "Case #%d:" % (i+1),;
   N = int(raw_input());
   Data = []
   for i in range(N):
      Data.append( map(int, raw_input().split()) );

   if not RunSlow(N, Data):
      print "Too Bad";
   else:
      RunGreedy(N, Data);
  
   
   

