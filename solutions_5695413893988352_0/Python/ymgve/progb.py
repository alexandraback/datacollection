import sys

import psyco; psyco.full()

def test_good(mask, cand):
    for i in xrange(len(mask)):
        if mask[i] == "?":
            continue
        if mask[i] != cand[i]:
            return False
    
    return True
    
def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        teamc, teamj = f.readline().strip().split()

        best = 99999999, 999999999, 9999999999, "XX", "YY"
        for ic in xrange(10**len(teamc)):
            for ij in xrange(10**len(teamj)):
                sc = str(ic).rjust(len(teamc), "0")
                sj = str(ij).rjust(len(teamc), "0")
                if test_good(teamc, sc) and test_good(teamj, sj):
                    diff = abs(ic-ij)
                    if diff < best[0]:
                        best = diff, ic, ij, sc, sj
                    elif diff == best[0]:
                        if ic < best[1]:
                            best = diff, ic, ij, sc, sj
                        elif ic == best[1]:
                            if ij < best[2]:
                                best = diff, ic, ij, sc, sj
                        
        
        print "Case #%d: %s %s" % (caseno+1, best[3], best[4])
        
main()