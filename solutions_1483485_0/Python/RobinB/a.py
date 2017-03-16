import sys

s = "qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
te = "zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"


def Solve(n,v1,v2):
    v1s = sorted(v1)
    v2s = sorted(v2, reverse=True)
    
    mult = 0
    for i in range(n):
        mult = mult + v1s[i]*v2s[i]

    return mult
        
        




f = open('a.in')
print "start..."
T = int(f.readline())
for t in range(T):
    text = f.readline()
    result = ""
    for letter in text:
        c = 0
        for l2 in s:
            if letter == l2:
                result = result + te[c]
                break

            c = c+1


            
    print "Case #%d: %s" % (t+1, result)
print "finish!"