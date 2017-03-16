import sys
 
def solve(msg):
   nrs = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
   uniq = ["Z","","W","","U","","X","","G",""]
   nrs2 = ["", "ONE", "", "THREE", "", "FIVE", "", "SEVEN", "", "NINE"]
   nuniq = ["","O","","T","","F","","S","",""]
   nrs9 = [str(x) for x in xrange(0,10)]

   final = []
   # remove unique letters
   for i in xrange(len(uniq)):
       if len(uniq[i]) > 0:
          while uniq[i] in msg:
             final.append(nrs9[i])
             for c in nrs[i]:
                 msg = msg.replace(c,"",1)
             # print " 1 .. removed", i, msg, final

   # remove unique 2
   if len(msg) > 0:
     for i in xrange(len(nuniq)):
         if len(nuniq[i]) > 0:
            while nuniq[i] in msg:
               final.append(nrs9[i])
               for c in nrs[i]:
                   msg = msg.replace(c,"",1)
               # print " 2 .. removed", i, msg, final

   # remove nines
   if len(msg) > 0:
      # print "remanin", msg
      if "N" not in msg: 
         print "PROBLEMS, msg does not have N"
      else:
         while "N" in msg:
            nine = "NINE"
            for x in nine:
                msg = msg.replace(x,"",1)
            final.append("9")

   answer = "".join([ str(x) for x in sorted(final)])
#   print final, answer
   return answer
 
# main()
 
# read 1 number, use it to control the loop
for tc in xrange(1, int(sys.stdin.readline())+1):
    # read 2 numbers
    msg = sys.stdin.readline().strip()
    # read several floats, keep the result in a list
 
    best = solve(msg)
    print 'Case #%d: %s' % (tc, best)
