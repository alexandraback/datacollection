import sys
import logging
# logging.basicConfig(format="    %(message)s", level=logging.DEBUG)

testCases = int(input())
    
for testCase in range(1, testCases + 1):
        
    si = sys.stdin.readline().strip().split()  
    
    j = int(si[0]) 
    p = int(si[1])
    s = int(si[2])
    k = int(si[3])

    logging.debug("\n    Case #" + str(testCase) + ": ")            
    logging.debug("J: "+str(j)+" P: "+str(p)+" S: "+str(s)+" K: "+str(k))    
    

    # there are j * p * s possible outfits
    # min(j*p, p*k)
    # We can wear any jacket up to 'k' * min(p,s) = p 

    # We can wear any pants up to k * s, so we get the (p,s) combinations 
    wear = []
    for x in range(1, j+1):
        for y in range(1, min(p,k)+1):
            for z in range(1, min(s,k)+1): 
                w = str(x) + " " + str(y) + " " + str(z)      
                logging.debug("WEAR IT: "+w)
                wear.append(w)
    
    logging.debug(str(wear))
    print("Case #" + str(testCase) 
       #   + " " + str(j) + "-" + str(p) + "-" + str(s) +" K: "+str(k)
          + ": " + str(len(wear)))
    for w in wear:
      print(w)