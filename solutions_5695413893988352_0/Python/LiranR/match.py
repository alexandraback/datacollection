def min_distance(s1, s2):
    if len(s1) == 0:
        return ("","",0)
    
    if s1[0] != s2[0] and s1[0] != "?" and s2[0] != "?":
        if s1[0] > s2[0]:
            s1 = s1.replace("?","0")
            s2 = s2.replace("?","9")
            return (s1, s2, abs(int(s1)-int(s2)) )
        else:
            s2 = s2.replace("?","0")
            s1 = s1.replace("?","9")
            return (s1, s2, abs(int(s1)-int(s2)) )
        
    if s1[0] == s2[0] and s1[0] != "?": 
        res = min_distance(s1[1:],s2[1:])
        return (s1[0] + res[0], s2[0] + res[1], res[2])

    if s1[0] != "?" and s2[0] == "?":
        if s1[0] == "0":
            options = ["0","1"]
        elif s1[0] == "9":
            options = ["8","9"]
        else:
            options = [ str(int(s1[0])-1), s1[0], str(int(s1[0])+1)]
            
        best = ("","",float('inf'))
        for o in options:
            res = min_distance(s1, o + s2[1:])
            if res[2] < best[2]:
                best = res
        return best

    if s2[0] != "?" and s1[0] == "?":
        if s2[0] == "0":
            options = ["0","1"]
        elif s2[0] == "9":
            options = ["8","9"]
        else:
            options = [ str(int(s2[0])-1), s2[0], str(int(s2[0])+1)]
        best = ("","",float('inf'))
        for o in options:
            res = min_distance(o + s1[1:], s2)
            if res[2] < best[2]:
                best = res
        return best

    if s1[0] == "?" and s2[0] == "?":
        options = [ ("0","0"), ("0","1"), ("1","0") ]
        best = ("","",float('inf'))
        for o in options:
            res = min_distance(o[0] + s1[1:], o[1] + s2[1:])
            if res[2] < best[2]:
                best = res
        return best

T = int(raw_input())
for t in xrange(1, T+1):
    s1, s2 = raw_input().split()
    res = min_distance(s1,s2)
    print "Case #%d: %s %s"%(t,res[0],res[1])
        
