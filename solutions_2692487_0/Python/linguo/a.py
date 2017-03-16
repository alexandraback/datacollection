def parse(inFile):
    return (tuple(inFile.getInts()), sorted(inFile.getInts()))

def solve(((A, n), motes)):
    rec = n
    inc = 0
    rem = n
    for mote in motes:
        if (A == 1) and (mote >= A):
            break
        while mote >= A:
            A = 2 * A - 1
            inc += 1
        A += mote
        rem -= 1
        scr = inc + rem
        if scr < rec:
            rec = scr
    return str(rec)

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2013_1b/a/", "A").run()

            
