import sys, string

debug = False

def mote(a, motes):
    ops = 0
    motes.sort()
    if debug: print a, motes
    while len(motes):
        curmote = motes.pop(0)
        if a <= curmote:
            if debug: print "Cursize %d, dealing with mote %d" % (a, curmote)
            if a < 2:
		return ops + len(motes) + 1
            # Try to add motes as long as it makes sense (less ops than just to delete everything)
            anew = a
            opsnew = 0
            while opsnew < len(motes)+1:
                anew += anew - 1
                opsnew += 1
                if anew > curmote:
                    break
            if debug: print "Trying to add %d motes" % opsnew
            # solve subtask
            opssub = mote(anew+curmote, motes[:])
            if opsnew + opssub <= len(motes):
                if debug: print "Added %d motes, subtask solved in %d ops, total %d" % (opsnew, opssub, ops + opsnew + opssub)
                return ops + opsnew + opssub
            else:
                if debug: print "Deleted %d motes" % (len(motes) + 1)
                return ops + len(motes) + 1
        else:
            a += curmote 
    return ops

def readnums(f):
    line = f.readline().rstrip()
    parts = line.split()
    nums = map(int, parts)
    return nums


def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for i in range(ncases):
        a, n = readnums(f)
        motes = readnums(f)
        motes.sort()
        ans = mote(a, motes)
        sys.stdout.write("Case #%d: %d\n" % (i+1, ans))

if __name__ == "__main__":
    main(sys.argv)