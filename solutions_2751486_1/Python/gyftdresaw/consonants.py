
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

vowels = ['a','e','i','o','u']

for i in xrange(trials):
    (name,n) = infile.readline().split()
    n = int(n)
    
    cislands = []
    cindex = 0
    while (cindex < len(name)):
        if name[cindex] in vowels:
            cindex += 1
        else:
            end = cindex
            while end < len(name) and not name[end] in vowels:
                end += 1
            streak = end - cindex
            if streak >= n:
                cislands.append((cindex,end-1))
            cindex = end
    
    total = 0
    for j in xrange(len(cislands)):
        (start,end) = cislands[j]
        clength = end - start + 1
        if j > 0:
            (ps,pe) = cislands[j-1]
            mins = pe - n + 2
        else:
            mins = 0
        last = len(name) - 1
        
        before = (clength - n)*(start - mins + 1)
        if clength >= n+2:
            internal = (clength - n - 1)*(clength-n)/2
        else:
            internal = 0
        after = (clength - n)*(last - end + 1)
        both = (start - mins + 1)*(last - end + 1)
        total += before + internal + after + both
    
    result = total
    s = "Case #%d: %s\n" % (i+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()