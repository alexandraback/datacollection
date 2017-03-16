def FindSum(Ni):
   Seen = [0]*2000000;
   How = [[]]*2000000;
  

   CanDo = [[0]];    # CanDo[i] will list available sums using first i digits:
   for i in range(20):
      CanDo.append([]);
      for e in CanDo[i]:
         CanDo[i+1] += [e, e+ni[i]];
         if Seen[e+ni[i]] == 1:
            list1 = How[e+ni[i]];
            list2 = How[e]+[ni[i]];
            for e in list1:
               print e,
            print
            for e in list2:
               print e,
            print
#            print e, How[e+ni[i]], How[e]+[ni[i]];
            return;
         Seen[e+ni[i]] = 1;
         How[e+ni[i]] = How[e] + [ni[i]];
            
#      for j in range(len(CanDo[i])-1):
#         if CanDo[i][j] == CanDo[i][j+1]:
#            print 'MATCH FOUND', CanDo[i][j], i;
#            return
#      print len(CanDo), len(CanDo[i]), CanDo[0:3]


   

T = int(raw_input());
for i in range(T):
   print "Case #%d:" % (i+1);
   ni = map(int, raw_input().split());
   N = ni.pop(0);
   FindSum(ni)
   # N = 20;

   

#   CanDo = [0]*2000000;
#   CanDo[0] = 1;
#   
#   for i in range(N):
#      for j in range(
   

 
