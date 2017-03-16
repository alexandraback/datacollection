from collections import Counter
def f(n):
    o = Counter(n.lower())
    s = [0]*10
    for let,n,word in (
        ("x", 6,"six"),
        ("z", 0,"zero"),
        ("w", 2,"two"),
        ("g", 8,"eight"),
        ("u", 4,"four"),
        ("o", 1,"one"),
        ("r", 3,"three"),
        ("s", 7,"seven"),
        ("v", 5,"five"),
        ("i", 9,"nine")
    ):
        s[n] = o[let]
        for i in xrange(s[n]):
            o -= Counter(word)
        
    # print o
    return "".join(str(i)*j for i,j in enumerate(s))
        
        
T = int(raw_input())
for i in xrange(1,T+1):
    print "Case #%d: %s" % (i, f((raw_input())))
    
# 4
# OZONETOWER
# WEIGHFOXTOURIST
# OURNEONFOE
# ETHER
    


    