T = int(raw_input())  
for t in xrange(T):
    R, C, W = map(int, raw_input().split(' '))  
    
    ans=-(-C//W)*R+W-1
              
    print "Case #%d: %s" % (t+1, ans)
  