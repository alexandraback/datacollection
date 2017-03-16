#!/usr/bin/env python3

tn = int (input ())
for t in range (1, tn + 1):
    n = int (input ())
    v = []
    #min_v = None
    #min_c = 0
    #max_v = None
    #max_c = 0
    ans = set ()
    for i in range (2 * n - 1):
        v.append (list (map (int, input ().split ())))
        for x in v[-1]:
            if x in ans:
                ans.remove (x)
            else:
                ans.add (x)
            #if min_v is None or x < min_v:
            #    min_v, min_c = x, 0
            #if x == min_v:
            #    min_c += 1
            #if max_v is None or x > max_v:
            #    max_v, max_c = x, 0
            #if x == max_v:
            #    max_c += 1
    #assert min_c <= 2 and max_c <= 2 and min_c + max_c >= 3
    #a = [[0 for j in range (n)] for i in range (n)]
    #if min_c == 2:
    print ("Case #%d: %s" % (t, ' '.join (map (str, sorted (ans)))))
        
