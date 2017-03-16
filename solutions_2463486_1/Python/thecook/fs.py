from math import sqrt, log10
import sys

#generate fair and square
def g_f_s(low, high):
    lowr = long(sqrt(low))
    highr = long(sqrt(high)) + 1
    candidates = [x*x for x in g_p_r(lowr,highr)]
    fs =  [x for x in candidates if low <= x <= high and is_palin(x)]
    return len(fs)
    
def is_palin(x):
    s = str(x)
    l = len(s)
    for i in range(l/2):
        if s[i] != s[l-i-1]:
            return False
    return True
    
#generate palindrome range
def g_p_r(low, high):
    lowsize = long(log10(low))+1
    highsize = long(log10(high))+1
    if lowsize == highsize:
        return [x for x in g_p_s(lowsize) if low <= x <= high]
    else:
        lows = [x for x in g_p_s(lowsize) if low <= x]
        #sys.stderr.write("finished " + str(lowsize)+"\n")
        highs = [x for x in g_p_s(highsize) if x <= high]
        #sys.stderr.write("finished " + str(highsize)+"\n")
        tr = lows
        for i in range(lowsize+1,highsize):
            tr += g_p_s(i)
            #sys.stderr.write("finished " + str(i)+"\n")
        tr += highs
        return tr
    
#generate palindrome size
def g_p_s(length): 
    if length == 1:
        return range(1,10)
    l = [x for x in range(10**((length/2)-1), 10**(length/2))]
    if length % 2 == 0:
        newl = [long(str(x)+str(x)[::-1]) for x in l]
    else:
        newl =  [long(str(x) + str(y) + str(x)[::-1]) for x in l for y in range(10)]
    return [x for x in newl if len(str(x)) == length]
        
        
if __name__=="__main__":
    filename = sys.argv[1]
    f = open(filename, 'r')
    numtests = int(f.readline())
    for i in range(1, numtests+1):
        l = f.readline().split()
        print "Case #" + str(i) + ": " + str(g_f_s(long(l[0]), long(l[1])))