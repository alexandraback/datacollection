def getMapping():
    mapping = [
               ("y qee", "a zoo"),
               ("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"),
         ("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"),
         ("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")]
    
    M = {'z':'q'}
    
    for (a, b) in mapping:
        for i in xrange(0, len(a)):
            M[a[i]] = b[i]
    
    return M
    
M = getMapping()

IN = open("c:/cj/A-small-attempt1.in", 'r')
OUT = open("c:/cj/A-small.out", 'w')

N = int(IN.readline().strip())

for case_nbr in xrange(1, N + 1):
    line = IN.readline().strip();
    res = map(lambda x: M[x], line)
    OUT.write("Case #" + str(case_nbr) + ": " + "".join(res) + "\n")

IN.close()
OUT.close()

print "done"