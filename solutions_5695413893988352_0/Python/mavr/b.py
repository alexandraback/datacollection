import sys


global ans
ans = (999999999999999999, 0, 0, "", "")

def repl(s, pos, c):
    return s[:pos]+c+s[pos+1:]

def larger(a, b):
    for A, B in zip(a, b):
        if A=="?" or B=="?":
            return 0
        if (ord(A)<ord(B)):
            return -1
        elif (ord(A)>ord(B)):
            return 1
    return 0

def bf(a, b, pos):  
        #print a, b
        if (pos>=len(a)):
            global ans
            A = int(a)
            B = int(b)
            nans = (abs(A-B), A, B, a, b)
            #print nans, ans
            if nans<ans:
                ans = nans
            return    
        i = pos
        A = a[pos]
        B = b[pos]
        if (A==B=="?"):
            aa = repl(a, i, "0")
            bb = repl(b, i, "0")
            bf(aa, bb, i+1)
            l = larger(a, b)
            #print a, b, l
            if (l==1):
                aa = repl(a, i, "0")
                bb = repl(b, i, "9")
                bf(aa, bb, i+1)
            elif (l==-1):
                aa = repl(a, i, "9")
                bb = repl(b, i, "0")
                bf(aa, bb, i+1)
            else:
                aa = repl(a, i, "0")
                bb = repl(b, i, "9")
                bf(aa, bb, i+1)
                aa = repl(a, i, "9")
                bb = repl(b, i, "0")
                bf(aa, bb, i+1)
            if (not (i<len(a)-1 and a[i+1]==b[i+1]=="?")):
                aa = repl(a, i, "1")
                bb = repl(b, i, "0")
                bf(aa, bb, i+1)
                aa = repl(a, i, "0")
                bb = repl(b, i, "1")
                bf(aa, bb, i+1)
        elif (A=="?"):
            if (B=="9"):
                aa = repl(a, i, "8")
                bf(aa, b, i+1)
            elif (B=="0"):
                aa = repl(a, i, "1")
                bf(aa, b, i+1)
            else:
                for cc in xrange(ord(B)-1, ord(B)+2):
                    if chr(cc) in ("0", "9"):
                        continue
                    aa = repl(a, i, chr(cc))
                    bf(aa, b, i+1)
            aa = repl(a, i, "9")
            bf(aa, b, i+1)
            aa = repl(a, i, "0")
            bf(aa, b, i+1)
        elif (B=="?"):
            if (A=="9"):
                bb = repl(b, i, "8")
                bf(a, bb, i+1)
            elif (A=="0"):
                bb = repl(b, i, "1")
                bf(a, bb, i+1)
            else:
                for cc in xrange(ord(A)-1, ord(A)+2):
                    if chr(cc) in ("0", "9"):
                        continue
                    bb = repl(b, i, chr(cc))
                    bf(a, bb, i+1)    
            bb = repl(b, i, "9")
            bf(a, bb, i+1)
            bb = repl(b, i, "0")
            #if a=="10" and b=="?5":
            #    print a, bb
            bf(a, bb, i+1)
        else:
            bf(a, b, i+1)



def solve(t):
    global ans
    ans = (999999999999999999, 0, 0, "", "")
    a, b = t.split()
    bf(a, b, 0)
    return "%s %s" % (ans[3], ans[4])

#input_filename = sys.argv[1]
input_filename = "B-small-attempt1.in"#"in.txt" #

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        tnum = int(infile.readline())
        for t in xrange(tnum):
            test = infile.readline().strip()
            ans = solve(test)
            outfile.write("Case #%d: %s\n" % (t+1, ans))
            print (t+1, ans)
        