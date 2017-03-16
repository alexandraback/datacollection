import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        counts = {}
        for c in "abcdefghijklmnopqrstuvwxyz":
            counts[c] = 0
            
        s = f.readline().strip().lower()
        for c in s:
            counts[c] += 1
            
        digits = ""
        if counts["z"] > 0:
            n = counts["z"]
            digits += "0" * n
            for c in "zero":
                counts[c] -= n
                
        if counts["w"] > 0:
            n = counts["w"]
            digits += "2" * n
            for c in "two":
                counts[c] -= n
        
        if counts["u"] > 0:
            n = counts["u"]
            digits += "4" * n
            for c in "four":
                counts[c] -= n
                
        if counts["x"] > 0:
            n = counts["x"]
            digits += "6" * n
            for c in "six":
                counts[c] -= n

        if counts["g"] > 0:
            n = counts["g"]
            digits += "8" * n
            for c in "eight":
                counts[c] -= n
                
        if counts["o"] > 0:
            n = counts["o"]
            digits += "1" * n
            for c in "one":
                counts[c] -= n
                
        if counts["h"] > 0:
            n = counts["h"]
            digits += "3" * n
            for c in "three":
                counts[c] -= n
                
        if counts["f"] > 0:
            n = counts["f"]
            digits += "5" * n
            for c in "five":
                counts[c] -= n
                
        if counts["s"] > 0:
            n = counts["s"]
            digits += "7" * n
            for c in "seven":
                counts[c] -= n
                
        if counts["i"] > 0:
            n = counts["i"]
            digits += "9" * n
            for c in "nine":
                counts[c] -= n
        
        for c in counts:
            if counts[c] != 0:
                sys.stderr.write("BAAAAAAAAAAAAD")
                exit()
                
        res = "".join(sorted(list(digits)))
        print "Case #%d: %s" % (caseno+1, res)
        
main()