
fi = open("input.txt", "r")
fo = open("output.txt", "w")

def compute_z(string):
    n = len(string)                                                                                                                 
    z = [0] * n                                                                                                                     

    zbox_l, zbox_r, z[0] = 0, 0, n                                                                                                  
    for i in xrange(1, n):          
        if i < zbox_r:                                                                                          
            k = i - zbox_l
            if z[k] < zbox_r - i:   
                z[i] = z[k]                                                                                      
                continue            
            zbox_l = i                                                                                      
        else:
            zbox_l = zbox_r = i     
        while zbox_r < n and string[zbox_r - zbox_l] == string[zbox_r]:                                                             
            zbox_r += 1 
        z[i] = zbox_r - zbox_l                                                                                                      
    return z

def solve():
    k, l, s = map(int, fi.readline().strip().split(' '))
    keyboard = fi.readline().strip()
    goal = fi.readline().strip()
    zv = compute_z(goal)

    cs = []
    for i, z in enumerate(zv):
        if i + z == len(zv):
            cs.append(i)

    count = 0
    if len(cs) == 1:
        count = s / l
    else:
        ci = 0
        while ci + l <= s:
            count += 1
            ci += cs[1]

    alph = [0 for _ in xrange(26)]
    for ch in keyboard:
        alph[ord(ch) - ord('A')] += 1

    prob = 1.0
    for ch in goal:
        temp = float(alph[ord(ch) - ord('A')])
        valid = alph[ord(ch) - ord('A')] > 0
        prob *= temp / k

    exp = prob * count 

    if not valid: return "%.9f" % (0.0)
    return "%.9f" % (count - (count * prob))
    

if __name__ == "__main__":
    t = int(fi.readline().strip())
    for tt in xrange(1, t + 1):
        ans = solve()
        print "Case #%d: %s" % (tt, ans)
        print >>fo, "Case #%d: %s" % (tt, ans)

fo.close()
