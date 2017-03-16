import sys

def g(s1, s2):
    best_diff = 10**20
    
    for i in xrange(len(s1)):
        if (s1[i] == '?') or (s2[i] == '?'):
            for c in xrange(10):
                if s1[i] == '?':
                    new_s1, new_s2 = g(s1[:i] + str(c) + s1[i+1:], s2)
                else:
                    new_s1, new_s2 = g(s1, s2[:i] + str(c) + s2[i+1:])
                diff = abs(int(new_s1)-int(new_s2))
                new_r = new_s1, new_s2
                if (diff < best_diff) or ((diff == best_diff) and ((new_r[0] < r[0]) or ((new_r[0] == r[0]) and (new_r[1] < r[1])))):
                    best_diff = diff
                    r = new_r
    if best_diff == 10**20:
        return s1, s2
    return r
                    
def f(s1, s2):
    is_eq = True
    for i in xrange(len(s1)):
        if (s1[i] != s2[i]) and (s1[i] != '?') and (s2[i] != '?'):
            is_eq = False
            pos = i
            break

    if is_eq:
        new_s = ""
        for i in xrange(len(s1)):
            if (s1[i] == '?') and (s2[i] == '?'):
                new_s += '0'
            else:
                if s1[i] != '?':
                    new_s += s1[i]
                else:
                    new_s += s2[i]

        return new_s, new_s
    return g(s1, s2)

    
                        
if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"

    if len(sys.argv) > 2:
        ofname = sys.argv[2]
    else:
        ofname = "out.txt"
                                                               
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]

    outp = open(r"out.txt", "wb")
    for i in xrange(len(inp)):
        print i
        cin = inp[i].split()
        cin = [cin[0].strip(), cin[1].strip()]
        r = " ".join(f(*cin))
        outp.write("Case #%d: " % (i+1) + r + "\r\n")        
        
    outp.close()


                
