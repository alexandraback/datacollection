from collections import Counter
t = int(raw_input())

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def remove(ind,count,d):
    l = Counter()
    for e in digits[ind]: l[e]+=1
    for e in l:
        d[e] -= (l[e]*count)
    
for cn in xrange(t):
    s = raw_input()
    d = Counter()
    for l in s:
        d[l]+=1
    res = "0"*d['Z']
    remove(0,d['Z'],d)
    res += "6"*d['X']
    remove(6,d['X'],d)
    res += "2"*d['W']
    remove(2,d['W'],d)
    res += "8"*d['G']
    remove(8,d['G'],d)
    res += "3"*d['H']
    remove(3,d['H'],d)
    res += "7"*d['S']
    remove(7,d['S'],d)
    res += "5"*d['V']
    remove(5,d['V'],d)
    res += "4"*d['F']
    remove(4,d['F'],d)
    res += "1"*d['O']
    remove(1,d['O'],d)
    res += "9"*d['E']
    remove(9,d['E'],d)
    print "Case #%d: %s" %(cn+1,"".join(sorted(res)))
    
    
    
