import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for i in xrange(ncases):
        s = ""
        for j in xrange(4):
            s += f.readline().strip()
        f.readline()
        if len(s) != 16:
            raise "WTF not proper board"
            
        if "." in s:
            complete = False
        else:
            complete = True
            
        arr = [0,4, 1,4, 2,4, 3,4, 0,1, 4,1, 8,1, 12,1, 0,5, 3,3]
        
        xwon = False
        owon = False
        
        for j in xrange(0, 10*2, 2):
            xcount = 0
            ocount = 0
            tcount = 0
            
            pos = arr[j]
            for k in xrange(4):
                if s[pos] == "X":
                    xcount += 1
                elif s[pos] == "O":
                    ocount += 1
                elif s[pos] == "T":
                    tcount += 1
                    
                pos += arr[j+1]
            
            if xcount + tcount == 4:
                xwon = True
            
            if ocount + tcount == 4:
                owon = True
                
        if complete:
            outs = "Draw"
        else:
            outs = "Game has not completed"
            
        if xwon and not owon:
            outs = "X won"
            
        if owon and not xwon:
            outs = "O won"
            
        if xwon and owon:
            outs = "Draw"
            
        print "Case #%d: %s" % (i+1, outs)
        
main()