from copy import copy
import pdb
def eat(start, motes, n, max_depth, s):
    #pdb.set_trace()
    #print start, motes, n, s
    if n >= max_depth:
        return n
    if not motes:
        return n
    if start > motes[0]:
        start += motes[0]
        return eat(start, motes[1:], n, max_depth, s + "0")
    if (start != 1) and (start != 0):
        max_depth = min(eat(start + start - 1, motes, n+1, max_depth, s + "1"), max_depth)
    return eat(start, motes[1:], n+1, max_depth, s + "2")


def main(args):    
    in_f = open(args[1])
    out_f = open(args[1]+".out", 'wt')
    cases = int(in_f.readline())
    for i in xrange(1, cases + 1):
        #pdb.set_trace()
        (mote_size, c_moutes) = [int(j) for j in in_f.readline().split()]
        motes = [int(j) for j in in_f.readline().split()]
        motes.sort()
        #pdb.set_trace()
        out_f.write("Case #%d: %d\n" % (i, eat(mote_size, tuple(motes), 0, len(motes),"")))
    out_f.close()
    print "DONE!"

if __name__ == '__main__':
    import sys
    main(sys.argv)
        
        