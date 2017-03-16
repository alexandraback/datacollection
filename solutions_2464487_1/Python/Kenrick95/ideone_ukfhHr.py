import math
T = int(raw_input())
for s in range(1, T+1):
    line = raw_input()
    data = line.partition(" ")
    
    r = float(data[0])
    t = float(data[2])
    ans = 0.0
    ans = int(((4.0*r*r -4.0*r + 8.0*t +1.0)**.5 + (-2.0*r + 1.0))/4.0)
    print "Case #"+str(s)+": "+str(ans)
    #print s
"""cin>>T;
   for (int s=1; s<=T; s++) {
      cin>>r;
      cin>>t;
      ans = 0;
      ans = (int64(sqrt((2*r-1)*(2*r-1) + 8*t)) + (-2*r + 1))/4;
      cout<<"Case #"<<s<<": "<<ans<<endl;
   }
"""