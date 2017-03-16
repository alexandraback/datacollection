import sys, string

def strategy(pwlen, typed, pcorrect):
    pcacc = pcorrect[0]
    # base case - enter + retyping + enter
    min_ex = pwlen + 2
#    print "base case %d" % min_ex
    for i in range(1, typed):
        ex = typed - i + pcacc*(pwlen-i+1) + (1-pcacc)*(pwlen*2-i+2)
#        print "%d backspaces, typethrough %d with p %f, fail %d with p %f, %f expected" % (typed-i, (pwlen-i+1), pcacc, (pwlen*2-i+3), (1-pcacc), ex)
        pcacc *= pcorrect[i]
        min_ex = min(min_ex, ex)
    ex = pcacc*(pwlen-typed+1) + (1-pcacc)*(pwlen*2-typed+2)    
#    print "typethrough %f expected" % ex
    min_ex = min(min_ex, ex)
    return min_ex

def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for i in range(ncases):
        line = f.readline().strip()
        typed, pwlen = map(int, line.split(" "))
        line = f.readline().strip()
        pcorrect = map(float, line.split(" "))
        ans = strategy(pwlen, typed, pcorrect)
        sys.stdout.write("Case #%d: %f\n" % (i+1, ans))

if __name__ == "__main__":
    main(sys.argv)